/* Copyright (c) 2002,2005, 2007 Joerg Wunsch
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

/* $Id: fdevopen.c 1944 2009-04-01 23:12:20Z arcanum $ */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "stdio_private.h"

FILE *
fdevopen(int (*put)(char, FILE *), int (*get)(FILE *))
{
	FILE *s;

	if (put == 0 && get == 0)
		return 0;

	if ((s = calloc(1, sizeof(FILE))) == 0)
		return 0;

	s->flags = __SMALLOC;

	if (get != 0) {
		s->get = get;
		s->flags |= __SRD;
#if 0
		if (stdin == 0)
			stdin = s;
#endif
	}

	if (put != 0) {
		s->put = put;
		s->flags |= __SWR;
#if 0
		if (stdout == 0) {
			stdout = s;
			if (stderr == 0)
				stderr = s;
		}
#endif
	}

	return s;
}
