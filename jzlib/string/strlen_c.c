#include <string.h>

size_t strlen(const char *p)
{
	int r = 0;
	while (*p) {
		p++;
		r++;
	}
	return r;
}

