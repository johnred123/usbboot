/*
 * USB_BOOT Handle routines
 *
 * Copyright (C) 2009 Qi Hardware Inc.,
 * Author:  Xiangfu Liu <xiangfu@qi-hardware.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 3 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301, USA
 */

#include "jz4740.h"
#include "usb.h" 
#include "error.h"
#include "usb_boot.h"
#include "usb_boot_defines.h"
#include "nandflash.h"
#include "udc.h"
#define dprintf(x) serial_puts(x)

unsigned int (*nand_query)(u8 *);
int (*nand_init)(int bus_width, int row_cycle, int page_size, int page_per_block,
		 int,int,int,int);
int (*nand_fini)(void);
u32 (*nand_program)(void *context, int spage, int pages,int option);
u32 (*nand_erase)(int blk_num, int sblk, int force);
u32 (*nand_read)(void *buf, u32 startpage, u32 pagenum,int option);
u32 (*nand_read_oob)(void *buf, u32 startpage, u32 pagenum);
u32 (*nand_read_raw)(void *buf, u32 startpage, u32 pagenum,int);
u32 (*nand_mark_bad) (int bad);
void (*nand_enable) (unsigned int csn);
void (*nand_disable) (unsigned int csn);

struct hand Hand,*Hand_p;
extern struct fw_args *fw_args;
extern u32 Bulk_buf[BULK_BUF_SIZE];
extern struct comm_struct comm_area;
extern u16 handshake_PKT[4];
extern udc_state;
extern void *memset(void *s, int c, size_t count);
extern void *memcpy(void *dest, const void *src, size_t count);

extern void comm_msgcpy(u8 *dest, u32 len);

extern void usb_reentrant_fix();

u32 ret_dat;
u32 start_addr;  //program operation start address or sector
u32 ops_length;  //number of operation unit ,in byte or sector
u32 ram_addr;

static inline unsigned int read_c0_status() {
	unsigned int c;
	__asm__ __volatile__("		\
		.set noreorder;		\
		mfc0	%0,$12;		\
		.set reorder"		\
		: "=r" (c): );
	return c;
}

static inline void write_c0_status(unsigned int c) {
	__asm__ __volatile__("		\
		.set noreorder;		\
		mtc0	$zero,$13;	\
		ssnop;			\
		ssnop;			\
		ssnop;			\
		sll $zero,$zero,3;			\
		nop;			\
		mtc0	%0,$12;		\
		ssnop;			\
		ssnop;			\
		ssnop;			\
		sll $zero,$zero,3;			\
		.set reorder"		\
		: : "r" (c));
}

static inline unsigned long read_gp() {
	unsigned int c = 0;
	__asm__ __volatile__("  \
		.set noreorder; \
		move    %0,$gp; \
		.set reorder" : "=r" (c): );
	return c;
}

static inline void write_gp(unsigned long c) {
	__asm__ __volatile__("\
		.set noreorder;         \
		move    $gp,%0;         \
		.set reorder" :: "r" (c));
}

void config_flash_info()
{
}

void dump_data(unsigned int *p, int size)
{
	int i;
	for(i = 0; i < size; i ++)
		serial_put_hex(*p++);
}

void config_hand()
{
	struct hand *hand_p;
	hand_p=(struct hand *)Bulk_buf;
	memcpy(&Hand, (unsigned char *)Bulk_buf, sizeof(struct hand));

#if 0
	Hand.nand_bw=hand_p->nand_bw;
	Hand.nand_rc=hand_p->nand_rc;
	Hand.nand_ps=hand_p->nand_ps;
	Hand.nand_ppb=hand_p->nand_ppb;
	Hand.nand_force_erase=hand_p->nand_force_erase;
	Hand.nand_pn=hand_p->nand_pn;
	Hand.nand_os=hand_p->nand_os;

	Hand.nand_eccpos=hand_p->nand_eccpos;
	Hand.nand_bbpos=hand_p->nand_bbpos;
	Hand.nand_bbpage=hand_p->nand_bbpage;
	serial_put_hex(Hand.fw_args.cpu_id);
	serial_put_hex(Hand.fw_args.ext_clk);
#endif
}

int GET_CUP_INFO_Handle()
{
	char temp1[8]="Boot4740",temp2[8]="Boot4750";
	dprintf("\n GET_CPU_INFO:\t");
	serial_put_hex(Hand.fw_args.cpu_id);
	if (Hand.fw_args.cpu_id == 0x4740)
		HW_SendPKT(0, temp1, 8);
	else
		HW_SendPKT(0, temp2, 8);
	udc_state = IDLE;
	return ERR_OK; 
}
	       
