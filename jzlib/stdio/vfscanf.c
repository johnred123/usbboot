/* Copyright (c) 2002,2004,2005 Joerg Wunsch
   Copyright (c) 2008  Dmitry Xmelkov
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
*/

/* $Id: vfscanf.c 1944 2009-04-01 23:12:20Z arcanum $ */

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdio_private.h"

#if	!defined (SCANF_LEVEL)
# ifndef SCANF_WWIDTH		/* use word for width variable	*/
#  define SCANF_WWIDTH 0
# endif
# ifndef SCANF_BRACKET		/* use '%[' conversion	*/
#  define SCANF_BRACKET	0
# endif
# ifndef SCANF_FLOAT		/* use float point conversion	*/
#  define SCANF_FLOAT	0
# endif
#elif	SCANF_LEVEL == SCANF_MIN
# define SCANF_WWIDTH	0
# define SCANF_BRACKET	0
# define SCANF_FLOAT	0
#elif	SCANF_LEVEL == SCANF_STD
# define SCANF_WWIDTH	0
# define SCANF_BRACKET	1
# define SCANF_FLOAT	0
#elif	SCANF_LEVEL == SCANF_FLT
# define SCANF_WWIDTH	1
# define SCANF_BRACKET	1
# define SCANF_FLOAT	1
#else
# error	 "Not a known scanf level."
#endif

#if	SCANF_WWIDTH
typedef unsigned int width_t;
#else
typedef unsigned char width_t;
#endif

/* ATTENTION: check FL_CHAR first, not FL_LONG. The last is set
   simultaneously.	*/
#define FL_STAR	    0x01	/* '*': skip assignment		*/
#define FL_WIDTH    0x02	/* width is present		*/
#define FL_LONG	    0x04	/* 'long' type modifier		*/
#define FL_CHAR	    0x08	/* 'char' type modifier		*/
#define FL_OCT	    0x10	/* octal number			*/
#define FL_DEC	    0x20	/* decimal number		*/
#define FL_HEX	    0x40	/* hexidecimal number		*/
#define FL_MINUS    0x80	/* minus flag (field or value)	*/

# define GETBYTE(flag, mask, pnt)	({	\
    unsigned char __c;				\
    __c =  *pnt;				\
    pnt++;					\
    __c;					\
})

/* Add noinline attribute to avoid GCC 4.2 optimization.	*/

__attribute__((noinline))
static void putval (void *addr, long val, unsigned char flags)
{
    if (!(flags & FL_STAR)) {
	if (flags & FL_CHAR)
	    *(char *)addr = val;
	else if (flags & FL_LONG)
	    *(long *)addr = val;
	else
	    *(int *)addr = val;
    }
}

__attribute__((noinline))
static unsigned long
mulacc (unsigned long val, unsigned char flags, unsigned char c)
{
    unsigned char cnt;

    if (flags & FL_OCT) {
	cnt = 3;
    } else if (flags & FL_HEX) {
	cnt = 4;
    } else {
	val += (val << 2);
	cnt = 1;
    }

    do { val <<= 1; } while (--cnt);
    return val + c;
}

__attribute__((noinline))
static unsigned char
conv_int (FILE *stream, width_t width, void *addr, unsigned char flags)
{
    unsigned long val;
    int i;

    i = getc (stream);			/* after ungetc()	*/

    switch ((unsigned char)i) {
      case '-':
        flags |= FL_MINUS;
	/* FALLTHROUGH */
      case '+':
	if (!--width || (i = getc(stream)) < 0)
	    goto err;
    }

    val = 0;
    flags &= ~FL_WIDTH;

    if (!(flags & (FL_DEC | FL_OCT)) && (unsigned char)i == '0') {
	if (!--width || (i = getc (stream)) < 0)
	    goto putval;
	flags |= FL_WIDTH;
	if ((unsigned char)(i) == 'x' || (unsigned char)(i) == 'X') {
	    flags |= FL_HEX;
	    if (!--width || (i = getc(stream)) < 0)
		goto putval;
	} else {
	    if (!(flags & FL_HEX))
		flags |= FL_OCT;
	}
    }

/* This fact is used below to parse hexidecimal digit.	*/
#if	('A' - '0') != (('a' - '0') & ~('A' ^ 'a'))
# error
#endif
    do {
	unsigned char c = i;
	c -= '0';
	if (c > 7) {
	    if (flags & FL_OCT) goto unget;
	    if (c > 9) {
		if (!(flags & FL_HEX)) goto unget;
		c &= ~('A' ^ 'a');
		c += '0' - 'A';
		if (c > 5) {
		  unget:
		    ungetc (i, stream);
		    break;
		}
		c += 10;
	    }
	}
	val = mulacc (val, flags, c);
	flags |= FL_WIDTH;
	if (!--width) goto putval;
    } while ((i = getc(stream)) >= 0);
    if (!(flags & FL_WIDTH))
	goto err;

  putval:
    if (flags & FL_MINUS) val = -val;
    putval (addr, val, flags);
    return 1;

  err:
    return 0;
}

