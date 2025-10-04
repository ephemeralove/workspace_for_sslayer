/*
 * AdcIf.h - AUTOSAR ADC Interface Header
 *
 * Created on: 2023-xx-xx
 * Author: BSW Team
 *
 * Description: This file contains the interface definitions
 *              for ADC module on Infineon TC377
 */

#ifndef ADCIF_H
#define ADCIF_H

#include "Std_Types.h"

/* ADC Channel IDs */
#define ADCIF_CHANNEL_0  0
#define ADCIF_CHANNEL_1  1
#define ADCIF_CHANNEL_2  2
#define ADCIF_CHANNEL_3  3

/* ADC Result Type */
typedef uint16 AdcIf_ValueType;

/* ADC Callback Function Pointer */
typedef void (*AdcIf_CallbackType)(AdcIf_ValueType result);

/* Function Prototypes */
void AdcIf_Init(void);
void AdcIf_StartConversion(uint8 channel);
void AdcIf_RegisterCallback(uint8 channel, AdcIf_CallbackType callback);

#endif /* ADCIF_H */