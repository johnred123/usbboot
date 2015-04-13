#include "ili93xx.h"

//#define ILI9325_PANEL	PANEL_CPT24
#define ILI9325_PANEL	PANEL_CUSTOM


#define PHYS_VSIZE	320
#define PHYS_HSIZE	240
static int vscroll_base;
static int col;
static int row;

static inline void ILI9325_Poweron()
{
#if (ILI9325_PANEL == PANEL_CPT24)
	ILI93XX_CtrlWrite(0x10, 0x1490); // SAP, BT[3:0], AP, DSTB, SLP, STB
	ILI93XX_CtrlWrite(0x11, 0x0227); // DC1[2:0], DC0[2:0], VC[2:0]
	mdelay(50);
	ILI93XX_CtrlWrite(0x12, 0x001C); //Inernal reference voltage =Vci;
	mdelay(50);
	ILI93XX_CtrlWrite(0x13, 0x1A00); // VDV[4:0] for VCOM amplitude
	ILI93XX_CtrlWrite(0x29, 0x0025); // VCM[5:0] for VCOMH
#elif (ILI9325_PANEL == PANEL_CPT28)
	ILI93XX_CtrlWrite(0x10, 0x1290); // SAP, BT[3:0], AP, DSTB, SLP, STB
	ILI93XX_CtrlWrite(0x11, 0x0227); // DC1[2:0], DC0[2:0], VC[2:0]
	mdelay(50);
	ILI93XX_CtrlWrite(0x12, 0x001A); //Inernal reference voltage =Vci;
	mdelay(50);
	ILI93XX_CtrlWrite(0x13, 0x1800); // VDV[4:0] for VCOM amplitude
	ILI93XX_CtrlWrite(0x29, 0x0028); // VCM[5:0] for VCOMH
#elif (ILI9325_PANEL == PANEL_CMO24)
	ILI93XX_CtrlWrite(0x10, 0x1290); // SAP, BT[3:0], AP, DSTB, SLP, STB
	ILI93XX_CtrlWrite(0x11, 0x0227); // DC1[2:0], DC0[2:0], VC[2:0]
	mdelay(50);
	ILI93XX_CtrlWrite(0x12, 0x001B); //Inernal reference voltage =Vci;
	mdelay(50);
	ILI93XX_CtrlWrite(0x13, 0x1900); // VDV[4:0] for VCOM amplitude
	ILI93XX_CtrlWrite(0x29, 0x000F); // VCM[5:0] for VCOMH
#elif (ILI9325_PANEL == PANEL_CMO28)
	ILI93XX_CtrlWrite(0x10, 0x1690); // SAP, BT[3:0], AP, DSTB, SLP, STB
	ILI93XX_CtrlWrite(0x11, 0x0227); // DC1[2:0], DC0[2:0], VC[2:0]
	mdelay(50);
	ILI93XX_CtrlWrite(0x12, 0x001B); //Inernal reference voltage =Vci;
	mdelay(50);
	ILI93XX_CtrlWrite(0x13, 0x1600); // VDV[4:0] for VCOM amplitude
	ILI93XX_CtrlWrite(0x29, 0x0018); // VCM[5:0] for VCOMH
#elif (ILI9325_PANEL == PANEL_CMO32)
	ILI93XX_CtrlWrite(0x10, 0x1290); // SAP, BT[3:0], AP, DSTB, SLP, STB
	ILI93XX_CtrlWrite(0x11, 0x0227); // DC1[2:0], DC0[2:0], VC[2:0]
	mdelay(50);
	ILI93XX_CtrlWrite(0x12, 0x0019); //Inernal reference voltage =Vci;
	mdelay(50);
	ILI93XX_CtrlWrite(0x13, 0x1D00); // VDV[4:0] for VCOM amplitude
	ILI93XX_CtrlWrite(0x29, 0x0028); // VCM[5:0] for VCOMH
#elif (ILI9325_PANEL == PANEL_AUO28)
	ILI93XX_CtrlWrite(0x10, 0x1490); // SAP, BT[3:0], AP, DSTB, SLP, STB
	ILI93XX_CtrlWrite(0x11, 0x0227); // DC1[2:0], DC0[2:0], VC[2:0]
	mdelay(50);
	ILI93XX_CtrlWrite(0x12, 0x001A); //Inernal reference voltage =Vci;
	mdelay(50);
	ILI93XX_CtrlWrite(0x13, 0x1400); // VDV[4:0] for VCOM amplitude
	ILI93XX_CtrlWrite(0x29, 0x000C); // VCM[5:0] for VCOMH
#elif (ILI9325_PANEL == PANEL_CUSTOM)
	ILI93XX_CtrlWrite(0x10, 0x1490); // SAP, BT[3:0], AP, DSTB, SLP, STB
	ILI93XX_CtrlWrite(0x11, 0x0227); // DC1[2:0], DC0[2:0], VC[2:0]
	mdelay(50);
	ILI93XX_CtrlWrite(0x12, 0x001C); //Inernal reference voltage =Vci;
	mdelay(50);
	ILI93XX_CtrlWrite(0x13, 0x0A00); // VDV[4:0] for VCOM amplitude
	ILI93XX_CtrlWrite(0x29, 0x000F); // VCM[5:0] for VCOMH
#endif
	mdelay(50);
}

