#ifndef _JZ_OSTIMER_H_
#define _JZ_OSTIMER_H_

#include <stdint.h>

extern uint32_t ostimer32();
extern uint64_t ostimer64();
extern int ostimer_clk();
extern void __ostimer_start(uint32_t ostcsr);
extern void ostimer_start(int is_fast);
extern void ostimer_stop();

#endif /* _JZ_OSTIMER_H_ */
