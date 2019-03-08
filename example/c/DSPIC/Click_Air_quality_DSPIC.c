/*
Example for Air_quality Click

    Date          : Jan 2019.
    Author        : Nenad Filipovic

Test configuration dsPIC :
    
    MCU                : P33FJ256GP710A
    Dev. Board         : EasyPIC Fusion v7
    dsPIC Compiler ver : v7.1.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO and LOG structures, sets AN pin as input.
- Application Initialization - Initialization driver enables GPIO and ADC, also starts write log.
- Application Task - (code snippet) This is a example which demonstrates the use of Air quality Click board.
     Air quality Click reads ADC value.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart changes for every 1 sec.

Additional Functions :

- void airquality_adcInit() - Function ADC initialization
- uint32_t airquality_readADC() - Function read ADC value

*/

#include "Click_Air_quality_types.h"
#include "Click_Air_quality_config.h"
#include "Click_Air_quality_adc.h"


uint16_t valueADC;
char logText[ 50 ];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );

    mikrobus_logInit( _LOG_USBUART_A, 9600 );

    Delay_100ms();
}

void applicationInit()
{
    airquality_gpioDriverInit( (T_AIRQUALITY_P)&_MIKROBUS1_GPIO );

    Delay_100ms();

    mikrobus_logWrite( "-------------------", _LOG_LINE );
    mikrobus_logWrite( " Air quality click ", _LOG_LINE );
    mikrobus_logWrite( "-------------------", _LOG_LINE );

    airquality_adcInit();

    Delay_100ms();

    mikrobus_logWrite( "   Initializated", _LOG_LINE );
    mikrobus_logWrite( "-------------------", _LOG_LINE );
}

void applicationTask()
{
    valueADC = airquality_readADC();

    Delay_100ms();

    IntToStr( valueADC, logText );
    mikrobus_logWrite( " ADC value: ", _LOG_TEXT );
    mikrobus_logWrite( logText, _LOG_LINE );
    mikrobus_logWrite( "-------------------", _LOG_LINE );

    Delay_1sec();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}