#include "stm32f4xx.h"
#include "usart.h"
#include "systick.h"
#include "tim.h"

int timeStamp = 0;

void _init(){}

int main(void){

   tim2_pa5_output_compare();
   tim3_pa6_input_capture();
   usart2TxInit();
    
    while(1){
        /*Wait until edge is captured*/
        while(!(TIM3->SR & TIM_SR_CC1IF)); // Wait for capture event on TIM3 channel 1

        /*Read Cvalue*/
        timeStamp = TIM3->CCR1; // Read the captured value from TIM3 channel 1
        printf("Captured value: %d\n\r", timeStamp); // Print the captured value

    }
    return 0;
}
