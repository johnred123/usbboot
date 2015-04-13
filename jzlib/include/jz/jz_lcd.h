#ifndef __JZ_LCD_H__
#define __JZ_LCD_H__
#ifndef __JZ_BASE_H__
#include <jz/jz_base.h>
#endif
/*************************************************************************
 * LCD (LCD Controller)
 *************************************************************************/
#define LCD_CFG		(LCD_BASE + 0x00) /* LCD Configure Register */
#define LCD_VSYNC	(LCD_BASE + 0x04) /* Vertical Synchronize Register */
#define LCD_HSYNC	(LCD_BASE + 0x08) /* Horizontal Synchronize Register */
#define LCD_VAT		(LCD_BASE + 0x0c) /* Virtual Area Setting Register */
#define LCD_DAH		(LCD_BASE + 0x10) /* Display Area Horizontal Start/End Point */
#define LCD_DAV		(LCD_BASE + 0x14) /* Display Area Vertical Start/End Point */
#define LCD_PS		(LCD_BASE + 0x18) /* PS Signal Setting */
#define LCD_CLS		(LCD_BASE + 0x1c) /* CLS Signal Setting */
#define LCD_SPL		(LCD_BASE + 0x20) /* SPL Signal Setting */
#define LCD_REV		(LCD_BASE + 0x24) /* REV Signal Setting */
#define LCD_CTRL	(LCD_BASE + 0x30) /* LCD Control Register */
#define LCD_STATE	(LCD_BASE + 0x34) /* LCD Status Register */
#define LCD_IID		(LCD_BASE + 0x38) /* Interrupt ID Register */
#define LCD_DA0		(LCD_BASE + 0x40) /* Descriptor Address Register 0 */
#define LCD_SA0		(LCD_BASE + 0x44) /* Source Address Register 0 */
#define LCD_FID0	(LCD_BASE + 0x48) /* Frame ID Register 0 */
#define LCD_CMD0	(LCD_BASE + 0x4c) /* DMA Command Register 0 */
#define LCD_DA1		(LCD_BASE + 0x50) /* Descriptor Address Register 1 */
#define LCD_SA1		(LCD_BASE + 0x54) /* Source Address Register 1 */
#define LCD_FID1	(LCD_BASE + 0x58) /* Frame ID Register 1 */
#define LCD_CMD1	(LCD_BASE + 0x5c) /* DMA Command Register 1 */

#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define LCD_OFFS0	(LCD_BASE + 0x60) /* DMA Offsize Register 0 */
#define LCD_PW0		(LCD_BASE + 0x64) /* DMA Page Width Register 0 */
#define LCD_CNUM0	(LCD_BASE + 0x68) /* DMA Command Counter Register 0 */
#define LCD_DESSIZE0	(LCD_BASE + 0x6C) /* Foreground Size in Descriptor 0 Register*/
#define LCD_OFFS1	(LCD_BASE + 0x70) /* DMA Offsize Register 1 */
#define LCD_PW1		(LCD_BASE + 0x74) /* DMA Page Width Register 1 */
#define LCD_CNUM1	(LCD_BASE + 0x78) /* DMA Command Counter Register 1 */
#define LCD_DESSIZE1	(LCD_BASE + 0x7C) /* Foreground Size in Descriptor 1 Register*/
#define LCD_RGBC	(LCD_BASE + 0x90) /* RGB Controll Register */
#define LCD_OSDC	(LCD_BASE + 0x100) /* LCD OSD Configure Register */
#define LCD_OSDCTRL	(LCD_BASE + 0x104) /* LCD OSD Control Register */
#define LCD_OSDS	(LCD_BASE + 0x108) /* LCD OSD Status Register */
#define LCD_BGC		(LCD_BASE + 0x10C) /* LCD Background Color Register */
#define LCD_KEY0	(LCD_BASE + 0x110) /* LCD Foreground Color Key Register 0 */
#define LCD_KEY1	(LCD_BASE + 0x114) /* LCD Foreground Color Key Register 1 */
#define LCD_ALPHA	(LCD_BASE + 0x118) /* LCD ALPHA Register */
#define LCD_IPUR	(LCD_BASE + 0x11C) /* LCD IPU Restart Register */
#define LCD_XYP0	(LCD_BASE + 0x120) /* Foreground 0 XY Position Register */
#define LCD_XYP1	(LCD_BASE + 0x124) /* Foreground 1 XY Position Register */
#define LCD_SIZE0	(LCD_BASE + 0x128) /* Foreground 0 Size Register */
#define LCD_SIZE1	(LCD_BASE + 0x12C) /* Foreground 1 Size Register */
#endif

