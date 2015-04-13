/*
#define vector(irq) 				\
	.weak __vector_ ## irq ;		\
	.set __vector_ ## irq , _bad_interrupt ;\
	la	$t9, __vector_ ## irq ;		\
	j	$t9 ;				\
	nop
*/
#define vector(irq) 				\
	.weak __vector_ ## irq ;		\
	.set __vector_ ## irq , _bad_interrupt ;\
	.word	__vector_ ## irq ;		\

	.text
	.align	5
	.set	nomips16
#	.frame	$sp,0,$31
	.globl	__vectors
	.ent	__vectors
	.type	__vectors, @function
__vectors:
	.set	noreorder
	vector(0)
	vector(1)
	vector(2)
	vector(3)
	vector(4)
	vector(5)
	vector(6)
	vector(7)
	vector(8)
	vector(9)
	vector(10)
	vector(11)
	vector(12)
	vector(13)
	vector(14)
	vector(15)
	vector(16)
	vector(17)
	vector(18)
	vector(19)
	vector(20)
	vector(21)
	vector(22)
	vector(23)
	vector(24)
	vector(25)
	vector(26)
	vector(27)
	vector(28)
	vector(29)
	vector(30)
	vector(31)
	.set	reorder
	.end	__vectors

	.globl	_bad_interrupt
	.ent	_bad_interrupt
	.type	_bad_interrupt, @function
_bad_interrupt:
	.set	noreorder
	move    $v0, $zero
	j	$ra
	nop
	.set	reorder
	.end	_bad_interrupt
