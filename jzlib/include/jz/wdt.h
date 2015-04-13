#ifndef _JZ_WDT2_H_
#define _JZ_WDT2_H_
#include <jz/jz_wdt.h>

/* avr-libc style wdt handling */

#define	WDTO_15MS	  123
#define	WDTO_30MS	  246
#define	WDTO_60MS	  492
#define	WDTO_120MS	  983
#define	WDTO_250MS	 2048
#define	WDTO_500MS	 4096
#define	WDTO_1S		 8192	/* = 32768/4 */
#define	WDTO_2S		16384
#define	WDTO_4S		32768
#define	WDTO_8S		0xffff

#define	WDTO_16S	( 8192<<4)
#define	WDTO_32S	(16384<<4)
#define	WDTO_64S	(32768<<4)
#define	WDTO_128S	(0xffff<<4)

#define wdt_reset() 	 	__wdt_set_count(0)
#define wdt_enable(value)	do { 		\
	__wdt_stop()				\
	__wdt_set_count(0)			\
	__wdt_select_rtcclk()			\
	if (value >= 65536) {			\
		__wdt_select_clk_div64() 	\
		__wdt_set_data(((value>>4)))	\
	} else {				\
		__wdt_select_clk_div4() 	\
		__wdt_set_data(value)		\
	}					\
	__wdt_start()				\
	} while (0)

#define wdt_disable()		__wdt_stop()

#endif /* _JZ_WDT2_H_ */
