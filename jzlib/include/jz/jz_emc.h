#ifndef __JZ_EMC_H__
#define __JZ_EMC_H__
#ifndef __JZ_BASE_H__
#include <jz/jz_base.h>
#endif

/*************************************************************************
 * EMC (External Memory Controller)
 *************************************************************************/
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define EMC_BCR    	(EMC_BASE + 0x00)  /* Bus Control Register */
#endif
#define EMC_SMCR0	(EMC_BASE + 0x10)  /* Static Memory Control Register 0 */
#define EMC_SMCR1	(EMC_BASE + 0x14)  /* Static Memory Control Register 1 */
#define EMC_SMCR2	(EMC_BASE + 0x18)  /* Static Memory Control Register 2 */
#define EMC_SMCR3	(EMC_BASE + 0x1c)  /* Static Memory Control Register 3 */
#define EMC_SMCR4	(EMC_BASE + 0x20)  /* Static Memory Control Register 4 */
#define EMC_SACR0	(EMC_BASE + 0x30)  /* Static Memory Bank 0 Addr Config Reg */
#define EMC_SACR1	(EMC_BASE + 0x34)  /* Static Memory Bank 1 Addr Config Reg */
#define EMC_SACR2	(EMC_BASE + 0x38)  /* Static Memory Bank 2 Addr Config Reg */
#define EMC_SACR3	(EMC_BASE + 0x3c)  /* Static Memory Bank 3 Addr Config Reg */
#define EMC_SACR4	(EMC_BASE + 0x40)  /* Static Memory Bank 4 Addr Config Reg */

#define EMC_NFCSR	(EMC_BASE + 0x050) /* NAND Flash Control/Status Register */

#define EMC_DMCR	(EMC_BASE + 0x80)  /* DRAM Control Register */
#define EMC_RTCSR	(EMC_BASE + 0x84)  /* Refresh Time Control/Status Register */
#define EMC_RTCNT	(EMC_BASE + 0x88)  /* Refresh Timer Counter */
#define EMC_RTCOR	(EMC_BASE + 0x8c)  /* Refresh Time Constant Register */
#define EMC_DMAR0	(EMC_BASE + 0x90)  /* SDRAM Bank 0 Addr Config Register */
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define EMC_DMAR1	(EMC_BASE + 0x94)  /* SDRAM Bank 1 Addr Config Register */
#endif
#if defined(__JZ4740__) || defined(__JZ4725__)
#define EMC_NFECR	(EMC_BASE + 0x100) /* NAND Flash ECC Control Register */
#define EMC_NFECC	(EMC_BASE + 0x104) /* NAND Flash ECC Data Register */
#define EMC_NFPAR0	(EMC_BASE + 0x108) /* NAND Flash RS Parity 0 Register */
#define EMC_NFPAR1	(EMC_BASE + 0x10c) /* NAND Flash RS Parity 1 Register */
#define EMC_NFPAR2	(EMC_BASE + 0x110) /* NAND Flash RS Parity 2 Register */
#define EMC_NFINTS	(EMC_BASE + 0x114) /* NAND Flash Interrupt Status Register */
#define EMC_NFINTE	(EMC_BASE + 0x118) /* NAND Flash Interrupt Enable Register */
#define EMC_NFERR0	(EMC_BASE + 0x11c) /* NAND Flash RS Error Report 0 Register */
#define EMC_NFERR1	(EMC_BASE + 0x120) /* NAND Flash RS Error Report 1 Register */
#define EMC_NFERR2	(EMC_BASE + 0x124) /* NAND Flash RS Error Report 2 Register */
#define EMC_NFERR3	(EMC_BASE + 0x128) /* NAND Flash RS Error Report 3 Register */
#endif
#define EMC_SDMR0	(EMC_BASE + 0xa000) /* Mode Register of SDRAM bank 0 */

#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define REG_EMC_BCR 	REG32(EMC_BCR)
#endif
#define REG_EMC_SMCR0	REG32(EMC_SMCR0)
#define REG_EMC_SMCR1	REG32(EMC_SMCR1)
#define REG_EMC_SMCR2	REG32(EMC_SMCR2)
#define REG_EMC_SMCR3	REG32(EMC_SMCR3)
#define REG_EMC_SMCR4	REG32(EMC_SMCR4)
#define REG_EMC_SACR0	REG32(EMC_SACR0)
#define REG_EMC_SACR1	REG32(EMC_SACR1)
#define REG_EMC_SACR2	REG32(EMC_SACR2)
#define REG_EMC_SACR3	REG32(EMC_SACR3)
#define REG_EMC_SACR4	REG32(EMC_SACR4)
#define REG_EMC_NFCSR	REG32(EMC_NFCSR)
#define REG_EMC_DMCR	REG32(EMC_DMCR)
#define REG_EMC_RTCSR	REG16(EMC_RTCSR)
#define REG_EMC_RTCNT	REG16(EMC_RTCNT)
#define REG_EMC_RTCOR	REG16(EMC_RTCOR)
#define REG_EMC_DMAR0	REG32(EMC_DMAR0)
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define REG_EMC_DMAR1	REG32(EMC_DMAR1)
#endif
#if defined(__JZ4740__) || defined(__JZ4725__)
#define REG_EMC_NFECR	REG32(EMC_NFECR)
#define REG_EMC_NFECC	REG32(EMC_NFECC)
#define REG_EMC_NFPAR0	REG32(EMC_NFPAR0)
#define REG_EMC_NFPAR1	REG32(EMC_NFPAR1)
#define REG_EMC_NFPAR2	REG32(EMC_NFPAR2)
#define REG_EMC_NFINTS	REG32(EMC_NFINTS)
#define REG_EMC_NFINTE	REG32(EMC_NFINTE)
#define REG_EMC_NFERR0	REG32(EMC_NFERR0)
#define REG_EMC_NFERR1	REG32(EMC_NFERR1)
#define REG_EMC_NFERR2	REG32(EMC_NFERR2)
#define REG_EMC_NFERR3	REG32(EMC_NFERR3)
#endif

