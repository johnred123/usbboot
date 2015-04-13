/*
 *  linux/include/asm-mips/mach-jz4740/regs.h
 *
 *  Ingenic's JZ47xx common include.
 *
 *  Copyright (C) 2006 - 2007 Ingenic Semiconductor Inc.
 *
 *  Author: <yliu@ingenic.cn>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __JZ_BASE_H__
#define __JZ_BASE_H__

#if defined(__ASSEMBLY__) || defined(__LANGUAGE_ASSEMBLY)
#define REG8(addr)	(addr)
#define REG16(addr)	(addr)
#define REG32(addr)	(addr)
#else
#define REG8(addr)	*((volatile unsigned char *)(addr))
#define REG16(addr)	*((volatile unsigned short *)(addr))
#define REG32(addr)	*((volatile unsigned int *)(addr))
#endif

/*
 * Define the module base addresses
 */
#define	CPM_BASE	0xB0000000
#define	INTC_BASE	0xB0001000
#define	TCU_BASE	0xB0002000
#define	WDT_BASE	0xB0002000
#define	RTC_BASE	0xB0003000
#define	GPIO_BASE	0xB0010000
#define	AIC_BASE	0xB0020000
#define	ICDC_BASE	0xB0020000
#define	MSC_BASE	0xB0021000
#define	UART0_BASE	0xB0030000
#define	UART1_BASE	0xB0031000
#define	UART2_BASE	0xB0032000
#define	UART3_BASE	0xB0033000
#define	I2C_BASE	0xB0042000
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4740__)
#define	SSI_BASE	0xB0043000
#endif
#define	SADC_BASE	0xB0070000
#define	EMC_BASE	0xB3010000
#define	DMAC_BASE	0xB3020000
#if defined(__JZ4750__) || defined(__JZ4740__)
#define	UHC_BASE	0xB3030000
#endif
#define	UDC_BASE	0xB3040000
#define	LCD_BASE	0xB3050000
#define	SLCD_BASE	0xB3050000
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4740__)
#define	CIM_BASE	0xB3060000
#endif
#define IPU_BASE	0xB3080000
#if defined(__JZ4750__) || defined(__JZ4740__)
#define	ETH_BASE	0xB3100000
#endif

#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define BCH_BASE	0xB30D0000
#define OTP_BASE	0xB3012000
#endif
#if defined(__JZ4750__) || defined(__JZ4755__) 
#define PCM_BASE        0xB0071000
#define	TVE_BASE	0xB3050100
#define ME_BASE		0xB3090000
#define MC_BASE		0xB30A0000
#define DBLK_BASE	0xB30B0000
#define MIDCT_BASE	0xB30C0000
#define	TCSM_BASE	0xF4000000
#define OWI_BASE	0XB0072000
#define TSSI_BASE	0xB0073000
#endif

/*************************************************************************
 * GPIO (General-Purpose I/O Ports)
 *************************************************************************/
#if defined(__JZ4740__) || defined(__JZ4725__) || defined(__JZ4725B__)
#define MAX_GPIO_NUM	128
#elif defined(__J4750__) || defined(__J4755__)
#define MAX_GPIO_NUM	192
#endif

