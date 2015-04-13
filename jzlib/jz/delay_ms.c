#include <jz/jz_core.h>
#include <jz/jz_cpm.h>

void delay_ms(unsigned int ms)
{
	int loop_ms = 0;
	int i;

	loop_ms = __cpm_get_cclk() / 2000;
	for (i=0; i<ms; i++) {
		__delay_loop_1(loop_ms);
	}
}
