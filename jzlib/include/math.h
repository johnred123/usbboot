/* Copyright (c) 2002,2007-2009 Michael Stumpf

   Portions of documentation Copyright (c) 1990 - 1994
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
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id: math.h 2064 2009-11-29 06:19:16Z dmix $ */

/*
   math.h - mathematical functions

   Author : Michael Stumpf
            Michael.Stumpf@t-online.de

   __ATTR_CONST__ added by marekm@linux.org.pl for functions
   that "do not examine any values except their arguments, and have
   no effects except the return value", for better optimization by gcc.
 */

#ifndef __MATH_H
#define __MATH_H

#define M_E		2.7182818284590452354
#define M_LOG2E		1.4426950408889634074	/* log_2 e */
#define M_LOG10E	0.43429448190325182765	/* log_10 e */
#define M_LN2		0.69314718055994530942	/* log_e 2 */
#define M_LN10		2.30258509299404568402	/* log_e 10 */
#define M_PI		3.14159265358979323846	/* pi */
#define M_PI_2		1.57079632679489661923	/* pi/2 */
#define M_PI_4		0.78539816339744830962	/* pi/4 */
#define M_1_PI		0.31830988618379067154	/* 1/pi */
#define M_2_PI		0.63661977236758134308	/* 2/pi */
#define M_2_SQRTPI	1.12837916709551257390	/* 2/sqrt(pi) */
#define M_SQRT2		1.41421356237309504880	/* sqrt(2) */
#define M_SQRT1_2	0.70710678118654752440	/* 1/sqrt(2) */
#define NAN	__builtin_nan("")
#define INFINITY	__builtin_inf()


#ifndef __ATTR_CONST__
# define __ATTR_CONST__ __attribute__((__const__))
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define isinf	__isinfd
#define isinff	__isinff

extern double cos(double __x) __ATTR_CONST__;
extern double sin(double __x) __ATTR_CONST__;
extern double tan(double __x) __ATTR_CONST__;
extern double fabs(double __x) __ATTR_CONST__;
extern double fmod(double __x, double __y) __ATTR_CONST__;
extern double modf(double __x, double *__iptr);
extern double sqrt(double __x) __ATTR_CONST__;
extern double cbrt(double __x) __ATTR_CONST__;
extern double hypot (double __x, double __y) __ATTR_CONST__;
extern double square(double __x) __ATTR_CONST__;
extern double floor(double __x) __ATTR_CONST__;
extern double ceil(double __x) __ATTR_CONST__;
extern double frexp(double __x, int *__pexp);
extern double ldexp(double __x, int __exp) __ATTR_CONST__;
extern double exp(double __x) __ATTR_CONST__;
extern double cosh(double __x) __ATTR_CONST__;
extern double sinh(double __x) __ATTR_CONST__;
extern double tanh(double __x) __ATTR_CONST__;
extern double acos(double __x) __ATTR_CONST__;
extern double asin(double __x) __ATTR_CONST__;
extern double atan(double __x) __ATTR_CONST__;
extern double atan2(double __y, double __x) __ATTR_CONST__;
extern double log(double __x) __ATTR_CONST__;
extern double log10(double __x) __ATTR_CONST__;
extern double pow(double __x, double __y) __ATTR_CONST__;
extern int isnan(double __x) __ATTR_CONST__;
extern int isinf(double __x) __ATTR_CONST__;

extern int isinff(float __x) __ATTR_CONST__;

#if 0
#define cosf	cos		/**< The alias for cos().	*/
#define sinf	sin		/**< The alias for sin().	*/
#define tanf	tan		/**< The alias for tan().	*/
#define fabsf	fabs		/**< The alias for fabs().	*/
extern float modff (float __x, float *__iptr);
#define fmodf	fmod		/**< The alias for fmod().	*/
#define sqrtf	sqrt		/**< The alias for sqrt().	*/
#define cbrtf	cbrt		/**< The alias for cbrt().	*/
#define hypotf	hypot		/**< The alias for hypot().	*/
#define squaref	square		/**< The alias for square().	*/
#define floorf	floor		/**< The alias for floor().	*/
#define ceilf	ceil		/**< The alias for ceil().	*/
#define frexpf	frexp		/**< The alias for frexp().	*/
#define ldexpf	ldexp		/**< The alias for ldexp().	*/
#define expf	exp		/**< The alias for exp().	*/
#define coshf	cosh		/**< The alias for cosh().	*/
#define sinhf	sinh		/**< The alias for sinh().	*/
#define tanhf	tanh		/**< The alias for tanh().	*/
#define acosf	acos		/**< The alias for acos().	*/
#define asinf	asin		/**< The alias for asin().	*/
#define atanf	atan		/**< The alias for atan().	*/
#define atan2f	atan2		/**< The alias for atan2().	*/
#define logf	log		/**< The alias for log().	*/
#define log10f	log10		/**< The alias for log10().	*/
#define powf	pow		/**< The alias for pow().	*/
#define	isnanf	isnan		/**< The alias for isnan().	*/
#define isinff	isinf		/**< The alias for isinf().	*/
#define isfinitef isfinite	/**< The alias for isfinite().	*/
#endif

extern int signbit (double __x) __ATTR_CONST__;
extern double fdim (double __x, double __y) __ATTR_CONST__;
extern double fma (double __x, double __y, double __z) __ATTR_CONST__;
extern double fmax (double __x, double __y) __ATTR_CONST__;
extern double fmin (double __x, double __y) __ATTR_CONST__;
extern double trunc (double __x) __ATTR_CONST__;
extern double round (double __x) __ATTR_CONST__;
extern long lround (double __x) __ATTR_CONST__;
extern long lrint (double __x) __ATTR_CONST__;

#if 0
#define signbitf signbit	/**< The alias for signbit().	*/
#define fdimf	fdim		/**< The alias for fdim().	*/
#define fmaf	fma		/**< The alias for fma().	*/
#define fmaxf	fmax		/**< The alias for fmax().	*/
#define fminf	fmin		/**< The alias for fmin().	*/
#define truncf	trunc		/**< The alias for trunc().	*/
#define roundf	round		/**< The alias for round().	*/
#define lroundf	lround		/**< The alias for lround().	*/
#define lrintf	lrint		/**< The alias for lrint().	*/
#endif

#ifdef __cplusplus
}
#endif

#endif /* !__MATH_H */