#if  SCANF_BRACKET
__attribute__((noinline))
static const char *
conv_brk (FILE *stream, width_t width, char *addr, const char *fmt)
{
    unsigned char msk[32];
    unsigned char fnegate;
    unsigned char frange;
    unsigned char cabove;
    int i;
    
    memset (msk, 0, sizeof(msk));
    fnegate = 0;
    frange = 0;
    cabove = 0;			/* init to avoid compiler warning	*/
    
    for (i = 0; ; i++) {
	unsigned char c = GETBYTE(stream->flags, __SPGM, fmt);

	if (c == 0) {
	    return 0;
	} else if (c == '^' && !i) {
	    fnegate = 1;
	    continue;
	} else if (i > fnegate) {
	    if (c == ']') break;
	    if (c == '-' && !frange) {
		frange = 1;
		continue;
	    }
	}
	
	if (!frange) cabove = c;
	
	for (;;) {
	    msk[c >> 3] |= 1 << (c & 7);
	    if (c == cabove) break;
	    if (c < cabove)
		c++;
	    else
		c--;
	}

	frange = 0;
    }
    if (frange)
	msk['-'/8] |= 1 << ('-' & 7);

    if (fnegate) {
	unsigned char *p = msk;
	do {
	    unsigned char c = *p;
	    *p++ = ~c;
	} while (p != msk + sizeof(msk));
    }

    /* And now it is a flag of fault.	*/
    fnegate = 1;

    /* NUL ('\0') is consided as normal character. This is match to Glibc.
       Note, there is no method to include NUL into symbol list.	*/
    do {
	i = getc (stream);
	if (i < 0) break;
	if (!((msk[(unsigned char)i >> 3] >> (i & 7)) & 1)) {
	    ungetc (i, stream);
	    break;
	}
	if (addr) *addr++ = i;
	fnegate = 0;
    } while (--width);
    
    if (fnegate) {
	return 0;
    } else {
	if (addr) *addr = 0;
        return fmt;
    }
}
#endif	/* SCANF_BRACKET */

#if  SCANF_FLOAT

/* GCC before 4.2 does not use a library function to convert an unsigned
   long to float.  Instead it uses a signed long to float conversion
   function along with a large inline code to correct the result.
   Seems, GCC 4.3 does not use it also.	*/
extern double __floatunsisf (unsigned long);

PROGMEM static const float pwr_p10 [6] = {
    1e+1, 1e+2, 1e+4, 1e+8, 1e+16, 1e+32
};
PROGMEM static const float pwr_m10 [6] = {
    1e-1, 1e-2, 1e-4, 1e-8, 1e-16, 1e-32
};

PROGMEM static const char pstr_nfinity[] = "nfinity";
PROGMEM static const char pstr_an[] = "an";

