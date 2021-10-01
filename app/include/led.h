#ifndef _LED_H_
#define _LED_H_

#include <stdint.h>

typedef enum {
	LED1    = 0x1,
	LED2    = 0x2,
	LED3    = 0x4,
	LED_ALL = 0x7,
} LED_e;

typedef enum {
	LED_STATE_OFF = 0,
	LED_STATE_ON  = 1,
} LED_State_e;

void LED_Init(void);
void LED_On(LED_e led);
void LED_Off(LED_e led);
void LED_OnOff(LED_e led);
LED_State_e LED_State(LED_e led);
void LED_PWM(uint32_t onMs, uint32_t offMs);

#endif /* _LED_H_ */
