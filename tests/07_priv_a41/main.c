#include "gpio.h"
#include "char_data.h"
#include "delay.h"

int bg_color = 0;
int fg_color = 0;

void msg_init();
void msg_proc();
void msg_putc(const char);
void msg_puts(const char *);

#define lcd_as_output()				\
do {						\
	REG_GPIO_PXFUNS(3) = 0x0000ffff;	\
	REG_GPIO_PXSELC(3) = 0x0000ffff;	\
	REG_GPIO_PXPES(3) = 0x0000ffff;		\
} while (0)

#define lcd_out(dat)				\
do {						\
	REG_GPIO_PXDAT(3) = dat;		\
} while (0)

#define lcd_out16(dat)				\
do {						\
	REG_GPIO_PXDATS(3) = (dat & 0xffff);	\
	REG_GPIO_PXDATC(3) = ((~dat) & 0xffff);	\
} while (0)

/***************

port output program

USAGE:

   > go 0x80600000 0 [A-D][0-9][0-9][HLZ]


B19 -- PB19
H : set to H level , L : set to L level , Z : set to Hi-Z (input)

****************/

static void set_pin(int pin, int val) {
	if (val > 0) {
		__gpio_as_output(pin);
		__gpio_set_pin(pin);
	} else if (val == 0) {
		__gpio_as_output(pin);
		__gpio_clear_pin(pin);
	} else {
		__gpio_as_input(pin);
	}
}

static inline void do_eret()
{
	__asm__ __volatile__(
	"mfc0   $t0,$12\n\t"		\
	"lui	$v0,0x0040\n\t"		\
	"xor	$t0,$t0,$v0\n\t"	\
	"mtc0	$t0,$12\n\t"		\
	"sll	$zero,1\n\t"		\
	"sll	$zero,1\n\t"		\
	"sll	$zero,1\n\t"		\
	"sll	$zero,$zero,0x3\n\t"	\
        "eret\n\t"			\
        "nop\n" ::);
}

extern void longjmp(unsigned *,int);
extern int setjmp(unsigned *);

void change_privmode() {
	unsigned int *p;
	p = (void *)0x80000170;
	unsigned int jmp_buf[20];

	__icache_invalidate_all();
	p[0] = (unsigned int)longjmp;
	p[1] = (unsigned int)jmp_buf;
	p[2] = 1;			/* return val of setjmp */
	p[3] = 0;
	p[4]  = 0x3c028000;	// lui     v0,0x8000
	p[5]  = 0x24420170;	// addiu   v0,v0,0x0170
	p[6]  = 0x8c480000;	// lw      t0,0(v0)
	p[7]  = 0x8c440004;	// lw      a0,4(v0)
	p[8]  = 0x8c450008;	// lw      a1,8(v0) 
	p[9]  = 0x8c46000c;	// lw      a2,12(v0)
	p[10] = 0x01000008;	// jr      t0
	p[11] = 0x00000000;	// nop
	__dcache_writeback_all();
	if (setjmp(jmp_buf)) {
		__icache_invalidate_all();
		return;
	}
	do_eret();
	for (;;)
		;
}


static inline unsigned int read_c0_epc() {
	unsigned int c = 0;
	ILI9325_Text("mfc0 c0_epc -> ");
	__asm__ __volatile__("                  \
		.set noreorder;                 \
		mfc0	%0,$14;                 \
		ssnop;		\
		ssnop;		\
		ssnop;		\
		ssnop;		\
		.set reorder"			\
		: "=r" (c): );
	ILI9325_Hex(c);
	ILI9325_Text("\n");
	return c;
}

static inline unsigned int read_c0_errorepc() {
	unsigned int c = 0;
	ILI9325_Text("mfc0 c0_errorepc -> ");
	__asm__ __volatile__("                  \
		.set noreorder;                 \
		mfc0	%0,$30;                 \
		ssnop;		\
		ssnop;		\
		ssnop;		\
		ssnop;		\
		.set reorder"			\
		: "=r" (c): );
	ILI9325_Hex(c);
	ILI9325_Text("\n");
	return c;
}

