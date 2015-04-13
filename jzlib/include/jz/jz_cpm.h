#ifndef __JZ_CPM_H__
#define __JZ_CPM_H__
#ifndef __JZ_BASE_H__
#include <jz/jz_base.h>
#endif
/*************************************************************************
 * CPM (Clock reset and Power control Management)
 *************************************************************************/
#define CPM_CPCCR	(CPM_BASE+0x00)
#define CPM_CPPCR	(CPM_BASE+0x10)
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define CPM_CPPSR	(CPM_BASE+0x14) /* PLL Switch and Status Register */
#endif
#define CPM_I2SCDR	(CPM_BASE+0x60)
#define CPM_LPCDR	(CPM_BASE+0x64)
#if defined(__JZ4750__)
#define CPM_MSCCDR(n)	(CPM_BASE+0x10*(n)+0x68) /* MSC0(n=0) or MSC1(n=1) devic
e clock divider Register */
#elif defined(__JZ4755__) || defined(__JZ4725B__)
#define CPM_MSCCDR(n)	(CPM_BASE+0x68) /* MSC0(n=0) or MSC1(n=1) device clock divider Register */
#endif
#define CPM_UHCCDR	(CPM_BASE+0x6C)
#define CPM_SSICDR	(CPM_BASE+0x74)
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define CPM_PCMCDR	(CPM_BASE+0x7C) /* PCM device clock divider Register */
#endif

#define CPM_LCR		(CPM_BASE+0x04)
#define CPM_CLKGR	(CPM_BASE+0x20)
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define CPM_OPCR	(CPM_BASE+0x24) /* Oscillator and Power Control Register */
#endif
#if defined(__JZ4740__) || defined(__JZ4725__)
#define CPM_SCR		(CPM_BASE+0x24)

#define CPM_HCR		(CPM_BASE+0x30)
#define CPM_HWFCR	(CPM_BASE+0x34)
#define CPM_HRCR	(CPM_BASE+0x38)
#define CPM_HWCR	(CPM_BASE+0x3c)
#define CPM_HWSR	(CPM_BASE+0x40)
#define CPM_HSPR	(CPM_BASE+0x44)
#endif

#define CPM_RSR		(CPM_BASE+0x08)

#define REG_CPM_CPCCR   	REG32(CPM_CPCCR)
#define REG_CPM_CPPCR    	REG32(CPM_CPPCR)
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define REG_CPM_CPPSR	        REG32(CPM_CPPSR)
#endif
#define REG_CPM_I2SCDR  	REG32(CPM_I2SCDR)
#define REG_CPM_LPCDR   	REG32(CPM_LPCDR)
#define REG_CPM_MSCCDR(n)	REG32(CPM_MSCCDR(n))
#if defined(__JZ4740__) || defined(__JZ4750__)
#define REG_CPM_UHCCDR   	REG32(CPM_UHCCDR)
#endif
#define REG_CPM_SSICDR  	REG32(CPM_SSICDR)
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define REG_CPM_PCMCDR          REG32(CPM_PCMCDR)
#endif

#define REG_CPM_LCR	REG32(CPM_LCR)
#define REG_CPM_CLKGR	REG32(CPM_CLKGR)
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define REG_CPM_OPCR	REG32(CPM_OPCR)
#endif
#if defined(__JZ4740__) || defined(__JZ4725__)
#define REG_CPM_SCR	REG32(CPM_SCR)
#define REG_CPM_HCR	REG32(CPM_HCR)
#define REG_CPM_HWFCR	REG32(CPM_HWFCR)
#define REG_CPM_HRCR	REG32(CPM_HRCR)
#define REG_CPM_HWCR	REG32(CPM_HWCR)
#define REG_CPM_HWSR	REG32(CPM_HWSR)
#define REG_CPM_HSPR	REG32(CPM_HSPR)
#endif
#define REG_CPM_RSR	REG32(CPM_RSR)

/* Clock Control Register */
#define CPM_CPCCR_I2CS		(1 << 31)
#define CPM_CPCCR_ECS   	(1 << 30) /* Select the between EXCLK and EXCLK/2 output */
#if defined(__JZ4740__) || defined(__JZ4725__)
#define CPM_CPCCR_CLKOEN   	CPM_CPCCR_ECS
#endif
#define CPM_CPCCR_UCS		(1 << 29)
#define CPM_CPCCR_UDIV_BIT	23
#define CPM_CPCCR_UDIV_MASK	(0x3f << CPM_CPCCR_UDIV_BIT)
#define CPM_CPCCR_CE		(1 << 22)
#define CPM_CPCCR_PCS		(1 << 21)

