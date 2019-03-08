/*
    __airquality_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__airquality_driver.h"
#include "__airquality_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __AIRQUALITY_DRV_I2C__
static uint8_t _slaveAddress;
#endif

const float _AIRQUALITY_RLOAD                                     = 10.0;
const float _AIRQUALITY_RZERO                                     = 76.63;
const float _AIRQUALITY_PARA                                      = 116.6020682;
const float _AIRQUALITY_PARB                                      = 2.769034857;
const float _AIRQUALITY_CORA                                      = 0.00035;
const float _AIRQUALITY_CORB                                      = 0.02718;
const float _AIRQUALITY_CORC                                      = 1.39538;
const float _AIRQUALITY_CORD                                      = 0.0018;
const float _AIRQUALITY_ATMOCO2                                   = 397.13;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __AIRQUALITY_DRV_SPI__

void airquality_spiDriverInit(T_AIRQUALITY_P gpioObj, T_AIRQUALITY_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __AIRQUALITY_DRV_I2C__

void airquality_i2cDriverInit(T_AIRQUALITY_P gpioObj, T_AIRQUALITY_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __AIRQUALITY_DRV_UART__

void airquality_uartDriverInit(T_AIRQUALITY_P gpioObj, T_AIRQUALITY_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

// GPIO Only Drivers - remove in other cases
void airquality_gpioDriverInit(T_AIRQUALITY_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
}

/* ----------------------------------------------------------- IMPLEMENTATION */

/* Get the correction factor function */
float airquality_getCorrectionFactor( float temperature, float humidity )
{
    float result;
    
    result = _AIRQUALITY_CORA;
    result *= temperature * temperature;
    result -= _AIRQUALITY_CORB * temperature;
    result += _AIRQUALITY_CORC;
    result -= ( humidity - 33.0 ) * _AIRQUALITY_CORD;
    
    return result;
}

/* Get the resistance of the sensor function */
float airquality_getResistance( uint32_t adcValue )
{
    float result;
    
    result = 1023.0;
    result /= ( float ) adcValue;
    result *= 5.0;
    result -= 1.0;
    result *= _AIRQUALITY_RLOAD;

    return result;
}

/* Get the corrected resistance of the sensor function */
float airquality_getCorrectedResistance( float temperature, float humidity, uint32_t adcValue )
{
    float result;

    result = airquality_getResistance( adcValue );
    result /= airquality_getCorrectionFactor( temperature, humidity );

    return result;
}





/* -------------------------------------------------------------------------- */
/*
  __airquality_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */