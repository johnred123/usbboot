/*
 * Copyright(C) 2009  Qi Hardware Inc.,
 * Authors: Xiangfu Liu <xiangfu@qi-hardware.com>
 *          Marek Lindner <lindner_marek@yahoo.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __INGENIC_USB_H__
#define __INGENIC_USB_H__

#include <stdint.h>

#define INGENIC_OUT_ENDPOINT	0x01
#define INGENIC_IN_ENDPOINT	0x81

#define VR_GET_CPU_INFO		0x00
#define VR_SET_DATA_ADDRESS	0x01
#define VR_SET_DATA_LENGTH	0x02
#define VR_FLUSH_CACHES		0x03
#define VR_PROGRAM_START1	0x04
#define VR_PROGRAM_START2	0x05
#define VR_NOR_OPS		0x06
#define VR_NAND_OPS		0x07
#define VR_SDRAM_OPS		0x08
#define VR_CONFIGRATION		0x09
#define VR_GET_NUM		0x0a

#define JZ4740V1	1
#define JZ4750V1	2
#define BOOT4740	3
#define BOOT4750	4

#define STAGE_ADDR_MSB(addr) ((addr) >> 16)
#define STAGE_ADDR_LSB(addr) ((addr) & 0xffff)

#define USB_PACKET_SIZE	512
#define USB_TIMEOUT	5000

#define VENDOR_ID	0x601a
#define PRODUCT_ID	0x4740
#define PRODUCT_ID2	0x4750

#define STAGE1_FILE_PATH ("xburst_stage1.bin")
#define STAGE2_FILE_PATH ("xburst_stage2.bin")

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

struct ingenic_dev {
	struct usb_device *usb_dev;
	struct usb_dev_handle *usb_handle;
	uint8_t interface;
	char cpu_info_buff[9];
	char *file_buff;
	unsigned int file_len;
};

int usb_ingenic_init(struct ingenic_dev *ingenic_dev);
int usb_get_ingenic_cpu(struct ingenic_dev *ingenic_dev);
int usb_ingenic_upload(struct ingenic_dev *ingenic_dev, int stage);
void usb_ingenic_cleanup(struct ingenic_dev *ingenic_dev);
int usb_send_data_address_to_ingenic(struct ingenic_dev *ingenic_dev, 
				     unsigned int stage_addr);
int usb_send_data_to_ingenic(struct ingenic_dev *ingenic_dev);
int usb_send_data_length_to_ingenic(struct ingenic_dev *ingenic_dev,
				    int len);
int usb_ingenic_nand_ops(struct ingenic_dev *ingenic_dev, int ops);
int usb_read_data_from_ingenic(struct ingenic_dev *ingenic_dev,unsigned char *buff, unsigned int len);
int usb_ingenic_configration(struct ingenic_dev *ingenic_dev, int ops);
int usb_ingenic_start(struct ingenic_dev *ingenic_dev, int rqst, int stage_addr);
int usb_ingenic_sdram_ops(struct ingenic_dev *ingenic_dev, int ops);

#endif	/* __INGENIC_USB_H__ */