#if defined(__JZ4740__) ||defined(__JZ4725__) || defined(__JZ4750__)
#define CPM_CPCCR_LDIV_BIT	16
#define CPM_CPCCR_LDIV_MASK	(0x1f << CPM_CPCCR_LDIV_BIT)
#elif defined(__JZ4755__) || defined(__JZ4725B__)
#define CPM_CPCCR_H1DIV_BIT	16
#define CPM_CPCCR_H1DIV_MASK	(0x1f << CPM_CPCCR_H1DIV_BIT)
#endif
#define CPM_CPCCR_MDIV_BIT	12
#define CPM_CPCCR_MDIV_MASK	(0x0f << CPM_CPCCR_MDIV_BIT)
#define CPM_CPCCR_PDIV_BIT	8
#define CPM_CPCCR_PDIV_MASK	(0x0f << CPM_CPCCR_PDIV_BIT)
#define CPM_CPCCR_HDIV_BIT	4
#define CPM_CPCCR_HDIV_MASK	(0x0f << CPM_CPCCR_HDIV_BIT)
#define CPM_CPCCR_CDIV_BIT	0
#define CPM_CPCCR_CDIV_MASK	(0x0f << CPM_CPCCR_CDIV_BIT)

#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
/* PLL Switch and Status Register */
#define CPM_CPPSR_PLLOFF        (1<<31)
#define CPM_CPPSR_PLLBP         (1<<30)
#define CPM_CPPSR_PLLON         (1<<29)
#define CPM_CPPSR_PS            (1<<28) /* Indicate whether the PLL parameters' change has finished */
#define CPM_CPPSR_FS            (1<<27) /* Indicate whether the main clock's change has finished */
#define CPM_CPPSR_CS            (1<<26) /* Indicate whether the clock switch has finished */
#define CPM_CPPSR_PM            (1<<1)  /* Clock switch mode */
#define CPM_CPPSR_FM            (1<<0)  /* Clock frequency change mode */
#endif

/* I2S Clock Divider Register */
#define CPM_I2SCDR_I2SDIV_BIT	0
#define CPM_I2SCDR_I2SDIV_MASK	(0x1ff << CPM_I2SCDR_I2SDIV_BIT)

/* LCD Pixel Clock Divider Register */
#if defined(__JZ4750__) || defined(CONFIG_FPGA)
#define CPM_LPCDR_LSCS	        (1<<31) /* TV encoder Source Pixel Clock Selection */
#define CPM_LPCDR_LPCS	        (1<<30) /* LCD Panel pix clock Selection */
#define CPM_LPCDR_LTCS	        (1<<29) /* LCD TV Encoder or Panel pix clock Selection */
#endif
#define CPM_LPCDR_PIXDIV_BIT	0
#define CPM_LPCDR_PIXDIV_MASK	(0x7ff << CPM_LPCDR_PIXDIV_BIT)

/* MSC Clock Divider Register */
#define CPM_MSCCDR_MSCDIV_BIT	0
#define CPM_MSCCDR_MSCDIV_MASK	(0x1f << CPM_MSCCDR_MSCDIV_BIT)

#if defined(__JZ4740__) || defined(__JZ4750__)
/* UHC Clock Divider Register */
#define CPM_UHCCDR_UHCDIV_BIT	0
#define CPM_UHCCDR_UHCDIV_MASK	(0xf << CPM_UHCCDR_UHCDIV_BIT)
#endif

/* SSI Clock Divider Register */
#if defined(__JZ4740__) || defined(__JZ4725__)
#define CPM_SSICDR_SCS		(1<<31) /* SSI clock source selection, 0:EXCLK, 1: PLL */
#endif
#define CPM_SSICDR_SSIDIV_BIT	0
#define CPM_SSICDR_SSIDIV_MASK	(0xf << CPM_SSICDR_SSIDIV_BIT)

#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
/* PCM device clock divider Register */
#define CPM_PCMCDR_PCMS         31 /* PCM source clock Selection */
#define CPM_PCMCDR_PCMCD_BIT    0
#define CPM_PCMCDR_PCMCD_MASK   (0x1ff << CPM_PCMCDR_PCMCD_BIT)
#endif

/* PLL Control Register */
#define CPM_CPPCR_PLLM_BIT	23
#define CPM_CPPCR_PLLM_MASK	(0x1ff << CPM_CPPCR_PLLM_BIT)
#define CPM_CPPCR_PLLN_BIT	18
#define CPM_CPPCR_PLLN_MASK	(0x1f << CPM_CPPCR_PLLN_BIT)
#define CPM_CPPCR_PLLOD_BIT	16
#define CPM_CPPCR_PLLOD_MASK	(0x03 << CPM_CPPCR_PLLOD_BIT)
#define CPM_CPPCR_PLLS		(1 << 10) /* obsolete, replaced by CPM_CPPSR_PLLON */
#define CPM_CPPCR_PLLBP		(1 << 9)
#define CPM_CPPCR_PLLEN		(1 << 8)
#define CPM_CPPCR_PLLST_BIT	0
#define CPM_CPPCR_PLLST_MASK	(0xff << CPM_CPPCR_PLLST_BIT)