static inline void ILI9325_Gamma()
{
#if (ILI9325_PANEL == PANEL_CPT24)
	ILI93XX_CtrlWrite(0x30, 0x0000);
	ILI93XX_CtrlWrite(0x31, 0x0506);
	ILI93XX_CtrlWrite(0x32, 0x0104);
	ILI93XX_CtrlWrite(0x35, 0x0207);
	ILI93XX_CtrlWrite(0x36, 0x000F);
	ILI93XX_CtrlWrite(0x37, 0x0306);
	ILI93XX_CtrlWrite(0x38, 0x0102);
	ILI93XX_CtrlWrite(0x39, 0x0707);
	ILI93XX_CtrlWrite(0x3C, 0x0702);
	ILI93XX_CtrlWrite(0x3D, 0x1604);
#elif (ILI9325_PANEL == PANEL_CPT28)
	ILI93XX_CtrlWrite(0x30, 0x0000);
	ILI93XX_CtrlWrite(0x31, 0x0305);
	ILI93XX_CtrlWrite(0x32, 0x0003);
	ILI93XX_CtrlWrite(0x35, 0x0304);
	ILI93XX_CtrlWrite(0x36, 0x000F);
	ILI93XX_CtrlWrite(0x37, 0x0407);
	ILI93XX_CtrlWrite(0x38, 0x0204);
	ILI93XX_CtrlWrite(0x39, 0x0707);
	ILI93XX_CtrlWrite(0x3C, 0x0403);
	ILI93XX_CtrlWrite(0x3D, 0x1604);
#elif (ILI9325_PANEL == PANEL_CMO24)
	ILI93XX_CtrlWrite(0x30, 0x0000);
	ILI93XX_CtrlWrite(0x31, 0x0406);
	ILI93XX_CtrlWrite(0x32, 0x0004);
	ILI93XX_CtrlWrite(0x35, 0x0305);
	ILI93XX_CtrlWrite(0x36, 0x0004);
	ILI93XX_CtrlWrite(0x37, 0x0207);
	ILI93XX_CtrlWrite(0x38, 0x0103);
	ILI93XX_CtrlWrite(0x39, 0x0707);
	ILI93XX_CtrlWrite(0x3C, 0x0503);
	ILI93XX_CtrlWrite(0x3D, 0x0004);
#elif (ILI9325_PANEL == PANEL_CMO28)
	ILI93XX_CtrlWrite(0x30, 0x0000);
	ILI93XX_CtrlWrite(0x31, 0x0603);
	ILI93XX_CtrlWrite(0x32, 0x0206);
	ILI93XX_CtrlWrite(0x35, 0x0206);
	ILI93XX_CtrlWrite(0x36, 0x0004);
	ILI93XX_CtrlWrite(0x37, 0x0105);
	ILI93XX_CtrlWrite(0x38, 0x0401);
	ILI93XX_CtrlWrite(0x39, 0x0707);
	ILI93XX_CtrlWrite(0x3C, 0x0602);
	ILI93XX_CtrlWrite(0x3D, 0x0004);
#elif (ILI9325_PANEL == PANEL_CMO32)
	ILI93XX_CtrlWrite(0x30, 0x0000);
	ILI93XX_CtrlWrite(0x31, 0x0603);
	ILI93XX_CtrlWrite(0x32, 0x0206);
	ILI93XX_CtrlWrite(0x35, 0x0206);
	ILI93XX_CtrlWrite(0x36, 0x0004);
	ILI93XX_CtrlWrite(0x37, 0x0105);
	ILI93XX_CtrlWrite(0x38, 0x0401);
	ILI93XX_CtrlWrite(0x39, 0x0707);
	ILI93XX_CtrlWrite(0x3C, 0x0602);
	ILI93XX_CtrlWrite(0x3D, 0x0004);
#elif (ILI9325_PANEL == PANEL_AUO28)
	ILI93XX_CtrlWrite(0x30, 0x0000);
	ILI93XX_CtrlWrite(0x31, 0x0607);
	ILI93XX_CtrlWrite(0x32, 0x0305);
	ILI93XX_CtrlWrite(0x35, 0x0000);
	ILI93XX_CtrlWrite(0x36, 0x1604);
	ILI93XX_CtrlWrite(0x37, 0x0204);
	ILI93XX_CtrlWrite(0x38, 0x0001);
	ILI93XX_CtrlWrite(0x39, 0x0707);
	ILI93XX_CtrlWrite(0x3C, 0x0000);
	ILI93XX_CtrlWrite(0x3D, 0x000F);
#elif (ILI9325_PANEL == PANEL_CUSTOM)
	ILI93XX_CtrlWrite(0x30, 0x0000);
	ILI93XX_CtrlWrite(0x31, 0x0203);
	ILI93XX_CtrlWrite(0x32, 0x0001);
	ILI93XX_CtrlWrite(0x35, 0x0205);
	ILI93XX_CtrlWrite(0x36, 0x030C);
	ILI93XX_CtrlWrite(0x37, 0x0607);
	ILI93XX_CtrlWrite(0x38, 0x0405);
	ILI93XX_CtrlWrite(0x39, 0x0707);
	ILI93XX_CtrlWrite(0x3C, 0x0502);
	ILI93XX_CtrlWrite(0x3D, 0x1008);
#endif
}

