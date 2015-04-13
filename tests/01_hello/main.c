void msg_init();
void msg_proc();
void msg_putc(const char);
void msg_puts(const char *);

void c_main(int argc, char *argv[]) {
	int i;

	msg_init((void *)argv);
	msg_puts("XXXXXXX hello world XXXXXXX\n");

	msg_puts("argc = ");
	msg_put_hex(argc);
	msg_puts("\nargv :");
	msg_put_hex(argv);
	msg_puts("\nproc_func addr :");
	msg_put_hex(get_proc_func());
	msg_puts("\n");

#if 1
	for (i=0; i<10; i++) {
		msg_proc();
	}
#endif
#if 0
	for (;;) {
		msg_proc();
	}
#endif
	return;	
}
