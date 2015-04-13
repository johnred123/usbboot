
#define COMM_CMD_SIZE	256
#define COMM_INPUT_SIZE	256
#define COMM_MSG_SIZE	4096

struct comm_struct {
        void *args[2];
        volatile int msg_length; // length of msgbuf
        volatile unsigned int msg_length_total; // total length of msgbuf
	void (*proc)();
	int filler[3];
	char msgbuf[COMM_MSG_SIZE];
        char input_line[COMM_INPUT_SIZE];
        char command_line[COMM_CMD_SIZE];
};

struct comm_struct *comm_area;

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

extern void call_back(void *p);

void msg_proc () {
	unsigned int saved_gp;
	saved_gp = read_gp();
	if (comm_area && comm_area->proc) 
		call_back(comm_area->proc);
	write_gp(saved_gp);
}

unsigned int get_proc_func() {
	unsigned int ret = 0;
	if (comm_area && comm_area->proc) 
		ret = (unsigned int)(comm_area->proc);
	return ret;
	
}

void msg_putc (const char c)
{
	if (c == '\n') msg_putc ('\r');

	if (comm_area->msg_length < COMM_MSG_SIZE - 1) {
		comm_area->msgbuf[comm_area->msg_length ++] = c;
		comm_area->msg_length_total++;
	}
}

void msg_puts (const char *s)
{
	while (*s) {
		msg_putc (*s++);
	}
}

void msg_init(void *p)
{
	comm_area = p;
}

void msg_put_hex(unsigned int  d)
{
	unsigned char c[9];
	char i;
	for(i = 0; i < 8; i++)
	{
		c[i] = (d >> ((7 - i) * 4)) & 0xf;
		if(c[i] < 10)
			c[i] += 0x30;
		else
			c[i] += (0x41 - 10);
	}

	c[8] = 0;

	msg_puts("0x");
	msg_puts(c);
}
