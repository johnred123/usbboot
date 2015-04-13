	.text
	.align	5
	.set	nomips16

	.globl	exvec3
	.globl	exvec3_end
	.ent	exvec3
	.type	exvec3, @function
	.set	noreorder
	.set    noat
exvec3:
	addiu   $sp,$sp,-128
	la	$k0, __intent
	jr	$k0
	nop
exvec3_end:
	.set	reorder
	.end	exvec3

#	.frame	$sp,0,$31
	.globl	__intent
	.ent	__intent
	.type	__intent, @function
	.align	5
	.set	noreorder
	.set    noat
__intent:
	sw	$at, 0*4+16($sp)
	sw	$v0, 1*4+16($sp)
	sw	$v1, 2*4+16($sp)
	sw	$a0, 3*4+16($sp)
	sw	$a1, 4*4+16($sp)
	sw	$a2, 5*4+16($sp)
	sw	$a3, 6*4+16($sp)
	sw	$t0, 7*4+16($sp)
	sw	$t1, 8*4+16($sp)
	sw	$t2, 9*4+16($sp)
	sw	$t3, 10*4+16($sp)
	sw	$t4, 11*4+16($sp)
	sw	$t5, 12*4+16($sp)
	sw	$t6, 13*4+16($sp)
	sw	$t7, 14*4+16($sp)
	sw	$t8, 15*4+16($sp)
	sw	$t9, 16*4+16($sp)
	sw	$gp, 17*4+16($sp)
	sw	$fp, 18*4+16($sp)
	sw	$ra, 19*4+16($sp)

	sw	$k1, 20*4+16($sp)
	mfc0    $a0,$12	/* c0_status */
	sw	$a0, 21*4+16($sp)
	mfc0    $a1,$13	/* c0_cause */
	sw	$a1, 22*4+16($sp)
	mfc0    $a2,$14	/* c0_epc */
	sw	$a3, 23*4+16($sp)

	/* call */
	la	$t9, intent
	jal	$t9

	move	$k0, $v0	/* return val = new c0_status */
	lw	$k1, 20*4+16($sp)

	lw	$at, 0*4+16($sp)
	lw	$v0, 1*4+16($sp)
	lw	$v1, 2*4+16($sp)
	lw	$a0, 3*4+16($sp)
	lw	$a1, 4*4+16($sp)
	lw	$a2, 5*4+16($sp)
	lw	$a3, 6*4+16($sp)
	lw	$t0, 7*4+16($sp)
	lw	$t1, 8*4+16($sp)
	lw	$t2, 9*4+16($sp)
	lw	$t3, 10*4+16($sp)
	lw	$t4, 11*4+16($sp)
	lw	$t5, 12*4+16($sp)
	lw	$t6, 13*4+16($sp)
	lw	$t7, 14*4+16($sp)
	lw	$t8, 15*4+16($sp)
	lw	$t9, 16*4+16($sp)
	lw	$gp, 17*4+16($sp)
	lw	$fp, 18*4+16($sp)
	lw	$ra, 19*4+16($sp)
	addiu   $sp,$sp,128
	
	mtc0    $k0,$12	/* c0_status */
	ssnop
	ssnop
	ssnop
	sll	$zero,$zero,0x3
	j	$k1
	nop

	.set	reorder
	.end	__intent
