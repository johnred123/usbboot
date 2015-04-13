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

	. = ALIGN(4);
	_gp = ABSOLUTE(.); /* Base of small data */
	.got : { *(.got*) } > ram

	. = ALIGN(4);
	.sbss : { *(.sbss*) } > ram
	.bss : { *(.bss*) } > ram
	. = ALIGN (4);
}

