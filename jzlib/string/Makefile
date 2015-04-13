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
#	-fno-pic  -mno-abicalls -mno-shared
CFLAGS  ?= -O2 -fno-zero-initialized-in-bss -mips32 -fno-pic -msoft-float -Wall

CFLAGS += -I../include -I.. -I.

OBJS	= ffs.o memccpy.o memcmp.o memset.o \
	strcasecmp.o strcasestr.o strcat.o strchr.o strcmp.o strcpy.o \
	strcspn.o strlcat.o strlcpy.o strlen.o strncat.o strncmp.o \
	strncpy.o strpbrk.o strrchr.o strspn.o strstr.o strtok.o \
	strtok_r.o strnlen.o memcpy.o memmove.o memchr.o 

all: $(OBJS)

.c.o:
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@
.S.o:
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)

ctype_.o : ctype_.c
isinfd_ieee754.o : isinfd_ieee754.c
isinff_ieee754.o : isinff_ieee754.c
memccpy.o : memccpy.c
memchr.o : memchr.c
memcmp.o : memcmp.c
strcasecmp.o : strcasecmp.c
strcasestr.o : strcasestr.c
strcat.o : strcat.c
strcpy.o : strcpy.c
strcspn.o : strcspn.c
strlcat.o : strlcat.c
strlcpy.o : strlcpy.c
strncat.o : strncat.c
strncmp.o : strncmp.c
strncpy.o : strncpy.c
strnlen.o : strnlen.c
strpbrk.o : strpbrk.c
strspn.o : strspn.c
strstr.o : strstr.c
strtod.o : strtod.c
strtok.o : strtok.c
strtok_r.o : strtok_r.c
vfprintf.o : vfprintf.c
bcopy.o : bcopy.S
ffs.o : ffs.S
index.o : index.S
memcpy.o : memcpy.S bcopy.S
memmove.o : memmove.S bcopy.S
memset.o : memset.S
rindex.o : rindex.S
strchr.o : strchr.S index.S
strcmp.o : strcmp.S
strlen.o : strlen.S
strrchr.o : strrchr.S rindex.S
