#include <jz/interrupt.h>
#include <jz/jz_intc.h>
#include <jz/jz_tcu.h>
#include <jz/jz_cpm.h>
#include <jz/jz_core.h>
#include <jz/timer.h>

#define JZ_TIMER_CH  2
#define JZ_TIMER_IRQ	IRQ_TCU2

/* memo:
   Jz475x
          IRQ_TCU0 OS Timer
          IRQ_TCU1 Chan 0,3,4,5 ( cannot work in sleep mode )
          IRQ_TCU2 Chan 1,2     ( can work in sleep mode )

   Jz474x
          IRQ_TCU0 Chan 0
          IRQ_TCU1 Chan 1
          IRQ_TCU2 Chan 2-7

end memo */

volatile uint32_t timer_ticks;

SIGNAL(JZ_TIMER_IRQ)
{
	__tcu_clear_full_match_flag(JZ_TIMER_CH);
	timer_ticks++;
	__intc_ack_irq(JZ_TIMER_IRQ);
	return IRQ_HANDLED;
}

int timer_hz()
{
	int clk,d;
	const int div[] = {1, 4, 16, 64, 256, 1024, 1, 1};

	if (REG_TCU_TCSR(JZ_TIMER_CH) & TCU_OSTCSR_PCK_EN) {
		clk = __cpm_get_pclk();
	} else {
		clk = JZ_EXTAL;
	}
	d = ( REG_TCU_TCSR(JZ_TIMER_CH) & TCU_TCSR_PRESCALE_MASK) >> TCU_TCSR_PRESCALE_BIT;
	return clk/div[d] * (__tcu_get_full_data(JZ_TIMER_CH) + 1);
}

void __timer_start(uint32_t tcsr, int interval)
{
	REG_TCU_TCSR(JZ_TIMER_CH) = tcsr;
	REG_TCU_TCNT(JZ_TIMER_CH) = 0;

	__tcu_mask_half_match_irq(JZ_TIMER_CH);
	__tcu_mask_full_match_irq(JZ_TIMER_CH);
	__tcu_set_full_data(JZ_TIMER_CH,interval);

	__tcu_clear_full_match_flag(JZ_TIMER_CH);
	__tcu_unmask_full_match_irq(JZ_TIMER_CH);
        __tcu_start_counter(JZ_TIMER_CH);
	__intc_unmask_irq(JZ_TIMER_IRQ);
}

void timer_start(int hz)
{
	uint32_t tcsr;
	int interval;
	/* ext clock (12MHz) / 4 = 3MHz : max interval 45.8 Hz */
	tcsr = TCU_TCSR_PRESCALE4 | TCU_TCSR_EXT_EN;
	
	if (hz < TIMER_HZ_MIN) hz = TIMER_HZ_MIN;
	if (hz > TIMER_HZ_MAX) hz = TIMER_HZ_MAX;
	interval = 3000000 / hz - 1;
	__timer_start(tcsr, interval);
}

void timer_stop()
{
	__intc_mask_irq(JZ_TIMER_IRQ);
	__tcu_mask_full_match_irq(JZ_TIMER_CH);
	__tcu_stop_counter(JZ_TIMER_CH);
	__tcu_clear_full_match_flag(JZ_TIMER_CH);

	REG_TCU_TCSR(JZ_TIMER_CH) = 0;
}
