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
#define GPIOCEN                     (1U << 2)
#define PIN5                        (1U << 5)
#define PIN13                       (1U << 13)
#define LED_PIN                     PIN5
#define PUSH_BUTTON_PIN             PIN13

void _init(){}

void delay(int ms){
    for(volatile int i = 0; i < ms*100000; i++) {}
    return;
}

int main(void){

    //Enable the clock for GPIOA and GPIOC
    RCC->AHB1ENR |= GPIOAEN; // Enable the clock for GPIOA
    RCC->AHB1ENR |= GPIOCEN; // Enable the clock for GPIOC

    // Set PA5 as output mode and PC13 as input mode
    GPIOA->MODER |= (1U << 10); // Set PA5 as output mode
    GPIOA->MODER &= ~(1U << 11); // Clear PA5 mode bits

    GPIOC->MODER &= ~(3U << 26); // Set PC13 as input mode

    while(1){

        //ceck if button is pressed
        if(GPIOC -> IDR & PUSH_BUTTON_PIN){
            // Button is pressed
            GPIOA->BSRR |= LED_PIN; // Set PA5 high (LED ON)
        } else {
            // Button is not pressed
            GPIOA->BSRR |= (1U << 21); // Reset PA5 (LED OFF)
        }
    }
    return 0;
}