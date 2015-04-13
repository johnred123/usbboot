#ifndef __JZ_SLCD_H__
#define __JZ_SLCD_H__
#ifndef __JZ_BASE_H__
#include <jz/jz_base.h>
#endif
/*************************************************************************
 * SLCD (Smart LCD Controller)
 *************************************************************************/

#define SLCD_CFG	(SLCD_BASE + 0xA0)  /* SLCD Configure Register */
#define SLCD_CTRL	(SLCD_BASE + 0xA4)  /* SLCD Control Register */
#define SLCD_STATE	(SLCD_BASE + 0xA8)  /* SLCD Status Register */
#define SLCD_DATA	(SLCD_BASE + 0xAC)  /* SLCD Data Register */

#define REG_SLCD_CFG	REG32(SLCD_CFG)
#define REG_SLCD_CTRL	REG8(SLCD_CTRL)
#define REG_SLCD_STATE	REG8(SLCD_STATE)
#define REG_SLCD_DATA	REG32(SLCD_DATA)

#if defined(__JZ4740__) || defined(__JZ4725__)
#define SLCD_FIFO	(SLCD_BASE + 0xB0)  /* SLCD FIFO Register */
#define REG_SLCD_FIFO	REG32(SLCD_FIFO)
#endif

/* SLCD Configure Register */
#if defined(__JZ4740__) || defined(__JZ4725__)
#define SLCD_CFG_BURST_BIT	14
#define SLCD_CFG_BURST_MASK	(0x3 << SLCD_CFG_BURST_BIT)
  #define SLCD_CFG_BURST_4_WORD	(0 << SLCD_CFG_BURST_BIT)
  #define SLCD_CFG_BURST_8_WORD	(1 << SLCD_CFG_BURST_BIT)
#endif
#define SLCD_CFG_DWIDTH_BIT	10
#define SLCD_CFG_DWIDTH_MASK	(0x7 << SLCD_CFG_DWIDTH_BIT)
  #define SLCD_CFG_DWIDTH_18BIT	(0 << SLCD_CFG_DWIDTH_BIT)
  #define SLCD_CFG_DWIDTH_16BIT	(1 << SLCD_CFG_DWIDTH_BIT)
  #define SLCD_CFG_DWIDTH_8BIT_x3	(2 << SLCD_CFG_DWIDTH_BIT)
  #define SLCD_CFG_DWIDTH_8BIT_x2	(3 << SLCD_CFG_DWIDTH_BIT)
  #define SLCD_CFG_DWIDTH_8BIT_x1	(4 << SLCD_CFG_DWIDTH_BIT)
#if defined(__JZ4750__) || defined(__JZ4755__)
  #define SLCD_CFG_DWIDTH_24BIT	(5 << SLCD_CFG_DWIDTH_BIT)
#endif
  #define SLCD_CFG_DWIDTH_9BIT_x2	(7 << SLCD_CFG_DWIDTH_BIT)
#define SLCD_CFG_CWIDTH_BIT	(8)
#define SLCD_CFG_CWIDTH_MASK	(0x7 << SLCD_CFG_CWIDTH_BIT)
#define SLCD_CFG_CWIDTH_16BIT	(0 << SLCD_CFG_CWIDTH_BIT)
#define SLCD_CFG_CWIDTH_8BIT	(1 << SLCD_CFG_CWIDTH_BIT)
#define SLCD_CFG_CWIDTH_18BIT	(2 << SLCD_CFG_CWIDTH_BIT)
#if defined(__JZ4750__) || defined(__JZ4755__)
#define SLCD_CFG_CWIDTH_24BIT	(3 << SLCD_CFG_CWIDTH_BIT)
#endif
#define SLCD_CFG_CS_ACTIVE_LOW	(0 << 4)
#define SLCD_CFG_CS_ACTIVE_HIGH	(1 << 4)
#define SLCD_CFG_RS_CMD_LOW	(0 << 3)
#define SLCD_CFG_RS_CMD_HIGH	(1 << 3)
#define SLCD_CFG_CLK_ACTIVE_FALLING	(0 << 1)
#define SLCD_CFG_CLK_ACTIVE_RISING	(1 << 1)
#define SLCD_CFG_TYPE_PARALLEL	(0 << 0)
#define SLCD_CFG_TYPE_SERIAL	(1 << 0)

