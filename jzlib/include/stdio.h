/* Copyright (c) 2002, 2005, 2007 Joerg Wunsch
   All rights reserved.

   Portions of documentation Copyright (c) 1990, 1991, 1993
   The Regents of the University of California.

   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.

  $Id: stdio.h 2135 2010-06-08 11:28:03Z joerg_wunsch $
*/

#ifndef _STDIO_H_
#define	_STDIO_H_ 1

#ifndef __ASSEMBLER__

#include <inttypes.h>
#include <stdarg.h>

#define __need_NULL
#define __need_size_t
#include <stddef.h>

/*
 * This is an internal structure of the library that is subject to be
 * changed without warnings at any time.  Please do *never* reference
 * elements of it beyond by using the official interfaces provided.
 */
struct __file {
	char	*buf;		/* buffer pointer */
	unsigned char unget;	/* ungetc() buffer */
	uint8_t	flags;		/* flags, see below */
#define __SRD	0x0001		/* OK to read */
#define __SWR	0x0002		/* OK to write */
#define __SSTR	0x0004		/* this is an sprintf/snprintf string */
#define __SPGM	0x0008		/* fmt string is in progmem */
#define __SERR	0x0010		/* found error */
#define __SEOF	0x0020		/* found EOF */
#define __SUNGET 0x040		/* ungetc() happened */
#define __SMALLOC 0x80		/* handle is malloc()ed */
#if 0
/* possible future extensions, will require uint16_t flags */
#define __SRW	0x0100		/* open for reading & writing */
#define __SLBF	0x0200		/* line buffered */
#define __SNBF	0x0400		/* unbuffered */
#define __SMBF	0x0800		/* buf is from malloc */
#endif
	int	size;		/* size of buffer */
	int	len;		/* characters read or written so far */
	int	(*put)(char, struct __file *);	/* function to write one char to device */
	int	(*get)(struct __file *);	/* function to read one char from device */
	void	*udata;		/* User defined and accessible data. */
};

#define FILE	struct __file
#define stdin (&__iob[0])
#define stdout (&__iob[1])
#define stderr (&__iob[2])

#define EOF	(-1)

#define fdev_set_udata(stream, u) do { (stream)->udata = u; } while(0)

#define fdev_get_udata(stream) ((stream)->udata)

#define fdev_setup_stream(stream, p, g, f) \
	do { \
		(stream)->put = p; \
		(stream)->get = g; \
		(stream)->flags = f; \
		(stream)->udata = 0; \
	} while(0)

#define _FDEV_SETUP_READ  __SRD	/**< fdev_setup_stream() with read intent */
#define _FDEV_SETUP_WRITE __SWR	/**< fdev_setup_stream() with write intent */
#define _FDEV_SETUP_RW    (__SRD|__SWR)	/**< fdev_setup_stream() with read/write intent */

#define _FDEV_ERR (-1)
#define _FDEV_EOF (-2)

#define FDEV_SETUP_STREAM(p, g, f) \
	{ \
		.put = p, \
		.get = g, \
		.flags = f, \
		.udata = 0, \
	}

#ifdef __cplusplus
extern "C" {
#endif

extern struct __file __iob[];

/* New prototype for avr-libc 1.4 and above. */
extern FILE *fdevopen(int (*__put)(char, FILE*), int (*__get)(FILE*));

extern int	fclose(FILE *__stream);
# define fdev_close() ((void)0)

extern int	vfprintf(FILE *__stream, const char *__fmt, va_list __ap);
extern int	vfprintf_P(FILE *__stream, const char *__fmt, va_list __ap);
extern int	fputc(int __c, FILE *__stream);

extern int	putc(int __c, FILE *__stream);
extern int	putchar(int __c);
#define putc(__c, __stream) fputc(__c, __stream)
#define putchar(__c) fputc(__c, stdout)

extern int	printf(const char *__fmt, ...);

extern int	vprintf(const char *__fmt, va_list __ap);
extern int	sprintf(char *__s, const char *__fmt, ...);
extern int	snprintf(char *__s, size_t __n, const char *__fmt, ...);
extern int	vsprintf(char *__s, const char *__fmt, va_list ap);

extern int	vsnprintf(char *__s, size_t __n, const char *__fmt, va_list ap);
extern int	fprintf(FILE *__stream, const char *__fmt, ...);

extern int	fputs(const char *__str, FILE *__stream);
extern int	puts(const char *__str);

extern size_t	fwrite(const void *__ptr, size_t __size, size_t __nmemb,
		       FILE *__stream);
extern int	fgetc(FILE *__stream);

extern int	getc(FILE *__stream);
extern int	getchar(void);
#define getc(__stream) fgetc(__stream)
#define getchar() fgetc(stdin)

extern int	ungetc(int __c, FILE *__stream);
extern char	*fgets(char *__str, int __size, FILE *__stream);
extern char	*gets(char *__str);
extern size_t	fread(void *__ptr, size_t __size, size_t __nmemb,
		      FILE *__stream);

extern void	clearerr(FILE *__stream);
#define clearerror(s) do { (s)->flags &= ~(__SERR | __SEOF); } while(0)

extern int	feof(FILE *__stream);
#define feof(s) ((s)->flags & __SEOF)
extern int	ferror(FILE *__stream);
#define ferror(s) ((s)->flags & __SERR)

extern int	vfscanf(FILE *__stream, const char *__fmt, va_list __ap);
extern int	fscanf(FILE *__stream, const char *__fmt, ...);
extern int	scanf(const char *__fmt, ...);
extern int	vscanf(const char *__fmt, va_list __ap);
extern int	sscanf(const char *__buf, const char *__fmt, ...);

static __inline__ int fflush(FILE *stream __attribute__((unused)))
{
	return 0;
}

#ifdef __cplusplus
}
#endif

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#endif /* __ASSEMBLER */

#endif /* _STDLIB_H_ */
