#include <stdio.h>
#include <jz/jz_core.h>

#define COMM_CMD_SIZE	256
#define COMM_INPUT_SIZE	256
#define COMM_MSG_SIZE	4096

struct comm_struct {
        void *args[2];
        volatile int ubcomm_length; // length of msgbuf
        volatile unsigned int ubcomm_length_total; // total length of msgbuf
	void (*proc)();
	int filler[3];
	char msgbuf[COMM_MSG_SIZE];
        char input_line[COMM_INPUT_SIZE];
        char command_line[COMM_CMD_SIZE];
};

struct comm_struct *comm_area;

void ubcomm_proc () {
	unsigned long flags;
	uint32_t gp_save;
	if (comm_area && comm_area->proc) {
		gp_save = read_gp();
		//flags = irq_disable();
		write_t9((uint32_t)(void *)(comm_area->proc));
		(comm_area->proc)();
		//irq_restore(flags);
		write_gp(gp_save);
	}
}

void ubcomm_putc (const char c)
{
	unsigned long flags;
	if (c == '\n') ubcomm_putc ('\r');

	//flags = irq_disable();
	if (comm_area->ubcomm_length < COMM_MSG_SIZE - 1) {
		comm_area->msgbuf[comm_area->ubcomm_length ++] = c;
		comm_area->ubcomm_length_total++;
	}
	//irq_restore(flags);
}

void ubcomm_init(void *p)
{
	comm_area = p;
}

static int __ubcomm_putc (char c, FILE *fp)
{
	//unsigned long flags;

	//flags = irq_disable();
	if (comm_area->ubcomm_length < COMM_MSG_SIZE - 1) {
		comm_area->msgbuf[comm_area->ubcomm_length ++] = c;
		comm_area->ubcomm_length_total++;
	}
	//irq_restore(flags);

	return 0;	// 0 or EOF
}

FILE *fdevopen_ubcomm(FILE *fp, void *p)
{
	ubcomm_init(p);
	if (fp) {
		fdev_setup_stream(fp, __ubcomm_putc, NULL, _FDEV_SETUP_WRITE);
	} else {
		fp = fdevopen(__ubcomm_putc, NULL);
	}
	return fp;
}
