#include <stdio.h>
#include <stdlib.h>
#include <jz/console.h>
#include <jz/jz_core.h>
#include <jz/jz_otp.h>
#include <jz/jz_cpm.h>
#include <jz/jz_emc.h>

#define REG_IS4725B	REG32(0xB00F0000)

void c_main(int argc, char *argv[]) {
	int i,argc2;
	char *argv2[10];
	uint32_t id;

	fdevopen_serial(stdout); /* generic */
	//fdevopen_ili9325(stdout, 0, 0, 0); /* for A-41 only */
	//fdevopen_ili9326(stdout, 0, 0, 0); /* for A-33 only */
	jzcon_append(stdout);
	fdevopen_ubcomm(stdout, (void *)argv);
	jzcon_append(stdout);
	jzcon_setup();

	argc2 = parse_args(argv[1], argv2, 10);
	printf("XXX hello world XXX %d 0x%lx\n",argc,(uint32_t)argv);

	id = read_c0_status();
	printf("c0_status    0x%08lx\n",id);
	id = read_c0_prid();
	printf("c0_prid      0x%08lx\n",id);

	printf("\n");
	printf("is4725B      0x%08x\n",REG_IS4725B);
	printf("\n");
	printf("otp_id0      0x%08x\n",REG_OTP_ID0);
	printf("otp_id1      0x%08x\n",REG_OTP_ID1);
	printf("otp_id2      0x%08x\n",REG_OTP_ID2);
	printf("otp_id3      0x%08x\n",REG_OTP_ID3);
	printf("otp_hw0      0x%08x\n",REG_OTP_HW0);
	printf("otp_hw1      0x%08x\n",REG_OTP_HW1);
	printf("\n");

	id = REG_OTP_ID0;
	printf("otp_product  0x%02x\n",(id && OTP_ID0_PID_MASK)>>OTP_ID0_PID_BIT);
	printf("otp_fundary  0x%02x\n",(id && OTP_ID0_FID_MASK)>>OTP_ID0_FID_BIT);
	printf("otp_mask     0x%02x\n",(id && OTP_ID0_MID_MASK)>>OTP_ID0_MID_BIT);
	printf("otp_wafer    0x%04x\n",(id && OTP_ID0_WID_MASK)>>OTP_ID0_WID_BIT);
	id = REG_OTP_ID1;
	printf("otp_lot      0x%06x\n",(id && OTP_ID1_LID_MASK)>>OTP_ID1_LID_BIT);
	id = REG_OTP_ID2;
	printf("otp_xadr     0x%02x\n",(id && OTP_ID2_XADR_MASK)>>OTP_ID2_XADR_BIT);
	printf("otp_yadr     0x%02x\n",(id && OTP_ID2_YADR_MASK)>>OTP_ID2_YADR_BIT);
	printf("otp_tdate    0x%04x\n",(id && OTP_ID2_TDATE_MASK)>>OTP_ID2_TDATE_BIT);
	id = REG_OTP_HW1;
	printf("   mc %d "	,(int)((id>>30) & 3));
	printf("me %d "		,(int)((id>>28) & 3));
	printf("de %d "		,(int)((id>>26) & 3));
	printf("idct %d\n"	,(int)((id>>24) & 3));
	printf("   uart3 %d "	,(int)((id>>22) & 3));
	printf("uart2 %d "	,(int)((id>>20) & 3));
	printf("uart1 %d "	,(int)((id>>18) & 3));
	printf("uart0 %d\n"	,(int)((id>>16) & 3));
	printf("    ssi1 %d "	,(int)((id>>14) & 3));
	printf("ssi0 %d "	,(int)((id>>12) & 3));
	printf("msc1 %d "	,(int)((id>>10) & 3));
	printf("msc0 %d\n"	,(int)((id>>8) & 3));
	printf("    uhc %d "	,(int)((id>>6) & 3));
	printf("tve %d "	,(int)((id>>4) & 3));
	printf("tssi %d "	,(int)((id>>2) & 3));
	printf("cim %d\n"	,(int)((id>>0) & 3));

	printf("cpuclock     %d\n",__cpm_get_cclk());
	printf("memsize      0x%08lx\n",__emc_get_sdram_size());
#if 0
	for (i=0; i<10; i++) {
		ubcomm_proc();
	}
#endif
	return;	
}
