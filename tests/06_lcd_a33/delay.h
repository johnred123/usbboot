#ifndef __DELAY_H__
#define __DELAY_H__

#define CPUCLOCK	228000000

static inline void __delay(unsigned int loops)
{
        __asm__ __volatile__ (
        "       .set    noreorder    \n"
        "       .align  3            \n"
        "1:     bnez    %0, 1b       \n"
        "       subu    %0, 1        \n"
        "       .set    reorder      \n"
        : "=r" (loops)
        : "0" (loops));
}

static inline void mdelay(unsigned int ms)
{
	int i;
	for (i=0; i<ms; i++) {
		__delay(CPUCLOCK / 2000);
	}
}

#endif /* __DELAY_H__ */
