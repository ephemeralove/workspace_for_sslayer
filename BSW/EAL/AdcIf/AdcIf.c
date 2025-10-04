/*
 * AdcIf.c - AUTOSAR ADC Interface Implementation
 *
 * Created on: 2023-xx-xx
 * Author: BSW Team
 *
 * Description: This file contains the implementation of
 *              ADC interface for Infineon TC377
 */

#include "AdcIf.h"
#include "Det.h"

/* Internal variables */
static AdcIf_CallbackType AdcIf_Callbacks[4] = {NULL_PTR};

/**
 * @brief Initialize ADC Interface
 */
void AdcIf_Init(void)
{
    /* Initialize hardware ADC */
    /* Configure ADC channels, sampling time, etc. */
    
    /* Clear all callbacks */
    for (uint8 i = 0; i < 4; i++)
    {
        AdcIf_Callbacks[i] = NULL_PTR;
    }
}

/**
 * @brief Start ADC conversion on specified channel
 * @param channel ADC channel number
 */
void AdcIf_StartConversion(uint8 channel)
{
    if (channel < 4)
    {
        /* Start hardware ADC conversion */
        /* This would typically involve:
         * - Selecting the channel
         * - Triggering the conversion
         */
    }
    else
    {
        Det_ReportError(ADCIF_MODULE_ID, 0, ADCIF_START_CONVERSION_SID, DET_E_PARAM);
    }
}

/**
 * @brief Register callback for ADC channel
 * @param channel ADC channel number
 * @param callback Callback function pointer
 */
void AdcIf_RegisterCallback(uint8 channel, AdcIf_CallbackType callback)
{
    if (channel < 4)
    {
        AdcIf_Callbacks[channel] = callback;
    }
    else
    {
        Det_ReportError(ADCIF_MODULE_ID, 0, ADCIF_REGISTER_CALLBACK_SID, DET_E_PARAM);
    }
}

/**
 * @brief ADC Interrupt Service Routine
 * 
 * This function should be called from the actual ADC ISR
 * in the MCAL layer or hardware abstraction layer.
 * 
 * @param channel ADC channel number
 * @param result Conversion result
 */
void AdcIf_Isr(uint8 channel, AdcIf_ValueType result)
{
    if (channel < 4 && AdcIf_Callbacks[channel] != NULL_PTR)
    {
        /* Call application layer callback */
        AdcIf_Callbacks[channel](result);
    }
}