__attribute__((noinline))
static unsigned char conv_flt (FILE *stream, width_t width, float *addr)
{
    union {
	unsigned long u32;
	float flt;
    } x;
    int i;
    const char *p;
    int exp;

    unsigned char flag;
#define FL_MINUS    0x80	/* number is negative	*/
#define FL_ANY	    0x02	/* any digit was readed	*/
#define FL_OVFL	    0x04	/* overflow was		*/
#define FL_DOT	    0x08	/* decimal '.' was	*/
#define FL_MEXP	    0x10	/* exponent 'e' is neg.	*/

    i = getc (stream);		/* after ungetc()	*/

    flag = 0;
    switch ((unsigned char)i) {
      case '-':
        flag = FL_MINUS;
	/* FALLTHROUGH */
      case '+':
	if (!--width || (i = getc (stream)) < 0)
	    goto err;
    }

    switch (tolower (i)) {

      case 'n':
	p = pstr_an;
	goto operate_pstr;

      case 'i':
	p = pstr_nfinity;
      operate_pstr:
        {
	    unsigned char c;
	    
	    while ((c = pgm_read_byte (p++)) != 0) {
		if (!--width
		    || (i = getc (stream)) < 0
		    || ((unsigned char)tolower(i) != c
			&& (ungetc (i, stream), 1)))
		{	
		    if (p == pstr_nfinity + 3)
			break;
		    goto err;
		}
	    }
        }
	x.flt = (p == pstr_an + 3) ? NAN : INFINITY;
	break;

      default:
        exp = 0;
	x.u32 = 0;
	do {

	    unsigned char c = i - '0';
    
	    if (c <= 9) {
		flag |= FL_ANY;
		if (flag & FL_OVFL) {
		    if (!(flag & FL_DOT))
			exp += 1;
		} else {
		    if (flag & FL_DOT)
			exp -= 1;
		    x.u32 = mulacc (x.u32, FL_DEC, c);
		    if (x.u32 >= (ULONG_MAX - 9) / 10)
			flag |= FL_OVFL;
	        }

	    } else if (c == (('.'-'0') & 0xff) && !(flag & FL_DOT)) {
		flag |= FL_DOT;
	    } else {
		break;
	    }
	} while (--width && (i = getc (stream)) >= 0);
    
	if (!(flag & FL_ANY))
	    goto err;
    
	if ((unsigned char)i == 'e' || (unsigned char)i == 'E')
	{
	    int expacc;

	    if (!--width || (i = getc (stream)) < 0) goto err;
	    switch ((unsigned char)i) {
	      case '-':
		flag |= FL_MEXP;
		/* FALLTHROUGH */
	      case '+':
		if (!--width) goto err;
		i = getc (stream);		/* test EOF will below	*/
	    }

	    if (!isdigit (i)) goto err;

	    expacc = 0;
	    do {
		expacc = mulacc (expacc, FL_DEC, i - '0');
	    } while (--width && isdigit (i = getc(stream)));
	    if (flag & FL_MEXP)
		expacc = -expacc;
	    exp += expacc;
	}

	if (width && i >= 0) ungetc (i, stream);
    
	x.flt = __floatunsisf (x.u32);

	if (exp < 0) {
	    p = (void *)(pwr_m10 + 5);
	    exp = -exp;
	} else {
	    p = (void *)(pwr_p10 + 5);
	}
	for (width = 32; width; width >>= 1) {
	    for (; (unsigned)exp >= width; exp -= width) {
		union {
		    long lo;
		    float fl;
		} y;
		y.lo = pgm_read_dword (p);
		x.flt *= y.fl;
	    }
	    p = (void *)p - sizeof(float);
	}
    } /* switch */

    if (flag & FL_MINUS)
	x.flt = -x.flt;
    if (addr) *addr = x.flt;
    return 1;

  err:
    return 0;
}
#endif	/* SCANF_FLOAT	*/

__attribute__((noinline))
static int skip_spaces (FILE *stream)
{
    int i;
    do {
	if ((i = getc (stream)) < 0)
	    return i;
    } while (isspace (i));
    ungetc (i, stream);
    return i;
}