#define REG_LCD_CFG	REG32(LCD_CFG)
#define REG_LCD_VSYNC	REG32(LCD_VSYNC)
#define REG_LCD_HSYNC	REG32(LCD_HSYNC)
#define REG_LCD_VAT	REG32(LCD_VAT)
#define REG_LCD_DAH	REG32(LCD_DAH)
#define REG_LCD_DAV	REG32(LCD_DAV)
#define REG_LCD_PS	REG32(LCD_PS)
#define REG_LCD_CLS	REG32(LCD_CLS)
#define REG_LCD_SPL	REG32(LCD_SPL)
#define REG_LCD_REV	REG32(LCD_REV)
#define REG_LCD_CTRL	REG32(LCD_CTRL)
#define REG_LCD_STATE	REG32(LCD_STATE)
#define REG_LCD_IID	REG32(LCD_IID)
#define REG_LCD_DA0	REG32(LCD_DA0)
#define REG_LCD_SA0	REG32(LCD_SA0)
#define REG_LCD_FID0	REG32(LCD_FID0)
#define REG_LCD_CMD0	REG32(LCD_CMD0)
#define REG_LCD_DA1	REG32(LCD_DA1)
#define REG_LCD_SA1	REG32(LCD_SA1)
#define REG_LCD_FID1	REG32(LCD_FID1)
#define REG_LCD_CMD1	REG32(LCD_CMD1)

#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define REG_LCD_OFFS0	REG32(LCD_OFFS0)
#define REG_LCD_PW0	REG32(LCD_PW0)
#define REG_LCD_CNUM0	REG32(LCD_CNUM0)
#define REG_LCD_DESSIZE0	REG32(LCD_DESSIZE0)
#define REG_LCD_OFFS1	REG32(LCD_OFFS1)
#define REG_LCD_PW1	REG32(LCD_PW1)
#define REG_LCD_CNUM1	REG32(LCD_CNUM1)
#define REG_LCD_DESSIZE1	REG32(LCD_DESSIZE1)
#define REG_LCD_RGBC	REG16(LCD_RGBC)
#define REG_LCD_OSDC	REG16(LCD_OSDC)
#define REG_LCD_OSDCTRL	REG16(LCD_OSDCTRL)
#define REG_LCD_OSDS	REG16(LCD_OSDS)
#define REG_LCD_BGC	REG32(LCD_BGC)
#define REG_LCD_KEY0	REG32(LCD_KEY0)
#define REG_LCD_KEY1	REG32(LCD_KEY1)
#define REG_LCD_ALPHA	REG8(LCD_ALPHA)
#define REG_LCD_IPUR	REG32(LCD_IPUR)
#define REG_LCD_XYP0	REG32(LCD_XYP0)
#define REG_LCD_XYP1	REG32(LCD_XYP1)
#define REG_LCD_SIZE0	REG32(LCD_SIZE0)
#define REG_LCD_SIZE1	REG32(LCD_SIZE1)
#endif

