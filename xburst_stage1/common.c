/*
 * device board 
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

#include "jz4740.h"
#include "configs.h"

void serial_putc (const char c)
{
	volatile u8 *uart_lsr = (volatile u8 *)(UART_BASE + OFF_LSR);
	volatile u8 *uart_tdr = (volatile u8 *)(UART_BASE + OFF_TDR);

	if (c == '\n') serial_putc ('\r');

	/* Wait for fifo to shift out some bytes */
	while ( !((*uart_lsr & (UART_LSR_TDRQ | UART_LSR_TEMT)) == 0x60) );

	*uart_tdr = (u8)c;
}

void serial_puts (const char *s)
{
	while (*s) {
		serial_putc (*s++);
	}
}

int serial_getc (void)
{
	volatile u8 *uart_rdr = (volatile u8 *)(UART_BASE + OFF_RDR);

	while (!serial_tstc());

	return *uart_rdr;
}

int serial_tstc (void)
{
	volatile u8 *uart_lsr = (volatile u8 *)(UART_BASE + OFF_LSR);

	if (*uart_lsr & UART_LSR_DR) {
		/* Data in rfifo */
		return (1);
	}
	return 0;
}

void serial_init(void)
{
	volatile u8 *uart_fcr = (volatile u8 *)(UART_BASE + OFF_FCR);
	volatile u8 *uart_lcr = (volatile u8 *)(UART_BASE + OFF_LCR);
	volatile u8 *uart_ier = (volatile u8 *)(UART_BASE + OFF_IER);
	volatile u8 *uart_sircr = (volatile u8 *)(UART_BASE + OFF_SIRCR);

	/* Disable port interrupts while changing hardware */
	*uart_ier = 0;

	/* Disable UART unit function */
	*uart_fcr = ~UART_FCR_UUE;

	/* Set both receiver and transmitter in UART mode (not SIR) */
	*uart_sircr = ~(SIRCR_RSIRE | SIRCR_TSIRE);

	/* Set databits, stopbits and parity. (8-bit data, 1 stopbit, no parity) */
	*uart_lcr = UART_LCR_WLEN_8 | UART_LCR_STOP_1;

	/* Set baud rate */
	if ( CPU_ID == 0x4740 )
		serial_setbrg_4740();
	else
		serial_setbrg_4750();

	/* Enable UART unit, enable and clear FIFO */
	*uart_fcr = UART_FCR_UUE | UART_FCR_FE | UART_FCR_TFLS | UART_FCR_RFLS;
}

void serial_put_hex(unsigned int  d)
{
	unsigned char c[12];
	char i;
	for(i = 0; i < 8;i++)
	{
		c[i] = (d >> ((7 - i) * 4)) & 0xf;
		if(c[i] < 10)
			c[i] += 0x30;
		else
			c[i] += (0x41 - 10);
	}
	c[8] = '\n';
	c[9] = 0;
	serial_puts(c);

}
