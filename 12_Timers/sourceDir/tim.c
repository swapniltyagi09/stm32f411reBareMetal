#include "stm32f4xx.h"

void tim2_1Hz_init(void){
    /*Enable clock access to timer 2*/
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    /*Set prescale value*/
    TIM2->PSC = 16000 - 1; // Prescaler value for 1 Hz (assuming 16 MHz clock)

    /*set auto-reload value*/
    TIM2->ARR = 1000 - 1; // Auto-reload value for 1 Hz (1000 ms)

    /*Clear counter*/
    TIM2->CNT = 0; // Clear the counter
    
    /*Enable Timer*/
    TIM2->CR1 |= TIM_CR1_CEN; // Enable the timer


}
