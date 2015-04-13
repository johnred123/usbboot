#ifndef __JZ_IPU_H__
#define __JZ_IPU_H__
#ifndef __JZ_BASE_H__
#include <jz/jz_base.h>
#endif
/*************************************************************************
 * IPU (Image Processing Unit)
 *************************************************************************/

#define IPU_CTRL	(IPU_BASE + 0x0) /* IPU Control Register */
#define IPU_STATUS	(IPU_BASE + 0x4) /* IPU Status Register */
#define IPU_D_FMT	(IPU_BASE + 0x8) /* Data Format Register */
#define IPU_Y_ADDR	(IPU_BASE + 0xc) /* Input Y or YUV422 Packaged Data Address Register */
#define IPU_U_ADDR	(IPU_BASE + 0x10) /* Input U Data Address Register */
#define IPU_V_ADDR	(IPU_BASE + 0x14) /* Input V Data Address Register */
#define IPU_IN_FM_GS	(IPU_BASE + 0x18) /* Input Geometric Size Register */
#define IPU_Y_STRIDE	(IPU_BASE + 0x1c) /* Input Y Data Line Stride Register */
#define IPU_UV_STRIDE	(IPU_BASE + 0x20) /* Input UV Data Line Stride Register */
#define IPU_OUT_ADDR	(IPU_BASE + 0x24) /* Output Frame Start Address Register */
#define IPU_OUT_GS	(IPU_BASE + 0x28) /* Output Geometric Size Register */
#define IPU_OUT_STRIDE	(IPU_BASE + 0x2c) /* Output Data Line Stride Register */
#define IPU_RSZ_COEF_INDEX	(IPU_BASE + 0x30) /* Resize Coefficients Table Index Register */
#define IPU_CSC_CO_COEF	(IPU_BASE + 0x34) /* CSC C0 Coefficient Register */
#define IPU_CSC_C1_COEF	(IPU_BASE + 0x38) /* CSC C1 Coefficient Register */
#define IPU_CSC_C2_COEF	(IPU_BASE + 0x3c) /* CSC C2 Coefficient Register */
#define IPU_CSC_C3_COEF	(IPU_BASE + 0x40) /* CSC C3 Coefficient Register */
#define IPU_CSC_C4_COEF	(IPU_BASE + 0x44) /* CSC C4 Coefficient Register */
#define IPU_HRSZ_LUT_BASE 	(IPU_BASE + 0x48) /* Horizontal Resize Coefficients Look Up Table Register group */
#define IPU_VRSZ_LUT_BASE 	(IPU_BASE + 0x4c) /* Virtical Resize Coefficients Look Up Table Register group */
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define IPU_CSC_OFSET_PARA	(IPU_BASE + 0x50) /* CSC Offset Parameter Register */
#define IPU_Y_PHY_T_ADDR	(IPU_BASE + 0x54) /* Input Y Physical Table Address Register */
#define IPU_U_PHY_T_ADDR	(IPU_BASE + 0x58) /* Input U Physical Table Address Register */
#define IPU_V_PHY_T_ADDR	(IPU_BASE + 0x5c) /* Input V Physical Table Address Register */
#define IPU_OUT_PHY_T_ADDR	(IPU_BASE + 0x60) /* Output Physical Table Address Register */
#endif

#define REG_IPU_CTRL			REG32(IPU_CTRL)
#define REG_IPU_STATUS			REG32(IPU_STATUS)
#define REG_IPU_D_FMT			REG32(IPU_D_FMT)
#define REG_IPU_Y_ADDR			REG32(IPU_Y_ADDR)
#define REG_IPU_U_ADDR			REG32(IPU_U_ADDR)
#define REG_IPU_V_ADDR			REG32(IPU_V_ADDR)
#define REG_IPU_IN_FM_GS		REG32(IPU_IN_FM_GS)
#define REG_IPU_Y_STRIDE		REG32(IPU_Y_STRIDE)
#define REG_IPU_UV_STRIDE		REG32(IPU_UV_STRIDE)
#define REG_IPU_OUT_ADDR		REG32(IPU_OUT_ADDR)
#define REG_IPU_OUT_GS			REG32(IPU_OUT_GS)
#define REG_IPU_OUT_STRIDE		REG32(IPU_OUT_STRIDE)
#define REG_IPU_RSZ_COEF_INDEX		REG32(IPU_COEF_INDEX)
#define REG_IPU_CSC_CO_COEF		REG32(IPU_CSC_C0_COEF)
#define REG_IPU_CSC_C1_COEF		REG32(IPU_CSC_C1_COEF)
#define REG_IPU_CSC_C2_COEF		REG32(IPU_CSC_C2_COEF)
#define REG_IPU_CSC_C3_COEF		REG32(IPU_CSC_C3_COEF)
#define REG_IPU_CSC_C4_COEF		REG32(IPU_CSC_C4_COEF)
#define REG_IPU_HRSZ_LUT_BASE 		REG32(IPU_HRSZ_LUT_BASE)
#define REG_IPU_VRSZ_LUT_BASE 		REG32(IPU_VRSZ_LUT_BASE)
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define REG_IPU_CSC_OFSET_PARA		REG32(IPU_CSC_OFFSET_PARA)
#define REG_IPU_Y_PHY_T_ADDR		REG32(IPU_Y_PHY_T_ADDR)
#define REG_IPU_U_PHY_T_ADDR		REG32(IPU_U_PHY_T_ADDR)
#define REG_IPU_V_PHY_T_ADDR		REG32(IPU_V_PHY_T_ADDR)
#define REG_IPU_OUT_PHY_T_ADDR		REG32(IPU_OUT_PHY_T_ADDR)
#endif

