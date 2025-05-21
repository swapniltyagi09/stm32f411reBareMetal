#include "stm32f4xx.h"
#include <stdio.h>
#include "uart.h"

void _init(){}

int main(void){

	usart2TxInit();

	while(1){
		printf("Hello from STM32F411RE................\n\r");
	}

	return 0;
}