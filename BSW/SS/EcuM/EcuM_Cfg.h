/*
 * EcuM_Cfg.h - AUTOSAR ECU State Manager Configuration
 *
 * Created on: 2023-xx-xx
 * Author: BSW Team
 *
 * Description: This file contains the configuration definitions for the
 *              ECU State Manager module for Infineon TC377
 */

#ifndef ECUM_CFG_H
#define ECUM_CFG_H

/* Include AUTOSAR standard types */
#include "Std_Types.h"

/* API service IDs */
#define ECUM_INIT_SID                     (0x00u)
#define ECUM_STARTUP_SID                  (0x01u)
#define ECUM_SHUTDOWN_SID                 (0x02u)
#define ECUM_GETSTATE_SID                 (0x03u)
#define ECUM_GET_VERSION_INFO_SID         (0x04u)

/* Error codes */
#define ECUM_E_NOT_INITIALIZED            (0x01u)
#define ECUM_E_ALREADY_INITIALIZED        (0x02u)
#define ECUM_E_PARAM_POINTER              (0x03u)

/* Shutdown target modes */
typedef enum {
    ECUM_SHUTDOWN_TARGET_SLEEP,
    ECUM_SHUTDOWN_TARGET_RESET,
    ECUM_SHUTDOWN_TARGET_OFF
} EcuM_ShutdownTargetType;

/* Configuration structure */
typedef struct {
    uint32 startupTimeoutMs;
    uint32 shutdownTimeoutMs;
    EcuM_ShutdownTargetType defaultShutdownTarget;
} EcuM_ConfigType;

/* Configuration parameters */
const EcuM_ConfigType EcuM_Configuration = {
    .startupTimeoutMs = 1000,
    .shutdownTimeoutMs = 500,
    .defaultShutdownTarget = ECUM_SHUTDOWN_TARGET_RESET
};

#endif /* ECUM_CFG_H */