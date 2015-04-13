#ifndef __JZ_ICDC_H__
#define __JZ_ICDC_H__
#ifndef __JZ_BASE_H__
#include <jz/jz_base.h>
#endif
/*************************************************************************
 * ICDC (Internal CODEC)
 *************************************************************************/

#if defined(__JZ4740__) || defined(__JZ4725__)
#define	ICDC_CR			(ICDC_BASE + 0x0400)  /* ICDC Control Register */
#define	ICDC_APWAIT		(ICDC_BASE + 0x0404)  /* Anti-Pop WAIT Stage Timing Control Register */
#define	ICDC_APPRE		(ICDC_BASE + 0x0408)  /* Anti-Pop HPEN-PRE Stage Timing Control Register */
#define	ICDC_APHPEN		(ICDC_BASE + 0x040C)  /* Anti-Pop HPEN Stage Timing Control Register */
#define	ICDC_APSR		(ICDC_BASE + 0x0410)  /* Anti-Pop Status Register */
#define ICDC_CDCCR1             (ICDC_BASE + 0x0080)
#define ICDC_CDCCR2             (ICDC_BASE + 0x0084)

#define	REG_ICDC_CR		REG32(ICDC_CR)
#define	REG_ICDC_APWAIT		REG32(ICDC_APWAIT)
#define	REG_ICDC_APPRE		REG32(ICDC_APPRE)
#define	REG_ICDC_APHPEN		REG32(ICDC_APHPEN)
#define	REG_ICDC_APSR		REG32(ICDC_APSR)
#define REG_ICDC_CDCCR1         REG32(ICDC_CDCCR1)
#define REG_ICDC_CDCCR2         REG32(ICDC_CDCCR2)

/* ICDC Control Register */
#define	ICDC_CR_LINVOL_BIT	24 /* LINE Input Volume Gain: GAIN=LINVOL*1.5-34.5 */
#define	ICDC_CR_LINVOL_MASK	(0x1f << ICDC_CR_LINVOL_BIT)
#define	ICDC_CR_ASRATE_BIT	20 /* Audio Sample Rate */
#define	ICDC_CR_ASRATE_MASK	(0x0f << ICDC_CR_ASRATE_BIT)
  #define ICDC_CR_ASRATE_8000	(0x0 << ICDC_CR_ASRATE_BIT)
  #define ICDC_CR_ASRATE_11025	(0x1 << ICDC_CR_ASRATE_BIT)
  #define ICDC_CR_ASRATE_12000	(0x2 << ICDC_CR_ASRATE_BIT)
  #define ICDC_CR_ASRATE_16000	(0x3 << ICDC_CR_ASRATE_BIT)
  #define ICDC_CR_ASRATE_22050	(0x4 << ICDC_CR_ASRATE_BIT)
  #define ICDC_CR_ASRATE_24000	(0x5 << ICDC_CR_ASRATE_BIT)
  #define ICDC_CR_ASRATE_32000	(0x6 << ICDC_CR_ASRATE_BIT)
  #define ICDC_CR_ASRATE_44100	(0x7 << ICDC_CR_ASRATE_BIT)
  #define ICDC_CR_ASRATE_48000	(0x8 << ICDC_CR_ASRATE_BIT)
#define	ICDC_CR_MICBG_BIT	18 /* MIC Boost Gain */
#define	ICDC_CR_MICBG_MASK	(0x3 << ICDC_CR_MICBG_BIT)
  #define ICDC_CR_MICBG_0DB	(0x0 << ICDC_CR_MICBG_BIT)
  #define ICDC_CR_MICBG_6DB	(0x1 << ICDC_CR_MICBG_BIT)
  #define ICDC_CR_MICBG_12DB	(0x2 << ICDC_CR_MICBG_BIT)
  #define ICDC_CR_MICBG_20DB	(0x3 << ICDC_CR_MICBG_BIT)
#define	ICDC_CR_HPVOL_BIT	16 /* Headphone Volume Gain */
#define	ICDC_CR_HPVOL_MASK	(0x3 << ICDC_CR_HPVOL_BIT)
  #define ICDC_CR_HPVOL_0DB	(0x0 << ICDC_CR_HPVOL_BIT)
  #define ICDC_CR_HPVOL_2DB	(0x1 << ICDC_CR_HPVOL_BIT)
  #define ICDC_CR_HPVOL_4DB	(0x2 << ICDC_CR_HPVOL_BIT)
  #define ICDC_CR_HPVOL_6DB	(0x3 << ICDC_CR_HPVOL_BIT)
#define ICDC_CR_ELINEIN		(1 << 13) /* Enable LINE Input */
#define ICDC_CR_EMIC		(1 << 12) /* Enable MIC Input */
#define ICDC_CR_SW1ON		(1 << 11) /* Switch 1 in CODEC is on */
#define ICDC_CR_EADC		(1 << 10) /* Enable ADC */
#define ICDC_CR_SW2ON		(1 << 9)  /* Switch 2 in CODEC is on */
#define ICDC_CR_EDAC		(1 << 8)  /* Enable DAC */
#define ICDC_CR_HPMUTE		(1 << 5)  /* Headphone Mute */
#define ICDC_CR_HPTON		(1 << 4)  /* Headphone Amplifier Trun On */
#define ICDC_CR_HPTOFF		(1 << 3)  /* Headphone Amplifier Trun Off */
#define ICDC_CR_TAAP		(1 << 2)  /* Turn Around of the Anti-Pop Procedure */
#define ICDC_CR_EAP		(1 << 1)  /* Enable Anti-Pop Procedure */
#define ICDC_CR_SUSPD		(1 << 0)  /* CODEC Suspend */

