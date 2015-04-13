#include <jz/jz_core.h>
#include <jz/interrupt.h>
#include <stdint.h>
#include <string.h>

#define	INT_VECT_GEN	(void *)0x80000180L
#define	INT_VECT_SPL	(void *)0x80000200L
#define	INT_VECT_SIZE	0x0100

extern void exvec3();
extern void exvec3_end();
extern int (* __vectors[32])(void);

void interrupt_enable()
{
	uint32_t c0_status;
	memcpy(INT_VECT_GEN, exvec3, (exvec3_end - exvec3));
	memcpy(INT_VECT_SPL, exvec3, (exvec3_end - exvec3));
	_cacheflush(INT_VECT_GEN, INT_VECT_SIZE, DCACHE|ICACHE);

	c0_status = read_c0_status();
	c0_status &= ~0xff1f;
	c0_status |= 0x01; /* IE = 1 */
	c0_status |= 0x0400; /* set IP2 */
	write_c0_status(c0_status);

	/* unmask all first */
	REG_INTC_IMCR = 0xffffffff;
}

uint32_t intent(uint32_t c0_status, uint32_t c0_cause, uint32_t c0_epc)
{
	uint32_t isr;
	int v,r;

	c0_status &= ~0x1e;
	write_c0_status(c0_status & ~0x1); /* irq_disable */
	do {
		isr = REG_INTC_ISR;
		v = ffs(isr);
		if (v) {
			v--;
			__intc_mask_irq(v);
			r = (__vectors[v])();
			if (r) {
				__intc_unmask_irq(v);
			}
		}
	} while (isr);

	write_c0_cause(0);
	return c0_status;
}
