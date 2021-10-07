#ifndef _MUART_H_
#define _MUART_H_

#include <stdint.h>

void mUartInit(void);
void mUartPutString(const char *str);
void mUartPutBytes(const uint8_t *bytes, uint32_t len);

#endif /* _MUART_H_ */
