#include "ili93xx.h"

#define ILI9326_PANEL	PANEL_CPT28

#define PHYS_VSIZE	432
#define PHYS_HSIZE	240
static int vscroll_base;
static int col;
static int row;

static inline void ILI9326_Poweron()
{
#if (ILI9326_PANEL == PANEL_CPT28)
	ILI93XX_CtrlWrite(0x100, 0x1190); // SAP, BT[3:0], AP, DSTB, SLP, STB
	ILI93XX_CtrlWrite(0x101, 0x0227); // DC1 [2:0], DC0 [2:0], VC [2:0]
	mdelay (50); 
	ILI93XX_CtrlWrite(0x102, 0x01BD); // VREG1OUT voltage
	mdelay (50); 
	ILI93XX_CtrlWrite(0x103, 0x2D00); // VDV [4:0] for VCOM amplitude 
	ILI93XX_CtrlWrite(0x281, 0x000E); // VCM [5:0] for VCOMH 
#elif (ILI9326_PANEL == PANEL_WINTEK28)
	ILI93XX_CtrlWrite(0x100, 0x1190); // SAP, BT[3:0], AP, DSTB, SLP, STB
	ILI93XX_CtrlWrite(0x101, 0x0227); // DC1 [2:0], DC0 [2:0], VC [2:0]
	mdelay (50); 
	ILI93XX_CtrlWrite(0x102, 0x01BD); // VREG1OUT voltage
	mdelay (50); 
	ILI93XX_CtrlWrite(0x103, 0x2F00); // VDV [4:0] for VCOM amplitude 
	ILI93XX_CtrlWrite(0x281, 0x0008); // VCM [5:0] for VCOMH 
#elif (ILI9326_PANEL == PANEL_LPL30)
	ILI93XX_CtrlWrite(0x100, 0x1190); // SAP, BT[3:0], AP, DSTB, SLP, STB
	ILI93XX_CtrlWrite(0x101, 0x0127); // DC1 [2:0], DC0 [2:0], VC [2:0]
	mdelay (50); 
	ILI93XX_CtrlWrite(0x102, 0x01B8); // VREG1OUT voltage
	mdelay (50); 
	ILI93XX_CtrlWrite(0x103, 0x3A00); // VDV [4:0] for VCOM amplitude 
	ILI93XX_CtrlWrite(0x281, 0x0006); // VCM [5:0] for VCOMH 
#endif
	mdelay (50); 
}

static inline void ILI9326_Gamma()
{
#if (ILI9326_PANEL == PANEL_CPT28)
	ILI93XX_CtrlWrite(0x300, 0x0000);
	ILI93XX_CtrlWrite(0x301, 0x0707);
	ILI93XX_CtrlWrite(0x302, 0x0606);
	ILI93XX_CtrlWrite(0x305, 0x0000);
	ILI93XX_CtrlWrite(0x306, 0x0D00);
	ILI93XX_CtrlWrite(0x307, 0x0706);
	ILI93XX_CtrlWrite(0x308, 0x0005);
	ILI93XX_CtrlWrite(0x309, 0x0007);
	ILI93XX_CtrlWrite(0x30C, 0x0000);
	ILI93XX_CtrlWrite(0x30D, 0x000A);
#elif (ILI9326_PANEL == PANEL_WINTEK28)
	ILI93XX_CtrlWrite(0x300, 0x0000);
	ILI93XX_CtrlWrite(0x301, 0x0406);
	ILI93XX_CtrlWrite(0x302, 0x0303);
	ILI93XX_CtrlWrite(0x305, 0x0005);
	ILI93XX_CtrlWrite(0x306, 0x1604);
	ILI93XX_CtrlWrite(0x307, 0x0404);
	ILI93XX_CtrlWrite(0x308, 0x0103);
	ILI93XX_CtrlWrite(0x309, 0x0007);
	ILI93XX_CtrlWrite(0x30C, 0x0700);
	ILI93XX_CtrlWrite(0x30D, 0x0008);
#elif (ILI9326_PANEL == PANEL_LPL30)
	ILI93XX_CtrlWrite(0x300, 0x0000);
	ILI93XX_CtrlWrite(0x301, 0x0506);
	ILI93XX_CtrlWrite(0x302, 0x0405);
	ILI93XX_CtrlWrite(0x305, 0x0007);
	ILI93XX_CtrlWrite(0x306, 0x0008);
	ILI93XX_CtrlWrite(0x307, 0x0203);
	ILI93XX_CtrlWrite(0x308, 0x0102);
	ILI93XX_CtrlWrite(0x309, 0x0007);
	ILI93XX_CtrlWrite(0x30C, 0x0500);
	ILI93XX_CtrlWrite(0x30D, 0x000F);
#endif
}

