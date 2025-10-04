/*
 * AdcIf_Cfg.h - AUTOSAR ADC Interface Configuration
 *
 * Created on: 2023-xx-xx
 * Author: BSW Team
 *
 * Description: Configuration file for ADC Interface module
 */

#ifndef ADCIF_CFG_H
#define ADCIF_CFG_H

/* Module ID and Vendor ID */
#define ADCIF_MODULE_ID          120
#define ADCIF_VENDOR_ID          0xABCD

/* Software Version Information */
#define ADCIF_SW_MAJOR_VERSION   1
#define ADCIF_SW_MINOR_VERSION   0
#define ADCIF_SW_PATCH_VERSION   0

/* API Service IDs */
#define ADCIF_INIT_SID                   0x01
#define ADCIF_START_CONVERSION_SID        0x02
#define ADCIF_REGISTER_CALLBACK_SID       0x03

/* Error Codes */
#define ADCIF_E_PARAM_CHANNEL            0x01

/* Development Error Codes */
#define ADCIF_E_UNINIT                   0x10
#define ADCIF_E_PARAM_POINTER            0x11

/* Maximum number of ADC channels */
#define ADCIF_MAX_CHANNELS               4

#endif /* ADCIF_CFG_H */