#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
/* Bus Control Register */
#define EMC_BCR_BT_SEL_BIT      30
#define EMC_BCR_BT_SEL_MASK     (0x3 << EMC_BCR_BT_SEL_BIT)
#define EMC_BCR_PK_SEL          (1 << 24)
#define EMC_BCR_BSR_MASK          (1 << 2)  /* Nand and SDRAM Bus Share Select: 0, share; 1, unshare */
  #define EMC_BCR_BSR_SHARE       (0 << 2)
  #define EMC_BCR_BSR_UNSHARE     (1 << 2)
#define EMC_BCR_BRE             (1 << 1)
#define EMC_BCR_ENDIAN          (1 << 0)
#endif

/* Static Memory Control Register */
#define EMC_SMCR_STRV_BIT	24
#define EMC_SMCR_STRV_MASK	(0x0f << EMC_SMCR_STRV_BIT)
#define EMC_SMCR_TAW_BIT	20
#define EMC_SMCR_TAW_MASK	(0x0f << EMC_SMCR_TAW_BIT)
#define EMC_SMCR_TBP_BIT	16
#define EMC_SMCR_TBP_MASK	(0x0f << EMC_SMCR_TBP_BIT)
#define EMC_SMCR_TAH_BIT	12
#define EMC_SMCR_TAH_MASK	(0x07 << EMC_SMCR_TAH_BIT)
#define EMC_SMCR_TAS_BIT	8
#define EMC_SMCR_TAS_MASK	(0x07 << EMC_SMCR_TAS_BIT)
#define EMC_SMCR_BW_BIT		6
#define EMC_SMCR_BW_MASK	(0x03 << EMC_SMCR_BW_BIT)
  #define EMC_SMCR_BW_8BIT	(0 << EMC_SMCR_BW_BIT)
  #define EMC_SMCR_BW_16BIT	(1 << EMC_SMCR_BW_BIT)
  #define EMC_SMCR_BW_32BIT	(2 << EMC_SMCR_BW_BIT)
#define EMC_SMCR_BCM		(1 << 3)
#define EMC_SMCR_BL_BIT		1
#define EMC_SMCR_BL_MASK	(0x03 << EMC_SMCR_BL_BIT)
  #define EMC_SMCR_BL_4		(0 << EMC_SMCR_BL_BIT)
  #define EMC_SMCR_BL_8		(1 << EMC_SMCR_BL_BIT)
  #define EMC_SMCR_BL_16	(2 << EMC_SMCR_BL_BIT)
  #define EMC_SMCR_BL_32	(3 << EMC_SMCR_BL_BIT)
#define EMC_SMCR_SMT		(1 << 0)

/* Static Memory Bank Addr Config Reg */
#define EMC_SACR_BASE_BIT	8
#define EMC_SACR_BASE_MASK	(0xff << EMC_SACR_BASE_BIT)
#define EMC_SACR_MASK_BIT	0
#define EMC_SACR_MASK_MASK	(0xff << EMC_SACR_MASK_BIT)

/* NAND Flash Control/Status Register */
#define EMC_NFCSR_NFCE4		(1 << 7) /* NAND Flash Enable */
#define EMC_NFCSR_NFE4		(1 << 6) /* NAND Flash FCE# Assertion Enable */
#define EMC_NFCSR_NFCE3		(1 << 5)
#define EMC_NFCSR_NFE3		(1 << 4)
#define EMC_NFCSR_NFCE2		(1 << 3)
#define EMC_NFCSR_NFE2		(1 << 2)
#define EMC_NFCSR_NFCE1		(1 << 1)
#define EMC_NFCSR_NFE1		(1 << 0)

#if defined(__JZ4740__) || defined(__JZ4725__)
/* NAND Flash ECC Control Register */
#define EMC_NFECR_PRDY		(1 << 4) /* Parity Ready */
#define EMC_NFECR_RS_DECODING	(0 << 3) /* RS is in decoding phase */
#define EMC_NFECR_RS_ENCODING	(1 << 3) /* RS is in encoding phase */
#define EMC_NFECR_HAMMING	(0 << 2) /* Select HAMMING Correction Algorithm */
#define EMC_NFECR_RS		(1 << 2) /* Select RS Correction Algorithm */
#define EMC_NFECR_ERST		(1 << 1) /* ECC Reset */
#define EMC_NFECR_ECCE		(1 << 0) /* ECC Enable */