void ILI9326_Init(void)
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
	ILI93XX_CtrlWrite(0x702, 0x3008); // Set internal timing
	ILI93XX_CtrlWrite(0x705, 0x0036); // Set internal timing
	ILI93XX_CtrlWrite(0x70B, 0x1213); // Set internal timing
	ILI93XX_CtrlWrite(0x001, 0x0100); // set SS and SM bit 
	ILI93XX_CtrlWrite(0x002, 0x0100); // set 1 line inversion 
	// 003h : Entry Mode
	//       D15/D14 : TRI/DFM = 00 -> 65K mode
	//       D12     : BGR = 1      -> swap R and R (??)
	//       D5/D4   : I/D = 11     -> incliment/decliment:  V inc , H inc
	//       D3      : AM = 0       -> update direction = Horizontal
	ILI93XX_CtrlWrite(0x003, 0x1030); // set GRAM write direction and BGR=1.
	ILI93XX_CtrlWrite(0x008, 0x0202); // set the back porch and front porch
	ILI93XX_CtrlWrite(0x009, 0x0000); // set non-display area refresh cycle ISC [3:0] 
	ILI93XX_CtrlWrite(0x00C, 0x0000); // RGB interface setting
	ILI93XX_CtrlWrite(0x00F, 0x0000); // RGB interface polarity

	//************* Power On sequence ****************//
	ILI93XX_CtrlWrite(0x100, 0x0000); // SAP, BT [3:0], AP, DSTB, SLP, STB
	ILI93XX_CtrlWrite(0x102, 0x0000); // VREG1OUT voltage 
	ILI93XX_CtrlWrite(0x103, 0x0000); // VDV[4:0] for VCOM amplitude
	mdelay (200);                         // Dis-charge capacitor power voltage
	ILI9326_Poweron();

	ILI93XX_CtrlWrite(0x200, 0x0000); // GRAM horizontal Address
	ILI93XX_CtrlWrite(0x201, 0x0000); // GRAM Vertical Address
	// ----------- Adjust the Gamma Curve ----------//
	ILI9326_Gamma();
	//------------------ Set GRAM area ---------------//
	ILI93XX_CtrlWrite(0x210, 0x0000); // Horizontal GRAM Start Address 
	ILI93XX_CtrlWrite(0x211, PHYS_HSIZE-1); // Horizontal GRAM End Address
	ILI93XX_CtrlWrite(0x212, 0x0000); // Vertical GRAM Start Address
	ILI93XX_CtrlWrite(0x213, PHYS_VSIZE-1); // Vertical GRAM Start Address
#if (ILI9326_PANEL == PANEL_CPT28)
	ILI93XX_CtrlWrite(0x400, 0x3100); // Gate Scan Line 400 lines
#else
	ILI93XX_CtrlWrite(0x400, 0x3500); // Gate Scan Line 400 lines
#endif
	// 401h : Gate Scan Control (Base Image Display Control)
	//       D2      : NDL     = 0 -> Non-Display Area = black ?
	//       D1      : VLE     = 0 -> virtial scrolling = disabled
	//       D0      : REV     = 1 -> change endian
	ILI93XX_CtrlWrite(0x401, 0x0001); // NDL = 0,VLE = 0, REV = 1
	vscroll_base = 0;
	ILI93XX_CtrlWrite(0x404, vscroll_base); // set scrolling line
	//-------------- Partial Display Control ---------//
	ILI93XX_CtrlWrite(0x500, 0x0000); //Partial Image 1 Display Position
	ILI93XX_CtrlWrite(0x501, 0x0000); //Partial Image 1 RAM Start/End Address
	ILI93XX_CtrlWrite(0x502, 0x0000); //Partial Image 1 RAM Start/End Address
	ILI93XX_CtrlWrite(0x503, 0x0000); //Partial Image 2 Display Position
	ILI93XX_CtrlWrite(0x504, 0x0000); //Partial Image 2 RAM Start/End Address
	ILI93XX_CtrlWrite(0x505, 0x0000); //Partial Image 2 RAM Start/End Address
	//-------------- Panel Control -------------------//
	ILI93XX_CtrlWrite(0x010, 0x0010); //DIVI[1:0];RTNI[4:0]
	ILI93XX_CtrlWrite(0x011, 0x0600); //NOWI[2:0];SDTI[2:0]
	ILI93XX_CtrlWrite(0x020, 0x0002); //DIVE[1:0];RTNE[5:0]
	ILI93XX_CtrlWrite(0x007, 0x0173); // 262K color and display ON
}