/* LCD Configure Register */
#define LCD_CFG_LCDPIN_BIT	31  /* LCD pins selection */
#define LCD_CFG_LCDPIN_MASK	(0x1 << LCD_CFG_LCDPIN_BIT)
  #define LCD_CFG_LCDPIN_LCD	(0x0 << LCD_CFG_LCDPIN_BIT)
  #define LCD_CFG_LCDPIN_SLCD	(0x1 << LCD_CFG_LCDPIN_BIT)
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define LCD_CFG_TVEPEH		(1 << 30) /* TVE PAL enable extra halfline signal */
#define LCD_CFG_FUHOLD		(1 << 29) /* hold pixel clock when outFIFO underrun */
#define LCD_CFG_NEWDES		(1 << 28) /* use new descripter. old: 4words, new:8words */
#define LCD_CFG_PALBP		(1 << 27) /* bypass data format and alpha blending */
#define LCD_CFG_TVEN		(1 << 26) /* indicate the terminal is lcd or tv */
#define LCD_CFG_RECOVER		(1 << 25) /* Auto recover when output fifo underrun */
#define LCD_CFG_DITHER		(1 << 24) /* Dither function */
#endif
#define LCD_CFG_PSM		(1 << 23) /* PS signal mode */
#define LCD_CFG_CLSM		(1 << 22) /* CLS signal mode */
#define LCD_CFG_SPLM		(1 << 21) /* SPL signal mode */
#define LCD_CFG_REVM		(1 << 20) /* REV signal mode */
#define LCD_CFG_HSYNM		(1 << 19) /* HSYNC signal mode */
#define LCD_CFG_PCLKM		(1 << 18) /* PCLK signal mode */
#define LCD_CFG_INVDAT		(1 << 17) /* Inverse output data */
#define LCD_CFG_SYNDIR_IN	(1 << 16) /* VSYNC&HSYNC direction */
#define LCD_CFG_PSP		(1 << 15) /* PS pin reset state */
#define LCD_CFG_CLSP		(1 << 14) /* CLS pin reset state */
#define LCD_CFG_SPLP		(1 << 13) /* SPL pin reset state */
#define LCD_CFG_REVP		(1 << 12) /* REV pin reset state */
#define LCD_CFG_HSP		(1 << 11) /* HSYNC polarity:0-active high,1-active low */
#define LCD_CFG_PCP		(1 << 10) /* PCLK polarity:0-rising,1-falling */
#define LCD_CFG_DEP		(1 << 9)  /* DE polarity:0-active high,1-active low */
#define LCD_CFG_VSP		(1 << 8)  /* VSYNC polarity:0-rising,1-falling */
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define LCD_CFG_MODE_TFT_18BIT 	(1 << 7)  /* 18bit TFT */
#define LCD_CFG_MODE_TFT_16BIT 	(0 << 7)  /* 16bit TFT */
#define LCD_CFG_MODE_TFT_24BIT 	(1 << 6)  /* 24bit TFT */
#endif
#define LCD_CFG_PDW_BIT		4  /* STN pins utilization */
#define LCD_CFG_PDW_MASK	(0x3 << LCD_DEV_PDW_BIT)
#define LCD_CFG_PDW_1		(0 << LCD_CFG_PDW_BIT) /* LCD_D[0] */
  #define LCD_CFG_PDW_2		(1 << LCD_CFG_PDW_BIT) /* LCD_D[0:1] */
  #define LCD_CFG_PDW_4		(2 << LCD_CFG_PDW_BIT) /* LCD_D[0:3]/LCD_D[8:11] */
  #define LCD_CFG_PDW_8		(3 << LCD_CFG_PDW_BIT) /* LCD_D[0:7]/LCD_D[8:15] */
#define LCD_CFG_MODE_BIT	0  /* Display Device Mode Select */
#define LCD_CFG_MODE_MASK	(0x0f << LCD_CFG_MODE_BIT)
  #define LCD_CFG_MODE_GENERIC_TFT	(0 << LCD_CFG_MODE_BIT) /* 16,18 bit TFT */
  #define LCD_CFG_MODE_SPECIAL_TFT_1	(1 << LCD_CFG_MODE_BIT)
  #define LCD_CFG_MODE_SPECIAL_TFT_2	(2 << LCD_CFG_MODE_BIT)
  #define LCD_CFG_MODE_SPECIAL_TFT_3	(3 << LCD_CFG_MODE_BIT)
  #define LCD_CFG_MODE_NONINTER_CCIR656	(4 << LCD_CFG_MODE_BIT)
  #define LCD_CFG_MODE_INTER_CCIR656	(6 << LCD_CFG_MODE_BIT)
  #define LCD_CFG_MODE_SINGLE_CSTN	(8 << LCD_CFG_MODE_BIT)
  #define LCD_CFG_MODE_SINGLE_MSTN	(9 << LCD_CFG_MODE_BIT)
  #define LCD_CFG_MODE_DUAL_CSTN	(10 << LCD_CFG_MODE_BIT)
  #define LCD_CFG_MODE_DUAL_MSTN	(11 << LCD_CFG_MODE_BIT)
  #define LCD_CFG_MODE_SERIAL_TFT	(12 << LCD_CFG_MODE_BIT)
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
  #define LCD_CFG_MODE_LCM  		(13 << LCD_CFG_MODE_BIT)
  #define LCD_CFG_MODE_SLCD  		LCD_CFG_MODE_LCM
#endif

/* Vertical Synchronize Register */
#define LCD_VSYNC_VPS_BIT	16  /* VSYNC pulse start in line clock, fixed to 0 */
#define LCD_VSYNC_VPS_MASK	(0xffff << LCD_VSYNC_VPS_BIT)
#define LCD_VSYNC_VPE_BIT	0   /* VSYNC pulse end in line clock */
#define LCD_VSYNC_VPE_MASK	(0xffff << LCD_VSYNC_VPS_BIT)

