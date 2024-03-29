/*	$NetBSD: memset.S,v 1.1 1999/03/15 06:37:43 jonathan Exp $	*/

#ifndef _LOCORE		/* avoid tripping over __RENAME() */
#define _LOCORE		/* XXX not really, just assembly-code source */
#endif


#define LEAF(name)	\
	.text ;				\
	.align	2 ;			\
	.globl	name ;			\
	.ent	name ;			\
	.type	name, @function ;	\
name: ;					\
	.set	reorder

#define END(name)			\
	.set	reorder	;		\
	.end	name

// _LITTLE_ENDIAN
# define LWHI lwr
# define LWLO lwl
# define SWHI swr
# define SWLO swl

/*
 * memset(void *s1, int c, int len)
 */
LEAF(memset)
	.set	noreorder
	blt	$a2, 12, smallclr	# small amount to clear?
	move	$v0, $a0			# save s1 for result

	sll	$t1, $a1, 8		# compute  c << 8 in t1
	or	$t1, $t1, $a1		# compute c << 8 | c in 11
	sll	$t2, $t1, 16		# shift that left 16
	or	$t1, $t2, $t1		# or together

	subu	$t0, $zero, $a0		# compute # bytes to word align address
	and	$t0, $t0, 3
	beq	$t0, $zero, 1f		# skip if word aligned
	subu	$a2, $a2, $t0		# subtract from remaining count
	SWHI	$t1, 0($a0)		# store 1, 2, or 3 bytes to align
	addu	$a0, $a0, $t0
1:
	and	$v1, $a2, 3		# compute number of whole words left
	subu	$t0, $a2, $v1
	subu	$a2, $a2, $t0 
	addu	$t0, $t0, $a0		# compute ending address
2:
	addu	$a0, $a0, 4		# clear words
	bne	$a0, $t0, 2b		#  unrolling loop does not help
	sw	$t1, -4($a0)		#  since we are limited by memory speed

smallclr:
	ble	$a2, $zero, 2f
	addu	$t0, $a2, $a0		# compute ending address
1:
	addu	$a0, $a0, 1		# clear bytes
	bne	$a0, $t0, 1b
	sb	$a1, -1($a0)
2:
	j	$ra
	nop
END(memset)
