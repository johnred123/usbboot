#include "ili93xx.h"

#define SLCD_RESET	(32*3 + 23) // PD23 (LCD_SPL)
#define SLCD_CS		(32*3 + 22) // PD22 (LCD_CLS)
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

void ILI93XX_Init(int idx)
{
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
	__delay(10);
	__gpio_clear_pin(SLCD_WR);
	__delay(20);
	__gpio_set_pin(SLCD_WR);
	__delay(10);
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
