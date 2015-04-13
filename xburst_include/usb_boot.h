/*
 * "Ingenic flash tool" - flash the Ingenic CPU via USB
 *
 * Copyright 2009 (C) Qi Hardware Inc.,
 * Author: Xiangfu Liu <xiangfu@qi-hardware.com>
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

#ifndef __USB_BOOT_H__
#define __USB_BOOT_H__

#define BULK_BUF_SIZE (2048 * 128)
#define MSGBUF_SIZE	(4096)

enum UDC_STATE
{
	IDLE,
	BULK_IN,
	BULK_OUT
};

enum USB_JZ4740_REQUEST	/* add for USB_BOOT */
{
	VR_GET_CUP_INFO = 0,
	VR_SET_DATA_ADDERSS,
	VR_SET_DATA_LENGTH,
	VR_FLUSH_CACHES,
	VR_PROGRAM_START1,
	VR_PROGRAM_START2,
	VR_NOR_OPS,
	VR_NAND_OPS,
	VR_SDRAM_OPS,
	VR_CONFIGRATION
};

#define COMM_CMD_SIZE	256
#define COMM_INPUT_SIZE	256
#define COMM_MSG_SIZE	4096

struct comm_struct {
        void *args[2];
        volatile int msg_length; // length of msgbuf
        volatile unsigned int msg_length_total; // total length of msgbuf
	void (*proc_func)();
	int filler[3];
	char msgbuf[COMM_MSG_SIZE];
        char input_line[COMM_INPUT_SIZE];
        char command_line[COMM_CMD_SIZE];
};

#endif	/* __USB_BOOT_H__ */
