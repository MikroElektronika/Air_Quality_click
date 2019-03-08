#include "Click_Air_quality_types.h"


void airquality_adcInit()
{
    ADC_Init();
}

uint32_t airquality_readADC()
{
    uint32_t readADC;
    
    readADC = ADC_Read( 7 );
    
    return readADC;
}