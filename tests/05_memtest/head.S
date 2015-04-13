/*
 * head.S
 *
 * Entry point of the firmware.
 * The firmware code are executed in the ICache.
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

	.text

	.extern c_main

	.globl _start
	.ent   _start
        .type   _start, @function
	.set noreorder
_start:
#if 0
	/*
	 * setup stack, jump to C code
	 */
	la	$sp, 0x80bffff0	/* sp */
#endif

	la	$gp, __gnu_local_gp
#if 0
	la	$gp, _gp
#endif
	j	c_main
	nop

	.set reorder
	.end _start

	.globl call_back
	.ent   call_back
        .type   call_back, @function
	.set noreorder
call_back:
	move	$t9,$a0
	j	$t9
	nop
	.set reorder
	.end call_back
