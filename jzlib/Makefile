CROSS_COMPILE=mipsel-linux-

#CFLAGS  = -O2 -fno-unit-at-a-time -fno-zero-initialized-in-bss -mips32 \
#        -fno-pic -mno-abicalls -mno-shared -msoft-float
CFLAGS  = -O2 -fno-zero-initialized-in-bss -mips32 -Wall
DEFINES = -D__JZ4725B__
#DEFINES = -D__JZ4755__

all: 
	( export CFLAGS="$(CFLAGS)"; cd string ; make )
	( export CFLAGS="$(CFLAGS)"; cd stdlib ; make )
	( export CFLAGS="$(CFLAGS)"; cd stdio ; make )
	( export CFLAGS="$(CFLAGS)"; cd others ; make )
	( export CFLAGS="$(CFLAGS)"; export DEFINES="$(DEFINES)" ; cd jz ; make )
	( export CFLAGS="$(CFLAGS)"; export DEFINES="$(DEFINES)" ; cd drivers ; make )
	rm -f libjz.a
	$(CROSS_COMPILE)ar ruc libjz.a string/*.o stdlib/*.o stdio/*.o others/*.o jz/*.o  drivers/*.o
	$(CROSS_COMPILE)ranlib libjz.a
	$(CROSS_COMPILE)ld -r -o libjz.o string/*.o stdlib/*.o stdio/*.o others/*.o jz/*.o drivers/*.o
	$(CROSS_COMPILE)nm libjz.o | grep " U "
	rm -f libjz.o

clean:
	( cd string ; make clean )
	( cd stdlib ; make clean )
	( cd stdio ; make clean )
	( cd others ; make clean )
	( cd jz ; make clean )
	( cd drivers ; make clean )
	rm -f libjz.a