/* SLCD Control Register */
#if defined(__JZ4755__) || defined(__JZ4725B__)
#define SLCD_CTRL_DMA_MODE	(1 << 2)
#define SLCD_CTRL_DMA_START	(1 << 1)
#endif
#define SLCD_CTRL_DMA_EN	(1 << 0)

/* SLCD Status Register */
#define SLCD_STATE_BUSY		(1 << 0)

/* SLCD Data Register */
#define SLCD_DATA_RS_DATA	(0 << 31)
#define SLCD_DATA_RS_COMMAND	(1 << 31)

#if defined(__JZ4740__) || defined(__JZ4725__)
/* SLCD FIFO Register */
#define SLCD_FIFO_RS_DATA	(0 << 31)
#define SLCD_FIFO_RS_COMMAND	(1 << 31)
#endif


/*
 * PIN Setting
 */
#if defined(__JZ4740__) || defined(__JZ4725__)

#define __gpio_as_slcd_8bit()			\
do {						\
	REG_GPIO_PXFUNS(2) = 0x001800ff;	\
	REG_GPIO_PXSELC(2) = 0x001800ff;	\
} while (0)

#define __gpio_as_slcd_9bit()			\
do {						\
	REG_GPIO_PXFUNS(2) = 0x001801ff;	\
	REG_GPIO_PXSELC(2) = 0x001801ff;	\
} while (0)

#define __gpio_as_slcd_16bit()			\
do {						\
	REG_GPIO_PXFUNS(2) = 0x0018ffff;	\
	REG_GPIO_PXSELC(2) = 0x0018ffff;	\
} while (0)

#define __gpio_as_slcd_18bit()			\
do {						\
	REG_GPIO_PXFUNS(2) = 0x001bffff;	\
	REG_GPIO_PXSELC(2) = 0x001bffff;	\
} while (0)

#elif defined(__JZ4750__)

#define __gpio_as_lcd_smart_pal_8bit()		\
do {						\
	REG_GPIO_PXFUNS(3) = 0x001c00ff;	\
	REG_GPIO_PXSELC(3) = 0x001c00ff;	\
	REG_GPIO_PXPES(3) = 0x001c00ff;		\
} while (0)

#define __gpio_as_lcd_smart_pal_15bit()		\
do {						\
	REG_GPIO_PXFUNS(3) = 0x001cffff;	\
	REG_GPIO_PXSELC(3) = 0x001cffff;	\
	REG_GPIO_PXPES(3) = 0x001cffff;		\
} while (0)

#define __gpio_as_lcd_smart_pal_17bit()		\
do {						\
	REG_GPIO_PXFUNS(3) = 0x001fffff;	\
	REG_GPIO_PXSELC(3) = 0x001fffff;	\
	REG_GPIO_PXPES(3) = 0x001fffff;		\
} while (0)

#define __gpio_as_lcd_smart_serial()		\
do {						\
	REG_GPIO_PXFUNS(3) = 0x001c8000;	\
	REG_GPIO_PXSELC(3) = 0x001c8000;	\
	REG_GPIO_PXPES(3) = 0x001c8000;		\
} while (0)
#elif defined(__JZ4755__) || defined(__JZ4725B__)
#endif

/*
 * OPs
 */
#if defined(__JZ4750__) || defined(__JZ4755__) || defined(__JZ4725B__)
/*************************************************************************
 * SLCD (Smart LCD Controller)
 *************************************************************************/
#define __slcd_set_data_18bit() \
  ( REG_SLCD_CFG = (REG_SLCD_CFG & ~SLCD_CFG_DWIDTH_MASK) | SLCD_CFG_DWIDTH_18BIT )
#define __slcd_set_data_16bit() \
  ( REG_SLCD_CFG = (REG_SLCD_CFG & ~SLCD_CFG_DWIDTH_MASK) | SLCD_CFG_DWIDTH_16BIT )
