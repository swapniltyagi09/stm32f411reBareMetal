#include "stm32f4xx.h"
#include "usart.h"
#include "systick.h"
#include "tim.h"

void _init(){}

int main(void){

   tim2_pa5_output_compare();
    
    while(1){}
    return 0;
}
