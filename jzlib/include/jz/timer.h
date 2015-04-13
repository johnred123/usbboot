#ifndef _JZ_TIMER_H_
#define _JZ_TIMER_H_
#include <stdint.h>

extern volatile uint32_t timer_ticks;

#define TIMER_HZ_MIN		   50
#define TIMER_HZ_MAX		 1000
#define TIMER_HZ_DEFAULT	  100

int timer_hz();
void __timer_start(uint32_t tcsr, int interval);
void timer_start(int hz);
void timer_stop();

#endif /* _JZ_TIMER_H_ */