/* Low Power Control Register */
#define CPM_LCR_DOZE_DUTY_BIT 	3
#define CPM_LCR_DOZE_DUTY_MASK 	(0x1f << CPM_LCR_DOZE_DUTY_BIT)
#define CPM_LCR_DOZE_ON		(1 << 2)
#define CPM_LCR_LPM_BIT		0
#define CPM_LCR_LPM_MASK	(0x3 << CPM_LCR_LPM_BIT)
  #define CPM_LCR_LPM_IDLE	(0x0 << CPM_LCR_LPM_BIT)
  #define CPM_LCR_LPM_SLEEP	(0x1 << CPM_LCR_LPM_BIT)

#if defined(__JZ4740__) || defined(__JZ4725__)
/* Clock Gate Register */
#define CPM_CLKGR_UART1		(1 << 15)
#define CPM_CLKGR_UHC		(1 << 14)
#define CPM_CLKGR_IPU		(1 << 13)
#define CPM_CLKGR_DMAC		(1 << 12)
#define CPM_CLKGR_UDC		(1 << 11)
#define CPM_CLKGR_LCD		(1 << 10)
#define CPM_CLKGR_CIM		(1 << 9)
#define CPM_CLKGR_SADC		(1 << 8)
#define CPM_CLKGR_MSC		(1 << 7)
#define CPM_CLKGR_AIC1		(1 << 6)
#define CPM_CLKGR_AIC2		(1 << 5)
#define CPM_CLKGR_SSI		(1 << 4)
#define CPM_CLKGR_I2C		(1 << 3)
#define CPM_CLKGR_RTC		(1 << 2)
#define CPM_CLKGR_TCU		(1 << 1)
#define CPM_CLKGR_UART0		(1 << 0)
#elif defined(__JZ4750__)
/* Clock Gate Register */
#define CPM_CLKGR_CIMRAM	(1 << 28)
#define CPM_CLKGR_IDCT  	(1 << 27)
#define CPM_CLKGR_DB    	(1 << 26)
#define CPM_CLKGR_ME    	(1 << 25)
#define CPM_CLKGR_MC    	(1 << 24)
#define CPM_CLKGR_TVE    	(1 << 23)
#define CPM_CLKGR_TSSI    	(1 << 22)
#define CPM_CLKGR_OWI    	(1 << 21)
#define CPM_CLKGR_PCM    	(1 << 20)
#define CPM_CLKGR_MSC1    	(1 << 19)
#define CPM_CLKGR_SSI0    	(1 << 18)
#define CPM_CLKGR_UART3    	(1 << 17)
#define CPM_CLKGR_UART2    	(1 << 16)
#define CPM_CLKGR_UART1		(1 << 15)
#define CPM_CLKGR_UHC		(1 << 14)
#define CPM_CLKGR_IPU		(1 << 13)
#define CPM_CLKGR_DMAC		(1 << 12)
#define CPM_CLKGR_UDC		(1 << 11)
#define CPM_CLKGR_LCD		(1 << 10)
#define CPM_CLKGR_CIM		(1 << 9)
#define CPM_CLKGR_SADC		(1 << 8)
#define CPM_CLKGR_MSC0		(1 << 7)
#define CPM_CLKGR_AIC1		(1 << 6)
#define CPM_CLKGR_AIC2		(1 << 5)
#define CPM_CLKGR_SSI1		(1 << 4)
#define CPM_CLKGR_I2C		(1 << 3)
#define CPM_CLKGR_RTC		(1 << 2)
#define CPM_CLKGR_TCU		(1 << 1)
#define CPM_CLKGR_UART0		(1 << 0)

#elif defined(__JZ4755__) || defined(__JZ4725B__)
/* Clock Gate Register */
#define CPM_CLKGR_AUX_CPU	(1 << 24)
#define CPM_CLKGR_AHB1  	(1 << 23)
#define CPM_CLKGR_IDCT  	(1 << 22)
#define CPM_CLKGR_DB    	(1 << 21)
#define CPM_CLKGR_ME    	(1 << 20)
#define CPM_CLKGR_MC    	(1 << 19)
#define CPM_CLKGR_TVE    	(1 << 18)
#define CPM_CLKGR_TSSI    	(1 << 17)
#define CPM_CLKGR_MSC1    	(1 << 16)
#define CPM_CLKGR_UART2    	(1 << 15)
#define CPM_CLKGR_UART1		(1 << 14)
#define CPM_CLKGR_IPU		(1 << 13)
#define CPM_CLKGR_DMAC		(1 << 12)
#define CPM_CLKGR_BCH		(1 << 11)
#define CPM_CLKGR_UDC		(1 << 10)
#define CPM_CLKGR_LCD		(1 << 9)
#define CPM_CLKGR_CIM		(1 << 8)
#define CPM_CLKGR_SADC		(1 << 7)
#define CPM_CLKGR_MSC0		(1 << 6)
#define CPM_CLKGR_AIC		(1 << 5)
#define CPM_CLKGR_SSI		(1 << 4)
#define CPM_CLKGR_I2C		(1 << 3)
#define CPM_CLKGR_RTC		(1 << 2)
#define CPM_CLKGR_TCU		(1 << 1)
#define CPM_CLKGR_UART0		(1 << 0)
#endif