/* NAND Flash ECC Data Register */
#define EMC_NFECC_ECC2_BIT	16
#define EMC_NFECC_ECC2_MASK	(0xff << EMC_NFECC_ECC2_BIT)
#define EMC_NFECC_ECC1_BIT	8
#define EMC_NFECC_ECC1_MASK	(0xff << EMC_NFECC_ECC1_BIT)
#define EMC_NFECC_ECC0_BIT	0
#define EMC_NFECC_ECC0_MASK	(0xff << EMC_NFECC_ECC0_BIT)

/* NAND Flash Interrupt Status Register */
#define EMC_NFINTS_ERRCNT_BIT	29       /* Error Count */
#define EMC_NFINTS_ERRCNT_MASK	(0x7 << EMC_NFINTS_ERRCNT_BIT)
#define EMC_NFINTS_PADF		(1 << 4) /* Padding Finished */
#define EMC_NFINTS_DECF		(1 << 3) /* Decoding Finished */
#define EMC_NFINTS_ENCF		(1 << 2) /* Encoding Finished */
#define EMC_NFINTS_UNCOR	(1 << 1) /* Uncorrectable Error Occurred */
#define EMC_NFINTS_ERR		(1 << 0) /* Error Occurred */

/* NAND Flash Interrupt Enable Register */
#define EMC_NFINTE_PADFE	(1 << 4) /* Padding Finished Interrupt Enable */
#define EMC_NFINTE_DECFE	(1 << 3) /* Decoding Finished Interrupt Enable */
#define EMC_NFINTE_ENCFE	(1 << 2) /* Encoding Finished Interrupt Enable */
#define EMC_NFINTE_UNCORE	(1 << 1) /* Uncorrectable Error Occurred Intr Enable */
#define EMC_NFINTE_ERRE		(1 << 0) /* Error Occurred Interrupt */

/* NAND Flash RS Error Report Register */
#define EMC_NFERR_INDEX_BIT	16       /* Error Symbol Index */
#define EMC_NFERR_INDEX_MASK	(0x1ff << EMC_NFERR_INDEX_BIT)
#define EMC_NFERR_MASK_BIT	0        /* Error Symbol Value */
#define EMC_NFERR_MASK_MASK	(0x1ff << EMC_NFERR_MASK_BIT)
#endif

/* DRAM Control Register */
#define EMC_DMCR_BW_BIT		31
#define EMC_DMCR_BW		(1 << EMC_DMCR_BW_BIT)
#define EMC_DMCR_CA_BIT		26
#define EMC_DMCR_CA_MASK	(0x07 << EMC_DMCR_CA_BIT)
  #define EMC_DMCR_CA_8		(0 << EMC_DMCR_CA_BIT)
  #define EMC_DMCR_CA_9		(1 << EMC_DMCR_CA_BIT)
  #define EMC_DMCR_CA_10	(2 << EMC_DMCR_CA_BIT)
  #define EMC_DMCR_CA_11	(3 << EMC_DMCR_CA_BIT)
  #define EMC_DMCR_CA_12	(4 << EMC_DMCR_CA_BIT)
#define EMC_DMCR_RMODE		(1 << 25)
#define EMC_DMCR_RFSH		(1 << 24)
#define EMC_DMCR_MRSET		(1 << 23)
#define EMC_DMCR_RA_BIT		20
#define EMC_DMCR_RA_MASK	(0x03 << EMC_DMCR_RA_BIT)
  #define EMC_DMCR_RA_11	(0 << EMC_DMCR_RA_BIT)
  #define EMC_DMCR_RA_12	(1 << EMC_DMCR_RA_BIT)
  #define EMC_DMCR_RA_13	(2 << EMC_DMCR_RA_BIT)
#define EMC_DMCR_BA_BIT		19
#define EMC_DMCR_BA		(1 << EMC_DMCR_BA_BIT)
#define EMC_DMCR_PDM		(1 << 18)
#define EMC_DMCR_EPIN		(1 << 17)
#define EMC_DMCR_MBSEL		(1 << 16)
#define EMC_DMCR_TRAS_BIT	13
#define EMC_DMCR_TRAS_MASK	(0x07 << EMC_DMCR_TRAS_BIT)
#define EMC_DMCR_RCD_BIT	11
#define EMC_DMCR_RCD_MASK	(0x03 << EMC_DMCR_RCD_BIT)
#define EMC_DMCR_TPC_BIT	8
#define EMC_DMCR_TPC_MASK	(0x07 << EMC_DMCR_TPC_BIT)
#define EMC_DMCR_TRWL_BIT	5
#define EMC_DMCR_TRWL_MASK	(0x03 << EMC_DMCR_TRWL_BIT)
#define EMC_DMCR_TRC_BIT	2
#define EMC_DMCR_TRC_MASK	(0x07 << EMC_DMCR_TRC_BIT)
#define EMC_DMCR_TCL_BIT	0
#define EMC_DMCR_TCL_MASK	(0x03 << EMC_DMCR_TCL_BIT)