void ILI9325_Init(void)
{
	// VCI=2.8V
	//************* Reset LCD Driver ****************//
	ILI93XX_Reset(1);
	mdelay(1);
	ILI93XX_Reset(0);
	mdelay(10); // This delay time is necessary 
	ILI93XX_Reset(1);
	mdelay(50);
	//************* Start Initial Sequence **********//
	ILI93XX_CtrlWrite(0xE3, 0x3008); // Set internal timing
	ILI93XX_CtrlWrite(0xE7, 0x0012); // Set internal timing
	ILI93XX_CtrlWrite(0xEF, 0x1231); // Set internal timing
	ILI93XX_CtrlWrite(0x01, 0x0100); // set SS and SM bit
	ILI93XX_CtrlWrite(0x02, 0x0700); // set 1 line inversion
	// 03h : Entry Mode
	//       D15/D14 : TRI/DFM = 00 -> 65K mode
	//       D12     : BGR = 1      -> swap R and R (??)
	//       D5/D4   : I/D = 11     -> incliment/decliment:  V inc , H inc
	//       D3      : AM = 0       -> update direction = Horizontal
	ILI93XX_CtrlWrite(0x03, 0x1030); // set GRAM write direction and BGR=1.
	ILI93XX_CtrlWrite(0x04, 0x0000); // Resize register
#if (ILI9325_PANEL == PANEL_CPT24)
	ILI93XX_CtrlWrite(0x08, 0x0202); // set the back porch and front porch
#else
	ILI93XX_CtrlWrite(0x08, 0x0207); // set the back porch and front porch
#endif
	ILI93XX_CtrlWrite(0x09, 0x0000); // set non-display area refresh cycle ISC[3:0]
	ILI93XX_CtrlWrite(0x0A, 0x0000); // FMARK function
	ILI93XX_CtrlWrite(0x0C, 0x0000); // RGB interface setting
	ILI93XX_CtrlWrite(0x0D, 0x0000); // Frame marker Position
	ILI93XX_CtrlWrite(0x0F, 0x0000); // RGB interface polarity
	//*************Power On sequence ****************//
	ILI93XX_CtrlWrite(0x10, 0x0000); // SAP, BT[3:0], AP, DSTB, SLP, STB
	ILI93XX_CtrlWrite(0x11, 0x0007); // DC1[2:0], DC0[2:0], VC[2:0]
	ILI93XX_CtrlWrite(0x12, 0x0000); // VREG1OUT voltage
	ILI93XX_CtrlWrite(0x13, 0x0000); // VDV[4:0] for VCOM amplitude
	mdelay(200);                    // Dis-charge capacitor power voltage
	ILI9325_Poweron();
	ILI93XX_CtrlWrite(0x2B, 0x000C); // Set Frame Rate
	mdelay(50);
	ILI93XX_CtrlWrite(0x20, 0x0000); // GRAM horizontal Address
	ILI93XX_CtrlWrite(0x21, 0x0000); // GRAM Vertical Address
	// ----------- Adjust the Gamma Curve ----------//
	ILI9325_Gamma();
	//------------------ Set GRAM area ---------------//
	ILI93XX_CtrlWrite(0x50, 0x0000);       // Horizontal GRAM Start Address
	ILI93XX_CtrlWrite(0x51, PHYS_HSIZE-1); // Horizontal GRAM End Address
	ILI93XX_CtrlWrite(0x52, 0x0000);       // Vertical GRAM Start Address
	ILI93XX_CtrlWrite(0x53, PHYS_VSIZE-1); // Vertical GRAM End Address
	ILI93XX_CtrlWrite(0x60, 0xA700); // Gate Scan Line
	
	// 61h : Gate Scan Control
	//       D2      : NDL     = 0 -> Non-Display Area = black ?
	//       D1      : VLE     = 0 -> virtial scrolling = disabled
	//       D0      : REV     = 1 -> change endian
	ILI93XX_CtrlWrite(0x61, 0x0003); // NDL = 0,VLE = 1, REV = 1
	vscroll_base = 0;
	ILI93XX_CtrlWrite(0x6A, vscroll_base); // set scrolling line
	//-------------- Partial Display Control ---------//
	ILI93XX_CtrlWrite(0x80, 0x0000);
	ILI93XX_CtrlWrite(0x81, 0x0000);
	ILI93XX_CtrlWrite(0x82, 0x0000);
	ILI93XX_CtrlWrite(0x83, 0x0000);
	ILI93XX_CtrlWrite(0x84, 0x0000);
	ILI93XX_CtrlWrite(0x85, 0x0000);
	//-------------- Panel Control -------------------//
	ILI93XX_CtrlWrite(0x90, 0x0010);
	ILI93XX_CtrlWrite(0x92, 0x0600);
	ILI93XX_CtrlWrite(0x07, 0x0133); // 262K color and display ON
	col = row = 0;
}
	
