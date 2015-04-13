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

CFLAGS	?= -O2 -fno-zero-initialized-in-bss -mips32 -
LDFLAGS	:= -nostdlib -EL -T target.ld 

OBJS	= head.o main.o msg.o

all: portout.bin

portout.bin: portout.elf
	$(CROSS_COMPILE)objcopy -O binary $< $@
	$(CROSS_COMPILE)objdump -D $< > portout.dump
	$(CROSS_COMPILE)objdump -h $< > portout.map
	$(CROSS_COMPILE)nm -n $< > System.map

portout.elf: $(OBJS)
	$(CROSS_COMPILE)ld $(LDFLAGS) $(OBJS) -o $@
.c.o:
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@
.S.o:
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@
clean:
	rm -f portout.bin portout.elf portout.dump portout.map
	rm -f $(OBJS)
	rm -f System.map
