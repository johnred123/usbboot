#
# Authors: Xiangfu Liu <xiangfu@qi-hardware.com>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version
# 3 of the License, or (at your option) any later version.
#

ifeq ($(CROSS_COMPILE),)
$(error CROSS_COMPILE variable not set, should point to .../mipsel-openwrt-linux-)
endif

CFLAGS	?= -O2 -mips32 -fno-zero-initialized-in-bss 
LDFLAGS	:= -nostdlib -EL -T target.ld 

OBJS	= head.o main.o msg.o ili9325.o ili93xx.o setjmp.o cache.o

all: privtest.bin

privtest.bin: privtest.elf
	$(CROSS_COMPILE)objcopy -O binary $< $@
	$(CROSS_COMPILE)objdump -D $< > privtest.dump
	$(CROSS_COMPILE)objdump -h $< > privtest.map
	$(CROSS_COMPILE)nm -n $< > System.map

privtest.elf: $(OBJS)
	$(CROSS_COMPILE)ld $(LDFLAGS) $(OBJS) -o $@
.c.o:
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@
.S.o:
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@
clean:
	rm -f privtest.bin privtest.elf privtest.dump privtest.map
	rm -f $(OBJS)
	rm -f System.map
