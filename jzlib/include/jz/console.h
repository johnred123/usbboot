#ifndef _JZ_CONSOLE_H_
#define _JZ_CONSOLE_H_

#include <stdio.h>

extern void serial_init(void);
extern void serial_putc(const char c);

extern void ubcomm_proc();
extern void ubcomm_putc(const char c);
extern void ubcomm_init(void *p);

extern void ILI9325_Init(int reset, int cs, int backlight);
extern void ILI9325_Pixel(int x, int y, int color);
extern void ILI9325_Char(int x, int y, int ch);
extern void ILI9325_Scroll(int height);
extern void ILI9325_Text(char *str);

extern void ILI9326_Init(int reset, int cs, int backlight);
extern void ILI9326_Pixel(int x, int y, int color);
extern void ILI9326_Char(int x, int y, int ch);
extern void ILI9326_Scroll(int height);
extern void ILI9326_Text(char *str);

extern FILE *fdevopen_serial(FILE *fp);
extern FILE *fdevopen_ubcomm(FILE *fp, void *p);
extern FILE *fdevopen_ili9325(FILE *fp, int reset, int cs, int backlight);
extern FILE *fdevopen_ili9326(FILE *fp, int reset, int cs, int backlight);

extern void jzcon_append(FILE *fp);
extern void jzcon_setup();

#endif /* _JZ_CONSOLE_H_ */
