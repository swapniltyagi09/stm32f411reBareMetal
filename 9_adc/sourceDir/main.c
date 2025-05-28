#include "stm32f4xx.h"
#include "adc.h"
#include "usart.h"

uint32_t sensorValue;

void _init(){}

int main(void){

    initialise();
    usart2TxInit();
    

    while(1){
        startConversion();
        sensorValue = adcRead();
        printf("Sensor Value : %lu\n\r",sensorValue);

    }

    return 0;
}