#if defined(__JZ4740__) || defined(__JZ4725__)
/* Sleep Control Register */
#define CPM_SCR_O1ST_BIT	8
#define CPM_SCR_O1ST_MASK	(0xff << CPM_SCR_O1ST_BIT)
#define CPM_SCR_USBPHY_ENABLE	(1 << 6)
#define CPM_SCR_OSC_ENABLE	(1 << 4)

/* Hibernate Control Register */
#define CPM_HCR_PD		(1 << 0)

/* Wakeup Filter Counter Register in Hibernate Mode */
#define CPM_HWFCR_TIME_BIT	0
#define CPM_HWFCR_TIME_MASK	(0x3ff << CPM_HWFCR_TIME_BIT)

/* Reset Counter Register in Hibernate Mode */
#define CPM_HRCR_TIME_BIT	0
#define CPM_HRCR_TIME_MASK	(0x7f << CPM_HRCR_TIME_BIT)

/* Wakeup Control Register in Hibernate Mode */
#define CPM_HWCR_WLE_LOW	(0 << 2)
#define CPM_HWCR_WLE_HIGH	(1 << 2)
#define CPM_HWCR_PIN_WAKEUP	(1 << 1)
#define CPM_HWCR_RTC_WAKEUP	(1 << 0)

/* Wakeup Status Register in Hibernate Mode */
#define CPM_HWSR_WSR_PIN	(1 << 1)
#define CPM_HWSR_WSR_RTC	(1 << 0)

#endif

#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
/* Oscillator and Power Control Register */
#define CPM_OPCR_O1ST_BIT	8
#define CPM_OPCR_O1ST_MASK	(0xff << CPM_SCR_O1ST_BIT)
#define CPM_OPCR_UHCPHY_DISABLE	(1 << 7)
#define CPM_OPCR_UDCPHY_ENABLE	(1 << 6)
#define CPM_OPCR_OSC_ENABLE	(1 << 4)
#define CPM_OPCR_ERCS           (1 << 2) /* EXCLK/512 clock and RTCLK clock selection */
#define CPM_OPCR_MOSE           (1 << 1) /* Main Oscillator Enable */
#define CPM_OPCR_MCS            (1 << 0) /* Main clock source select register */
#endif

/* Reset Status Register */
#define CPM_RSR_HR		(1 << 2)
#define CPM_RSR_WR		(1 << 1)
#define CPM_RSR_PR		(1 << 0)


/*
 * OPs
 */
/***************************************************************************
 * CPM
 ***************************************************************************/
#define __cpm_get_pllm() \
	((REG_CPM_CPPCR & CPM_CPPCR_PLLM_MASK) >> CPM_CPPCR_PLLM_BIT)
#define __cpm_get_plln() \
	((REG_CPM_CPPCR & CPM_CPPCR_PLLN_MASK) >> CPM_CPPCR_PLLN_BIT)
#define __cpm_get_pllod() \
	((REG_CPM_CPPCR & CPM_CPPCR_PLLOD_MASK) >> CPM_CPPCR_PLLOD_BIT)

#define __cpm_get_cdiv() \
	((REG_CPM_CPCCR & CPM_CPCCR_CDIV_MASK) >> CPM_CPCCR_CDIV_BIT)
#define __cpm_get_hdiv() \
	((REG_CPM_CPCCR & CPM_CPCCR_HDIV_MASK) >> CPM_CPCCR_HDIV_BIT)
#define __cpm_get_pdiv() \
	((REG_CPM_CPCCR & CPM_CPCCR_PDIV_MASK) >> CPM_CPCCR_PDIV_BIT)
#define __cpm_get_mdiv() \
	((REG_CPM_CPCCR & CPM_CPCCR_MDIV_MASK) >> CPM_CPCCR_MDIV_BIT)
#if defined(__JZ4750__)
#define __cpm_get_ldiv() \
	((REG_CPM_CPCCR & CPM_CPCCR_LDIV_MASK) >> CPM_CPCCR_LDIV_BIT)
#elif defined(__JZ4755__) || defined(__JZ4725B__)
#define __cpm_get_h1div() \
	((REG_CPM_CPCCR & CPM_CPCCR_H1DIV_MASK) >> CPM_CPCCR_H1DIV_BIT)
#endif
#define __cpm_get_udiv() \
	((REG_CPM_CPCCR & CPM_CPCCR_UDIV_MASK) >> CPM_CPCCR_UDIV_BIT)
#define __cpm_get_i2sdiv() \
	((REG_CPM_I2SCDR & CPM_I2SCDR_I2SDIV_MASK) >> CPM_I2SCDR_I2SDIV_BIT)
#define __cpm_get_pixdiv() \
	((REG_CPM_LPCDR & CPM_LPCDR_PIXDIV_MASK) >> CPM_LPCDR_PIXDIV_BIT)
#define __cpm_get_mscdiv(n) \
	((REG_CPM_MSCCDR(n) & CPM_MSCCDR_MSCDIV_MASK) >> CPM_MSCCDR_MSCDIV_BIT)