int SET_DATA_ADDERSS_Handle(u8 *buf)
{
	USB_DeviceRequest *dreq = (USB_DeviceRequest *)buf;
	start_addr=(((u32)dreq->wValue)<<16)+(u32)dreq->wIndex;
	dprintf("\n SET ADDRESS:\t");
	serial_put_hex(start_addr);
	return ERR_OK;
}
		
int SET_DATA_LENGTH_Handle(u8 *buf)
{
	USB_DeviceRequest *dreq = (USB_DeviceRequest *)buf;
	ops_length=(((u32)dreq->wValue)<<16)+(u32)dreq->wIndex;
	dprintf("\n DATA_LENGTH:\t");
	serial_put_hex(ops_length);
	return ERR_OK;
}

int FLUSH_CACHES_Handle()
{
	return ERR_OK;
}
    
int PROGRAM_START1_Handle(u8 *buf)
{
	USB_DeviceRequest *dreq = (USB_DeviceRequest *)buf;
	ram_addr=(((u32)dreq->wValue)<<16)+(u32)dreq->wIndex;
	//dprintf("\n RAM ADDRESS :%x", ram_addr);
	return ERR_OK;
}

int PROGRAM_START2_Handle(u8 *buf)
{
	unsigned int save_gp;
	extern void udc4740Proc();
	void (*f)(int,void *,void *);
	unsigned int c;
	USB_DeviceRequest *dreq = (USB_DeviceRequest *)buf;
	f=(void *) ((((u32)dreq->wValue)<<16)+(u32)dreq->wIndex);
	__dcache_writeback_all();
	__icache_invalidate_all();
	//stop udc connet before execute program!
#if 0
	jz_writeb(USB_REG_POWER,0x0);   //High speed
#endif
	//dprintf("\n Execute program at %x",(u32)f);
	usb_reentrant_fix();
	comm_area.proc_func = (void *)udc4740Proc;
	comm_area.args[0] = NULL;
	comm_area.args[1] = (void *)(comm_area.command_line);
#if 1
	dprintf("\n Execute program at ");
	serial_put_hex((u32)f);
	dprintf("\n Command line: ");
	dprintf(comm_area.command_line);
	dprintf("\n comm_area addr:");
	serial_put_hex((u32)(&comm_area));
	dprintf("\n proc_func addr:");
	serial_put_hex((u32)(comm_area.proc_func));
	dprintf("\n");
#endif
	c = read_c0_status();
	c |= 0x10000000;
	c &= ~0x1f;
	write_c0_status(c);
	save_gp = read_gp();
	f(2, comm_area.args, NULL);
	write_gp(save_gp);
	__icache_invalidate_all();
	return ERR_OK;
}
	      
int NOR_OPS_Handle(u8 *buf)
{
	USB_DeviceRequest *dreq = (USB_DeviceRequest *)buf;
	return ERR_OK;
}