int vfscanf (FILE * stream, const char *fmt, va_list ap)
{
    unsigned char nconvs;
    unsigned char stream_flags;
    unsigned char c;
    width_t width;
    void *addr;
    unsigned char flags;
    int i;

    nconvs = 0;
    stream->len = 0;

    /* Initialization of stream_flags at each pass simplifies the register
       allocation with GCC 3.3 - 4.2.  Only the GCC 4.3 is good to move it
       to the begin.	*/
    while ((c = GETBYTE (stream_flags = stream->flags, __SPGM, fmt)) != 0) {

	if (isspace (c)) {
	    skip_spaces (stream);

	} else if (c != '%'
		   || (c = GETBYTE (stream_flags, __SPGM, fmt)) == '%')
	{
	    /* Ordinary character.	*/
	    if ((i = getc (stream)) < 0)
		goto eof;
	    if ((unsigned char)i != c) {
		ungetc (i, stream);
		break;
	    }
	
	} else {
	    flags = 0;

	    if (c == '*') {
		flags = FL_STAR;
		c = GETBYTE (stream_flags, __SPGM, fmt);
	    }

	    width = 0;
	    while ((c -= '0') < 10) {
		flags |= FL_WIDTH;
		width = mulacc (width, FL_DEC, c);
		c = GETBYTE (stream_flags, __SPGM, fmt);
	    }
	    c += '0';
	    if (flags & FL_WIDTH) {
		/* C99 says that width must be greater than zero.
		   To simplify program do treat 0 as error in format.	*/
		if (!width) break;
	    } else {
		width = ~0;
	    }

	    /* ATTENTION: with FL_CHAR the FL_LONG is set also.	*/
	    switch (c) {
	      case 'h':
	        if ((c = GETBYTE (stream_flags, __SPGM, fmt)) != 'h')
		    break;
		flags |= FL_CHAR;
		/* FALLTHROUGH */
	      case 'l':
		flags |= FL_LONG;
		c = GETBYTE (stream_flags, __SPGM, fmt);
	    }

#define CNV_BASE	"cdinopsuxX"
#if	SCANF_BRACKET
# define CNV_BRACKET	"["
#else
# define CNV_BRACKET	""
#endif
#if	SCANF_FLOAT
# define CNV_FLOAT	"efgEFG"
#else
# define CNV_FLOAT	""
#endif
#define CNV_LIST	CNV_BASE CNV_BRACKET CNV_FLOAT
	    if (!c || !strchr (CNV_LIST, c))
		break;

	    addr = (flags & FL_STAR) ? 0 : va_arg (ap, void *);

	    if (c == 'n') {
		putval (addr, (unsigned)(stream->len), flags);
		continue;
	    }

	    if (c == 'c') {
		if (!(flags & FL_WIDTH)) width = 1;
		do {
		    if ((i = getc (stream)) < 0)
			goto eof;
		    if (addr) *(char *)addr++ = i;
		} while (--width);
		c = 1;			/* no matter with smart GCC	*/

#if  SCANF_BRACKET
	    } else if (c == '[') {
		fmt = conv_brk (stream, width, addr, fmt);
		c = (fmt != 0);
#endif

	    } else {

		if (skip_spaces (stream) < 0)
		    goto eof;
		
		switch (c) {

		  case 's':
		    /* Now we have 1 nospace symbol.	*/
		    do {
			if ((i = getc (stream)) < 0)
			    break;
			if (isspace (i)) {
			    ungetc (i, stream);
			    break;
			}
			if (addr) *(char *)addr++ = i;
		    } while (--width);
		    if (addr) *(char *)addr = 0;
		    c = 1;		/* no matter with smart GCC	*/
		    break;

#if  SCANF_FLOAT
	          case 'p':
		  case 'x':
	          case 'X':
		    flags |= FL_HEX;
		    goto conv_int;

	          case 'd':
		  case 'u':
		    flags |= FL_DEC;
		    goto conv_int;

	          case 'o':
		    flags |= FL_OCT;
		    /* FALLTHROUGH */
		  case 'i':
		  conv_int:
		    c = conv_int (stream, width, addr, flags);
		    break;

	          default:		/* e,E,f,F,g,G	*/
		    c = conv_flt (stream, width, addr);
#else
	          case 'd':
		  case 'u':
		    flags |= FL_DEC;
		    goto conv_int;

	          case 'o':
		    flags |= FL_OCT;
		    /* FALLTHROUGH */
		  case 'i':
		    goto conv_int;

		  default:			/* p,x,X	*/
		    flags |= FL_HEX;
		  conv_int:
		    c = conv_int (stream, width, addr, flags);
#endif
		}
	    } /* else */

	    if (!c) {
		if (stream->flags & (__SERR | __SEOF))
		    goto eof;
		break;
	    }
	    if (!(flags & FL_STAR)) nconvs += 1;
	} /* else */
    } /* while */
    return nconvs;

  eof:
    return nconvs ? nconvs : EOF;
}