#define __cpm_get_uhcdiv() \
	((REG_CPM_UHCCDR & CPM_UHCCDR_UHCDIV_MASK) >> CPM_UHCCDR_UHCDIV_BIT)
#define __cpm_get_ssidiv() \
	((REG_CPM_SSICCDR & CPM_SSICDR_SSICDIV_MASK) >> CPM_SSICDR_SSIDIV_BIT)
#if defined(__JZ4750__) || defined(__JZ4755__)
#define __cpm_get_pcmdiv(v) \
	((REG_CPM_PCMCDR & CPM_PCMCDR_PCMCD_MASK) >> CPM_PCMCDR_PCMCD_BIT)
#endif

#define __cpm_set_cdiv(v) \
	(REG_CPM_CPCCR = (REG_CPM_CPCCR & ~CPM_CPCCR_CDIV_MASK) | ((v) << (CPM_CPCCR_CDIV_BIT)))
#define __cpm_set_hdiv(v) \
	(REG_CPM_CPCCR = (REG_CPM_CPCCR & ~CPM_CPCCR_HDIV_MASK) | ((v) << (CPM_CPCCR_HDIV_BIT)))
#define __cpm_set_pdiv(v) \
	(REG_CPM_CPCCR = (REG_CPM_CPCCR & ~CPM_CPCCR_PDIV_MASK) | ((v) << (CPM_CPCCR_PDIV_BIT)))
#define __cpm_set_mdiv(v) \
	(REG_CPM_CPCCR = (REG_CPM_CPCCR & ~CPM_CPCCR_MDIV_MASK) | ((v) << (CPM_CPCCR_MDIV_BIT)))
#if defined(__JZ4750__)
#define __cpm_set_ldiv(v) \
	(REG_CPM_CPCCR = (REG_CPM_CPCCR & ~CPM_CPCCR_LDIV_MASK) | ((v) << (CPM_CPCCR_LDIV_BIT)))
#elif defined(__JZ4755__) || defined(__JZ4725B__)
#define __cpm_set_h1div(v) \
	(REG_CPM_CPCCR = (REG_CPM_CPCCR & ~CPM_CPCCR_H1DIV_MASK) | ((v) << (CPM_CPCCR_H1DIV_BIT)))
#endif
#define __cpm_set_udiv(v) \
	(REG_CPM_CPCCR = (REG_CPM_CPCCR & ~CPM_CPCCR_UDIV_MASK) | ((v) << (CPM_CPCCR_UDIV_BIT)))
#define __cpm_set_i2sdiv(v) \
	(REG_CPM_I2SCDR = (REG_CPM_I2SCDR & ~CPM_I2SCDR_I2SDIV_MASK) | ((v) << (CPM_I2SCDR_I2SDIV_BIT)))
#define __cpm_set_pixdiv(v) \
	(REG_CPM_LPCDR = (REG_CPM_LPCDR & ~CPM_LPCDR_PIXDIV_MASK) | ((v) << (CPM_LPCDR_PIXDIV_BIT)))
#define __cpm_set_mscdiv(n, v) \
	(REG_CPM_MSCCDR(n) = (REG_CPM_MSCCDR(n) & ~CPM_MSCCDR_MSCDIV_MASK) | ((v) << (CPM_MSCCDR_MSCDIV_BIT)))
#define __cpm_set_uhcdiv(v) \
	(REG_CPM_UHCCDR = (REG_CPM_UHCCDR & ~CPM_UHCCDR_UHCDIV_MASK) | ((v) << (CPM_UHCCDR_UHCDIV_BIT)))
#define __cpm_set_ssidiv(v) \
	(REG_CPM_SSICDR = (REG_CPM_SSICDR & ~CPM_SSICDR_SSIDIV_MASK) | ((v) << (CPM_SSICDR_SSIDIV_BIT)))
#define __cpm_set_pcmdiv(v) \
	(REG_CPM_PCMCDR = (REG_CPM_PCMCDR & ~CPM_PCMCDR_PCMCD_MASK) | ((v) << (CPM_PCMCDR_PCMCD_BIT)))

#if defined(__JZ4740__) || defined(__JZ4725__)
#define __cpm_ssiclk_select_exclk() (REG_CPM_SSICDR &= ~CPM_SSICDR_SCS)
#define __cpm_ssiclk_select_pllout() (REG_CPM_SSICDR |= CPM_SSICDR_SCS)
#elif defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define __cpm_select_pcmclk_pll() 	(REG_CPM_PCMCDR |= CPM_PCMCDR_PCMS)
#define __cpm_select_pcmclk_exclk() 	(REG_CPM_PCMCDR &= ~CPM_PCMCDR_PCMS)
#if defined(__JZ4750__)
#define __cpm_select_pixclk_ext()	(REG_CPM_LPCDR |= CPM_LPCDR_LPCS)
#define __cpm_select_pixclk_pll()	(REG_CPM_LPCDR &= ~CPM_LPCDR_LPCS)
#endif
#define __cpm_select_tveclk_exclk()	(REG_CPM_LPCDR |= CPM_CPCCR_LSCS)
#define __cpm_select_tveclk_pll()	(REG_CPM_LPCDR &= ~CPM_LPCDR_LSCS)
#define __cpm_select_pixclk_lcd()	(REG_CPM_LPCDR &= ~CPM_LPCDR_LTCS)
#define __cpm_select_pixclk_tve()	(REG_CPM_LPCDR |= CPM_LPCDR_LTCS)
#endif
#define __cpm_select_i2sclk_exclk()	(REG_CPM_CPCCR &= ~CPM_CPCCR_I2CS)
#define __cpm_select_i2sclk_pll()	(REG_CPM_CPCCR |= CPM_CPCCR_I2CS)
#define __cpm_select_usbclk_exclk()	(REG_CPM_CPCCR &= ~CPM_CPCCR_UCS)
#define __cpm_select_usbclk_pll()	(REG_CPM_CPCCR |= CPM_CPCCR_UCS)

