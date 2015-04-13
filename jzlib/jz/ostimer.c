#include <jz/interrupt.h>
#include <jz/jz_intc.h>
#include <jz/jz_tcu.h>
#include <jz/jz_cpm.h>
#include <jz/jz_core.h>
#include <jz/ostimer.h>

static uint32_t current_cycle_high = 0;

union cycle_type {
	uint64_t cycle64;
	uint32_t cycle32[2];
};

uint32_t ostimer32()
{
	return REG_TCU_OSTCNT;
}

uint64_t ostimer64()
{
        unsigned int ostcount;
        unsigned long flags;
        unsigned int current_cycle;
        unsigned int f;
        union cycle_type old_cycle;
        flags = irq_disable();
        current_cycle = current_cycle_high;
        ostcount = REG_TCU_OSTCNT;
        f = (REG_TCU_TFR & TCU_TFCR_OSTFCL) ? 1: 0;
        if(f) ostcount = REG_TCU_OSTCNT;
        irq_restore(flags);

        old_cycle.cycle32[0] = ostcount;
        old_cycle.cycle32[1] = current_cycle + f;

        return (old_cycle.cycle64);
}

SIGNAL(IRQ_TCU0)
{
	__tcu_clear_ost_match_flag();	/* ACK timer */
	current_cycle_high++;
	__intc_ack_irq(IRQ_TCU0);
	return IRQ_HANDLED;
}

int ostimer_clk()
{
	int clk,d;
	const int div[] = {1, 4, 16, 64, 256, 1024, 1, 1};

	if (REG_TCU_OSTCSR & TCU_OSTCSR_PCK_EN) {
		clk = __cpm_get_pclk();
	} else {
		clk = JZ_EXTAL;
	}
	d = ( REG_TCU_OSTCSR & TCU_OSTCSR_PRESCALE_MASK) >> TCU_OSTCSR_PRESCALE_BIT;
	return clk/div[d];
}

void __ostimer_start(uint32_t ostcsr)
{

	current_cycle_high = 0;
	REG_TCU_OSTCSR = ostcsr;
	REG_TCU_OSTCNT = 0;
	REG_TCU_OSTDR = 0xffffffff;	/* Data Reg : free running */

	__tcu_unmask_ost_match_irq();	/* unmask match irq */
	__tcu_enable_ost();		/* enable timer clock */
	__tcu_start_ost_clock();	/* start counting up */

	__intc_unmask_irq(IRQ_TCU0);
}

void ostimer_start(int is_fast)
{
	uint32_t ostcsr;
	if (!is_fast) {
		/* ext clock (12MHz) / 4 = 3MHz : overflow 23.8 min */
		ostcsr = TCU_OSTCSR_PRESCALE4 | TCU_OSTCSR_EXT_EN;
	} else {
		/* pclk (cpuclock / 1,2,3,4,6,8) 
		 * overflow 21.5 sec @ 200MHz 
		 * overflow 37.6 sec @ 114MHz */
		ostcsr = TCU_OSTCSR_PRESCALE1 | TCU_OSTCSR_PCK_EN;
	}
	__ostimer_start(ostcsr);
}


void ostimer_stop()
{
	__intc_mask_irq(IRQ_TCU0);
	__tcu_unmask_ost_match_irq();	/* mask match irq */
	__tcu_stop_ost_clock();		/* stop counting up */
	__tcu_clear_ost_match_flag();
	__tcu_disable_ost();		/* disable timer clock */
	REG_TCU_OSTCSR = 0;
}
