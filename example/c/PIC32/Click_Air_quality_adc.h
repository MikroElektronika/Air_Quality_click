#include "Click_Air_quality_types.h"


void airquality_adcInit()
{
    ADC1_Init();
}

uint32_t airquality_readADC()
{
    uint32_t readADC;
    
    readADC = ADC1_Read( 8 );
    
    return readADC;
}