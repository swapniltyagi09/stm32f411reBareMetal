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

#define GPIOAEN                     (1U << 0)

#define PIN5                        (1U << 5)
#define LED_PIN                     PIN5

#define __IO                        volatile

typedef struct{
    __IO uint32_t MODER; // GPIO Port mode register
    __IO uint32_t OTYPER; // GPIO Port output type register
    __IO uint32_t OSPEEDR; // GPIO Port output speed register
    __IO uint32_t PUPDR; // GPIO Port pull-up/pull-down register
    __IO uint32_t IDR; // GPIO Port input data register
    __IO uint32_t ODR; // GPIO Port output data register        
    __IO uint32_t BSRR; // GPIO Port bit set/reset register     
    __IO uint32_t LCKR; // GPIO Port configuration lock register
    __IO uint32_t AFRL; // GPIO alternate function low register
    __IO uint32_t AFRH; // GPIO alternate function high register
}GPIO_Typedef;

typedef struct{
    __IO uint32_t CR; // RCC clock control register
    __IO uint32_t PLLCFGR; // RCC PLL configuration register
    __IO uint32_t CFGR; // RCC clock configuration register
    __IO uint32_t CIR; // RCC clock interrupt register
    __IO uint32_t AHB1RSTR; // RCC AHB1 peripheral reset register
    __IO uint32_t AHB2RSTR; // RCC AHB2 peripheral reset register
    __IO uint32_t AHB3RSTR; // RCC AHB3 peripheral reset register
    uint32_t RESERVED0; // Reserved
    __IO uint32_t APB1RSTR; // RCC APB1 peripheral reset register
    __IO uint32_t APB2RSTR; // RCC APB2 peripheral reset register
    uint32_t RESERVED1[2]; // Reserved
    __IO uint32_t AHB1ENR; // RCC AHB1 peripheral clock enable register
}RCC_Typedef;

#define RCC ((RCC_Typedef*)RCC_BASE)
#define GPIOA ((GPIO_Typedef*)GPIO_BASE)

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

    while(1){
        GPIOA->ODR  ^= LED_PIN;
        //for(int i = 0; i < 500000 ; i++){}
        delay(2);
    }
    return 0;
}