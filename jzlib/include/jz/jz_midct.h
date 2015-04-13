#ifndef __JZ_MIDCT_H__
#define __JZ_MIDCT_H__
#ifndef __JZ_BASE_H__
#include <jz/jz_base.h>
#endif
/*************************************************************************
 * MICDT 
 *************************************************************************/
#define MIDCT_4X4_GCSR		(MIDCT_BASE + 0x00) /* Globe control and status Register */
#define MIDCT_4X4_END	(MIDCT_BASE + 0x04) /* MIDCT_4X4 end Register */
#define MIDCT_4X4_DHA	(MIDCT_BASE + 0x08) /* Descriptor Head Address Register */
#define MIDCT_4X4_VTR	(MIDCT_BASE + 0x0C) /* video and type Register */
#define MIDCT_4X4_INPUT_ADDR	(MIDCT_BASE + 0x10) /* input Addr Register */
#define MIDCT_4X4_OUTPUT_ADDR	(MIDCT_BASE + 0x14) /* output Addr Register */
#define MIDCT_4X4_INOUT_STR	(MIDCT_BASE + 0x18) /* in/out Stride Register */

#define REG_MIDCT_4X4_GCSR		REG32(MIDCT_4X4_GCSR)
#define REG_MIDCT_4X4_DHA	REG32(MIDCT_4X4_DHA)
#define REG_MIDCT_4X4_VTR	REG32(MIDCT_4X4_VTR)
#define REG_MIDCT_4X4_INPUT_ADDR		REG32(MIDCT_4X4_INPUT_ADDR)
#define REG_MIDCT_4X4_OUTPUT_ADDR		REG32(MIDCT_4X4_OUTPUT_ADDR)
#define REG_MIDCT_4X4_INOUT_STR		REG32(MIDCT_4X4_INOUT_STR)


/* Globe control and status Register */
#define MIDCT_4X4_ERROR_BIT		24 /* */
#define MIDCT_4X4_ERROR_MASK		(3 << 24) /* */
#define MIDCT_4X4_FRESH			(1 << 5) /* */
#define MIDCT_4X4_DES_SEL		(1 << 2) /* */
#define MIDCT_4X4_START			(1 << 1) /* */
#define MIDCT_4X4_ICDTE			(1 << 0) /* */

/* MIDCT_4X4 end Register */
#define MIDCT_4X4_END_END		(1 << 0) /* */

/* video and type Register */
#define MIDCT_4X4_VIDEO_BIT		16 /* */
#define MIDCT_4X4_VIDEO_MASK		(3 << 16) /* */
#define MIDCT_4X4_VIDEO_HAMA		(0 << 16) /* */
#define MIDCT_4X4_VIDEO_H264		(1 << 16) /* */
#define MIDCT_4X4_VIDEO_REAL		(2 << 16) /* */
#define MIDCT_4X4_VIDEO_WMV		(3 << 16) /* */

#define MIDCT_4X4_TYPE_BIT		0 /* */
#define MIDCT_4X4_TYPE_MASK		(3 << 0) /* */

/* in/out Stride Register */
#define MIDCT_4X4_INPUT_STR_BIT		0 /* */
#define MIDCT_4X4_INPUT_STR_MASK	(0xff << 0) /* */
#define MIDCT_4X4_OUTPUT_STR		16 /* */
#define MIDCT_4X4_OUTPUT_STR_MASK	(0xff << 16) /* */

#endif /* __JZ_MIDCT_H__ */