static inline unsigned int read_c0_status() {
	unsigned int c = 0;
	ILI9325_Text("mfc0 c0_status -> ");
	__asm__ __volatile__("                  \
		.set noreorder;                 \
		mfc0	%0,$12;                 \
		ssnop;		\
		ssnop;		\
		ssnop;		\
		ssnop;		\
		.set reorder"			\
		: "=r" (c): );
	ILI9325_Hex(c);
	ILI9325_Text("\n");
	return c;
}

static inline void set_c0_status(unsigned int c) {
	ILI9325_Text("mtc0 c0_status <- ");
	ILI9325_Hex(c);
	__asm__ __volatile__("                  \
		.set noreorder;                 \
		nop;		\
		mtc0	%0,$12;                 \
		ssnop;		\
		ssnop;		\
		ssnop;		\
		ssnop;		\
		.set reorder"			\
		: : "r" (c));
	ILI9325_Text("  -- OK\n");
}

void c_main(int argc, char *argv[]) {
	int i;
	int pin,on_off;
	int c;

	msg_init((void *)argv);
	c = argv[1][0];
	pin = 32 * 2 + 13; /* PC13/PWM3 -- LCD backlight (A-41) */
	on_off = 1; /* on */
	if (c >= 'A' && c <= 'D') {
		pin = (c - 'A') * 32;
		c = argv[1][1];
		if (c >= '0' && c <= '9') {
			pin += (c - '0') * 10;
		}
		c = argv[1][2];
		if (c >= '0' && c <= '9') {
			pin += (c - '0');
		}
		if ((argv[1][3] == '-') || (argv[1][3] == 'L')) {
			on_off = 0;
		} else if (argv[1][3] == 'Z') {
			on_off = -1;
		}
	}
	msg_puts("XXXXXXX hello world XXXXXXX\n");

	msg_puts("argc = ");
	msg_put_hex(argc);
	msg_puts("\nargv :");
	msg_put_hex(argv);
	msg_puts("\nproc_func addr :");
	msg_put_hex(get_proc_func());
	msg_puts("\n");
#if 1
	for (i=0; i<10; i++) {
		msg_proc();
	}
#endif
	msg_puts("set pin ");
	msg_put_hex(pin);
	msg_puts("-> ");
	msg_put_hex(on_off);
	msg_puts("\n");
	set_pin(pin, on_off);


	bg_color = 0x000f; // dark blue
	fg_color = 0xffff; // white

	ILI93XX_Init();
	ILI9325_Init();
	ILI9325_Clear(0);

	bg_color = 0xf800; // red
	ILI9325_Char(10,10,'A');
	ILI9325_Char(10,11,'B');
	ILI9325_Char(11,11,'C');
	mdelay(200);
	ILI9325_Scroll(8);
	mdelay(200);
	ILI9325_Char(10,10,'A');
	ILI9325_Char(10,11,'B');
	ILI9325_Char(11,11,'C');
	mdelay(200);
	ILI9325_Text("XXXXXXX hello world XXXXXXX\n");
	c = read_c0_status();
	read_c0_epc();
	read_c0_errorepc();
	ILI9325_Text("XXXXXXX hello world XXXXXXX\n");

#if 0
	if (c & 0x4) { // ERL == 1
		change_privmode();
	}
#endif
	c = read_c0_status();
#if 1
	c &= ~0x4; /* NG */
	set_c0_status(c);
#endif
	c |= 0x10000000;
	c &= ~0x1;
	set_c0_status(c);
	c |= 0x1;
	set_c0_status(c);
	c &= ~0x1;
	set_c0_status(c);
	c &= ~0x10;
	set_c0_status(c);

	c = read_c0_status();
	ILI9325_Text("XXXXXXX hello world XXXXXXX\n");
}
