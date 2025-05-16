// STM32F411RE LED BLINK 
//AUTHOR: SWAPNIL TYAGI
//DATE:  14-MAY-2025

//DESCRIPTION: This code is used to blink the LED connected to pin PA5 of STM32F411RE microcontroller.
// The code is written in C and uses the STM32F4xx standard peripheral library.
// The code is designed to run on the STM32F411RE microcontroller and uses the GPIOA port to control the LED.
// This is a bare metal programming example.
// The code does not use any operating system or RTOS.

#include <stdint.h>

#define PERIPH_BASE                 (0x40000000UL)
#define AHB1_OFFSET                 (0x00020000UL)  
#define AHB1_BASE                   (PERIPH_BASE + AHB1_OFFSET)

#define GPIOA_OFFSET                (0x00000000UL)
#define GPIO_BASE                   (AHB1_BASE + GPIOA_OFFSET)

#define RCC_OFFSET                  (0x00003800UL)
#define RCC_BASE                    (AHB1_BASE + RCC_OFFSET)

#define RCC_AHB1EN_REGISTER_OFFEST  (0x00000030UL)
#define RCC_AHB1EN_REGISTER         (*(volatile unsigned int*)(RCC_BASE + RCC_AHB1EN_REGISTER_OFFEST))

#define GPIOA_MODER_OFFSET          (0x00000000UL)
#define GPIOA_MODER_REGISTER        (*(volatile unsigned int*)(GPIO_BASE + GPIOA_MODER_OFFSET))

#define GPIOA_ODR_OFFSET            (0x00000014UL)
#define GPIOA_ODR_REGISTER          (*(volatile unsigned int*)(GPIO_BASE + GPIOA_ODR_OFFSET))

#define GPIOAEN                     (1U << 0)

#define PIN5                        (1U << 5)
#define LED_PIN                     PIN5

void _init(){}

void delay(int ms){
    for(volatile int i = 0; i < ms*100000; i++) {}
    return;
}

int main(void){

    RCC_AHB1EN_REGISTER |= GPIOAEN;
    GPIOA_MODER_REGISTER |= (1U << 10);
    GPIOA_MODER_REGISTER &= ~(1U << 11);

    while(1){
        GPIOA_ODR_REGISTER ^= LED_PIN;
        //for(int i = 0; i < 500000 ; i++){}
        delay(5);
    }
    return 0;
}




