#include "Click_Air_quality_types.h"


void airquality_adcInit()
{
    ADC_Init();
	ADC_Set_Input_Channel( _ADC_CHANNEL_4 );
}

uint32_t airquality_readADC()
{
    uint32_t readADC;
    
    readADC = ADC_Read( 4 );
    
    return readADC;
}