int NAND_OPS_Handle(u8 *buf)
{
	USB_DeviceRequest *dreq = (USB_DeviceRequest *)buf;
	u32 temp;
	int option;
	u8 CSn;

	CSn = (dreq->wValue>>4) & 0xff;
	option = (dreq->wValue>>12) & 0xff;
	nand_enable(CSn);
	switch ((dreq->wValue)&0xf)
	{
	case NAND_QUERY:
		dprintf("\n Request : NAND_QUERY!");
		nand_query((u8 *)Bulk_buf);
		HW_SendPKT(1, Bulk_buf, 8);
		handshake_PKT[3]=(u16)ERR_OK;
		udc_state = BULK_IN;
		break;
	case NAND_INIT:
		dprintf("\n Request : NAND_INIT!");

		break;
	case NAND_MARK_BAD:
		dprintf("\n Request : NAND_MARK_BAD!");
		ret_dat = nand_mark_bad(start_addr);
		handshake_PKT[0] = (u16) ret_dat;
		handshake_PKT[1] = (u16) (ret_dat>>16);
		HW_SendPKT(1,handshake_PKT,sizeof(handshake_PKT));
		udc_state = IDLE;		

		break;
	case NAND_READ_OOB:
		dprintf("\n Request : NAND_READ_OOB!");
		memset(Bulk_buf,0,ops_length*Hand.nand_ps);
		ret_dat = nand_read_oob(Bulk_buf,start_addr,ops_length);
		handshake_PKT[0] = (u16) ret_dat;
		handshake_PKT[1] = (u16) (ret_dat>>16);
		HW_SendPKT(1,(u8 *)Bulk_buf,ops_length*Hand.nand_ps);
		udc_state = BULK_IN;		
		break;
	case NAND_READ_RAW:
		dprintf("\n Request : NAND_READ_RAW!");
		switch (option)
		{
		case OOB_ECC:
			nand_read_raw(Bulk_buf,start_addr,ops_length,option);
			HW_SendPKT(1,(u8 *)Bulk_buf,ops_length*(Hand.nand_ps + Hand.nand_os));
			handshake_PKT[0] = (u16) ret_dat;
			handshake_PKT[1] = (u16) (ret_dat>>16);
			udc_state = BULK_IN;
			break;
		default:
			nand_read_raw(Bulk_buf,start_addr,ops_length,option);
			HW_SendPKT(1,(u8 *)Bulk_buf,ops_length*Hand.nand_ps);
			handshake_PKT[0] = (u16) ret_dat;
			handshake_PKT[1] = (u16) (ret_dat>>16);
			udc_state = BULK_IN;
			break;
		}
		break;
	case NAND_ERASE:
		dprintf("\n Request : NAND_ERASE");
		ret_dat = nand_erase(ops_length,start_addr,
			   Hand.nand_force_erase);
		handshake_PKT[0] = (u16) ret_dat;
		handshake_PKT[1] = (u16) (ret_dat>>16);
		HW_SendPKT(1,handshake_PKT,sizeof(handshake_PKT));
		udc_state = IDLE;
		dprintf(" ... finished.");
		break;
	case NAND_READ:
		dprintf("\n Request : NAND_READ!");
		switch (option) {
		case 	OOB_ECC:
			ret_dat = nand_read(Bulk_buf,start_addr,ops_length,OOB_ECC);
			handshake_PKT[0] = (u16) ret_dat;
			handshake_PKT[1] = (u16) (ret_dat>>16);
			HW_SendPKT(1,(u8 *)Bulk_buf,ops_length*(Hand.nand_ps + Hand.nand_os ));
			udc_state = BULK_IN;
			break;
		case 	OOB_NO_ECC:
			ret_dat = nand_read(Bulk_buf,start_addr,ops_length,OOB_NO_ECC);
			handshake_PKT[0] = (u16) ret_dat;
			handshake_PKT[1] = (u16) (ret_dat>>16);
			HW_SendPKT(1,(u8 *)Bulk_buf,ops_length*(Hand.nand_ps + Hand.nand_os));
			udc_state = BULK_IN;
			break;
		case 	NO_OOB:
			ret_dat = nand_read(Bulk_buf,start_addr,ops_length,NO_OOB);
			handshake_PKT[0] = (u16) ret_dat;
			handshake_PKT[1] = (u16) (ret_dat>>16);
			HW_SendPKT(1,(u8 *)Bulk_buf,ops_length*Hand.nand_ps);
			udc_state = BULK_IN;
			break;
		}
		dprintf(" ... finished.");
		break;
	case NAND_PROGRAM:
		dprintf("\n Request : NAND_PROGRAM!");
		ret_dat = nand_program((void *)Bulk_buf,
			     start_addr,ops_length,option);
		handshake_PKT[0] = (u16) ret_dat;
		handshake_PKT[1] = (u16) (ret_dat>>16);
		HW_SendPKT(1,handshake_PKT,sizeof(handshake_PKT));
		udc_state = IDLE;
		dprintf(" ... finished.");
		break;
	case NAND_READ_TO_RAM:
		dprintf("\n Request : NAND_READ_TO_RAM!");
		nand_read((u8 *)ram_addr,start_addr,ops_length,NO_OOB);
		__dcache_writeback_all();
		handshake_PKT[3]=(u16)ERR_OK;
		HW_SendPKT(1,handshake_PKT,sizeof(handshake_PKT));
		udc_state = IDLE;
		break;
	default:
		nand_disable(CSn);
		return ERR_OPS_NOTSUPPORT;
	}

	return ERR_OK;
}