/* Refresh Time Control/Status Register */
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
#define EMC_RTCSR_SFR		(1 << 8)    /* self refresh flag */
#endif
#define EMC_RTCSR_CMF		(1 << 7)
#define EMC_RTCSR_CKS_BIT	0
#define EMC_RTCSR_CKS_MASK	(0x07 << EMC_RTCSR_CKS_BIT)
  #define EMC_RTCSR_CKS_DISABLE	(0 << EMC_RTCSR_CKS_BIT)
  #define EMC_RTCSR_CKS_4	(1 << EMC_RTCSR_CKS_BIT)
  #define EMC_RTCSR_CKS_16	(2 << EMC_RTCSR_CKS_BIT)
  #define EMC_RTCSR_CKS_64	(3 << EMC_RTCSR_CKS_BIT)
  #define EMC_RTCSR_CKS_256	(4 << EMC_RTCSR_CKS_BIT)
  #define EMC_RTCSR_CKS_1024	(5 << EMC_RTCSR_CKS_BIT)
  #define EMC_RTCSR_CKS_2048	(6 << EMC_RTCSR_CKS_BIT)
  #define EMC_RTCSR_CKS_4096	(7 << EMC_RTCSR_CKS_BIT)

/* SDRAM Bank Address Configuration Register */
#define EMC_DMAR_BASE_BIT	8
#define EMC_DMAR_BASE_MASK	(0xff << EMC_DMAR_BASE_BIT)
#define EMC_DMAR_MASK_BIT	0
#define EMC_DMAR_MASK_MASK	(0xff << EMC_DMAR_MASK_BIT)

/* Mode Register of SDRAM bank 0 */
#define EMC_SDMR_BM		(1 << 9) /* Write Burst Mode */
#define EMC_SDMR_OM_BIT		7        /* Operating Mode */
#define EMC_SDMR_OM_MASK	(3 << EMC_SDMR_OM_BIT)
  #define EMC_SDMR_OM_NORMAL	(0 << EMC_SDMR_OM_BIT)
#define EMC_SDMR_CAS_BIT	4        /* CAS Latency */
#define EMC_SDMR_CAS_MASK	(7 << EMC_SDMR_CAS_BIT)
  #define EMC_SDMR_CAS_1	(1 << EMC_SDMR_CAS_BIT)
  #define EMC_SDMR_CAS_2	(2 << EMC_SDMR_CAS_BIT)
  #define EMC_SDMR_CAS_3	(3 << EMC_SDMR_CAS_BIT)
#define EMC_SDMR_BT_BIT		3        /* Burst Type */
#define EMC_SDMR_BT_MASK	(1 << EMC_SDMR_BT_BIT)
  #define EMC_SDMR_BT_SEQ	(0 << EMC_SDMR_BT_BIT) /* Sequential */
  #define EMC_SDMR_BT_INT	(1 << EMC_SDMR_BT_BIT) /* Interleave */
#define EMC_SDMR_BL_BIT		0        /* Burst Length */
#define EMC_SDMR_BL_MASK	(7 << EMC_SDMR_BL_BIT)
  #define EMC_SDMR_BL_1		(0 << EMC_SDMR_BL_BIT)
  #define EMC_SDMR_BL_2		(1 << EMC_SDMR_BL_BIT)
  #define EMC_SDMR_BL_4		(2 << EMC_SDMR_BL_BIT)
  #define EMC_SDMR_BL_8		(3 << EMC_SDMR_BL_BIT)

#define EMC_SDMR_CAS2_16BIT \
  (EMC_SDMR_CAS_2 | EMC_SDMR_BT_SEQ | EMC_SDMR_BL_2)
#define EMC_SDMR_CAS2_32BIT \
  (EMC_SDMR_CAS_2 | EMC_SDMR_BT_SEQ | EMC_SDMR_BL_4)
#define EMC_SDMR_CAS3_16BIT \
  (EMC_SDMR_CAS_3 | EMC_SDMR_BT_SEQ | EMC_SDMR_BL_2)
#define EMC_SDMR_CAS3_32BIT \
  (EMC_SDMR_CAS_3 | EMC_SDMR_BT_SEQ | EMC_SDMR_BL_4)


#if defined(__JZ4740__) || defined(__JZ4725__)
/*
 * D0 ~ D31, A0 ~ A16, DCS#, RAS#, CAS#, CKE#, 
 * RDWE#, CKO#, WE0#, WE1#, WE2#, WE3#
 */
#define __gpio_as_sdram_32bit()			\
do {						\
	REG_GPIO_PXFUNS(0) = 0xffffffff;	\
	REG_GPIO_PXSELC(0) = 0xffffffff;	\
	REG_GPIO_PXPES(0) = 0xffffffff;		\
	REG_GPIO_PXFUNS(1) = 0x81f9ffff;	\
	REG_GPIO_PXSELC(1) = 0x81f9ffff;	\
	REG_GPIO_PXPES(1) = 0x81f9ffff;		\
	REG_GPIO_PXFUNS(2) = 0x07000000;	\
	REG_GPIO_PXSELC(2) = 0x07000000;	\
	REG_GPIO_PXPES(2) = 0x07000000;		\
} while (0)

