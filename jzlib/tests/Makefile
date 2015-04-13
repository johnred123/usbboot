ifeq ($(CROSS_COMPILE),)
$(error CROSS_COMPILE variable not set, should point to .../mipsel-openwrt-linux-)
endif

#CFLAGS  = -O2 -fno-unit-at-a-time -fno-zero-initialized-in-bss -mips32 \
#        -fno-pic -mno-abicalls -mno-shared -msoft-float
CFLAGS  = -O2 -fno-zero-initialized-in-bss -mips32 -msoft-float -Wall
DEFINES = -D__JZ4725B__
#DEFINES = -D__JZ4755__

all: 
	( export CFLAGS="$(CFLAGS)"; export DEFINES="$(DEFINES)" ; cd 01_hello ; make )
	( export CFLAGS="$(CFLAGS)"; export DEFINES="$(DEFINES)" ; cd 02_machid ; make )
	( export CFLAGS="$(CFLAGS)"; export DEFINES="$(DEFINES)" ; cd 03_timer ; make )
clean:
	( cd 01_hello ; make clean )
	( cd 02_machid ; make clean )
	( cd 03_timer ; make clean )