//n = 0,1,2,3,4,5 (PORTA, PORTB, PORTC, PORTD, PORTE, PORTF)
#define GPIO_PXPIN(n)	(GPIO_BASE + (0x00 + (n)*0x100)) /* PIN Level Register */
#define GPIO_PXDAT(n)	(GPIO_BASE + (0x10 + (n)*0x100)) /* Port Data Register */
#define GPIO_PXDATS(n)	(GPIO_BASE + (0x14 + (n)*0x100)) /* Port Data Set Register */
#define GPIO_PXDATC(n)	(GPIO_BASE + (0x18 + (n)*0x100)) /* Port Data Clear Register */
#define GPIO_PXIM(n)	(GPIO_BASE + (0x20 + (n)*0x100)) /* Interrupt Mask Register */
#define GPIO_PXIMS(n)	(GPIO_BASE + (0x24 + (n)*0x100)) /* Interrupt Mask Set Reg */
#define GPIO_PXIMC(n)	(GPIO_BASE + (0x28 + (n)*0x100)) /* Interrupt Mask Clear Reg */
#define GPIO_PXPE(n)	(GPIO_BASE + (0x30 + (n)*0x100)) /* Pull Enable Register */
#define GPIO_PXPES(n)	(GPIO_BASE + (0x34 + (n)*0x100)) /* Pull Enable Set Reg. */
#define GPIO_PXPEC(n)	(GPIO_BASE + (0x38 + (n)*0x100)) /* Pull Enable Clear Reg. */
#define GPIO_PXFUN(n)	(GPIO_BASE + (0x40 + (n)*0x100)) /* Function Register */
#define GPIO_PXFUNS(n)	(GPIO_BASE + (0x44 + (n)*0x100)) /* Function Set Register */
#define GPIO_PXFUNC(n)	(GPIO_BASE + (0x48 + (n)*0x100)) /* Function Clear Register */
#define GPIO_PXSEL(n)	(GPIO_BASE + (0x50 + (n)*0x100)) /* Select Register */
#define GPIO_PXSELS(n)	(GPIO_BASE + (0x54 + (n)*0x100)) /* Select Set Register */
#define GPIO_PXSELC(n)	(GPIO_BASE + (0x58 + (n)*0x100)) /* Select Clear Register */
#define GPIO_PXDIR(n)	(GPIO_BASE + (0x60 + (n)*0x100)) /* Direction Register */
#define GPIO_PXDIRS(n)	(GPIO_BASE + (0x64 + (n)*0x100)) /* Direction Set Register */
#define GPIO_PXDIRC(n)	(GPIO_BASE + (0x68 + (n)*0x100)) /* Direction Clear Register */
#define GPIO_PXTRG(n)	(GPIO_BASE + (0x70 + (n)*0x100)) /* Trigger Register */
#define GPIO_PXTRGS(n)	(GPIO_BASE + (0x74 + (n)*0x100)) /* Trigger Set Register */
#define GPIO_PXTRGC(n)	(GPIO_BASE + (0x78 + (n)*0x100)) /* Trigger Set Register */
#define GPIO_PXFLG(n)	(GPIO_BASE + (0x80 + (n)*0x100)) /* Port Flag Register */
#define GPIO_PXFLGC(n)	(GPIO_BASE + (0x14 + (n)*0x100)) /* Port Flag Clear Register */

#define REG_GPIO_PXPIN(n)	REG32(GPIO_PXPIN((n)))  /* PIN level */
#define REG_GPIO_PXDAT(n)	REG32(GPIO_PXDAT((n)))  /* 1: interrupt pending */
#define REG_GPIO_PXDATS(n)	REG32(GPIO_PXDATS((n)))
#define REG_GPIO_PXDATC(n)	REG32(GPIO_PXDATC((n)))
#define REG_GPIO_PXIM(n)	REG32(GPIO_PXIM((n)))   /* 1: mask pin interrupt */
#define REG_GPIO_PXIMS(n)	REG32(GPIO_PXIMS((n)))
#define REG_GPIO_PXIMC(n)	REG32(GPIO_PXIMC((n)))
#define REG_GPIO_PXPE(n)	REG32(GPIO_PXPE((n)))   /* 1: disable pull up/down */
#define REG_GPIO_PXPES(n)	REG32(GPIO_PXPES((n)))
#define REG_GPIO_PXPEC(n)	REG32(GPIO_PXPEC((n)))
#define REG_GPIO_PXFUN(n)	REG32(GPIO_PXFUN((n)))  /* 0:GPIO or intr, 1:FUNC */
#define REG_GPIO_PXFUNS(n)	REG32(GPIO_PXFUNS((n)))
#define REG_GPIO_PXFUNC(n)	REG32(GPIO_PXFUNC((n)))
#define REG_GPIO_PXSEL(n)	REG32(GPIO_PXSEL((n))) /* 0:GPIO/Fun0,1:intr/fun1*/
#define REG_GPIO_PXSELS(n)	REG32(GPIO_PXSELS((n)))
#define REG_GPIO_PXSELC(n)	REG32(GPIO_PXSELC((n)))
#define REG_GPIO_PXDIR(n)	REG32(GPIO_PXDIR((n))) /* 0:input/low-level-trig/falling-edge-trig, 1:output/high-level-trig/rising-edge-trig */
#define REG_GPIO_PXDIRS(n)	REG32(GPIO_PXDIRS((n)))
#define REG_GPIO_PXDIRC(n)	REG32(GPIO_PXDIRC((n)))
#define REG_GPIO_PXTRG(n)	REG32(GPIO_PXTRG((n))) /* 0:level-trigger, 1:edge-trigger */
#define REG_GPIO_PXTRGS(n)	REG32(GPIO_PXTRGS((n)))
#define REG_GPIO_PXTRGC(n)	REG32(GPIO_PXTRGC((n)))
#define REG_GPIO_PXFLG(n)	REG32(GPIO_PXFLG((n))) /* interrupt flag */
#define REG_GPIO_PXFLGC(n)	REG32(GPIO_PXFLGC((n))) /* interrupt flag */