#if defined(__JZ4740__) || defined(__JZ4725__)
#define __cpm_enable_cko()		(REG_CPM_CPCCR |= CPM_CPCCR_CLKOEN)
#elif defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define __cpm_enable_cko()
#define __cpm_exclk_direct()		(REG_CPM_CPCCR &= ~CPM_CPCCR_ECS)
#define __cpm_exclk_div2()             	(REG_CPM_CPCCR |= CPM_CPCCR_ECS)
#endif
#define __cpm_enable_pll_change()	(REG_CPM_CPCCR |= CPM_CPCCR_CE)
#define __cpm_pllout_direct()		(REG_CPM_CPCCR |= CPM_CPCCR_PCS)
#define __cpm_pllout_div2()		(REG_CPM_CPCCR &= ~CPM_CPCCR_PCS)
#define __cpm_pll_enable()		(REG_CPM_CPPCR |= CPM_CPPCR_PLLEN)
#if defined(__JZ4740__) || defined(__JZ4725__)
#define __cpm_pll_is_on()		(REG_CPM_CPPCR & CPM_CPPCR_PLLS)
#define __cpm_pll_bypass()		(REG_CPM_CPPCR |= CPM_CPPCR_PLLBP)
#elif defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define __cpm_pll_is_off()		(REG_CPM_CPPSR & CPM_CPPSR_PLLOFF)
#define __cpm_pll_is_on()		(REG_CPM_CPPSR & CPM_CPPSR_PLLON)
#define __cpm_pll_bypass()		(REG_CPM_CPPSR |= CPM_CPPSR_PLLBP)
#endif

#define __cpm_get_cclk_doze_duty() \
	((REG_CPM_LCR & CPM_LCR_DOZE_DUTY_MASK) >> CPM_LCR_DOZE_DUTY_BIT)
#define __cpm_set_cclk_doze_duty(v) \
	(REG_CPM_LCR = (REG_CPM_LCR & ~CPM_LCR_DOZE_DUTY_MASK) | ((v) << (CPM_LCR_DOZE_DUTY_BIT)))

#define __cpm_doze_mode()		(REG_CPM_LCR |= CPM_LCR_DOZE_ON)
#define __cpm_idle_mode() \
	(REG_CPM_LCR = (REG_CPM_LCR & ~CPM_LCR_LPM_MASK) | CPM_LCR_LPM_IDLE)
#define __cpm_sleep_mode() \
	(REG_CPM_LCR = (REG_CPM_LCR & ~CPM_LCR_LPM_MASK) | CPM_LCR_LPM_SLEEP)

