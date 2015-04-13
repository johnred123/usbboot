#include <stdio.h>
#include <stdlib.h>
#include <jz/console.h>
#include <jz/interrupt.h>

#define JZ_TIMER_TCU_CH  2
#define JZ_TIMER_IRQ  IRQ_TCU2
#define JZ_TIMER_CLOCK (JZ_EXTAL>>4) /* Jz timer clock frequency */


void c_main(int argc, char *argv[]) {
	int i,argc2;
	char *argv2[10];
	int c;

//	fdopen_serial(stdout);
	fdevopen_ili9325(stdout, 0, 0, 0);
	jzcon_append(stdout);
	ILI9325_Text("#1#");
	fdevopen_ubcomm(stdout, (void *)argv);
	ILI9325_Text("#2#");
	jzcon_append(stdout);
	ILI9325_Text("#3#");

	printf("XXX hello world 1 XXX \n");
	fprintf(stdout, "XXX hello world 2 XXX \n");
	printf("XXX hello world 3 XXX %d 0x%lx\n",argc,(uint32_t)argv);

#if 1
	for (i=0; i<10; i++) {
		ubcomm_proc();
	}
#endif
	argc2 = parse_args(argv[1],10, argv2);
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
	return;	
}
