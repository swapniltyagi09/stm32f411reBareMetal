#include "stm32f4xx.h"
#include "usart.h"
#include "systick.h"

void _init(){}

int main(void){

    /*Enable clock access to GPIOA*/
    RCC->AHB1ENR = RCC_AHB1ENR_GPIOAEN;

    /*Set PA5 as the output pin*/
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    GPIOA->MODER &= ~(GPIO_MODER_MODE5_1);

    usart2TxInit();
    
    while(1){
        
        printf("A second passed !! \n\r");
        GPIOA->ODR ^= GPIO_ODR_OD5;
        systickDelayMs(1000);

    }
    return 0;
}
