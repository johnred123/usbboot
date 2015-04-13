#include <stdio.h>
#include <stdlib.h>
#include <jz/console.h>

void ubcomm_puts(char *s)
{
	while (*s) {
		ubcomm_putc(*s);
		s++;
	}
}

void c_main(int argc, char *argv[]) {
#if 0
	ubcomm_init(argv);
	ubcomm_puts("XXX hello world 0 XXX \n");
	ILI9325_Init(0,0,0);
	ILI9325_Text("XXX hello world 0 XXX \n");
#else
	int i,argc2;
	char *argv2[10];
	int c;

	fdevopen_serial(stdout); /* generic */
	//fdevopen_ili9325(stdout, 0, 0, 0); /* for A-41 only */
	//fdevopen_ili9326(stdout, 0, 0, 0); /* for A-33 only */
	jzcon_append(stdout);
	ILI9325_Text("#1#");
	fdevopen_ubcomm(stdout, (void *)argv);
	ILI9325_Text("#2#");
	jzcon_append(stdout);
	ILI9325_Text("#3#");
//	fdevopen_serial(stdout);
//	jzcon_append(stdout);
	jzcon_setup();
	ILI9325_Text("#4#");
	printf("XXX hello world 1 XXX \n");
	fprintf(stdout, "XXX hello world 2 XXX \n");
	printf("XXX hello world 3 XXX %d 0x%lx\n",argc,(uint32_t)argv);
	ILI9325_Text("#5#");

#if 0
	for (i=0; i<10; i++) {
		ubcomm_proc();
	}
#endif

#if 1
	printf("cmdline [%s]\n", argv[1]);
	argc2 = parse_args(argv[1],argv2, 10);
	printf("parse_args result %d\n", argc2);
	if (1 < argc && argc <= 10) {
		for (i=1; i<argc2; i++) {
			printf("arg %d = [%s]\n", i, argv2[i]);
		}
	}
	printf("getopt test\n");
	while (1) {
		c = getopt(argc2, argv2, "abcd:e:f:");
		if (c == 'a' || c == 'b' || c == 'c' ) {
			printf("  option %c\n",c);
		}
		else if (c == 'd' || c == 'e' || c == 'f' ) {
			printf("  option %c [%s]\n",c,argv2[optind]);
		}
		else {
			break;
		} 
	}
#endif
#endif
	return;	
}
