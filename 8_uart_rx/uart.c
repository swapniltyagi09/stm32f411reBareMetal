#include "uart.h"


#define SYS_FREQ		(16000000)
#define APB1_CLK		SYS_FREQ
#define UART2_BAUDRATE	115200

void usart2TxInit(){
	/*****Configure USART2 GPIO PIN*****/
	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	/*Set PA2 mode to alternate Function mode*/
	GPIOA->MODER &= ~(GPIO_MODER_MODER2_0);
	GPIOA->MODER |= GPIO_MODER_MODER2_1;

	/*Set PA2 alternate function type as USART2_TX (AF07)*/
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL2_0;
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL2_1;
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL2_2;
	GPIOA->AFR[0] &= ~(GPIO_AFRL_AFSEL2_3);

	/*Configure USART2 module*/
	/*Enable clock access to USART2*/
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

	/*Conigure the USART2 Baud Rate*/
	USART2->BRR = (SYS_FREQ + (UART2_BAUDRATE/2))/UART2_BAUDRATE;

	/*Configure the transfer direction*/
	USART2->CR1 = USART_CR1_TE; //Clean everything and only set TE bit as 1 , to enable transmission mode

	/*Enable the USART2 module*/
	USART2->CR1 |= USART_CR1_UE;

}

void usart2RxTxInit(){
	/*****Configure USART2 GPIO PIN*****/
	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	/*Set PA2 mode to alternate Function mode*/
	GPIOA->MODER &= ~(GPIO_MODER_MODER2_0);
	GPIOA->MODER |= GPIO_MODER_MODER2_1;

	/*Set PA3 mode to alternate Function mode*/
	GPIOA->MODER &= ~(GPIO_MODER_MODER3_0);
	GPIOA->MODER |= GPIO_MODER_MODER3_1;

	/*Set PA2 alternate function type as USART2_TX (AF07)*/
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL2_0;
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL2_1;
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL2_2;
	GPIOA->AFR[0] &= ~(GPIO_AFRL_AFSEL2_3);

	/*Set PA3 alternate function type as USART2_RX ()*/
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL3_0;
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL3_1;
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL3_2;
	GPIOA->AFR[0] &= ~(GPIO_AFRL_AFSEL3_3);

	/*Configure USART2 module*/
	/*Enable clock access to USART2*/
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

	/*Conigure the USART2 Baud Rate*/
	USART2->BRR = (SYS_FREQ + (UART2_BAUDRATE/2))/UART2_BAUDRATE;

	/*Configure the transfer direction*/
	USART2->CR1 = USART_CR1_TE | USART_CR1_RE; //Clean everything and only set TE and RE  bits as 1 , to enable transmission mode and reception mode

	/*Enable the USART2 module*/
	USART2->CR1 |= USART_CR1_UE;

}

void usart2DataWrite(int ch){
	/*Make sure that transmit data regster is empty*/
	while(!(USART2->SR & USART_SR_TXE)){}

	/*Write to transmit data register*/
	USART2->DR = ch & USART_DR_DR;
}

char usart2DataRead(void){
	/*Make sure that recieve data regster is empty*/
	while(!(USART2->SR & USART_SR_RXNE)){}

	/*Read data*/
	return USART2->DR;

}

int __io_putchar(int ch){
	usart2DataWrite(ch);
	return ch;
}