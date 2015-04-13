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

#CFLAGS	?= -O2 -fno-unit-at-a-time -fno-zero-initialized-in-bss -mips32 \
#	-fno-pic -mno-abicalls -mno-shared -msoft-float -Wall
CFLAGS	?= -O2 -fno-zero-initialized-in-bss -mips32 -msoft-float -Wall
CFLAGS  +=	-I../../include

LDFLAGS	:= -EL -T target.ld 
LIBS	:= -L../.. -ljz -lgcc

PROGRAM := hello

OBJS	= head.o main.o 

all: $(PROGRAM).bin

$(PROGRAM).bin: $(PROGRAM).elf
	$(CROSS_COMPILE)objcopy -O binary $< $@
	$(CROSS_COMPILE)objdump -D $< > $(PROGRAM).dump
	$(CROSS_COMPILE)objdump -h $< > $(PROGRAM).map
	$(CROSS_COMPILE)nm -n $< > System.map

$(PROGRAM).elf: $(OBJS)
	$(CROSS_COMPILE)ld $(LDFLAGS) $(OBJS) $(LIBS) -o $@
.c.o:
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@
.S.o:
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@
clean:
	rm -f $(PROGRAM).bin $(PROGRAM).elf $(PROGRAM).dump $(PROGRAM).map
	rm -f $(OBJS)
	rm -f System.map
