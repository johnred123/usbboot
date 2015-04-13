#ifndef __JZ_CORE_H__
#define __JZ_CORE_H__

static inline unsigned long read_gp() {
	unsigned int c = 0;
	__asm__ __volatile__("  \
		.set noreorder; \
		move    %0,$gp; \
		.set reorder" : "=r" (c): );
	return c;
}

static inline void write_gp(unsigned long c) {
	__asm__ __volatile__("\
		.set noreorder;         \
		move    $gp,%0;         \
		.set reorder" :: "r" (c));
}

static inline void write_t9(unsigned long c) {
	__asm__ __volatile__("\
		.set noreorder;         \
		move    $t9,%0;         \
		.set reorder" :: "r" (c));
}

static inline unsigned long read_sp() {
	unsigned int c = 0;
	__asm__ __volatile__("  \
		.set noreorder; \
		move    %0,$sp; \
		.set reorder" : "=r" (c): );
	return c;
}

static inline unsigned long read_c0_status() {
	unsigned int c = 0;
	__asm__ __volatile__("	\
		.set noreorder;	\
		mfc0	%0,$12;	\
		.set reorder" : "=r" (c): );
	return c;
}

static inline void write_c0_status(unsigned long c) {
	__asm__ __volatile__("\
	.set noreorder;		\
	nop;			\
	mtc0	%0,$12;		\
	ssnop;			\
	ssnop;			\
	ssnop;			\
	ssnop;			\
	.set reorder" :: "r" (c));
}

#define C0_STATUS_CU3		(1<<31)
#define C0_STATUS_CU2		(1<<30)
#define C0_STATUS_CU1		(1<<29)
#define C0_STATUS_CU0		(1<<28)
#define C0_STATUS_RP		(1<<27)
#define C0_STATUS_BEV		(1<<22)
#define C0_STATUS_SR		(1<<20)
#define C0_STATUS_NMI		(1<<19)

#define C0_STATUS_IM7		(1<<15)
#define C0_STATUS_IM6		(1<<14)
#define C0_STATUS_IM5		(1<<13)
#define C0_STATUS_IM4		(1<<12)
#define C0_STATUS_IM3		(1<<11)
#define C0_STATUS_IM2		(1<<10)
#define C0_STATUS_IM1		(1<<9)
#define C0_STATUS_IM0		(1<<8)

#define C0_STATUS_UM		(1<<4)
#define C0_STATUS_ERL		(1<<2)
#define C0_STATUS_EXL		(1<<1)
#define C0_STATUS_IE		(1<<0)

static inline unsigned long read_c0_cause() {
	unsigned int c = 0;
	__asm__ __volatile__("	\
		.set noreorder;	\
		mfc0	%0,$13;	\
		.set reorder" : "=r" (c): );
	return c;
}

static inline void write_c0_cause(unsigned long c) {
	__asm__ __volatile__("\
	.set noreorder;		\
	nop;			\
	mtc0	%0,$13;		\
	ssnop;			\
	ssnop;			\
	ssnop;			\
	ssnop;			\
	.set reorder" :: "r" (c));
}

#define C0_CAUSE_BD		(1<<31)
#define C0_CAUSE_CE_BIT		(28)
#define C0_CAUSE_CE_MASK	(3<<28)
#define C0_CAUSE_IV		(1<<23)
#define C0_CAUSE_WP		(1<<22)

#define C0_CAUSE_IP7		(1<<15)
#define C0_CAUSE_IP6		(1<<14)
#define C0_CAUSE_IP5		(1<<13)
#define C0_CAUSE_IP4		(1<<12)
#define C0_CAUSE_IP3		(1<<11)
#define C0_CAUSE_IP2		(1<<10)
#define C0_CAUSE_IP1		(1<<9)
#define C0_CAUSE_IP0		(1<<8)

