
#ifndef UART_H
#define UART_H

#include "stm32f4xx.h"
void usart2TxInit();
char usart2DataRead(void);
void usart2RxTxInit();

#endif /*UART_H*/