/* GPIO basic ops */

#define __gpio_get_port(p)	(REG_GPIO_PXPIN(p))

#define __gpio_port_as_output(p, o)		\
do {						\
    REG_GPIO_PXFUNC(p) = (1 << (o));		\
    REG_GPIO_PXSELC(p) = (1 << (o));		\
    REG_GPIO_PXDIRS(p) = (1 << (o));		\
} while (0)

#define __gpio_port_as_input(p, o)		\
do {						\
    REG_GPIO_PXFUNC(p) = (1 << (o));		\
    REG_GPIO_PXSELC(p) = (1 << (o));		\
    REG_GPIO_PXDIRC(p) = (1 << (o));		\
} while (0)

#define __gpio_as_output(n)			\
do {						\
	unsigned int p, o;			\
	p = (n) / 32;				\
	o = (n) % 32;				\
	__gpio_port_as_output(p, o);		\
} while (0)

#define __gpio_as_input(n)			\
do {						\
	unsigned int p, o;			\
	p = (n) / 32;				\
	o = (n) % 32;				\
	__gpio_port_as_input(p, o);		\
} while (0)

#define __gpio_set_pin(n)			\
do {						\
	unsigned int p, o;			\
	p = (n) / 32;				\
	o = (n) % 32;				\
	REG_GPIO_PXDATS(p) = (1 << o);		\
} while (0)

#define __gpio_clear_pin(n)			\
do {						\
	unsigned int p, o;			\
	p = (n) / 32;				\
	o = (n) % 32;				\
	REG_GPIO_PXDATC(p) = (1 << o);		\
} while (0)

#define __gpio_get_pin(n)			\
({						\
	unsigned int p, o, v;			\
	p = (n) / 32;				\
	o = (n) % 32;				\
	if (__gpio_get_port(p) & (1 << o))	\
		v = 1;				\
	else					\
		v = 0;				\
	v;					\
})

#define __gpio_as_irq_high_level(n)		\
do {						\
	unsigned int p, o;			\
	p = (n) / 32;				\
	o = (n) % 32;				\
	REG_GPIO_PXIMS(p) = (1 << o);		\
	REG_GPIO_PXTRGC(p) = (1 << o);		\
	REG_GPIO_PXFUNC(p) = (1 << o);		\
	REG_GPIO_PXSELS(p) = (1 << o);		\
	REG_GPIO_PXDIRS(p) = (1 << o);		\
	REG_GPIO_PXFLGC(p) = (1 << o);		\
	REG_GPIO_PXIMC(p) = (1 << o);		\
} while (0)

#define __gpio_as_irq_low_level(n)		\
do {						\
	unsigned int p, o;			\
	p = (n) / 32;				\
	o = (n) % 32;				\
	REG_GPIO_PXIMS(p) = (1 << o);		\
	REG_GPIO_PXTRGC(p) = (1 << o);		\
	REG_GPIO_PXFUNC(p) = (1 << o);		\
	REG_GPIO_PXSELS(p) = (1 << o);		\
	REG_GPIO_PXDIRC(p) = (1 << o);		\
	REG_GPIO_PXFLGC(p) = (1 << o);		\
	REG_GPIO_PXIMC(p) = (1 << o);		\
} while (0)

