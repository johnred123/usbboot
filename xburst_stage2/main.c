/*
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
#include "usb_boot_defines.h"

extern void usb_main();
unsigned int start_addr,got_start,got_end;
extern unsigned int UART_BASE;
struct fw_args *fw_args;

extern struct comm_struct comm_area;
extern void udc4740Proc(void);

extern void msg_init(void);

void c_main(void)
{
	volatile unsigned int addr,offset;
	/* get absolute start address  */
	__asm__ __volatile__(			
		"move %0, $s4\n\t"
		: "=r"(start_addr)
		: 
		);			

	/* get related GOT address  */
	__asm__ __volatile__(			
		"la %0, _gp\n\t"
		"la %1, _got_end\n\t"
		: "=r"(got_start),"=r"(got_end)
		: 
		);

	/* calculate offset and correct GOT*/
	offset = start_addr - 0x80000000;	
 	got_start += offset;
	got_end  += offset;

	for ( addr = got_start + 8; addr < got_end; addr += 4 )
	{
		*((volatile unsigned int *)(addr)) += offset;   //add offset to correct all GOT
	}

	fw_args = (struct fw_args *)(start_addr + 0x8);       //get the fw args from memory
	if ( fw_args->use_uart > 3 ) fw_args->use_uart = 0;
	UART_BASE = 0xB0030000 + fw_args->use_uart * 0x1000;

	msg_init();
	serial_puts("\n Stage2 start address is :\t");
	serial_put_hex(start_addr);
	serial_puts("\n Address offset is:\t");
	serial_put_hex(offset);
	serial_puts("\n GOT correct to :\t");
	serial_put_hex(got_start);
	fw_args->start = (unsigned int)(void *)udc4740Proc;
	fw_args->size = (unsigned int)(void *)(&comm_area);
	usb_main();
}
