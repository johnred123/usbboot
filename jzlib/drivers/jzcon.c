#include <stdio.h>

#define NR_PUTFUNC	4

static int (*__putfunc[NR_PUTFUNC])(char, FILE*) = {};
static int __putfunc_num = 0;

static int __jzcon_putc (char c, FILE *fp)
{
	int i;
	for (i=0; i< __putfunc_num; i++) {
		(__putfunc[i])(c,fp);
	}
	return 0;	// 0 or EOF
}

void jzcon_append(FILE *fp) {
	unsigned int addr;
	int i;

	if (__putfunc_num >= NR_PUTFUNC) return;
	if (!fp) return;
	addr = (unsigned int)(void *)(fp->put);
	if ((0x80000000 > addr) || (addr > 0xa0000000)) return;
	if (addr == (unsigned int)(void *)__jzcon_putc) return;

	for (i=0; i< __putfunc_num; i++) {
		if (addr == (unsigned int)(void *)__putfunc[i]) return;
	}
	__putfunc[__putfunc_num++] = fp->put;
}

void jzcon_setup()
{
	fdev_setup_stream(stdout, __jzcon_putc, NULL, _FDEV_SETUP_WRITE);
	fdev_setup_stream(stderr, __jzcon_putc, NULL, _FDEV_SETUP_WRITE);
}
