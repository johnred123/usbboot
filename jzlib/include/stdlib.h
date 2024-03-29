/* Copyright (c) 2002, Marek Michalkiewicz
   Copyright (c) 2004,2007 Joerg Wunsch

   Portions of documentation Copyright (c) 1990, 1991, 1993, 1994
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

  $Id: stdlib.h 1623 2008-03-16 13:44:45Z dmix $
*/

#ifndef _STDLIB_H_
#define	_STDLIB_H_ 1

#ifndef __ASSEMBLER__

#define __need_NULL
#define __need_size_t
#define __need_wchar_t
#include <stddef.h>

#ifndef __ptr_t
#define __ptr_t void *
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	int quot;                   /**< The Quotient. */
	int rem;                    /**< The Remainder. */
} div_t;

typedef struct {
	long quot;                  /**< The Quotient. */
	long rem;                   /**< The Remainder. */
} ldiv_t;

typedef int (*__compar_fn_t)(const void *, const void *);

#ifndef __ATTR_CONST__
#define __ATTR_CONST__ __attribute__((__const__))
#endif

#ifndef __ATTR_MALLOC__
#define __ATTR_MALLOC__ __attribute__((__malloc__))
#endif

#ifndef __ATTR_NORETURN__
#define __ATTR_NORETURN__ __attribute__((__noreturn__))
#endif

#ifndef __ATTR_PURE__
#define __ATTR_PURE__ __attribute__((__pure__))
#endif

extern void abort(void) __ATTR_NORETURN__;

extern int abs(int __i) __ATTR_CONST__;
#define	abs(__i) __builtin_abs(__i)

extern long labs(long __i) __ATTR_CONST__;
#define labs(__i) __builtin_labs(__i)

extern void *bsearch(const void *__key, const void *__base, size_t __nmemb,
		     size_t __size, int (*__compar)(const void *, const void *));

extern div_t div(int __num, int __denom) __asm__("__divmodhi4") __ATTR_CONST__;
extern ldiv_t ldiv(long __num, long __denom) __asm__("__divmodsi4") __ATTR_CONST__;

extern void qsort(void *__base, size_t __nmemb, size_t __size,
		  __compar_fn_t __compar);

extern long strtol(const char *__nptr, char **__endptr, int __base);
extern unsigned long strtoul(const char *__nptr, char **__endptr, int __base);

extern long atol(const char *__s) __ATTR_PURE__;
extern int atoi(const char *__s) __ATTR_PURE__;
extern void exit(int __status) __ATTR_NORETURN__;

extern void *malloc(size_t __size) __ATTR_MALLOC__;
extern void free(void *__ptr);

extern size_t __malloc_margin;
extern char *__malloc_heap_start;
extern char *__malloc_heap_end;
extern void *calloc(size_t __nele, size_t __size) __ATTR_MALLOC__;
extern void *realloc(void *__ptr, size_t __size) __ATTR_MALLOC__;
extern double strtod(const char *__nptr, char **__endptr);
extern double atof(const char *__nptr);

/** Highest number that can be generated by rand(). */
#define	RAND_MAX 0x7FFFFFFF

extern int rand(void);
extern void srand(unsigned int __seed);

extern int rand_r(unsigned long *__ctx);

extern char *itoa(int __val, char *__s, int __radix);
extern char *ltoa(long int __val, char *__s, int __radix);
extern char *utoa(unsigned int __val, char *__s, int __radix);
extern char *ultoa(unsigned long int __val, char *__s, int __radix);

#define	RANDOM_MAX 0x7FFFFFFF
extern long random(void);
extern void srandom(unsigned long __seed);
extern long random_r(unsigned long *__ctx);

#define DTOSTR_ALWAYS_SIGN 0x01        /* put '+' or ' ' for positives */
#define DTOSTR_PLUS_SIGN   0x02        /* put '+' rather than ' ' */
#define DTOSTR_UPPERCASE   0x04        /* put 'E' rather 'e' */

extern char *dtostre(double __val, char *__s, unsigned char __prec,
		     unsigned char __flags);

extern char *dtostrf(double __val, signed char __width,
                     unsigned char __prec, char *__s);

#if 0  /* not yet implemented */
extern int atexit(void (*)(void));
#endif

extern int	opterr;		/* if error message should be printed */
extern int	optind;		/* index into parent argv vector */
extern int	optopt;		/* character checked for validity */
extern int	optreset;	/* reset getopt */
extern char	*optarg;	/* argument associated with option */

extern int getopt(int nargc, char * const nargv[], const char *ostr);
extern int parse_args(char *cmdline, char *argv[], int argv_size);

#ifdef __cplusplus
}
#endif

#endif /* __ASSEMBLER */

#endif /* _STDLIB_H_ */