/* Horizontal Synchronize Register */
#define LCD_HSYNC_HPS_BIT	16  /* HSYNC pulse start position in dot clock */
#define LCD_HSYNC_HPS_MASK	(0xffff << LCD_HSYNC_HPS_BIT)
#define LCD_HSYNC_HPE_BIT	0   /* HSYNC pulse end position in dot clock */
#define LCD_HSYNC_HPE_MASK	(0xffff << LCD_HSYNC_HPE_BIT)

/* Virtual Area Setting Register */
#define LCD_VAT_HT_BIT		16  /* Horizontal Total size in dot clock */
#define LCD_VAT_HT_MASK		(0xffff << LCD_VAT_HT_BIT)
#define LCD_VAT_VT_BIT		0   /* Vertical Total size in dot clock */
#define LCD_VAT_VT_MASK		(0xffff << LCD_VAT_VT_BIT)

/* Display Area Horizontal Start/End Point Register */
#define LCD_DAH_HDS_BIT		16  /* Horizontal display area start in dot clock */
#define LCD_DAH_HDS_MASK	(0xffff << LCD_DAH_HDS_BIT)
#define LCD_DAH_HDE_BIT		0   /* Horizontal display area end in dot clock */
#define LCD_DAH_HDE_MASK	(0xffff << LCD_DAH_HDE_BIT)

/* Display Area Vertical Start/End Point Register */
#define LCD_DAV_VDS_BIT		16  /* Vertical display area start in line clock */
#define LCD_DAV_VDS_MASK	(0xffff << LCD_DAV_VDS_BIT)
#define LCD_DAV_VDE_BIT		0   /* Vertical display area end in line clock */
#define LCD_DAV_VDE_MASK	(0xffff << LCD_DAV_VDE_BIT)

/* PS Signal Setting */
#define LCD_PS_PSS_BIT		16  /* PS signal start position in dot clock */
#define LCD_PS_PSS_MASK		(0xffff << LCD_PS_PSS_BIT)
#define LCD_PS_PSE_BIT		0   /* PS signal end position in dot clock */
#define LCD_PS_PSE_MASK		(0xffff << LCD_PS_PSE_BIT)

/* CLS Signal Setting */
#define LCD_CLS_CLSS_BIT	16  /* CLS signal start position in dot clock */
#define LCD_CLS_CLSS_MASK	(0xffff << LCD_CLS_CLSS_BIT)
#define LCD_CLS_CLSE_BIT	0   /* CLS signal end position in dot clock */
#define LCD_CLS_CLSE_MASK	(0xffff << LCD_CLS_CLSE_BIT)

/* SPL Signal Setting */
#define LCD_SPL_SPLS_BIT	16  /* SPL signal start position in dot clock */
#define LCD_SPL_SPLS_MASK	(0xffff << LCD_SPL_SPLS_BIT)
#define LCD_SPL_SPLE_BIT	0   /* SPL signal end position in dot clock */
#define LCD_SPL_SPLE_MASK	(0xffff << LCD_SPL_SPLE_BIT)

/* REV Signal Setting */
#define LCD_REV_REVS_BIT	16  /* REV signal start position in dot clock */
#define LCD_REV_REVS_MASK	(0xffff << LCD_REV_REVS_BIT)

/* LCD Control Register */
#define LCD_CTRL_BST_BIT	28  /* Burst Length Selection */
#define LCD_CTRL_BST_MASK	(0x03 << LCD_CTRL_BST_BIT)
  #define LCD_CTRL_BST_4	(0 << LCD_CTRL_BST_BIT) /* 4-word */
  #define LCD_CTRL_BST_8	(1 << LCD_CTRL_BST_BIT) /* 8-word */
  #define LCD_CTRL_BST_16	(2 << LCD_CTRL_BST_BIT) /* 16-word */
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
  #define LCD_CTRL_BST_32	(3 << LCD_CTRL_BST_BIT) /* 32-word */
#endif
#define LCD_CTRL_RGB565		(0 << 27) /* RGB565 mode(foreground 0 in OSD mode) */
#define LCD_CTRL_RGB555		(1 << 27) /* RGB555 mode(foreground 0 in OSD mode) */
#define LCD_CTRL_OFUP		(1 << 26) /* Output FIFO underrun protection enable */
#define LCD_CTRL_FRC_BIT	24  /* STN FRC Algorithm Selection */
#define LCD_CTRL_FRC_MASK	(0x03 << LCD_CTRL_FRC_BIT)
  #define LCD_CTRL_FRC_16	(0 << LCD_CTRL_FRC_BIT) /* 16 grayscale */
  #define LCD_CTRL_FRC_4	(1 << LCD_CTRL_FRC_BIT) /* 4 grayscale */
  #define LCD_CTRL_FRC_2	(2 << LCD_CTRL_FRC_BIT) /* 2 grayscale */
