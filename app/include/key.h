#ifndef _KEY_H_
#define _KEY_H_

typedef enum {
	KEY_UP    = 0x01,
	KEY_DOWN  = 0x02,
	KEY_LEFT  = 0x04,
	KEY_RIGHT = 0x08,
	KEY_HOME  = 0x10,
	KEY_ENUM  = 0x20,
	KEY_POWER = 0x40,
} KEY_e;

void KEY_Init(void);
void KEY_Scan(void);


#endif /* _KEY_H_ */