/* IPU Control */

#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define IPU_CTRL_DFIX_SEL			(1 << 17)
#define IPU_CTRL_FIELD_SEL			(1 << 16)
#define IPU_CTRL_FIELD_CONF_EN			(1 << 15)
#define IPU_CTRL_DISP_SEL			(1 << 14)
#define IPU_CTRL_DPAGE_MAP			(1 << 13)
#define IPU_CTRL_SPAGE_MAP 			(1 << 12)
#define IPU_CTRL_LCDC_SEL			(1 << 11)
#define IPU_CTRL_SPKG_SEL			(1 << 10)
#define IPU_CTRL_IPU_RST			(1 << 6)
#define IPU_CTRL_FM_IRQ_EN			(1 << 5)
#define IPU_CTRL_CSC_EN				(1 << 4)
#define IPU_CTRL_VRSZ_EN			(1 << 3)
#define IPU_CTRL_HRSZ_EN			(1 << 2)
#define IPU_CTRL_IPU_RUN			(1 << 1)
#endif
#if defined(__JZ4740__) || defined(__JZ4725__)
#define IPU_CTRL_IPU_RST			(1 << 3)
#define IPU_CTRL_FM_IRQ_EN			(1 << 2)
#define IPU_CTRL_RSZ_EN				(1 << 1)
#endif
#define IPU_CTRL_V_SCALE			(1 << 9)
#define IPU_CTRL_H_SCALE			(1 << 8)
#define IPU_CTRL_CHIP_EN			(1 << 0)

/* IPU Status */
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define IPU_STAT_SIZE_ERR			(1 << 2)
#define IPU_STAT_FMT_ERR			(1 << 1)
#endif
#define IPU_STAT_OUT_END			(1 << 0)

/* IPU Data Format */

#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define IPU_D_FMT_RGB_OUT_888_FMT		(1 << 24)

#define IPU_D_FMT_RGB_OUT_OFT_MASK		(0x7 << 21)
#define IPU_D_FMT_RGB_OUT_OFT_RGB		(0 << 21)
#define IPU_D_FMT_RGB_OUT_OFT_RBG		(1 << 21)
#define IPU_D_FMT_RGB_OUT_OFT_GBR		(2 << 21)
#define IPU_D_FMT_RGB_OUT_OFT_GRB		(3 << 21)
#define IPU_D_FMT_RGB_OUT_OFT_BRG		(4 << 21)
#define IPU_D_FMT_RGB_OUT_OFT_BGR		(5 << 21)

#define IPU_D_FMT_OUT_FMT_MASK			(0x3 << 19)
#define IPU_D_FMT_OUT_FMT_RGB555		(0 << 19)
#define IPU_D_FMT_OUT_FMT_RGB565		(1 << 19)
#define IPU_D_FMT_OUT_FMT_RGB888		(2 << 19)
#define IPU_D_FMT_OUT_FMT_YUV422		(3 << 19)

#define IPU_D_FMT_YUV_PKG_OUT_OFT_MASK		(0x7 << 16)
#define IPU_D_FMT_YUV_PKG_OUT_OFT_Y1UY0V	(0 << 16)
#define IPU_D_FMT_YUV_PKG_OUT_OFT_Y1VY0U	(1 << 16)
#define IPU_D_FMT_YUV_PKG_OUT_OFT_UY1VY0	(2 << 16)
#define IPU_D_FMT_YUV_PKG_OUT_OFT_VY1UY0	(3 << 16)
#define IPU_D_FMT_YUV_PKG_OUT_OFT_Y0UY1V	(4 << 16)
#define IPU_D_FMT_YUV_PKG_OUT_OFT_Y0VY1U	(5 << 16)
#define IPU_D_FMT_YUV_PKG_OUT_OFT_UY0VY1	(6 << 16)
#define IPU_D_FMT_YUV_PKG_OUT_OFT_VY0UY1	(7 << 16)