#define LCD_CTRL_PDD_BIT	16  /* Load Palette Delay Counter */
#define LCD_CTRL_PDD_MASK	(0xff << LCD_CTRL_PDD_BIT)
#if defined(__JZ4755__) || defined(__JZ4725B__)
#define LCD_CTRL_VGA		(1 << 15) /* VGA interface enable */
#define LCD_CTRL_DACTE		(1 << 14) /* DAC loop back test */
#endif
#define LCD_CTRL_EOFM		(1 << 13) /* EOF interrupt mask */
#define LCD_CTRL_SOFM		(1 << 12) /* SOF interrupt mask */
#define LCD_CTRL_OFUM		(1 << 11) /* Output FIFO underrun interrupt mask */
#define LCD_CTRL_IFUM0		(1 << 10) /* Input FIFO 0 underrun interrupt mask */
#define LCD_CTRL_IFUM1		(1 << 9)  /* Input FIFO 1 underrun interrupt mask */
#define LCD_CTRL_LDDM		(1 << 8)  /* LCD disable done interrupt mask */
#define LCD_CTRL_QDM		(1 << 7)  /* LCD quick disable done interrupt mask */
#define LCD_CTRL_BEDN		(1 << 6)  /* Endian selection */
#define LCD_CTRL_PEDN		(1 << 5)  /* Endian in byte:0-msb first, 1-lsb first */
#define LCD_CTRL_DIS		(1 << 4)  /* Disable indicate bit */
#define LCD_CTRL_ENA		(1 << 3)  /* LCD enable bit */
#define LCD_CTRL_BPP_BIT	0  /* Bits Per Pixel */
#define LCD_CTRL_BPP_MASK	(0x07 << LCD_CTRL_BPP_BIT)
  #define LCD_CTRL_BPP_1	(0 << LCD_CTRL_BPP_BIT) /* 1 bpp */
  #define LCD_CTRL_BPP_2	(1 << LCD_CTRL_BPP_BIT) /* 2 bpp */
  #define LCD_CTRL_BPP_4	(2 << LCD_CTRL_BPP_BIT) /* 4 bpp */
  #define LCD_CTRL_BPP_8	(3 << LCD_CTRL_BPP_BIT) /* 8 bpp */
  #define LCD_CTRL_BPP_16	(4 << LCD_CTRL_BPP_BIT) /* 15/16 bpp */
  #define LCD_CTRL_BPP_18_24	(5 << LCD_CTRL_BPP_BIT) /* 18/24/32 bpp */
#if defined(__JZ4755__) || defined(__JZ4725B__)
  #define LCD_CTRL_BPP_CMPS_24	(6 << LCD_CTRL_BPP_BIT) /* 24 compress bpp */
#endif

/* LCD Status Register */
#define LCD_STATE_QD		(1 << 7) /* Quick Disable Done */
#define LCD_STATE_EOF		(1 << 5) /* EOF Flag */
#define LCD_STATE_SOF		(1 << 4) /* SOF Flag */
#define LCD_STATE_OFU		(1 << 3) /* Output FIFO Underrun */
#define LCD_STATE_IFU0		(1 << 2) /* Input FIFO 0 Underrun */
#define LCD_STATE_IFU1		(1 << 1) /* Input FIFO 1 Underrun */
#define LCD_STATE_LDD		(1 << 0) /* LCD Disabled */

/* DMA Command Register */
#define LCD_CMD_SOFINT		(1 << 31)
#define LCD_CMD_EOFINT		(1 << 30)
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define LCD_CMD_CMD		(1 << 29) /* indicate command in slcd mode */
#endif
#define LCD_CMD_PAL		(1 << 28)
#define LCD_CMD_LEN_BIT		0
#define LCD_CMD_LEN_MASK	(0xffffff << LCD_CMD_LEN_BIT)