#if defined(__JZ4740__) || defined(__JZ4725__)
#define __cpm_stop_all() 	(REG_CPM_CLKGR = 0x7fff)
#elif defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define __cpm_stop_all() 	(REG_CPM_CLKGR = 0x1fffffff)
#define __cpm_stop_cimram()	(REG_CPM_CLKGR |= CPM_CLKGR_CIMRAM)
#define __cpm_stop_idct()	(REG_CPM_CLKGR |= CPM_CLKGR_IDCT)
#define __cpm_stop_db()	        (REG_CPM_CLKGR |= CPM_CLKGR_DB)
#define __cpm_stop_me()	        (REG_CPM_CLKGR |= CPM_CLKGR_ME)
#define __cpm_stop_mc()	        (REG_CPM_CLKGR |= CPM_CLKGR_MC)
#define __cpm_stop_tve()        (REG_CPM_CLKGR |= CPM_CLKGR_TVE)
#define __cpm_stop_tssi()       (REG_CPM_CLKGR |= CPM_CLKGR_TSSI)
#define __cpm_stop_owi()        (REG_CPM_CLKGR |= CPM_CLKGR_OWI)
#define __cpm_stop_pcm()        (REG_CPM_CLKGR |= CPM_CLKGR_PCM)
#define __cpm_stop_uart3()	(REG_CPM_CLKGR |= CPM_CLKGR_UART3)
#define __cpm_stop_uart2()	(REG_CPM_CLKGR |= CPM_CLKGR_UART2)
#endif
#define __cpm_stop_uart1()	(REG_CPM_CLKGR |= CPM_CLKGR_UART1)
#define __cpm_stop_uhc()	(REG_CPM_CLKGR |= CPM_CLKGR_UHC)
#define __cpm_stop_ipu()	(REG_CPM_CLKGR |= CPM_CLKGR_IPU)
#define __cpm_stop_dmac()	(REG_CPM_CLKGR |= CPM_CLKGR_DMAC)
#define __cpm_stop_udc()	(REG_CPM_CLKGR |= CPM_CLKGR_UDC)
#define __cpm_stop_lcd()	(REG_CPM_CLKGR |= CPM_CLKGR_LCD)
#define __cpm_stop_cim()	(REG_CPM_CLKGR |= CPM_CLKGR_CIM)
#define __cpm_stop_sadc()	(REG_CPM_CLKGR |= CPM_CLKGR_SADC)
#define __cpm_stop_msc(n)	(REG_CPM_CLKGR |= CPM_CLKGR_MSC##n)
#define __cpm_stop_aic1()	(REG_CPM_CLKGR |= CPM_CLKGR_AIC1)
#define __cpm_stop_aic2()	(REG_CPM_CLKGR |= CPM_CLKGR_AIC2)
#define __cpm_stop_ssi(n)	(REG_CPM_CLKGR |= CPM_CLKGR_SSI##n)
#define __cpm_stop_i2c()	(REG_CPM_CLKGR |= CPM_CLKGR_I2C)
#define __cpm_stop_rtc()	(REG_CPM_CLKGR |= CPM_CLKGR_RTC)
#define __cpm_stop_tcu()	(REG_CPM_CLKGR |= CPM_CLKGR_TCU)
#define __cpm_stop_uart0()	(REG_CPM_CLKGR |= CPM_CLKGR_UART0)

#define __cpm_start_all() 	(REG_CPM_CLKGR = 0x0)
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define __cpm_start_cimram()	(REG_CPM_CLKGR &= ~CPM_CLKGR_CIMRAM)
#define __cpm_start_idct()	(REG_CPM_CLKGR &= ~CPM_CLKGR_IDCT)
#define __cpm_start_db()        (REG_CPM_CLKGR &= ~CPM_CLKGR_DB)
#define __cpm_start_me()        (REG_CPM_CLKGR &= ~CPM_CLKGR_ME)
#define __cpm_start_mc()        (REG_CPM_CLKGR &= ~CPM_CLKGR_MC)
#define __cpm_start_tve()        (REG_CPM_CLKGR &= ~CPM_CLKGR_TVE)
#define __cpm_start_tssi()       (REG_CPM_CLKGR &= ~CPM_CLKGR_TSSI)
#define __cpm_start_owi()        (REG_CPM_CLKGR &= ~CPM_CLKGR_OWI)
#define __cpm_start_pcm()        (REG_CPM_CLKGR &= ~CPM_CLKGR_PCM)
#define __cpm_start_uart3()	(REG_CPM_CLKGR &= ~CPM_CLKGR_UART3)
#define __cpm_start_uart2()	(REG_CPM_CLKGR &= ~CPM_CLKGR_UART2)
#endif
#define __cpm_start_uart1()	(REG_CPM_CLKGR &= ~CPM_CLKGR_UART1)
#define __cpm_start_uhc()	(REG_CPM_CLKGR &= ~CPM_CLKGR_UHC)
#define __cpm_start_ipu()	(REG_CPM_CLKGR &= ~CPM_CLKGR_IPU)
#define __cpm_start_dmac()	(REG_CPM_CLKGR &= ~CPM_CLKGR_DMAC)
#define __cpm_start_udc()	(REG_CPM_CLKGR &= ~CPM_CLKGR_UDC)
#define __cpm_start_lcd()	(REG_CPM_CLKGR &= ~CPM_CLKGR_LCD)
#define __cpm_start_cim()	(REG_CPM_CLKGR &= ~CPM_CLKGR_CIM)
#define __cpm_start_sadc()	(REG_CPM_CLKGR &= ~CPM_CLKGR_SADC)
#define __cpm_start_msc(n)	(REG_CPM_CLKGR &= ~CPM_CLKGR_MSC##n)
#define __cpm_start_aic1()	(REG_CPM_CLKGR &= ~CPM_CLKGR_AIC1)
#define __cpm_start_aic2()	(REG_CPM_CLKGR &= ~CPM_CLKGR_AIC2)
#define __cpm_start_ssi(n)	(REG_CPM_CLKGR &= ~CPM_CLKGR_SSI##n)
#define __cpm_start_i2c()	(REG_CPM_CLKGR &= ~CPM_CLKGR_I2C)
#define __cpm_start_rtc()	(REG_CPM_CLKGR &= ~CPM_CLKGR_RTC)
#define __cpm_start_tcu()	(REG_CPM_CLKGR &= ~CPM_CLKGR_TCU)
#define __cpm_start_uart0()	(REG_CPM_CLKGR &= ~CPM_CLKGR_UART0)

