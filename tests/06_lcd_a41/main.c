#include "gpio.h"
#include "char_data.h"
#include "delay.h"

int bg_color;
int fg_color;

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
	ILI9325_Clear();

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
	ILI9325_Text("XXXXXXX hello world XXXXXXX\n");
	return;	
}
