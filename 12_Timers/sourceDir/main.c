#include "stm32f4xx.h"
#include "usart.h"
#include "systick.h"
#include "tim.h"

void _init(){}

int main(void){

    /*Enable clock access to GPIOA*/
    RCC->AHB1ENR = RCC_AHB1ENR_GPIOAEN;

    /*Set PA5 as the output pin*/
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    GPIOA->MODER &= ~(GPIO_MODER_MODE5_1);


    usart2TxInit();
    tim2_1Hz_init();
    
    while(1){

        /*Wait until the timer reaches the auto-reload value*/
        while(!(TIM2->SR & TIM_SR_UIF)){}; // Wait for update event

        /*Clear UIF*/
        TIM2->SR &= ~TIM_SR_UIF; // Clear the update interrupt flag

        /*Toggle PA5*/
        printf("A second passed !! \n\r");
        GPIOA->ODR ^= GPIO_ODR_OD5;
        
    }
    return 0;
}
