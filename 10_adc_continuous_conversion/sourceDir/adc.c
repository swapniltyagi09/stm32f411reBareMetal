#ifndef ADC_H_
#define ADC_H_
#include "stm32f4xx.h"
#include <stdint.h>

void initialise(void){
    /*ENABLE CLOCK FOR ADC1*/
    RCC->APB2ENR = RCC_APB2ENR_ADC1EN; 

    /*ENABLE GPIO FOR ANALOG OUTPUT*/
    RCC->AHB1ENR = RCC_AHB1ENR_GPIOAEN; //Enabling GPIOA;

    /*Configure PA1 in analog mode (11)*/
    GPIOA->MODER |= GPIO_MODER_MODER1; //Configuring PA1 in analog mode for ADC

    /*Configure ADC Parameters*/
    ADC1->SQR3= ADC_SQR3_SQ1_0;

    /*Configure the sequence length (Number of conversions)*/
    ADC1->SQR1 = 0x0UL << ADC_SQR1_L_Pos; //We are configuring only one channel , so set L to 0000;

    /*Enable the ADC module*/
    ADC1->CR2 |= ADC_CR2_ADON;

    }

void startConversion(void){
    /*Enable continuos conversion*/
    ADC1->CR2 |= ADC_CR2_CONT;
    /*Start ADC conversion */
    ADC1->CR2 |= ADC_CR2_SWSTART;
}

uint32_t adcRead(void){
    /*Wait for conversion to complete */
    while(!(ADC1->SR & ADC_SR_EOC)){}

    /*Read Converted result*/
    return ADC1->DR;

}

#endif


