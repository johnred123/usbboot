/* Copyright (c) 2002,2007 Michael Stumpf
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
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id: ctype.h 1504 2007-12-16 07:34:00Z dmix $ */

/*
   ctype.h - character conversion macros and ctype macros

  Author : Michael Stumpf
           Michael.Stumpf@t-online.de
*/

#ifndef __CTYPE_H_
#define __CTYPE_H_ 1

#ifndef __ATTR_CONST__
#define __ATTR_CONST__ __attribute__((__const__))
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern int isalnum(int __c) __ATTR_CONST__;
extern int isalpha(int __c) __ATTR_CONST__;
extern int isascii(int __c) __ATTR_CONST__;
extern int isblank(int __c) __ATTR_CONST__;
extern int iscntrl(int __c) __ATTR_CONST__;
extern int isdigit(int __c) __ATTR_CONST__;
extern int isgraph(int __c) __ATTR_CONST__;
extern int islower(int __c) __ATTR_CONST__;
extern int isprint(int __c) __ATTR_CONST__;
extern int ispunct(int __c) __ATTR_CONST__;
extern int isspace(int __c) __ATTR_CONST__;
extern int isupper(int __c) __ATTR_CONST__;
extern int isxdigit(int __c) __ATTR_CONST__;

extern int toascii(int __c) __ATTR_CONST__;
extern int tolower(int __c) __ATTR_CONST__;
extern int toupper(int __c) __ATTR_CONST__;

#define _CTYPE_NUM_CHARS 128

extern const unsigned char _C_ctype_[1 + _CTYPE_NUM_CHARS];

#define _U      0x01
#define _L      0x02
#define _N      0x04
#define _S      0x08
#define _P      0x10
#define _C      0x20
#define _X      0x40
#define _B      0x80

#define isalnum(c)      ((int)((_C_ctype_ + 1)[(int)(c)] & (_U|_L|_N)))
#define isalpha(c)      ((int)((_C_ctype_ + 1)[(int)(c)] & (_U|_L)))
#define isascii(c)      ((unsigned)(c) <= 0177)
#define isblank(c)      ((int)((_C_ctype_ + 1)[(int)(c)] & _B))
#define iscntrl(c)      ((int)((_C_ctype_ + 1)[(int)(c)] & _C))
#define isdigit(c)      ((int)((_C_ctype_ + 1)[(int)(c)] & _N))
#define isgraph(c)      ((int)((_C_ctype_ + 1)[(int)(c)] & (_P|_U|_L|_N)))
#define islower(c)      ((int)((_C_ctype_ + 1)[(int)(c)] & _L))
#define isprint(c)      ((int)((_C_ctype_ + 1)[(int)(c)] & (_P|_U|_L|_N|_B)))
#define ispunct(c)      ((int)((_C_ctype_ + 1)[(int)(c)] & _P))
#define isspace(c)      ((int)((_C_ctype_ + 1)[(int)(c)] & _S))
#define isupper(c)      ((int)((_C_ctype_ + 1)[(int)(c)] & _U))
#define isxdigit(c)     ((int)((_C_ctype_ + 1)[(int)(c)] & (_N|_X)))

#define toascii(c)      ((c) & 0177)
#define tolower(c)     ((c) - 'A' + 'a')
#define toupper(c)     ((c) - 'a' + 'A')

#ifdef __cplusplus
}
#endif

#endif
