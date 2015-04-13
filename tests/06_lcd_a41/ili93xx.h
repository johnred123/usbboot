#ifndef __ILI93XX_H__
#define __ILI93XX_H__

#include "gpio.h"
#include "delay.h"

/* ILI9325 panels */
#define PANEL_CPT24	1
#define PANEL_CPT28	2
#define PANEL_CMO24	3
#define PANEL_CMO28	4
#define PANEL_CMO32	5
#define PANEL_AUO28	6
#define PANEL_CUSTOM	255	

/* ILI9326 panels */
//#define PANEL_CPT28	2
#define PANEL_WINTEK28	7
#define PANEL_LPL30	8

extern void ILI93XX_Ctrl(int);
extern void ILI93XX_Write(int);
extern void ILI93XX_CtrlWrite(int, int);
extern void ILI93XX_Reset(int);

#endif /* __ILI93XX_H__ */
