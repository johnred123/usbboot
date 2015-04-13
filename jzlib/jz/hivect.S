#define hivect(irq) 				\
	.weak __hivect_ ## irq ;		\
	.set __hivect_ ## irq , _bad_interrupt ;\
	la	$t9, __hivect_ ## irq ;		\
	j	$t9 ;				\
	nop

	.text
	.align	5
	.set	nomips16
#	.frame	$sp,0,$31
	.globl	__hivects
	.ent	__hivects
	.type	__hivects, @function
__hivects:
	.set	noreorder
	hivect(0)
	hivect(1)
	hivect(2)
	hivect(3)
	hivect(4)
	hivect(5)
	hivect(6)
	hivect(7)
	hivect(8)
	hivect(9)
	hivect(10)
	hivect(11)
	hivect(12)
	hivect(13)
	hivect(14)
	hivect(15)
	.set	reorder
	.end	__hivects