/*
 * D0 ~ D15, A0 ~ A16, DCS#, RAS#, CAS#, CKE#, 
 * RDWE#, CKO#, WE0#, WE1#
 */
#define __gpio_as_sdram_16bit()			\
do {						\
	REG_GPIO_PXFUNS(0) = 0x5442bfaa;	\
	REG_GPIO_PXSELC(0) = 0x5442bfaa;	\
	REG_GPIO_PXPES(0) = 0x5442bfaa;		\
	REG_GPIO_PXFUNS(1) = 0x81f9ffff;	\
	REG_GPIO_PXSELC(1) = 0x81f9ffff;	\
	REG_GPIO_PXPES(1) = 0x81f9ffff;		\
	REG_GPIO_PXFUNS(2) = 0x01000000;	\
	REG_GPIO_PXSELC(2) = 0x01000000;	\
	REG_GPIO_PXPES(2) = 0x01000000;		\
} while (0)

/*
 * CS1#, CLE, ALE, FRE#, FWE#, FRB#, RDWE#/BUFD#
 */
#define __gpio_as_nand()			\
do {						\
	REG_GPIO_PXFUNS(1) = 0x02018000;	\
	REG_GPIO_PXSELC(1) = 0x02018000;	\
	REG_GPIO_PXPES(1) = 0x02018000;		\
	REG_GPIO_PXFUNS(2) = 0x30000000;	\
	REG_GPIO_PXSELC(2) = 0x30000000;	\
	REG_GPIO_PXPES(2) = 0x30000000;		\
	REG_GPIO_PXFUNC(2) = 0x40000000;	\
	REG_GPIO_PXSELC(2) = 0x40000000;	\
	REG_GPIO_PXDIRC(2) = 0x40000000;	\
	REG_GPIO_PXPES(2) = 0x40000000;		\
	REG_GPIO_PXFUNS(1) = 0x00400000;	\
	REG_GPIO_PXSELC(1) = 0x00400000;	\
} while (0)

/*
 * CS4#, RD#, WR#, WAIT#, A0 ~ A22, D0 ~ D7
 */
#define __gpio_as_nor_8bit()			\
do {						\
	REG_GPIO_PXFUNS(0) = 0x000000ff;	\
	REG_GPIO_PXSELC(0) = 0x000000ff;	\
	REG_GPIO_PXPES(0) = 0x000000ff;		\
	REG_GPIO_PXFUNS(1) = 0x7041ffff;	\
	REG_GPIO_PXSELC(1) = 0x7041ffff;	\
	REG_GPIO_PXPES(1) = 0x7041ffff;		\
	REG_GPIO_PXFUNS(1) = 0x00060000;	\
	REG_GPIO_PXSELS(1) = 0x00060000;	\
	REG_GPIO_PXPES(1) = 0x00060000;		\
	REG_GPIO_PXFUNS(2) = 0x08000000;	\
	REG_GPIO_PXSELC(2) = 0x08000000;	\
	REG_GPIO_PXPES(2) = 0x08000000;		\
	REG_GPIO_PXFUNS(2) = 0x00c00000;	\
	REG_GPIO_PXSELS(2) = 0x00c00000;	\
	REG_GPIO_PXPES(2) = 0x00c00000;		\
	REG_GPIO_PXFUNS(3) = 0x18000000;	\
	REG_GPIO_PXSELS(3) = 0x18000000;	\
	REG_GPIO_PXPES(3) = 0x18000000;		\
} while (0)

/*
 * CS4#, RD#, WR#, WAIT#, A0 ~ A22, D0 ~ D15
 */
#define __gpio_as_nor_16bit()			\
do {						\
	REG_GPIO_PXFUNS(0) = 0x0000ffff;	\
	REG_GPIO_PXSELC(0) = 0x0000ffff;	\
	REG_GPIO_PXPES(0) = 0x0000ffff;		\
	REG_GPIO_PXFUNS(1) = 0x7041ffff;	\
	REG_GPIO_PXSELC(1) = 0x7041ffff;	\
	REG_GPIO_PXPES(1) = 0x7041ffff;		\
	REG_GPIO_PXFUNS(1) = 0x00060000;	\
	REG_GPIO_PXSELS(1) = 0x00060000;	\
	REG_GPIO_PXPES(1) = 0x00060000;		\
	REG_GPIO_PXFUNS(2) = 0x08000000;	\
	REG_GPIO_PXSELC(2) = 0x08000000;	\
	REG_GPIO_PXPES(2) = 0x08000000;		\
	REG_GPIO_PXFUNS(2) = 0x00c00000;	\
	REG_GPIO_PXSELS(2) = 0x00c00000;	\
	REG_GPIO_PXPES(2) = 0x00c00000;		\
	REG_GPIO_PXFUNS(3) = 0x18000000;	\
	REG_GPIO_PXSELS(3) = 0x18000000;	\
	REG_GPIO_PXPES(3) = 0x18000000;		\
} while (0)

