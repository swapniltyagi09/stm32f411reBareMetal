#include "stm32f4xx.h"
#define SYSTICK_LOAD_VAL        (16000)     /*Number of clock cycles for 1ms delay*/

void systickDelayMs(int delay){

    /*Reload with number of clocks per millisecond*/
    SysTick->LOAD = SYSTICK_LOAD_VAL;

    /*Clear SysTick current vale register*/
    SysTick->VAL = 0;


    /*Enable sysTick and select internal clk source*/
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_CLKSOURCE_Msk;

    for(int i = 0; i < delay ; i++){
        /*Wait until the COUNTFLAG is set*/
        while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0) {}
        
    }

    SysTick->CTRL = 0;

}