#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
/* OSD Configure Register */
#define LCD_OSDC_SOFM1		(1 << 15) /* Start of frame interrupt mask for foreground 1 */
#define LCD_OSDC_EOFM1		(1 << 14) /* End of frame interrupt mask for foreground 1 */
#if defined(__JZ4750__)
#define LCD_OSDC_REM1		(1 << 13) /* Real end of frame mask for foreground 1 */
#endif
#define LCD_OSDC_SOFM0		(1 << 11) /* Start of frame interrupt mask for foreground 0 */
#define LCD_OSDC_EOFM0		(1 << 10) /* End of frame interrupt mask for foreground 0 */
#if defined(__JZ4750__)
#define LCD_OSDC_REM0		(1 << 9) /* Real end of frame mask for foreground 0 */
#define LCD_OSDC_REMB		(1 << 7) /* Real end of frame mask for background */
#endif
#define LCD_OSDC_F1EN		(1 << 4) /* enable foreground 1 */
#define LCD_OSDC_F0EN		(1 << 3) /* enable foreground 0 */
#define LCD_OSDC_ALPHAEN		(1 << 2) /* enable alpha blending */
#define LCD_OSDC_ALPHAMD		(1 << 1) /* alpha blending mode */
#define LCD_OSDC_OSDEN		(1 << 0) /* OSD mode enable */

/* OSD Controll Register */
#define LCD_OSDCTRL_IPU		(1 << 15) /* input data from IPU */
#define LCD_OSDCTRL_RGB565	(0 << 4) /* foreground 1, 16bpp, 0-RGB565, 1-RGB555 */
#define LCD_OSDCTRL_RGB555	(1 << 4) /* foreground 1, 16bpp, 0-RGB565, 1-RGB555 */
#define LCD_OSDCTRL_CHANGES	(1 << 3) /* Change size flag */
#define LCD_OSDCTRL_OSDBPP_BIT	0 	 /* Bits Per Pixel of OSD Channel 1 */
#define LCD_OSDCTRL_OSDBPP_MASK	(0x7<<LCD_OSDCTRL_OSDBPP_BIT) 	 /* Bits Per Pixel of OSD Channel 1's MASK */
  #define LCD_OSDCTRL_OSDBPP_16	(4 << LCD_OSDCTRL_OSDBPP_BIT) /* RGB 15,16 bit*/
  #define LCD_OSDCTRL_OSDBPP_15_16	(4 << LCD_OSDCTRL_OSDBPP_BIT) /* RGB 15,16 bit*/
  #define LCD_OSDCTRL_OSDBPP_18_24	(5 << LCD_OSDCTRL_OSDBPP_BIT) /* RGB 18,24 bit*/
#if defined(__JZ4755__) || defined(__JZ4725B__)
  #define LCD_OSDCTRL_OSDBPP_CMPS_24	(6 << LCD_OSDCTRL_OSDBPP_BIT) /* RGB 18,24 bit*/
#endif

/* OSD State Register */
#define LCD_OSDS_SOF1		(1 << 15) /* Start of frame flag for foreground 1 */
#define LCD_OSDS_EOF1		(1 << 14) /* End of frame flag for foreground 1 */
#define LCD_OSDS_SOF0		(1 << 11) /* Start of frame flag for foreground 0 */
#define LCD_OSDS_EOF0		(1 << 10) /* End of frame flag for foreground 0 */
#define LCD_OSDS_READY		(1 << 0)  /* Read for accept the change */

/* Background Color Register */
#define LCD_BGC_RED_OFFSET	(1 << 16)  /* Red color offset */
#define LCD_BGC_RED_MASK	(0xFF<<LCD_BGC_RED_OFFSET)
#define LCD_BGC_GREEN_OFFSET	(1 << 8)   /* Green color offset */
#define LCD_BGC_GREEN_MASK	(0xFF<<LCD_BGC_GREEN_OFFSET)
#define LCD_BGC_BLUE_OFFSET	(1 << 0)   /* Blue color offset */
#define LCD_BGC_BLUE_MASK	(0xFF<<LCD_BGC_BLUE_OFFSET)

/* Foreground Color Key Register 0,1(foreground 0, foreground 1) */
#define LCD_KEY_KEYEN		(1 << 31)   /* enable color key */
#define LCD_KEY_KEYMD		(1 << 30)   /* color key mode */
#define LCD_KEY_RED_OFFSET	16  /* Red color offset */
#define LCD_KEY_RED_MASK	(0xFF<<LCD_KEY_RED_OFFSET)
#define LCD_KEY_GREEN_OFFSET	8   /* Green color offset */
#define LCD_KEY_GREEN_MASK	(0xFF<<LCD_KEY_GREEN_OFFSET)
#define LCD_KEY_BLUE_OFFSET	0   /* Blue color offset */
#define LCD_KEY_BLUE_MASK	(0xFF<<LCD_KEY_BLUE_OFFSET)
#define LCD_KEY_MASK		(LCD_KEY_RED_MASK|LCD_KEY_GREEN_MASK|LCD_KEY_BLUE_MASK)

