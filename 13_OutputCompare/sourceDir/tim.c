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

void tim2_pa5_output_compare(void){

    /*Enable clock access to GPIOA*/
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    /*Set PA5 to alternate function mode*/
    GPIOA->MODER &= ~(GPIO_MODER_MODE5); // Clear mode bits for PA5
    GPIOA->MODER |= GPIO_MODER_MODE5_1; // Set PA5 to alternate function mode

    /*Enable PA5 alternate function type to TIM2_CH1*/
    GPIOA->AFR[0] &= ~(GPIO_AFRL_AFSEL5); // Clear alternate function bits for PA5
    GPIOA->AFR[0] |= (1 << GPIO_AFRL_AFSEL5_Pos); // Set PA5 to AF1 (TIM2_CH1)

    /*Enable clock access to timer 2*/
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    /*Set prescale value*/
    TIM2->PSC = 16000 - 1; // Prescaler value for 1 Hz (assuming 16 MHz clock)

    /*set auto-reload value*/
    TIM2->ARR = 1000 - 1; // Auto-reload value for 1 Hz (1000 ms)

    /*Set the output compare toggle mode*/
    TIM2->CCMR1 |= TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC1M_1; // Set OC1 mode to toggle
    TIM2->CCMR1 &= ~TIM_CCMR1_OC1M_2; // Clear OC1M bit 2

    /*Enable tim2 ch1 in compare mode*/
    TIM2->CCER |= TIM_CCER_CC1E; // Enable channel 1 output

    /*Clear counter*/
    TIM2->CNT = 0; // Clear the counter
    
    /*Enable Timer*/
    TIM2->CR1 |= TIM_CR1_CEN; // Enable the timer
}