#define IPU_D_FMT_IN_OFT_MASK			(0x3 << 2)
#define IPU_D_FMT_IN_OFT_Y1UY0V			(0 << 2)
#define IPU_D_FMT_IN_OFT_Y1VY0U			(1 << 2)
#define IPU_D_FMT_IN_OFT_UY1VY0			(2 << 2)
#define IPU_D_FMT_IN_OFT_VY1UY0			(3 << 2)
#endif
#if defined(__JZ4740__) || defined(__JZ4725__)
#define IPU_D_FMT_OUT_FMT_MASK			(0x3 << 16)
#define IPU_D_FMT_OUT_FMT_RGB555		(0 << 16)
#define IPU_D_FMT_OUT_FMT_RGB565		(1 << 16)
#define IPU_D_FMT_OUT_FMT_RGB888		(2 << 16)
#endif
#define IPU_D_FMT_IN_FMT_MASK			(0x3 << 0)
#define IPU_D_FMT_IN_FMT_YUV420			(0 << 0)
#define IPU_D_FMT_IN_FMT_YUV422			(1 << 0)
#define IPU_D_FMT_IN_FMT_YUV444			(2 << 0)
#define IPU_D_FMT_IN_FMT_YUV411			(3 << 0)

/* Input Geometric Size Register */
#define IPU_IN_FM_GS_W_MASK			(0xFFF)
#define IPU_IN_FM_GS_W(n)			((n) << 16)

#define IPU_IN_FM_GS_H_MASK			(0xFFF)
#define IPU_IN_FM_GS_H(n)			((n) << 0)

/* Input UV Data Line Stride Register */
#define IPU_UV_STRIDE_U_S_MASK			(0x1FFF)
#define IPU_UV_STRIDE_U_S(n) 			((n) << 16)

#define IPU_UV_STRIDE_V_S_MASK			(0x1FFF)
#define IPU_UV_STRIDE_V_S(n)			((n) << 0)

/* Output Geometric Size Register */
#define IPU_OUT_GS_W_MASK			(0x7FFF)
#define IPU_OUT_GS_W(n)				((n) << 16)

#define IPU_OUT_GS_H_MASK			(0x1FFF)
#define IPU_OUT_GS_H(n)				((n) << 0)

/* Resize Coefficients Table Index Register */
#define IPU_RSZ_COEF_INDEX_HE_IDX_MASK		(0x1F)
#define IPU_RSZ_COEF_INDEX_HE_IDX(n)		((n) << 16)

#define IPU_RSZ_COEF_INDEX_VE_IDX_MASK		(0x1F)
#define IPU_RSZ_COEF_INDEX_VE_IDX(n)		((n) << 0)

/* Resize Coefficients Look Up Table Register group */
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define IPU_HRSZ_COEF_LUT_START			(1 << 12)
#endif
#define IPU_HRSZ_COEF_LUT_W_COEF_MASK		(0x3FF)
#define IPU_HRSZ_COEF_LUT_W_COEF(n)		((n) << 2)

#define IPU_HRSZ_COEF_LUT_IN_EN			(1 << 1)
#define IPU_HRSZ_COEF_LUT_OUT_EN		(1 << 0)

#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define IPU_VRSZ_COEF_LUT_START			(1 << 12)
#endif

#define IPU_VRSZ_COEF_LUT_W_COEF_MASK		(0x3FF)
#define IPU_VRSZ_COEF_LUT_W_COEF(n)		((n) << 2)

#define IPU_VRSZ_COEF_LUT_IN_EN			(1 << 1)
#define IPU_VRSZ_COEF_LUT_OUT_EN		(1 << 0)

#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
/* CSC Offset Parameter Register */
#define IPU_CSC_OFFSET_PARA_CHROM_OF_MASK	(0xFF)
#define IPU_CSC_OFFSET_PARA_CHROM_OF(n)		((n) << 16)

#define IPU_CSC_OFFSET_LUMA_OF_MASK		(0xFF)
#define IPU_CSC_OFFSET_LUMA_OF(n)		((n) << 0)
#endif
/*
 * OPs
 */
#endif /* __JZ_IPU_H__ */