/* IPU Restart Register */
#define LCD_IPUR_IPUREN		(1 << 31)   /* IPU restart function enable*/
#define LCD_IPUR_IPURMASK	(0xFFFFFF)   /* IPU restart value mask*/

/* RGB Control Register */
#define LCD_RGBC_RGBDM		(1 << 15)   /* enable RGB Dummy data */
#define LCD_RGBC_DMM		(1 << 14)   /* RGB Dummy mode */
#define LCD_RGBC_YCC		(1 << 8)    /* RGB to YCC */
#define LCD_RGBC_ODDRGB_BIT	4	/* odd line serial RGB data arrangement */
#define LCD_RGBC_ODDRGB_MASK	(0x7<<LCD_RGBC_ODDRGB_BIT)
  #define LCD_RGBC_ODD_RGB	0
  #define LCD_RGBC_ODD_RBG	1
  #define LCD_RGBC_ODD_GRB	2
  #define LCD_RGBC_ODD_GBR	3
  #define LCD_RGBC_ODD_BRG	4
  #define LCD_RGBC_ODD_BGR	5
#define LCD_RGBC_EVENRGB_BIT	0	/* even line serial RGB data arrangement */
#define LCD_RGBC_EVENRGB_MASK	(0x7<<LCD_RGBC_EVENRGB_BIT)
  #define LCD_RGBC_EVEN_RGB	0
  #define LCD_RGBC_EVEN_RBG	1
  #define LCD_RGBC_EVEN_GRB	2
  #define LCD_RGBC_EVEN_GBR	3
  #define LCD_RGBC_EVEN_BRG	4
  #define LCD_RGBC_EVEN_BGR	5

/* Foreground XY Position Register */
#define LCD_XYP_YPOS_BIT	16  /* Y position bit of foreground 0 or 1 */
#define LCD_XYP_YPOS_MASK	(0xffff << LCD_XYP_YPOS_BIT)
#define LCD_XYP_XPOS_BIT	0   /* X position bit of foreground 0 or 1 */
#define LCD_XYP_XPOS_MASK	(0xffff << LCD_XYP_XPOS_BIT)

/* DMA Offsize Register 0,1 */

/* DMA Page Width Register 0,1 */

/* DMA Command Counter Register 0,1 */

/* Foreground 0,1 Size Register */
#define LCD_DESSIZE_HEIGHT_BIT	16  /* height of foreground 1 */
#define LCD_DESSIZE_HEIGHT_MASK	(0xffff << LCD_DESSIZE_HEIGHT_BIT)
#define LCD_DESSIZE_WIDTH_BIT	0  /* width of foreground 1 */
#define LCD_DESSIZE_WIDTH_MASK	(0xffff << LCD_DESSIZE_WIDTH_BIT)

#endif /* defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__) */


/*
 * PIN Setting
 */
#if defined(__JZ4740__) || defined(__JZ4725__)
#define __gpio_as_lcd_16bit()			\
do {						\
	REG_GPIO_PXFUNS(2) = 0x003cffff;	\
	REG_GPIO_PXSELC(2) = 0x003cffff;	\
	REG_GPIO_PXPES(2) = 0x003cffff;		\
} while (0)

#define __gpio_as_lcd_18bit()			\
do {						\
	REG_GPIO_PXFUNS(2) = 0x003fffff;	\
	REG_GPIO_PXSELC(2) = 0x003fffff;	\
	REG_GPIO_PXPES(2) = 0x003fffff;		\
} while (0)

#define __gpio_as_lcd_special()			\
do {						\
	REG_GPIO_PXFUNS(1) = 0x00060000;	\
	REG_GPIO_PXSELC(1) = 0x00060000;	\
	REG_GPIO_PXPES(1)  = 0x00060000;	\
	REG_GPIO_PXFUNS(2) = 0x00c00000;	\
	REG_GPIO_PXSELC(2) = 0x00c00000;	\
	REG_GPIO_PXPES(2)  = 0x00c00000;	\
} while (0)
#elif defined(__JZ4750__)

#define __gpio_as_lcd_8bit()			\
do {						\
	REG_GPIO_PXFUNS(3) = 0x003c00ff;	\
	REG_GPIO_PXSELC(3) = 0x003c00ff;	\
	REG_GPIO_PXPES(3) = 0x003c00ff;		\
} while (0)

