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

DEFINES ?= -D__JZ4725B__
#CFLAGS	?= -O2 -fno-unit-at-a-time -fno-zero-initialized-in-bss -mips32 \
#	-fno-pic -mno-abicalls -mno-shared -msoft-float -Wall
CFLAGS  ?= -O2 -fno-zero-initialized-in-bss -mips32 -fno-pic -msoft-float -Wall
CFLAGS  += -I../include -I.. -I.
CFLAGS  += $(DEFINES)

OBJS	= cache.o  delay_ms.o  delay_us.o vector.o ostimer.o timer.o \
	interrupt.o intent.o hivect.o 

all: $(OBJS)

.c.o:
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@
.S.o:
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
