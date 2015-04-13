#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_args(char *cmdline, char *argv[], int argv_size)
{
	int argc = 1;
	char *s, *p;

	argv[0] = "";
	p = cmdline;
	while (1) {
		if (argc >= argv_size) break;
		while (*p) {
			if ((*p != ' ') && (*p != '\t')
				 && (*p != '\r') && (*p != '\n')) break;
			p++;
		}
		s = p;
		while (*p) {
			if ((*p == ' ') || (*p == '\t')
				 || (*p == '\r') || (*p == '\n')) break;
			p++;
		}
		if (s == p) break;
		argv[argc++] = s;
		if (*p) {
			*p = 0;
			p++;
		} else break;
	}
	return argc;
}
