#include <jz/jz_core.h>
#include <jz/jz_cpm.h>

void delay_us(unsigned int us)
{
	static int loop_us = 0;
	int i;

	if (loop_us == 0) {
		loop_us = __cpm_get_cclk() >> 1;
	}
	for (i=0; i<us; i++) {
		__delay_loop_1(loop_us);
	}
}
