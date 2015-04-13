#include "gpio.h"

#define CPUCLOCK	228000000

void msg_init();
void msg_proc();
void msg_putc(const char);
void msg_puts(const char *);

/***************

port output program (blink)

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

inline void __delay(unsigned int loops)
{
        __asm__ __volatile__ (
        "       .set    noreorder                               \n"
        "       .align  3                                       \n"
        "1:     bnez    %0, 1b                                  \n"
        "       subu    %0, 1                                   \n"
        "       .set    reorder                                 \n"
        : "=r" (loops)
        : "0" (loops));
}

void c_main(int argc, char *argv[]) {
	int i;
	int pin,on_off;
	int c;

	msg_init((void *)argv);
	c = argv[1][0];
	pin = 79; /* PC15/PWM5 -- LCD backlight (NS3K) */
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

	if (on_off < 0) {
		set_pin(pin, on_off);
		return;	
	}
	for (i=0; i<100; i++) {
		set_pin(pin, on_off);
		__delay(CPUCLOCK/4);
		msg_proc();
		on_off = !on_off;
	}
}
