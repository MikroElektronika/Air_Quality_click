#include "Click_Air_quality_types.h"


void airquality_adcInit()
{
    ADC1_Init_Advanced(_ADC_12bit, _ADC_INTERNAL_VREFL | _ADC_INTERNAL_VREFH );
}

uint32_t airquality_readADC()
{
    uint32_t readADC;
    
    readADC = ADC1_Read( 8 );
    
    return readADC;
}