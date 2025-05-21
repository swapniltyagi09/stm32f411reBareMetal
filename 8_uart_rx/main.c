#include "stm32f4xx.h"
#include <stdio.h>
#include "uart.h"

void _init(){}
char key;

int main(void){

	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	/*SET PA5 as output pin*/
	GPIOA->MODER |= GPIO_MODER_MODER5_0;
	GPIOA->MODER &= ~(GPIO_MODER_MODER5_1);

	usart2RxTxInit();

	while(1){
		key = usart2DataRead();
		if(key =='1')
			GPIOA->ODR |= GPIO_ODR_OD5;

		else
			GPIOA->ODR &= ~(GPIO_ODR_OD5);

	}

	return 0;
}