#define __gpio_as_lcd_16bit()			\
do {						\
	REG_GPIO_PXFUNS(3) = 0x003cffff;	\
	REG_GPIO_PXSELC(3) = 0x003cffff;	\
	REG_GPIO_PXPES(3) = 0x003cffff;		\
} while (0)

#define __gpio_as_lcd_18bit()			\
do {						\
	REG_GPIO_PXFUNS(3) = 0x003fffff;	\
	REG_GPIO_PXSELC(3) = 0x003fffff;	\
	REG_GPIO_PXPES(3) = 0x003fffff;		\
} while (0)

#define __gpio_as_lcd_24bit()			\
do {						\
	REG_GPIO_PXFUNS(3) = 0x003fffff;	\
	REG_GPIO_PXSELC(3) = 0x003fffff;	\
	REG_GPIO_PXPES(3)  = 0x003fffff;	\
	REG_GPIO_PXFUNS(3) = 0x03c00000;	\
	REG_GPIO_PXSELS(3) = 0x03c00000;	\
	REG_GPIO_PXPES(3)  = 0x03c00000;	\
	REG_GPIO_PXFUNS(5) = 0x000c0000;	\
	REG_GPIO_PXSELS(5) = 0x000c0000;	\
	REG_GPIO_PXPES(5)  = 0x000c0000;	\
} while (0)

#define __gpio_as_lcd_special()			\
do {						\
	REG_GPIO_PXFUNS(3) = 0x03C00000;	\
	REG_GPIO_PXSELC(3) = 0x03C00000;	\
	REG_GPIO_PXPES(3)  = 0x03C00000;	\
} while (0)

#elif defined(__JZ4755__) || defined(__JZ4725B__)

#define __gpio_as_lcd_8bit()			\
do {						\
	REG_GPIO_PXFUNS(3) = 0x003c00ff;	\
	REG_GPIO_PXTRGC(3) = 0x003c00ff;	\
	REG_GPIO_PXSELC(3) = 0x003c00ff;	\
	REG_GPIO_PXPES(3) = 0x003c00ff;		\
} while (0)

#define __gpio_as_lcd_16bit()			\
do {						\
	REG_GPIO_PXFUNS(3) = 0x003cffff;	\
	REG_GPIO_PXTRGC(3) = 0x003cffff;	\
	REG_GPIO_PXSELC(3) = 0x003cffff;	\
	REG_GPIO_PXPES(3) = 0x003cffff;		\
} while (0)

#define __gpio_as_lcd_18bit()			\
do {						\
	REG_GPIO_PXFUNS(3) = 0x003fffff;	\
	REG_GPIO_PXTRGC(3) = 0x003fffff;	\
	REG_GPIO_PXSELC(3) = 0x003fffff;	\
	REG_GPIO_PXPES(3) = 0x003fffff;		\
} while (0)

#define __gpio_as_lcd_24bit()			\
do {						\
	REG_GPIO_PXFUNS(3) = 0x003fffff;	\
	REG_GPIO_PXTRGC(3) = 0x003fffff;	\
	REG_GPIO_PXSELC(3) = 0x003fffff;	\
	REG_GPIO_PXPES(3)  = 0x003fffff;	\
	REG_GPIO_PXFUNS(3) = 0x03c00000;	\
	REG_GPIO_PXTRGC(3) = 0x03c00000;	\
	REG_GPIO_PXSELS(3) = 0x03c00000;	\
	REG_GPIO_PXPES(3)  = 0x03c00000;	\
} while (0)

#define __gpio_as_lcd_special()			\
do {						\
	REG_GPIO_PXFUNS(3) = 0x03C00000;	\
	REG_GPIO_PXTRGC(3) = 0x03C00000;	\
	REG_GPIO_PXSELC(3) = 0x03C00000;	\
	REG_GPIO_PXPES(3)  = 0x03C00000;	\
} while (0)

#endif

/*
 * OPs
 */
/***************************************************************************
 * LCD
 ***************************************************************************/
#define __lcd_as_smart_lcd() 		( REG_LCD_CFG |= ( LCD_CFG_LCDPIN_SLCD | LCD_CFG_MODE_SLCD))
#define __lcd_as_general_lcd() 		( REG_LCD_CFG &= ~( LCD_CFG_LCDPIN_SLCD | LCD_CFG_MODE_SLCD))

#if defined(__JZ4740__) || defined(__JZ4725__)
#include <jz/jz_lcd_ops4.h>
#elif defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#include <jz/jz_lcd_ops5.h>
#endif
#endif /* __JZ_LCD_H__ */
