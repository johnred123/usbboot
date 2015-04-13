#include <jz/jz_intc.h>

#define _VECTOR(irq)	__vector_ ## irq
#define _HIVECTOR(irq)	__hivect_ ## irq

#define SIGNAL(irq)	int _VECTOR(irq) ()
#define SIGNAL_HI(irq)	int _HIVECTOR(irq) ()

#define IRQ_NONE		0
#define IRQ_HANDLED		(1)

extern void interrupt_enable(void);