void ILI9325_ExitSleep(void)
{
	//*************Power On sequence ******************//
	ILI93XX_CtrlWrite(0x10, 0x0080); // SAP, BT[3:0], AP, DSTB, SLP
	ILI93XX_CtrlWrite(0x11, 0x0000); // DC1[2:0], DC0[2:0], VC[2:0]
	ILI93XX_CtrlWrite(0x12, 0x0000); // VREG1OUT voltage
	ILI93XX_CtrlWrite(0x13, 0x0000); // VDV[4:0] for VCOM amplitude
	mdelay(200);                    // Dis-charge capacitor power voltage
	ILI9325_Poweron();
	ILI93XX_CtrlWrite(0x07, 0x0133); // 262K color and display ON
}

void ILI9325_EnterSleep(void)
{
	ILI93XX_CtrlWrite(0x07, 0x0131); // Set D1=0, D0=1
	mdelay(10);
	ILI93XX_CtrlWrite(0x07, 0x0130); // Set D1=0, D0=0
	mdelay(10);
	ILI93XX_CtrlWrite(0x07, 0x0000); // display OFF
	//************* Power OFF sequence **************//
	ILI93XX_CtrlWrite(0x10, 0x0080); // SAP, BT[3:0], APE, AP, DSTB, SLP
	ILI93XX_CtrlWrite(0x11, 0x0000); // DC1[2:0], DC0[2:0], VC[2:0]
	ILI93XX_CtrlWrite(0x12, 0x0000); // VREG1OUT voltage
	ILI93XX_CtrlWrite(0x13, 0x0000); // VDV[4:0] for VCOM amplitude
	mdelay(200);                    // Dis-charge capacitor power voltage
	ILI93XX_CtrlWrite(0x10, 0x0082); // SAP, BT[3:0], APE, AP, DSTB, SLP
}

