#ifndef _MLED_H_
#define _MLED_H_

typedef enum {
	MLED_L1,
	MLED_L2,
	MLED_L3,
	MLED_L123,
} MLed_Enum;

void mLedInit(void);
void mLedSetOn(MLed_Enum led);
void mLedSetOff(MLed_Enum led);
void mLedSetShine(MLed_Enum led);

#endif /* _MLED_H */