/* Anti-Pop WAIT Stage Timing Control Register */
#define	ICDC_APWAIT_WAITSN_BIT	0
#define	ICDC_APWAIT_WAITSN_MASK	(0x7ff << ICDC_APWAIT_WAITSN_BIT)

/* Anti-Pop HPEN-PRE Stage Timing Control Register */
#define	ICDC_APPRE_PRESN_BIT	0
#define	ICDC_APPRE_PRESN_MASK	(0x1ff << ICDC_APPRE_PRESN_BIT)

/* Anti-Pop HPEN Stage Timing Control Register */
#define	ICDC_APHPEN_HPENSN_BIT	0
#define	ICDC_APHPEN_HPENSN_MASK	(0x3fff << ICDC_APHPEN_HPENSN_BIT)

/* Anti-Pop Status Register */
#define	ICDC_SR_HPST_BIT	14  /* Headphone Amplifier State */
#define	ICDC_SR_HPST_MASK	(0x7 << ICDC_SR_HPST_BIT)
#define ICDC_SR_HPST_HP_OFF	 (0x0 << ICDC_SR_HPST_BIT) /* HP amplifier is off */
#define ICDC_SR_HPST_TON_WAIT	 (0x1 << ICDC_SR_HPST_BIT) /* wait state in turn-on */
  #define ICDC_SR_HPST_TON_PRE	 (0x2 << ICDC_SR_HPST_BIT) /* pre-enable state in turn-on */
#define ICDC_SR_HPST_TON_HPEN	 (0x3 << ICDC_SR_HPST_BIT) /* HP enable state in turn-on */
  #define ICDC_SR_HPST_TOFF_HPEN (0x4 << ICDC_SR_HPST_BIT) /* HP enable state in turn-off */
  #define ICDC_SR_HPST_TOFF_PRE  (0x5 << ICDC_SR_HPST_BIT) /* pre-enable state in turn-off */
  #define ICDC_SR_HPST_TOFF_WAIT (0x6 << ICDC_SR_HPST_BIT) /* wait state in turn-off */
  #define ICDC_SR_HPST_HP_ON	 (0x7 << ICDC_SR_HPST_BIT) /* HP amplifier is on */
#define	ICDC_SR_SNCNT_BIT	0  /* Sample Number Counter */
#define	ICDC_SR_SNCNT_MASK	(0x3fff << ICDC_SR_SNCNT_BIT)
#endif


#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)

#define	ICDC_CKCFG	  (ICDC_BASE + 0x00a0)  /* Clock Configure Register */
#define	ICDC_RGADW	  (ICDC_BASE + 0x00a4)  /* internal register access control */
#define	ICDC_RGDATA	  (ICDC_BASE + 0x00a8)  /* internal register data output */

#define	REG_ICDC_CKCFG		REG32(ICDC_CKCFG)
#define	REG_ICDC_RGADW		REG32(ICDC_RGADW)
#define	REG_ICDC_RGDATA		REG32(ICDC_RGDATA)

/* ICDC Clock Configure Register */
#define	ICDC_CKCFG_CKRDY	(1 << 1) 
#define	ICDC_CKCFG_SELAD	(1 << 0)

/* ICDC internal register access control Register */
#define ICDC_RGADW_RGWR         (1 << 16)
#define ICDC_RGADW_RGADDR_BIT   8
#define	ICDC_RGADW_RGADDR_MASK	(0x7f << ICDC_RGADW_RGADDR_BIT)
#define ICDC_RGADW_RGDIN_BIT    0
#define	ICDC_RGADW_RGDIN_MASK	(0xff << ICDC_RGADW_RGDIN_BIT)

/* ICDC internal register data output Register */
#define ICDC_RGDATA_IRQ         (1 << 8)
#define ICDC_RGDATA_RGDOUT_BIT  0
#define ICDC_RGDATA_RGDOUT_MASK (0xff << ICDC_RGDATA_RGDOUT_BIT)

#endif


/*
 * OPs
 */

#define __i2s_internal_codec()         __aic_internal_codec()
#define __i2s_external_codec()         __aic_external_codec()

#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define __icdc_clk_ready()             ( REG_ICDC_CKCFG & ICDC_CKCFG_CKRDY )
#define __icdc_sel_adc()               ( REG_ICDC_CKCFG |= ICDC_CKCFG_SELAD )
#define __icdc_sel_dac()               ( REG_ICDC_CKCFG &= ~ICDC_CKCFG_SELAD )

#define __icdc_set_rgwr()              ( REG_ICDC_RGADW |= ICDC_RGADW_RGWR )
#define __icdc_clear_rgwr()            ( REG_ICDC_RGADW &= ~ICDC_RGADW_RGWR )
#define __icdc_rgwr_ready()            ( REG_ICDC_RGADW & ICDC_RGADW_RGWR )

#define __icdc_set_addr(n)				\
do {          						\
	REG_ICDC_RGADW &= ~ICDC_RGADW_RGADDR_MASK;	\
	REG_ICDC_RGADW |= (n) << ICDC_RGADW_RGADDR_BIT;	\
} while(0)

#define __icdc_set_cmd(n)				\
do {          						\
	REG_ICDC_RGADW &= ~ICDC_RGADW_RGDIN_MASK;	\
	REG_ICDC_RGADW |= (n) << ICDC_RGADW_RGDIN_BIT;	\
} while(0)

#define __icdc_irq_pending()            ( REG_ICDC_RGDATA & ICDC_RGDATA_IRQ )
#define __icdc_get_value()              ( REG_ICDC_RGDATA & ICDC_RGDATA_RGDOUT_MASK )

#endif


#endif /* __JZ_ICDC_H__ */
