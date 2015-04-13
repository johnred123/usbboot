#ifndef __JZ_INTC_H__
#define __JZ_INTC_H__
#ifndef __JZ_BASE_H__
#include <jz/jz_base.h>
#endif
/*************************************************************************
 * INTC (Interrupt Controller)
 *************************************************************************/
#define INTC_ISR	(INTC_BASE + 0x00)
#define INTC_IMR	(INTC_BASE + 0x04)
#define INTC_IMSR	(INTC_BASE + 0x08)
#define INTC_IMCR	(INTC_BASE + 0x0c)
#define INTC_IPR	(INTC_BASE + 0x10)

#define REG_INTC_ISR	REG32(INTC_ISR)
#define REG_INTC_IMR	REG32(INTC_IMR)
#define REG_INTC_IMSR	REG32(INTC_IMSR)
#define REG_INTC_IMCR	REG32(INTC_IMCR)
#define REG_INTC_IPR	REG32(INTC_IPR)

#if defined(__JZ4750__)
// 1st-level interrupts
#define IRQ_OWI		0
#define IRQ_I2C		1
#define IRQ_TSSI	2
#define IRQ_UART3	3
#define IRQ_UART2	4
#define IRQ_UART1	5
#define IRQ_UART0	6
#define IRQ_PCM		7
#define IRQ_AIC		8
#define IRQ_RTC		9
#define IRQ_ETH		9
#define IRQ_SADC	10
#define IRQ_SSI1	11
#define IRQ_SSI0	12
#define IRQ_MSC1	13
#define IRQ_MSC0	14
#define IRQ_DMAC1	15
#define IRQ_BCH		16
#define IRQ_UHC		17
#define IRQ_CIM		18
#define IRQ_UDC		19
#define IRQ_DMAC0	20
#define IRQ_TCU2	21
#define IRQ_TCU1	22
#define IRQ_TCU0	23
#define IRQ_GPIO5	24
#define IRQ_GPIO4	25
#define IRQ_GPIO3	26
#define IRQ_GPIO2	27
#define IRQ_GPIO1	28
#define IRQ_GPIO0	29
#define IRQ_IPU		30
#define IRQ_LCD		31

// 2nd-level interrupts
#define IRQ_DMA_0	32  /* 32 to 43 for DMAC0's 0-5  and DMAC1's 0-5 */
#define IRQ_GPIO_0	48  /* 48 to 240 for GPIO pin 0 to 192 */

#define NUM_DMA         MAX_DMA_NUM	/* 12 */
#define NUM_GPIO        MAX_GPIO_NUM	/* GPIO NUM: 192, Jz4750 real num GPIO 178 */
#endif
#if defined(__JZ4755__) || defined(__JZ4725B__)
// 1st-level interrupts
#define IRQ_ETH		0
#define IRQ_SFT		4
#define IRQ_I2C		5
#define IRQ_RTC		6
#define IRQ_UART2	7
#define IRQ_UART1	8
#define IRQ_UART0	9
#define IRQ_AIC 	10
#define IRQ_GPIO5	11
#define IRQ_GPIO4	12
#define IRQ_GPIO3	13
#define IRQ_GPIO2	14
#define IRQ_GPIO1	15
#define IRQ_GPIO0	16
#define IRQ_BCH		17
#define IRQ_SADC	18
#define IRQ_CIM		19
#define IRQ_TSSI	20
#define IRQ_TCU2	21
#define IRQ_TCU1	22
#define IRQ_TCU0	23
#define IRQ_MSC1	24
#define IRQ_MSC0	25
#define IRQ_SSI   	26
#define IRQ_UDC		27
#define IRQ_DMAC1	28
#define IRQ_DMAC0	29
#define IRQ_IPU		30
#define IRQ_LCD		31

// 2nd-level interrupts
#define IRQ_DMA_0	32  /* 32 to 43 for DMAC0's 0-5  and DMAC1's 0-5 */
#define IRQ_GPIO_0	48  /* 48 to 240 for GPIO pin 0 to 192 */

#define NUM_DMA         MAX_DMA_NUM	/* 12 */
#define NUM_GPIO        MAX_GPIO_NUM	/* GPIO NUM: 192, Jz4750L real num GPIO 178 */
#endif

#if defined(__JZ4740__) || defined(__JZ4725__)
// 1st-level interrupts
#define IRQ_I2C		1
#define IRQ_UHC		3
#define IRQ_UART1	8
#define IRQ_UART0	9
#define IRQ_SADC	12
#define IRQ_MSC		14
#define IRQ_RTC		15
#define IRQ_SSI		16
#define IRQ_CIM		17
#define IRQ_AIC		18
#define IRQ_ETH		19
#define IRQ_DMAC	20
#define IRQ_TCU2	21
#define IRQ_TCU1	22
#define IRQ_TCU0	23
#define IRQ_UDC 	24
#define IRQ_GPIO3	25
#define IRQ_GPIO2	26
#define IRQ_GPIO1	27
#define IRQ_GPIO0	28
#define IRQ_IPU		29
#define IRQ_LCD		30

// 2nd-level interrupts
#define IRQ_DMA_0	32  /* 32 to 37 for DMAC channel 0 to 5 */
#define IRQ_GPIO_0	48  /* 48 to 175 for GPIO pin 0 to 127 */

#define NUM_DMA         6
#define NUM_GPIO        128
#endif

/*
 * OPs
 */
/***************************************************************************
 * INTC
 ***************************************************************************/
#define __intc_unmask_irq(n)	( REG_INTC_IMCR = (1 << (n)) )
#define __intc_mask_irq(n)	( REG_INTC_IMSR = (1 << (n)) )
#define __intc_ack_irq(n)	( REG_INTC_IPR = (1 << (n)) ) /* A dummy ack, as the Pending Register is Read Only. Should we remove __intc_ack_irq() */


#endif /* __JZ_INTC_H__ */
