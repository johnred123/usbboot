#
# Authors: Xiangfu Liu <xiangfu@qi-hardware.com>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version
# 3 of the License, or (at your option) any later version.
#

INFLASH_SRC_PATH = ../src
XBURST_INCLUDE_PATH = ../xburst_include

CROSS_COMPILE=mipsel-linux-

#CFLAGS	:= -O2 -fno-unit-at-a-time -fno-zero-initialized-in-bss \
#	-mips32 -fno-pic -mno-abicalls \
#	-I$(INFLASH_SRC_PATH) -I$(XBURST_INCLUDE_PATH)
CFLAGS	:= -O2 -fno-zero-initialized-in-bss \
	-mips32 -G 0 \
	-I$(INFLASH_SRC_PATH) -I$(XBURST_INCLUDE_PATH)
LDFLAGS	:= -nostdlib -EL -T target.ld 

OBJS	= head.o main.o common.o board_4740.o board_4750.o debug.o

all: xburst_stage1.bin

xburst_stage1.bin: xburst_stage1.elf
	$(CROSS_COMPILE)objcopy -O binary $< $@
	$(CROSS_COMPILE)objdump -D $< > xburst_stage1.dump
	$(CROSS_COMPILE)objdump -h $< > xburst_stage1.map
	$(CROSS_COMPILE)nm -n $< > System.map

xburst_stage1.elf: $(OBJS)
	$(CROSS_COMPILE)ld $(LDFLAGS) $(OBJS) -o $@
.c.o:
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@
.S.o:
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@
clean:
	rm -f xburst_stage1.bin xburst_stage1.elf xburst_stage1.dump xburst_stage1.map
	rm -f $(OBJS)
	rm -f System.map
