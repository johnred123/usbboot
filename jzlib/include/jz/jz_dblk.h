#ifndef __JZ_DBLK_H__
#define __JZ_DBLK_H__
#ifndef __JZ_BASE_H__
#include <jz/jz_base.h>
#endif
/*************************************************************************
 * DBLK (De-Block)
 *************************************************************************/
#define DBLK_CTRL		(DBLK_BASE + 0x00) /* ME Control Register */
#define DBLK_REF_ADDR	(DBLK_BASE + 0x04) /* ME Reference Block Address Register */
#define DBLK_CURR_ADDR	(DBLK_BASE + 0x08) /* ME Current Block Address Register */
#define DBLK_DIFF_ADDR	(DBLK_BASE + 0x0C) /* ME Difference Address Register */
#define DBLK_REF_STRD	(DBLK_BASE + 0x10) /* ME Reference Frame Stride Register */
#define DBLK_CURR_STRD	(DBLK_BASE + 0x14) /* ME Current Frame Stride Register */
#define DBLK_DIFF_STRD	(DBLK_BASE + 0x18) /* ME Difference Frame Stride Register */
#define DBLK_SETTINGS	(DBLK_BASE + 0x1C) /* ME Settings Register */
#define DBLK_MVD		(DBLK_BASE + 0x20) /* ME Motion Vector Difference Register */
#define DBLK_FLAG		(DBLK_BASE + 0x24) /* ME Flag Register */

#define REG_DBLK_CTRL		REG32(DBLK_CTRL)
#define REG_DBLK_REF_ADDR		REG32(DBLK_REF_ADDR)
#define REG_DBLK_CURR_ADDR	REG32(DBLK_CURR_ADDR)
#define REG_DBLK_DIFF_ADDR	REG32(DBLK_DIFF_ADDR)
#define REG_DBLK_REF_STRD		REG32(DBLK_REF_STRD)
#define REG_DBLK_CURR_STRD	REG32(DBLK_CURR_STRD)
#define REG_DBLK_DIFF_STRD	REG32(DBLK_DIFF_STRD)
#define REG_DBLK_SETTINGS		REG32(DBLK_SETTINGS)
#define REG_DBLK_MVD		REG32(DBLK_MVD)
#define REG_DBLK_FLAG		REG32(DBLK_FLAG)


/* ME Control Register */
#define DBLK_CTRL_FLUSH		(1 << 2) /* ME cache clear */
#define DBLK_CTRL_RESET		(1 << 1) /* ME reset */
#define DBLK_CTRL_ENABLE		(1 << 0) /* ME enable */

/* ME Settings Register */
#define DBLK_SETTINGS_SAD_GATE_BIT	16 /* The max SAD value which can be accepted */
#define DBLK_SETTINGS_SAD_GATE_MASK	(0xffff << DBLK_SETTINGS_SAD_GATE_BIT)
#define DBLK_SETTINGS_STEP_NUM_BIT	0  /* The max step number the search process can not exceed */
#define DBLK_SETTINGS_STEP_NUM_MASK	(0x3f << DBLK_SETTINGS_STEP_NUM_BIT)

/* ME Motion Vector Difference Register */
#define DBLK_MVD_MVDY_BIT		16 /* The MVD value of coordinate-Y */
#define DBLK_MVD_MVDY_MASK	(0xffff << DBLK_MVD_MVDY_BIT)
#define DBLK_MVD_MVDX_BIT		0  /* The MVD value of coordinate-X */
#define DBLK_MVD_MVDX_MASK	(0xffff << DBLK_MVD_MVDX_BIT)

/* ME Flag Register */
#define DBLK_FLAG_INTRA		(1 << 1) /* Indicate the current MB will be predicted in intra mode */
#define DBLK_FLAG_COMPLETED	(1 << 0) /* The ME of the current part of the MB is completed */

#endif /* __JZ_DBLK_H__ */