#define __gpio_as_irq_rise_edge(n)		\
do {						\
	unsigned int p, o;			\
	p = (n) / 32;				\
	o = (n) % 32;				\
	REG_GPIO_PXIMS(p) = (1 << o);		\
	REG_GPIO_PXTRGS(p) = (1 << o);		\
	REG_GPIO_PXFUNC(p) = (1 << o);		\
	REG_GPIO_PXSELS(p) = (1 << o);		\
	REG_GPIO_PXDIRS(p) = (1 << o);		\
	REG_GPIO_PXFLGC(p) = (1 << o);		\
	REG_GPIO_PXIMC(p) = (1 << o);		\
} while (0)

#define __gpio_as_irq_fall_edge(n)		\
do {						\
	unsigned int p, o;			\
	p = (n) / 32;				\
	o = (n) % 32;				\
	REG_GPIO_PXIMS(p) = (1 << o);		\
	REG_GPIO_PXTRGS(p) = (1 << o);		\
	REG_GPIO_PXFUNC(p) = (1 << o);		\
	REG_GPIO_PXSELS(p) = (1 << o);		\
	REG_GPIO_PXDIRC(p) = (1 << o);		\
	REG_GPIO_PXFLGC(p) = (1 << o);		\
	REG_GPIO_PXIMC(p) = (1 << o);		\
} while (0)

#define __gpio_mask_irq(n)			\
do {						\
	unsigned int p, o;			\
	p = (n) / 32;				\
	o = (n) % 32;				\
	REG_GPIO_PXIMS(p) = (1 << o);		\
} while (0)

#define __gpio_unmask_irq(n)			\
do {						\
	unsigned int p, o;			\
	p = (n) / 32;				\
	o = (n) % 32;				\
	REG_GPIO_PXIMC(p) = (1 << o);		\
} while (0)

#define __gpio_ack_irq(n)			\
do {						\
	unsigned int p, o;			\
	p = (n) / 32;				\
	o = (n) % 32;				\
	REG_GPIO_PXFLGC(p) = (1 << o);		\
} while (0)

#define __gpio_get_irq()			\
({						\
	unsigned int p, i, tmp, v = 0;		\
	for (p = 3; p >= 0; p--) {		\
		tmp = REG_GPIO_PXFLG(p);	\
		for (i = 0; i < 32; i++)	\
			if (tmp & (1 << i))	\
				v = (32*p + i);	\
	}					\
	v;					\
})

#define __gpio_group_irq(n)			\
({						\
	register int tmp, i;			\
	tmp = REG_GPIO_PXFLG((n));		\
	for (i=31;i>=0;i--)			\
		if (tmp & (1 << i))		\
			break;			\
	i;					\
})

#define __gpio_enable_pull(n)			\
do {						\
	unsigned int p, o;			\
	p = (n) / 32;				\
	o = (n) % 32;				\
	REG_GPIO_PXPEC(p) = (1 << o);		\
} while (0)

#define __gpio_disable_pull(n)			\
do {						\
	unsigned int p, o;			\
	p = (n) / 32;				\
	o = (n) % 32;				\
	REG_GPIO_PXPES(p) = (1 << o);		\
} while (0)

#define __gpio_as_func0(n)			\
do {						\
	unsigned int p, o;			\
	p = (n) / 32;				\
	o = (n) % 32;				\
	REG_GPIO_PXFUNS(p) = (1 << o);		\
	REG_GPIO_PXTRGC(p) = (1 << o);		\
	REG_GPIO_PXSELC(p) = (1 << o);		\
} while (0)

#define __gpio_as_func1(n)			\
do {						\
	unsigned int p, o;			\
	p = (n) / 32;				\
	o = (n) % 32;				\
	REG_GPIO_PXFUNS(p) = (1 << o);		\
	REG_GPIO_PXTRGC(p) = (1 << o);		\
	REG_GPIO_PXSELS(p) = (1 << o);		\
} while (0)

#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define __gpio_as_func2(n)			\
do {						\
	unsigned int p, o;			\
	p = (n) / 32;				\
	o = (n) % 32;				\
	REG_GPIO_PXFUNS(p) = (1 << o);		\
	REG_GPIO_PXTRGS(p) = (1 << o);		\
	REG_GPIO_PXSELC(p) = (1 << o);		\
} while (0)

#endif

#endif /* __JZ_BASE_H__ */
