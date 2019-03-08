/*
    __airquality_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __airquality_driver.h
@brief    Air_quality Driver
@mainpage Air_quality Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   AIRQUALITY
@brief      Air_quality Click Driver
@{

| Global Library Prefix | **AIRQUALITY** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jan 2019.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _AIRQUALITY_H_
#define _AIRQUALITY_H_

/** 
 * @macro T_AIRQUALITY_P
 * @brief Driver Abstract type 
 */
#define T_AIRQUALITY_P    const uint8_t*

/** @defgroup AIRQUALITY_COMPILE Compilation Config */              /** @{ */

//  #define   __AIRQUALITY_DRV_SPI__                            /**<     @macro __AIRQUALITY_DRV_SPI__  @brief SPI driver selector */
//  #define   __AIRQUALITY_DRV_I2C__                            /**<     @macro __AIRQUALITY_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __AIRQUALITY_DRV_UART__                           /**<     @macro __AIRQUALITY_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup AIRQUALITY_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup AIRQUALITY_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup AIRQUALITY_INIT Driver Initialization */              /** @{ */

#ifdef   __AIRQUALITY_DRV_SPI__
void airquality_spiDriverInit(T_AIRQUALITY_P gpioObj, T_AIRQUALITY_P spiObj);
#endif
#ifdef   __AIRQUALITY_DRV_I2C__
void airquality_i2cDriverInit(T_AIRQUALITY_P gpioObj, T_AIRQUALITY_P i2cObj, uint8_t slave);
#endif
#ifdef   __AIRQUALITY_DRV_UART__
void airquality_uartDriverInit(T_AIRQUALITY_P gpioObj, T_AIRQUALITY_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void airquality_gpioDriverInit(T_AIRQUALITY_P gpioObj);
                                                                       /** @} */
/** @defgroup AIRQUALITY_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Get the correction factor function
 *
 * @param[in] temperature                    float value of the ambient air temperature
 *
 * @param[in] humidity                       float value of the relative humidity
 *
 * @return 
 * float value of the calculated correction factor
 *
 * Function get the correction factor to correct for temperature and humidity.
*/
float airquality_getCorrectionFactor( float temperature, float humidity );

/**
 * @brief Get the resistance of the sensor function
 *
 * @param[in] adcValue                       the measurement adc value
 *
 * @return
 * float value of the sensor resistance in kOhm
 *
 * Function get the resistance of the sensor, ie. measurement adc value
 * of MQ-135 sensor on Air quality Click.
*/
float airquality_getResistance( uint32_t adcValue );

/**
 * @brief Get the corrected resistance of the sensor function
 *
 * @param[in] temperature                    float value of the ambient air temperature
 *
 * @param[in] humidity                       float value of the relative humidity
 *
 * @param[in] adcValue                       the measurement adc value
 *
 * @return
 * float value of the corrected sensor resistance kOhm
 *
 * Function get the corrected resistance of the sensor, ie. measurement adc value
 * of MQ-135 sensor on Air quality Click.
*/
float airquality_getCorrectedResistance( float temperature, float humidity, uint32_t adcValue );






                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Air_quality_STM.c
    @example Click_Air_quality_TIVA.c
    @example Click_Air_quality_CEC.c
    @example Click_Air_quality_KINETIS.c
    @example Click_Air_quality_MSP.c
    @example Click_Air_quality_PIC.c
    @example Click_Air_quality_PIC32.c
    @example Click_Air_quality_DSPIC.c
    @example Click_Air_quality_AVR.c
    @example Click_Air_quality_FT90x.c
    @example Click_Air_quality_STM.mbas
    @example Click_Air_quality_TIVA.mbas
    @example Click_Air_quality_CEC.mbas
    @example Click_Air_quality_KINETIS.mbas
    @example Click_Air_quality_MSP.mbas
    @example Click_Air_quality_PIC.mbas
    @example Click_Air_quality_PIC32.mbas
    @example Click_Air_quality_DSPIC.mbas
    @example Click_Air_quality_AVR.mbas
    @example Click_Air_quality_FT90x.mbas
    @example Click_Air_quality_STM.mpas
    @example Click_Air_quality_TIVA.mpas
    @example Click_Air_quality_CEC.mpas
    @example Click_Air_quality_KINETIS.mpas
    @example Click_Air_quality_MSP.mpas
    @example Click_Air_quality_PIC.mpas
    @example Click_Air_quality_PIC32.mpas
    @example Click_Air_quality_DSPIC.mpas
    @example Click_Air_quality_AVR.mpas
    @example Click_Air_quality_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __airquality_driver.h

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