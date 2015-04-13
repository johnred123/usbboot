OUTPUT_ARCH(mips)
ENTRY(_start)
MEMORY
{
	ram	: ORIGIN = 0x80600000 , LENGTH = 6M
}

SECTIONS
{
	. = ALIGN(4);
	.text : { *(.text*) } > ram

	. = ALIGN(4);
	.rodata : { *(.rodata*) } > ram

	. = ALIGN(4);
	.sdata : { *(.sdata*) } > ram

	. = ALIGN(4);
	.data : { *(.data*) *(.scommon*) *(.reginfo*) } > ram

	_gp = ABSOLUTE(.); /* Base of small data */

	.got : { *(.got*) } > ram

	. = ALIGN(4);
	__bss_start = ABSOLUTE(.); /* BSS */
	.sbss : { *(.sbss*) } > ram
	.bss : { *(.bss*) } > ram
	__bss_stop = ABSOLUTE(.);
	_end = . ;
	. = ALIGN (4);
}

