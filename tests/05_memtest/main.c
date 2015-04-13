#include "gpio.h"

#define EMC_BASE        0xB3010000
#define EMC_DMCR        (EMC_BASE + 0x80)  /* DRAM Control Register */
#define REG_EMC_DMCR    REG32(EMC_DMCR)

void msg_init();
void msg_proc();
void msg_putc(const char);
void msg_puts(const char *);

void c_main(int argc, char *argv[]) {
	int i,ii,j,k;
	unsigned int from,to,sum,prev,sum_prev;
	unsigned int from0,to0;
	unsigned int *p;

	msg_init((void *)argv);
	msg_puts("XXXXXXX memory test XXXXXXX\n");

	msg_puts("argc = ");
	msg_put_hex(argc);
	msg_puts("\nargv :");
	msg_put_hex(argv);
	msg_puts("\nproc_func addr :");
	msg_put_hex(get_proc_func());
	msg_puts("\n");

	from0 = 0x80600000 + (6 * 1024 * 1024); // check target.ld
	to0 = (unsigned int)argv & ~(4 * 1024 * 1024 -1);

	msg_puts("  test area : 0x80010000 - 0x80600000/");
	msg_put_hex(from0);
	msg_puts(" -  ");
	msg_put_hex(to0);
	msg_puts("\n");
	msg_puts("  EMC_DMCR  : ");
	msg_put_hex(REG_EMC_DMCR);
	msg_puts("\n");

	sum = 0;
	for (i=0; i<1000; i++) {
	   for (ii=0; ii<2; ii++) {
		sum_prev = sum;
		sum = 0;
		if (ii == 0) {
			from = 0x80010000;
			to = 0x80600000;
		} else {
			from = from0;
			to = to0;
		}
		p = (unsigned int *)(void *)from;
		j=0;
		while ((unsigned int)p < to) {
			prev = *p;
			*p = i + (unsigned int)p;
			sum += *p;
			if ((i != 0) && (prev != i + (unsigned int)p-1)) {
				msg_puts("memtest ERROR -- loop = 0x");
				msg_put_hex(i);
				msg_puts("\n");
				return;	
			}
			p++;
			j++;
			if ((j & 0xfffff) == 0) {
				for (k=0; k<10; k++) {
					msg_proc();
				}
			}
		}
	    }
	    if ((i & 0xf) == 0) {
			msg_puts("  loop 0x");
			msg_put_hex(i);
			msg_puts(" done \n");
	    }
	}
	msg_puts("memtest OK -- loop = 0x");
	msg_put_hex(i);
	msg_puts("\n");
	return;	
}
