// STM32F411RE LED BLINK 
//AUTHOR: SWAPNIL TYAGI
//DATE:  14-MAY-2025

//DESCRIPTION: This code is used to blink the LED connected to pin PA5 of STM32F411RE microcontroller.
// The code is written in C and uses the STM32F4xx standard peripheral library.
// The code is designed to run on the STM32F411RE microcontroller and uses the GPIOA port to control the LED.
// This is a bare metal programming example.
// The code does not use any operating system or RTOS.

#include <stdint.h>
#include <stm32f4xx.h>

#define GPIOAEN                     (1U << 0)
#define PIN5                        (1U << 5)
#define LED_PIN                     PIN5

void _init(){}

void delay(int ms){
    for(volatile int i = 0; i < ms*100000; i++) {}
    return;
}

int main(void){

    //RCC_AHB1EN_REGISTER |= GPIOAEN;
    RCC->AHB1ENR |= GPIOAEN; // Enable the clock for GPIOA

    GPIOA->MODER |= (1U << 10); // Set PA5 as output mode
    GPIOA->MODER &= ~(1U << 11); // Clear PA5 mode bits

    //GPIOA_MODER_REGISTER |= (1U << 10);
    //GPIOA_MODER_REGISTER &= ~(1U << 11);

    while(1){
        GPIOA->ODR  ^= LED_PIN;
        //for(int i = 0; i < 500000 ; i++){}
        delay(1);
    }
    return 0;
}