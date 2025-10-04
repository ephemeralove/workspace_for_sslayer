/*
 * Det_Cfg.h - Configuration file for Development Error Tracer
 *
 *  Created on: 2023-xx-xx
 *      Author: BSW Team
 *
 *  Description: This file contains the configuration parameters for the
 *               Development Error Tracer module
 */

#ifndef DET_CFG_H
#define DET_CFG_H

/* Include platform types */
#include "Platform_Types.h"

/* DET Configuration parameters */

/* Enable/Disable DET module */
#define DET_ENABLED                     (STD_ON)

/* Maximum number of errors that can be stored */
#define DET_MAX_ERROR_ENTRIES           (32u)

/* Enable/Disable version info API */
#define DET_VERSION_INFO_API            (STD_ON)

/* Enable/Disable runtime error reporting */
#define DET_RUNTIME_ERROR_REPORTING     (STD_ON)

/* Define if DET should report errors during initialization */
#define DET_REPORT_ERRORS_AT_INIT       (STD_ON)

/* Error buffer size for storing error information */
#define DET_ERROR_BUFFER_SIZE           (DET_MAX_ERROR_ENTRIES * 5u) /* 5 bytes per error entry */

/* Define if DET should trigger a trap on development errors */
#define DET_TRAP_ON_ERROR               (STD_OFF)  /* Set to STD_ON for debugging */

/* Define if DET should use dedicated hardware for error reporting */
#define DET_USE_HW_ERROR_PORT           (STD_OFF)

#if (DET_USE_HW_ERROR_PORT == STD_ON)
    /* Define hardware error port and pin if used */
    #define DET_ERROR_PORT              (0u)
    #define DET_ERROR_PIN               (0u)
#endif

/* Define if DET should timestamp error reports */
#define DET_USE_TIMESTAMP               (STD_OFF)

#if (DET_USE_TIMESTAMP == STD_ON)
    /* Include necessary header for timestamp functionality */
    /* #include "Gpt.h" */
    
    /* Define timestamp source */
    #define DET_TIMESTAMP_SOURCE        (0u)
#endif

#endif /* DET_CFG_H */