#elif defined(__JZ4750__)
/*
 * D0 ~ D31, A0 ~ A14, DCS0#, RAS#, CAS#,
 * RDWE#, WE0#, WE1#, WE2#, WE3#, CKO#, CKE#
 */
#define __gpio_as_sdram_32bit()			\
do {						\
	REG_GPIO_PXFUNS(0) = 0xffffffff;	\
	REG_GPIO_PXSELC(0) = 0xffffffff;	\
	REG_GPIO_PXPES(0) = 0xffffffff;		\
	REG_GPIO_PXFUNS(1) = 0x03ff7fff;	\
	REG_GPIO_PXSELC(1) = 0x03ff7fff;	\
	REG_GPIO_PXPES(1) = 0x03ff7fff;		\
} while (0)

/*
 * D0 ~ D15, A0 ~ A14, DCS0#, RAS#, CAS#,
 * RDWE#, WE0#, WE1#, WE2#, WE3#, CKO#, CKE#
 */
#define __gpio_as_sdram_16bit()						\
do {								        \
	if (is_normal_order()) {					\
		/* 32/16-bit data normal order */			\
		REG_GPIO_PXFUNS(0) = 0x0000ffff;			\
		REG_GPIO_PXSELC(0) = 0x0000ffff;			\
		REG_GPIO_PXPES(0) = 0x0000ffff;				\
	} else {							\
		/* 16-bit data special order */				\
		REG_GPIO_PXFUNS(0) = 0x00ffff00;			\
		REG_GPIO_PXSELC(0) = 0x00ffff00;			\
		REG_GPIO_PXPES(0) = 0x00ffff00;				\
	}								\
	REG_GPIO_PXFUNS(1) = 0x03ff7fff;				\
	REG_GPIO_PXSELC(1) = 0x03ff7fff;				\
	REG_GPIO_PXPES(1) = 0x03ff7fff;					\
} while (0)

/*
 * D0 ~ D7, CS1#, CLE, ALE, FRE#, FWE#, FRB#, RDWE#/BUFD#
 * @n: chip select number(1 ~ 4)
 */
#define __gpio_as_nand_8bit(n)						\
do {		              						\
	if (!is_share_mode()) {						\
		/* unshare mode */					\
		REG_GPIO_PXFUNS(2) = 0x000000ff; /* SD0~SD7 */		\
		REG_GPIO_PXSELC(2) = 0x000000ff;			\
		REG_GPIO_PXPES(2) = 0x000000ff;				\
		REG_GPIO_PXFUNS(1) = 0x00008000; /* CLE(SA3) */		\
		REG_GPIO_PXSELS(1) = 0x00008000;			\
		REG_GPIO_PXPES(1) = 0x00008000;				\
		REG_GPIO_PXFUNS(2) = 0x00010000; /* ALE(SA4) */		\
		REG_GPIO_PXSELS(2) = 0x00010000;			\
		REG_GPIO_PXPES(2) = 0x00010000;				\
	} else {							\
		/* share mode */					\
		if (is_normal_order()) {	              		\
			/* 32/16-bit data normal order */		\
			REG_GPIO_PXFUNS(0) = 0x000000ff; /* D0~D7 */	\
			REG_GPIO_PXSELC(0) = 0x000000ff;		\
			REG_GPIO_PXPES(0) = 0x000000ff;			\
		} else {						\
			/* 16-bit data special order */			\
			REG_GPIO_PXFUNS(0) = 0x0000ff00; /* D0~D7 */	\
			REG_GPIO_PXSELC(0) = 0x0000ff00;		\
			REG_GPIO_PXPES(0) = 0x0000ff00;			\
		}							\
		REG_GPIO_PXFUNS(1) = 0x00008000; /* CLE(A15) */		\
		REG_GPIO_PXSELC(1) = 0x00008000;			\
		REG_GPIO_PXPES(1) = 0x00008000;				\
		REG_GPIO_PXFUNS(2) = 0x00010000; /* ALE(A16) */		\
		REG_GPIO_PXSELC(2) = 0x00010000;			\
		REG_GPIO_PXPES(2) = 0x00010000;				\
	}								\
	REG_GPIO_PXFUNS(2) = 0x00200000 << ((n)-1); /* CSn */		\
	REG_GPIO_PXSELC(2) = 0x00200000 << ((n)-1);			\
	REG_GPIO_PXPES(2) = 0x00200000 << ((n)-1);			\
									\
        REG_GPIO_PXFUNS(1) = 0x00080000; /* RDWE#/BUFD# */		\
        REG_GPIO_PXSELC(1) = 0x00080000;				\
	REG_GPIO_PXPES(1) = 0x00080000;					\
	REG_GPIO_PXFUNS(2) = 0x30000000; /* FRE#, FWE# */		\
	REG_GPIO_PXSELC(2) = 0x30000000;				\
	REG_GPIO_PXPES(2) = 0x30000000;					\
	REG_GPIO_PXFUNC(2) = 0x08000000; /* FRB#(input) */		\
	REG_GPIO_PXSELC(2) = 0x08000000;				\
	REG_GPIO_PXDIRC(2) = 0x08000000;				\
	REG_GPIO_PXPES(2) = 0x08000000;					\
} while (0)