int SDRAM_OPS_Handle(u8 *buf)
{
	USB_DeviceRequest *dreq = (USB_DeviceRequest *)buf;
	u32 temp,i;
	u32 option;
	u8 *obj;

	option = (dreq->wValue>>12) & 0xff;
	ret_dat = 0;
	switch ((dreq->wValue)&0xf)
	{
	case 	SDRAM_LOAD:
		//dprintf("\n Request : SDRAM_LOAD!");
		if (option == SPACE_RAM) {
			ret_dat = (u32)memcpy((u8 *)start_addr,Bulk_buf,ops_length);
		} else if (option == SPACE_INPUT) {
			ret_dat = (u32)memcpy((u8 *)(comm_area.input_line+start_addr),Bulk_buf,ops_length);
		} else if (option == SPACE_CMD) {
			ret_dat = (u32)memcpy((u8 *)(comm_area.command_line+start_addr),Bulk_buf,ops_length);
		}
		__dcache_writeback_all();
		handshake_PKT[0] = (u16) ret_dat;
		handshake_PKT[1] = (u16) (ret_dat>>16);
		HW_SendPKT(1,handshake_PKT,sizeof(handshake_PKT));
		udc_state = IDLE;
		break;
	case 	SDRAM_READ:
		//dprintf("\n Request : SDRAM_READ!");
		memset(Bulk_buf,0,ops_length);
		switch(option) {
			case SPACE_RAM:
				ret_dat = (u32)memcpy(Bulk_buf,(u8 *)start_addr,ops_length);
				break;
			case SPACE_GPIO:
				((u32 *)Bulk_buf)[0] = REG_GPIO_PXPIN(0);
				((u32 *)Bulk_buf)[1] = REG_GPIO_PXPIN(1);
				((u32 *)Bulk_buf)[2] = REG_GPIO_PXPIN(2);
				((u32 *)Bulk_buf)[3] = REG_GPIO_PXPIN(3);
				if (fw_args->pin_num > 32 * 4) {
				    ((u32 *)Bulk_buf)[4] = REG_GPIO_PXPIN(4);
				    ((u32 *)Bulk_buf)[5] = REG_GPIO_PXPIN(5);
				} else {
				    ((u32 *)Bulk_buf)[4] = 0xffffffff;
				    ((u32 *)Bulk_buf)[5] = 0xffffffff;
				}
				break;
			case SPACE_MSG:
				comm_msgcpy((u8 *)Bulk_buf,ops_length);
				break;
		}
		handshake_PKT[0] = (u16) ret_dat;
		handshake_PKT[1] = (u16) (ret_dat>>16);
		HW_SendPKT(1,(u8 *)Bulk_buf,ops_length);
		udc_state = BULK_IN;		
		break;
	}
	return ERR_OK;
}

void Borad_Init()
{
	dprintf("\n Borad_init! ");
	serial_put_hex(Hand.fw_args.cpu_id);
	switch (Hand.fw_args.cpu_id)
	{
	case 0x4740:
		//Init nand flash
		nand_init_4740(Hand.nand_bw, Hand.nand_rc, Hand.nand_ps, 
			       Hand.nand_ppb, Hand.nand_bbpage, Hand.nand_bbpos,
			       Hand.nand_force_erase, Hand.nand_eccpos);
	
		nand_program = nand_program_4740;
		nand_erase = nand_erase_4740;
		nand_read = nand_read_4740;
		nand_read_oob = nand_read_oob_4740;
		nand_read_raw = nand_read_raw_4740;
		nand_query = nand_query_4740;
		nand_enable = nand_enable_4740;
		nand_disable = nand_disable_4740;
		nand_mark_bad = nand_mark_bad_4740;
	break;
	case 0x4750:
		//Init nand flash
		nand_init_4750(Hand.nand_bw, Hand.nand_rc, Hand.nand_ps,
			       Hand.nand_ppb, Hand.nand_bchbit, Hand.nand_eccpos,
			       Hand.nand_bbpos, Hand.nand_bbpage, Hand.nand_force_erase);

		nand_program = nand_program_4750;
		nand_erase = nand_erase_4750;
		nand_read = nand_read_4750;
		nand_read_oob = nand_read_oob_4750;
		nand_read_raw = nand_read_raw_4750;
		nand_query = nand_query_4750;
		nand_enable = nand_enable_4750;
		nand_disable = nand_disable_4750;
		nand_mark_bad = nand_mark_bad_4750;
	break;
	default:
		serial_puts("Not support CPU ID!");
	}
}

int CONFIGRATION_Handle(u8 *buf)
{
	dprintf("\n Configuration:\t");

	USB_DeviceRequest *dreq = (USB_DeviceRequest *)buf;
	switch ((dreq->wValue)&0xf) {
	case DS_flash_info:
		dprintf("DS_flash_info_t!");
		config_flash_info();
		break;

	case DS_hand:
		dprintf("DS_hand_t!");
		config_hand();
		break;
	default:
		;
	}

	Borad_Init();
	return ERR_OK;
}


