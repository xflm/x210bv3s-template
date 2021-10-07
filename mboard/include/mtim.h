#ifndef _MTIM_H_
#define _MTIM_H_

#include <stdint.h>

void mTimInit(void);
void mTimDelayMs(uint16_t ms);
void mTimDelayS(uint16_t s);

#endif /* _MTIM_H_ */
