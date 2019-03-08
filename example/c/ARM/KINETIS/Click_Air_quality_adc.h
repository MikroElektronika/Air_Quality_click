#include "Click_Air_quality_types.h"


void airquality_adcInit()
{
    ADC1_Init();
    ADC_Set_Input_Channel( _ADC_CHANNEL_12 );
}

uint32_t airquality_readADC()
{
    uint32_t readADC;
    
    readADC = ADC1_Read( 12 );
    
    return readADC;
}