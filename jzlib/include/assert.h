/* Copyright (c) 2005,2007 Joerg Wunsch
   All rights reserved.

   Portions of documentation Copyright (c) 1991, 1993
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

  $Id: assert.h 1196 2007-01-23 15:34:58Z joerg_wunsch $
*/

#undef assert

#  if defined(NDEBUG)
#    define assert(e)	((void)0)
#  else /* !NDEBUG */
#    if defined(__ASSERT_USE_STDERR)
#      define assert(e)	((e) ? (void)0 : \
                         __assert(__func__, __FILE__, __LINE__, #e))
#    else /* !__ASSERT_USE_STDERR */
#      define assert(e)	((e) ? (void)0 : abort())
#    endif /* __ASSERT_USE_STDERR */
#  endif /* NDEBUG */

#ifdef __cplusplus
extern "C" {
#endif

extern void __assert(const char *__func, const char *__file,
		     int __lineno, const char *__sexp);

#ifdef __cplusplus
}
#endif

