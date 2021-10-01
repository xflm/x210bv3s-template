#ifndef _UART_H_
#define _UART_H_

#include <stdint.h>

void UART_Init(void);
void UART0_OutByte(uint8_t byte);
void UART0_OutBytes(const void *bytes, uint32_t len);
void UART0_OutString(const char *str);
uint8_t UART0_InByte(void);
uint32_t UART0_InBytes(void *bytes, uint32_t len);
void UART0_StopRun(void);
void UART0_RunCmd(const char *cmd);
void UART0_RunCmd1(void);
void UART0_RunCmd2(void);
void UART0_Isr(void);

#endif /* _UART_H_ */
