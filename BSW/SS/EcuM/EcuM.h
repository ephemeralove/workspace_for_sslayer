/*
 * EcuM.h - AUTOSAR ECU State Manager Interface
 *
 * Created on: 2023-xx-xx
 * Author: BSW Team
 *
 * Description: This file contains the interface definition for the
 *              ECU State Manager module for Infineon TC377
 */

#ifndef ECUM_H
#define ECUM_H

/* Include AUTOSAR standard types */
#include "Std_Types.h"

/* AUTOSAR Version information */
#define ECUM_VENDOR_ID                    (0x1234)
#define ECUM_MODULE_ID                    (0x000C)
#define ECUM_AR_RELEASE_MAJOR_VERSION     (4)
#define ECUM_AR_RELEASE_MINOR_VERSION     (4)
#define ECUM_AR_RELEASE_REVISION_VERSION  (0)
#define ECUM_SW_MAJOR_VERSION             (1)
#define ECUM_SW_MINOR_VERSION             (0)
#define ECUM_SW_PATCH_VERSION             (0)

/* Check AUTOSAR version compatibility */
#if ((STD_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION) || \
     (STD_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION))
#error "AUTOSAR version mismatch between EcuM.h and Std_Types.h"
#endif

/* ECU states */
typedef enum {
    ECUM_STATE_STARTUP,
    ECUM_STATE_RUN,
    ECUM_STATE_SHUTDOWN,
    ECUM_STATE_SLEEP,
    ECUM_STATE_RESET
} EcuM_StateType;

/* Function prototypes */

/**
 * @brief   Initialize the ECU State Manager module
 */
void EcuM_Init(void);

/**
 * @brief   Start the ECU state machine
 */
void EcuM_Startup(void);

/**
 * @brief   Shutdown the ECU
 */
void EcuM_Shutdown(void);

/**
 * @brief   Get current ECU state
 */
EcuM_StateType EcuM_GetState(void);

/**
 * @brief   Get version information
 */
void EcuM_GetVersionInfo(Std_VersionInfoType *versioninfo);

#endif /* ECUM_H */