/*
 * CS4#, RD#, WR#, WAIT#, A0 ~ A22, D0 ~ D7
 * @n: chip select number(1 ~ 4)
 */
#define __gpio_as_nor_8bit(n)						\
do {								        \
	if (is_normal_order()) {					\
		/* 32/16-bit data normal order */			\
		REG_GPIO_PXFUNS(0) = 0x000000ff;			\
		REG_GPIO_PXSELC(0) = 0x000000ff;			\
		REG_GPIO_PXPES(0) = 0x000000ff;				\
	} else {							\
		/* 16-bit data special order */				\
		REG_GPIO_PXFUNS(0) = 0x0000ff00;			\
		REG_GPIO_PXSELC(0) = 0x0000ff00;			\
		REG_GPIO_PXPES(0) = 0x0000ff00;				\
	}								\
	REG_GPIO_PXFUNS(2) = 0x00200000 << ((n)-1); /* CSn */		\
	REG_GPIO_PXSELC(2) = 0x00200000 << ((n)-1);			\
	REG_GPIO_PXPES(2) = 0x00200000 << ((n)-1);			\
									\
	REG_GPIO_PXFUNS(1) = 0x0000ffff; /* A0~A15 */			\
	REG_GPIO_PXSELC(1) = 0x0000ffff;				\
	REG_GPIO_PXPES(1) = 0x0000ffff;					\
	REG_GPIO_PXFUNS(2) = 0x06110007; /* RD#, WR#, WAIT#, A20~A22 */	\
	REG_GPIO_PXSELC(2) = 0x06110007;				\
	REG_GPIO_PXPES(2) = 0x06110007;					\
	REG_GPIO_PXFUNS(2) = 0x000e0000; /* A17~A19 */	        	\
	REG_GPIO_PXSELS(2) = 0x000e0000;				\
	REG_GPIO_PXPES(2) = 0x000e0000;					\
} while (0)

/*
 * CS4#, RD#, WR#, WAIT#, A0 ~ A22, D0 ~ D15
 * @n: chip select number(1 ~ 4)
 */
#define __gpio_as_nor_16bit(n)						\
do {	               							\
	if (is_normal_order()) {					\
		/* 32/16-bit data normal order */			\
		REG_GPIO_PXFUNS(0) = 0x0000ffff;			\
		REG_GPIO_PXSELC(0) = 0x0000ffff;			\
		REG_GPIO_PXPES(0) = 0x0000ffff;				\
	} else {							\
		/* 16-bit data special order */				\
		REG_GPIO_PXFUNS(0) = 0x00ffff00;			\
		REG_GPIO_PXSELC(0) = 0x00ffff00;			\
		REG_GPIO_PXPES(0) = 0x00ffff00;				\
	}								\
	REG_GPIO_PXFUNS(2) = 0x00200000 << ((n)-1); /* CSn */		\
	REG_GPIO_PXSELC(2) = 0x00200000 << ((n)-1);			\
	REG_GPIO_PXPES(2) = 0x00200000 << ((n)-1);			\
									\
	REG_GPIO_PXFUNS(1) = 0x0000ffff; /* A0~A15 */			\
	REG_GPIO_PXSELC(1) = 0x0000ffff;				\
	REG_GPIO_PXPES(1) = 0x0000ffff;					\
	REG_GPIO_PXFUNS(2) = 0x06110007; /* RD#, WR#, WAIT#, A20~A22 */	\
	REG_GPIO_PXSELC(2) = 0x06110007;				\
	REG_GPIO_PXPES(2) = 0x06110007;					\
	REG_GPIO_PXFUNS(2) = 0x000e0000; /* A17~A19 */	        	\
	REG_GPIO_PXSELS(2) = 0x000e0000;				\
	REG_GPIO_PXPES(2) = 0x000e0000;					\
} while (0)

#elif defined(__JZ4755__) || defined(__JZ4725B__)
/*
 * D0 ~ D15, A0 ~ A14, DCS0#, RAS#, CAS#, 
 * RDWE#, WE0#, WE1#, CKO#, CKE#
 */
#define __gpio_as_sdram_16bit()			\
do {						\
	REG_GPIO_PXFUNS(0) = 0x0000ffff;	\
	REG_GPIO_PXSELC(0) = 0x0000ffff;	\
	REG_GPIO_PXPES(0) = 0x0000ffff;		\
	REG_GPIO_PXFUNS(1) = 0x03ff7fff;	\
	REG_GPIO_PXSELC(1) = 0x03ff7fff;	\
	REG_GPIO_PXPES(1) = 0x03ff7fff;		\
} while (0)

/*
 * D0 ~ D7, CS1#, CLE, ALE, FRE#, FWE#, FRB#, RDWE#/BUFD#
 * @n: chip select number(1 ~ 4)
 */