#define C0_EXC_BIT		(2)
#define C0_EXC_MASK		(0x3f<<2)
#define C0_EXC_INT		(0<<2)
#define C0_EXC_MOD		(1<<2)
#define C0_EXC_TLBL		(2<<2)
#define C0_EXC_TLBS		(3<<2)
#define C0_EXC_ADEL		(4<<2)
#define C0_EXC_ADES		(5<<2)
#define C0_EXC_IBE		(6<<2)
#define C0_EXC_DBE		(7<<2)
#define C0_EXC_SYS		(8<<2)
#define C0_EXC_BP		(9<<2)
#define C0_EXC_RI		(10<<2)
#define C0_EXC_CPU		(11<<2)
#define C0_EXC_OV		(12<<2)
#define C0_EXC_TR		(13<<2)
#define C0_EXC_WATCH		(23<<2)
#define C0_EXC_MCHECK		(24<<2)

static inline unsigned long read_c0_epc() {
	unsigned int c = 0;
	__asm__ __volatile__("	\
		.set noreorder;	\
		mfc0	%0,$14;	\
		.set reorder" : "=r" (c): );
	return c;
}

static inline void write_c0_epc(unsigned long c) {
	__asm__ __volatile__("\
	.set noreorder;		\
	nop;			\
	mtc0	%0,$14;		\
	ssnop;			\
	ssnop;			\
	ssnop;			\
	ssnop;			\
	.set reorder" :: "r" (c));
}

static inline unsigned long read_c0_prid() {
	unsigned int c = 0;
	__asm__ __volatile__("	\
		.set noreorder;	\
		mfc0	%0,$15;	\
		.set reorder" : "=r" (c): );
	return c;
}

#define C0_PRID_COMPANY_BIT		(16)
#define C0_PRID_COMPANY_MASK		(0xff<<16)
#define C0_PRID_COMPANY_MIPS		(1<<16)
#define C0_PRID_PROCESSOR_BIT		(8)
#define C0_PRID_PROCESSOR_MASK		(0xff<<8)
#define C0_PRID_PROCESSOR_4KC		(0x80<<8)
#define C0_PRID_PROCESSOR_4KM		(0x83<<8)
#define C0_PRID_REVISION_BIT		(0)
#define C0_PRID_REVISION_MASK		(0xff<<0)

static inline unsigned long read_c0_errorepc() {
	unsigned int c = 0;
	__asm__ __volatile__("	\
		.set noreorder;	\
		mfc0	%0,$30;	\
		.set reorder" : "=r" (c): );
	return c;
}

static inline void write_c0_errorepc(unsigned long c) {
	__asm__ __volatile__("\
	.set noreorder;		\
	nop;			\
	mtc0	%0,$30;		\
	ssnop;			\
	ssnop;			\
	ssnop;			\
	ssnop;			\
	.set reorder" :: "r" (c));
}

static inline void __irq_enable(void)
{
	unsigned long c;
	write_c0_cause(0);
	c = read_c0_status();
	c &= 0x1f;
	c |= 0x01;
	write_c0_status(c);
}

static inline unsigned long irq_disable()
{
	unsigned long c;
	c = read_c0_status();
	write_c0_status(c & ~0x1f);
	return c;
}

static inline void irq_restore(unsigned long c)
{
	write_c0_status(c);
}

static inline void __delay_loop_1(unsigned int loops)
{
        __asm__ __volatile__ (
        "       .set    noreorder    \n"
        "       .align  3            \n"
        "1:     bnez    %0, 1b       \n"
        "       subu    %0, 1        \n"
        "       .set    reorder      \n"
        : "=r" (loops)
        : "0" (loops));
}

extern void delay_us(unsigned int us);
extern void delay_ms(unsigned int ms);

extern void __flush_dcache_line(unsigned long addr);
extern void __icache_invalidate_all(void);
extern void __dcache_invalidate_all(void);
extern void __dcache_writeback_all(void);

#define ICACHE	0x01			/* invalidate I-cache */
#define DCACHE	0x02			/* writeback and invalidate D-cache */
#define BCACHE	(ICACHE|DCACHE)		/* invalidate both caches, as above */

int _cacheflush( void * addr, int nbytes, int whichcache);

#endif /* __JZ_CORE_H__ */