#define __slcd_set_data_8bit_x3() \
  ( REG_SLCD_CFG = (REG_SLCD_CFG & ~SLCD_CFG_DWIDTH_MASK) | SLCD_CFG_DWIDTH_8BIT_x3 )
#define __slcd_set_data_8bit_x2() \
  ( REG_SLCD_CFG = (REG_SLCD_CFG & ~SLCD_CFG_DWIDTH_MASK) | SLCD_CFG_DWIDTH_8BIT_x2 )
#define __slcd_set_data_8bit_x1() \
  ( REG_SLCD_CFG = (REG_SLCD_CFG & ~SLCD_CFG_DWIDTH_MASK) | SLCD_CFG_DWIDTH_8BIT_x1 )
#define __slcd_set_data_24bit() \
  ( REG_SLCD_CFG = (REG_SLCD_CFG & ~SLCD_CFG_DWIDTH_MASK) | SLCD_CFG_DWIDTH_24BIT )
#define __slcd_set_data_9bit_x2() \
  ( REG_SLCD_CFG = (REG_SLCD_CFG & ~SLCD_CFG_DWIDTH_MASK) | SLCD_CFG_DWIDTH_9BIT_x2 )

#define __slcd_set_cmd_16bit() \
  ( REG_SLCD_CFG = (REG_SLCD_CFG & ~SLCD_CFG_CWIDTH_MASK) | SLCD_CFG_CWIDTH_16BIT )
#define __slcd_set_cmd_8bit() \
  ( REG_SLCD_CFG = (REG_SLCD_CFG & ~SLCD_CFG_CWIDTH_MASK) | SLCD_CFG_CWIDTH_8BIT )
#define __slcd_set_cmd_18bit() \
  ( REG_SLCD_CFG = (REG_SLCD_CFG & ~SLCD_CFG_CWIDTH_MASK) | SLCD_CFG_CWIDTH_18BIT )
#define __slcd_set_cmd_24bit() \
  ( REG_SLCD_CFG = (REG_SLCD_CFG & ~SLCD_CFG_CWIDTH_MASK) | SLCD_CFG_CWIDTH_24BIT )

#define __slcd_set_cs_high()        ( REG_SLCD_CFG |= SLCD_CFG_CS_ACTIVE_HIGH )
#define __slcd_set_cs_low()         ( REG_SLCD_CFG &= ~SLCD_CFG_CS_ACTIVE_HIGH )

#define __slcd_set_rs_high()        ( REG_SLCD_CFG |= SLCD_CFG_RS_CMD_HIGH )
#define __slcd_set_rs_low()         ( REG_SLCD_CFG &= ~SLCD_CFG_RS_CMD_HIGH )

#define __slcd_set_clk_falling()    ( REG_SLCD_CFG &= ~SLCD_CFG_CLK_ACTIVE_RISING )
#define __slcd_set_clk_rising()     ( REG_SLCD_CFG |= SLCD_CFG_CLK_ACTIVE_RISING )

#define __slcd_set_parallel_type()  ( REG_SLCD_CFG &= ~SLCD_CFG_TYPE_SERIAL )
#define __slcd_set_serial_type()    ( REG_SLCD_CFG |= SLCD_CFG_TYPE_SERIAL )

/* SLCD Control Register */
#define __slcd_enable_dma()         ( REG_SLCD_CTRL |= SLCD_CTRL_DMA_EN )
#define __slcd_disable_dma()        ( REG_SLCD_CTRL &= ~SLCD_CTRL_DMA_EN )

/* SLCD Status Register */
#define __slcd_is_busy()            ( REG_SLCD_STATE & SLCD_STATE_BUSY )

/* SLCD Data Register */
#define __slcd_set_cmd_rs()         ( REG_SLCD_DATA |= SLCD_DATA_RS_COMMAND)
#define __slcd_set_data_rs()        ( REG_SLCD_DATA &= ~SLCD_DATA_RS_COMMAND)

#endif


#endif /* __JZ_SLCD_H__ */
