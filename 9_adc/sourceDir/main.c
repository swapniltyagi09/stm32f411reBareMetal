#include "stm32f4xx.h"
#include "adc.h"

uint32_t sensorValue;

void _init(){}


int main(void){

    initialise();

    while(1){
         startConversion();
        sensorValue = adcRead();
    }

    return 0;
}
