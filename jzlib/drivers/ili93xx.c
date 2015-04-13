#include <jz/jz_base.h>
#include <jz/jz_core.h>
#include "ili93xx.h"

static int __slcd_reset = (32*3 + 23); // PD23 (LCD_SPL) A-41/A-33
static int __slcd_cs    = (32*3 + 22); // PD22 (LCD_CLS) A-41/A-33

//int bg_color = 0xffff; // white
int bg_color = 0xf3ef; // ??
int fg_color = 0x000f; // dark blue

#define SLCD_RESET	__slcd_reset
#define SLCD_CS		__slcd_cs
#define SLCD_RS		(32*3 + 19) // PD19 (LCD_HSYN = SLCD_RS)
#define SLCD_WR		(32*3 + 20) // PD20 (LCD_VSYN = SLCD_CS)

#define lcd_as_output()				\
do {						\
	REG_GPIO_PXFUNC(3) = 0x0000ffff;	\
	REG_GPIO_PXSELC(3) = 0x0000ffff;	\
	REG_GPIO_PXDIRS(3) = 0x0000ffff;	\
} while (0)

#define lcd_out(dat)				\
do {						\
	REG_GPIO_PXDATS(3) = (dat & 0xffff);	\
	REG_GPIO_PXDATC(3) = ((~dat) & 0xffff);	\
} while (0)

void ILI93XX_Init(int reset, int cs)
{
	if ((reset > 0) && (cs > 0)) {
		SLCD_RESET = reset;
		SLCD_CS = cs;
	}
	__gpio_set_pin(SLCD_RESET);
	__gpio_set_pin(SLCD_CS);
	__gpio_set_pin(SLCD_RS);
	__gpio_set_pin(SLCD_WR);
	__gpio_as_output(SLCD_RESET);
	__gpio_as_output(SLCD_CS);
	__gpio_as_output(SLCD_RS);
	__gpio_as_output(SLCD_WR);
	lcd_as_output();
}

void ILI93XX_Reset(int v)
{
	if (v > 0) {
		__gpio_set_pin(SLCD_RESET);
		__gpio_as_output(SLCD_RESET);
	} else if (v == 0) {
		__gpio_clear_pin(SLCD_RESET);
		__gpio_as_output(SLCD_RESET);
	}
}

void ILI93XX_Write(int val)
{
	lcd_out(val);
	__gpio_clear_pin(SLCD_CS);
	__delay_loop_1(10);
	__gpio_clear_pin(SLCD_WR);
	__delay_loop_1(20);
	__gpio_set_pin(SLCD_WR);
	__delay_loop_1(10);
	__gpio_set_pin(SLCD_CS);
}

void ILI93XX_Ctrl(int idx)
{
	__gpio_clear_pin(SLCD_RS);
	ILI93XX_Write(idx);
	__gpio_set_pin(SLCD_RS);
}

void ILI93XX_CtrlWrite(int idx, int val)
{
	__gpio_clear_pin(SLCD_RS);
	ILI93XX_Write(idx);
	__gpio_set_pin(SLCD_RS);
	ILI93XX_Write(val);
}