void ILI9326_ExitSleep(void)
{
	//************* Power On sequence ******************//
	ILI93XX_CtrlWrite(0x100, 0x0000); // SAP, BT[3:0], AP, DSTB, SLP
	mdelay (200); // Dis-charge capacitor power voltage
	ILI9326_Poweron();
	ILI93XX_CtrlWrite(0x007, 0x0173); // 262K color and display ON
}

void ILI9326_EnterSleep(void)
{
	ILI93XX_CtrlWrite(0x007, 0x0131); // Set D1=0, D0=1
	mdelay (10);
	ILI93XX_CtrlWrite(0x007, 0x0130); // Set D1=0, D0=0
	mdelay (10); 
	ILI93XX_CtrlWrite(0x007, 0x0000); // display OFF
	//************* Power OFF sequence **************//
	ILI93XX_CtrlWrite(0x100, 0x0000); // SAP, BT[3:0], APE, AP, DSTB, SLP
	mdelay (200);                     // Dis-charge capacitor power voltage
	ILI93XX_CtrlWrite(0x100, 0x0002); // SAP, BT[3:0], APE, AP, DSTB, SLP
}

extern int bg_color;
extern int fg_color;
extern unsigned char char_data[];

void ILI9326_Clear(int height)
{
	int x,y;

	if (height == 0) height = PHYS_VSIZE;
	ILI93XX_CtrlWrite(0x20, 0x0000); // GRAM horizontal Address
	ILI93XX_CtrlWrite(0x200, 0x0000); // GRAM horizontal Address
	ILI93XX_CtrlWrite(0x201, 0x0000); // GRAM Vertical Address 
	ILI93XX_Ctrl(0x202);              // Write Data to GRAM
	for (y=0; y< height; y++) {
		for (x=0; x< PHYS_HSIZE; x++) {
			ILI93XX_Write(bg_color);
		}
	}
}

void ILI9326_Pixel(int x, int y, int color)
{
	y += vscroll_base;
	if (y >= PHYS_VSIZE) y -= PHYS_VSIZE;

	ILI93XX_CtrlWrite(0x200, x);     // GRAM horizontal Address
	ILI93XX_CtrlWrite(0x201, y);     // GRAM Vertical Address 
	ILI93XX_CtrlWrite(0x202, color); // Write Data to GRAM
}

#define CHAR_WIDTH	6
#define CHAR_HEIGHT	8

void ILI9326_Char(int x, int y, int ch)
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
			ILI9326_Pixel(x+i ,y+j , color);
			dat >>= 1;
		}
	}
}

void ILI9326_Scroll(int height)
{
	ILI9326_Clear(height);
	vscroll_base += height;
	if (vscroll_base >= PHYS_VSIZE) vscroll_base -= PHYS_VSIZE;
	ILI93XX_CtrlWrite(0x6A, vscroll_base); // set scrolling line
}

#define COL_SIZE	(PHYS_HSIZE / CHAR_WIDTH)
#define ROW_SIZE	(PHYS_VSIZE / CHAR_HEIGHT)

void ILI9326_Text(char *str)
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
			ILI9326_Char(col, row, ch);
			col++;
			if (col >= COL_SIZE) {
				col = 0;
				row++;
			}
		}
		if (row >= ROW_SIZE) {
			ILI9326_Scroll(CHAR_HEIGHT);
			row = ROW_SIZE - 1;
		}
	}
}

void ILI9326_Hex(unsigned int  d)
{
	unsigned char c[9];
	char i;
	for(i = 0; i < 8; i++)
	{
		c[i] = (d >> ((7 - i) * 4)) & 0xf;
		if(c[i] < 10)
			c[i] += 0x30;
		else
			c[i] += (0x41 - 10);
	}

	c[8] = 0;

	ILI9326_Text("0x");
	ILI9326_Text(c);
}
