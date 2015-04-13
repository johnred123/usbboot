#include "gpio.h"

void msg_init();
void msg_proc();
void msg_putc(const char);
void msg_puts(const char *);

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
	return;	
}