#if defined(__JZ4740__) || defined(__JZ4725__)
#define __cpm_get_o1st() \
	((REG_CPM_SCR & CPM_SCR_O1ST_MASK) >> CPM_SCR_O1ST_BIT)
#define __cpm_set_o1st(v) \
	(REG_CPM_SCR = (REG_CPM_SCR & ~CPM_SCR_O1ST_MASK) | ((v) << (CPM_SCR_O1ST_BIT)))

#define __cpm_suspend_usbphy()		(REG_CPM_SCR |= CPM_SCR_USBPHY_SUSPEND)
#define __cpm_enable_osc_in_sleep()	(REG_CPM_SCR |= CPM_SCR_OSC_ENABLE)

#elif defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define __cpm_get_o1st() \
	((REG_CPM_OPCR & CPM_OPCR_O1ST_MASK) >> CPM_OPCR_O1ST_BIT)
#define __cpm_set_o1st(v) \
	(REG_CPM_OPCR = (REG_CPM_OPCR & ~CPM_OPCR_O1ST_MASK) | ((v) << (CPM_OPCR_O1ST_BIT)))

#define __cpm_enable_uhcphy()		(REG_CPM_OPCR &= ~CPM_OPCR_UHCPHY_DISABLE)
#define __cpm_suspend_uhcphy()		(REG_CPM_OPCR |= CPM_OPCR_UHCPHY_DISABLE)
#define __cpm_enable_udcphy()		(REG_CPM_OPCR |= CPM_OPCR_UDCPHY_ENABLE)
#define __cpm_suspend_udcphy()		(REG_CPM_OPCR &= ~CPM_OPCR_UDCPHY_ENABLE)
#define __cpm_enable_osc_in_sleep()	(REG_CPM_OPCR |= CPM_OPCR_OSC_ENABLE)
#define __cpm_disable_osc_in_sleep()	(REG_CPM_OPCR &= ~CPM_OPCR_OSC_ENABLE)
#define __cpm_select_rtcclk_rtc()	(REG_CPM_OPCR |= CPM_OPCR_ERCS)
#define __cpm_select_rtcclk_exclk()	(REG_CPM_OPCR &= ~CPM_OPCR_ERCS)
#endif


#define JZ_EXTAL		12000000

/* PLL output frequency */
static inline unsigned int __cpm_get_pllout(void)
{
	unsigned long m, n, no, pllout;
	unsigned long cppcr = REG_CPM_CPPCR;
	const unsigned long od[4] = {1, 2, 2, 4};
	if ((cppcr & CPM_CPPCR_PLLEN) && !(cppcr & CPM_CPPCR_PLLBP)) {
		m = __cpm_get_pllm() + 2;
		n = __cpm_get_plln() + 2;
		no = od[__cpm_get_pllod() &0x3];
		pllout = ((JZ_EXTAL) / (n * no)) * m;
	} else
		pllout = JZ_EXTAL;
	return pllout;
}

/* PLL output frequency for MSC/I2S/LCD/USB */
static inline unsigned int __cpm_get_pllout2(void)
{
	if (REG_CPM_CPCCR & CPM_CPCCR_PCS)
		return __cpm_get_pllout();
	else
		return __cpm_get_pllout()/2;
}

/* CPU core clock */
static inline unsigned int __cpm_get_cclk(void)
{
	const int div[] = {1, 2, 3, 4, 6, 8, 12, 16, 24, 32};
	return __cpm_get_pllout() / div[__cpm_get_cdiv()];
}

/* Memory bus clock */
static inline unsigned int __cpm_get_mclk(void)
{
	const int div[] = {1, 2, 3, 4, 6, 8, 12, 16, 24, 32};

	return __cpm_get_pllout() / div[__cpm_get_mdiv()];
}

/* APB peripheral bus clock */
static inline unsigned int __cpm_get_pclk(void)
{
	const int div[] = {1, 2, 3, 4, 6, 8, 12, 16, 24, 32};

	return __cpm_get_pllout() / div[__cpm_get_pdiv()];
}

/* LCD pixel clock */
static inline unsigned int __cpm_get_pixclk(void)
{
	return __cpm_get_pllout2() / (__cpm_get_pixdiv() + 1);
}

/* 
 * MSC clock
 * @n: the index of MMC/SD controller 
 */
static inline unsigned int __cpm_get_mscclk(int n)
{
	return __cpm_get_pllout2() / (__cpm_get_mscdiv(n) + 1);
}

/*
 * Output 24MHz for SD and 16MHz for MMC.
 * @n: the index of MMC/SD controller
 */
static inline void __cpm_select_msc_clk(int n, int sd)
{
	unsigned int pllout2 = __cpm_get_pllout2();
	unsigned int div = 0;

	if (sd) {
		div = pllout2 / 24000000;
	}
	else {
		div = pllout2 / 16000000;
	}

	REG_CPM_MSCCDR(n) = div - 1;
	REG_CPM_CPCCR |= CPM_CPCCR_CE;
}

#endif /* __JZ_CPM_H__ */
