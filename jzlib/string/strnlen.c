#include <string.h>

size_t strnlen(const char *s, size_t n)
{
	int i;
	for (i=0; i<n; i++) {
		if ( *s++ == 0 ) break;
	}
	return i;
}