extern int bg_color;
extern int fg_color;
extern unsigned char char_data[];

void ILI9325_Clear()
{
	int x,y;

	ILI93XX_CtrlWrite(0x20, 0x0000); // GRAM horizontal Address
	ILI93XX_CtrlWrite(0x21, 0x0000); // GRAM Vertical Address 
	ILI93XX_Ctrl(0x22);              // Write Data to GRAM
	for (y=0; y< PHYS_VSIZE; y++) {
		for (x=0; x< PHYS_HSIZE; x++) {
			ILI93XX_Write(bg_color);
		}
	}
}

void ILI9325_Pixel(int x, int y, int color)
{
	y -= vscroll_base;
	if (y < 0) y += PHYS_VSIZE;

	ILI93XX_CtrlWrite(0x20, x);     // GRAM horizontal Address
	ILI93XX_CtrlWrite(0x21, y);     // GRAM Vertical Address 
	ILI93XX_CtrlWrite(0x22, color); // Write Data to GRAM
}

#define CHAR_WIDTH	6
#define CHAR_HEIGHT	8

void ILI9325_Char(int x, int y, int ch)
{
	int i,j;
	unsigned char *p,dat;
	int color;
	x *= CHAR_WIDTH;
	y *= CHAR_HEIGHT;

	ch -= 0x20;
	if ((0 > ch) || (ch >= 95)) ch = '.' - 0x20;
	p = char_data + (ch * 5);
	for (i=0; i< 6; i++) {
		if (i==5) dat = 0;
		else dat = *p++;
		for (j=0; j<8; j++) {
			color = bg_color;
			if (dat & 0x01) color = fg_color;
			ILI9325_Pixel(x+i ,y+j , color);
			dat >>= 1;
		}
	}
}

void ILI9325_Scroll(int height)
{
	vscroll_base += height;
	if (vscroll_base >= PHYS_VSIZE) vscroll_base -= PHYS_VSIZE;
	ILI93XX_CtrlWrite(0x6A, vscroll_base); // set scrolling line
}

#define COL_SIZE	(PHYS_HSIZE / CHAR_WIDTH)
#define ROW_SIZE	(PHYS_VSIZE / CHAR_HEIGHT)

void ILI9325_Text(char *str)
{
	int ch;
	if (col >= COL_SIZE || col < 0) col = 0;
	if (row >= ROW_SIZE || row < 0) row = 0;

	while (ch = *str++) {
		if (ch == '\r') {
			// do nothing
		} else if (ch == '\n') {
			col = 0;
			row++;
		} else {
			ILI9325_Char(col, row, ch);
			col++;
			if (col >= COL_SIZE) {
				col = 0;
				row++;
			}
		}
		if (row >= ROW_SIZE) {
			ILI9325_Scroll(CHAR_HEIGHT);
			row = ROW_SIZE - 1;
		}
	}
}