#define __gpio_as_nand_8bit(n)						\
do {		              						\
	/* 32/16-bit data bus */					\
	REG_GPIO_PXFUNS(0) = 0x000000ff; /* D0~D7 */			\
	REG_GPIO_PXSELC(0) = 0x000000ff;				\
	REG_GPIO_PXPES(0) = 0x000000ff;					\
	REG_GPIO_PXFUNS(2) = 0x00000300; /* CLE(A15), ALE(A16) */	\
	REG_GPIO_PXSELC(2) = 0x00000300;				\
	REG_GPIO_PXPES(2) = 0x0000300;					\
									\
	REG_GPIO_PXFUNS(2) = 0x00200000 << ((n)-1); /* CSn */		\
	REG_GPIO_PXSELC(2) = 0x00200000 << ((n)-1);			\
	REG_GPIO_PXPES(2) = 0x00200000 << ((n)-1);			\
									\
        REG_GPIO_PXFUNS(1) = 0x00080000; /* RDWE#/BUFD# */		\
        REG_GPIO_PXSELC(1) = 0x00080000;				\
	REG_GPIO_PXPES(1) = 0x00080000;					\
	REG_GPIO_PXFUNS(2) = 0x30000000; /* FRE#, FWE# */		\
	REG_GPIO_PXSELC(2) = 0x30000000;				\
	REG_GPIO_PXPES(2) = 0x30000000;					\
	REG_GPIO_PXFUNC(2) = 0x08000000; /* FRB#(input) */		\
	REG_GPIO_PXSELC(2) = 0x08000000;				\
	REG_GPIO_PXDIRC(2) = 0x08000000;				\
	REG_GPIO_PXPES(2) = 0x08000000;					\
} while (0)

/*
 * CS4#, RD#, WR#, WAIT#, A0 ~ A22, D0 ~ D7
 * @n: chip select number(1 ~ 4)
 */
#define __gpio_as_nor_8bit(n)						\
do {								        \
	/* 32/16-bit data bus */					\
	REG_GPIO_PXFUNS(0) = 0x000000ff;				\
	REG_GPIO_PXSELC(0) = 0x000000ff;				\
	REG_GPIO_PXPES(0) = 0x000000ff;					\
									\
	REG_GPIO_PXFUNS(2) = 0x00200000 << ((n)-1); /* CSn */		\
	REG_GPIO_PXSELC(2) = 0x00200000 << ((n)-1);			\
	REG_GPIO_PXPES(2) = 0x00200000 << ((n)-1);			\
									\
	REG_GPIO_PXFUNS(1) = 0x0000ffff; /* A0~A15 */			\
	REG_GPIO_PXSELC(1) = 0x0000ffff;				\
	REG_GPIO_PXPES(1) = 0x0000ffff;					\
	REG_GPIO_PXFUNS(2) = 0x06110007; /* RD#, WR#, WAIT#, A20~A22 */	\
	REG_GPIO_PXSELC(2) = 0x06110007;				\
	REG_GPIO_PXPES(2) = 0x06110007;					\
	REG_GPIO_PXFUNS(2) = 0x000e0000; /* A17~A19 */	        	\
	REG_GPIO_PXSELS(2) = 0x000e0000;				\
	REG_GPIO_PXPES(2) = 0x000e0000;					\
} while (0)

/*
 * CS4#, RD#, WR#, WAIT#, A0 ~ A22, D0 ~ D15
 * @n: chip select number(1 ~ 4)
 */
#define __gpio_as_nor_16bit(n)						\
do {	               							\
	/* 32/16-bit data normal order */				\
	REG_GPIO_PXFUNS(0) = 0x0000ffff;				\
	REG_GPIO_PXSELC(0) = 0x0000ffff;				\
	REG_GPIO_PXPES(0) = 0x0000ffff;					\
									\
	REG_GPIO_PXFUNS(2) = 0x00200000 << ((n)-1); /* CSn */		\
	REG_GPIO_PXSELC(2) = 0x00200000 << ((n)-1);			\
	REG_GPIO_PXPES(2) = 0x00200000 << ((n)-1);			\
									\
	REG_GPIO_PXFUNS(1) = 0x0000ffff; /* A0~A15 */			\
	REG_GPIO_PXSELC(1) = 0x0000ffff;				\
	REG_GPIO_PXPES(1) = 0x0000ffff;					\
	REG_GPIO_PXFUNS(2) = 0x06110007; /* RD#, WR#, WAIT#, A20~A22 */	\
	REG_GPIO_PXSELC(2) = 0x06110007;				\
	REG_GPIO_PXPES(2) = 0x06110007;					\
	REG_GPIO_PXFUNS(2) = 0x000e0000; /* A17~A19 */	        	\
	REG_GPIO_PXSELS(2) = 0x000e0000;				\
	REG_GPIO_PXPES(2) = 0x000e0000;					\
} while (0)

#endif

static inline unsigned long __emc_get_sdram_size() {
	unsigned long memsize;
	unsigned int dmcr;
	memsize = 0x400000; /* 4MB */
	dmcr = REG_EMC_DMCR;
	if (!(dmcr & EMC_DMCR_BW)) memsize <<= 1;
	memsize <<= (( dmcr & EMC_DMCR_RA_MASK) >> EMC_DMCR_RA_BIT);
	memsize <<= (( dmcr & EMC_DMCR_CA_MASK) >> EMC_DMCR_CA_BIT);
	return memsize;
}

#endif /* __JZ_EMC_H__ */
