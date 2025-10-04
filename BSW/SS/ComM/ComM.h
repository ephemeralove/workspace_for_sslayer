/*
 * ComM.h - AUTOSAR Communication Manager Interface
 *
 * Created on: 2023-xx-xx
 * Author: BSW Team
 *
 * Description: This file contains the interface definition for the
 *              Communication Manager module for Infineon TC377
 */

#ifndef COMM_H
#define COMM_H

/* Include AUTOSAR standard types */
#include "Std_Types.h"

/* AUTOSAR Version information */
#define COMM_VENDOR_ID                    (0x1234)
#define COMM_MODULE_ID                    (0x000B)
#define COMM_AR_RELEASE_MAJOR_VERSION     (4)
#define COMM_AR_RELEASE_MINOR_VERSION     (4)
#define COMM_AR_RELEASE_REVISION_VERSION  (0)
#define COMM_SW_MAJOR_VERSION             (1)
#define COMM_SW_MINOR_VERSION             (0)
#define COMM_SW_PATCH_VERSION             (0)

/* Check AUTOSAR version compatibility */
#if ((STD_AR_RELEASE_MAJOR_VERSION != COMM_AR_RELEASE_MAJOR_VERSION) || \
     (STD_AR_RELEASE_MINOR_VERSION != COMM_AR_RELEASE_MINOR_VERSION))
#error "AUTOSAR version mismatch between ComM.h and Std_Types.h"
#endif

/* API service IDs */
#define COMM_INIT_SID                     (0x00u)
#define COMM_REQUEST_COMM_SID             (0x01u)
#define COMM_RELEASE_COMM_SID             (0x02u)
#define COMM_GET_VERSION_INFO_SID         (0x03u)

/* Function prototypes */

/**
 * @brief   Initialize the Communication Manager module
 */
void ComM_Init(void);

/**
 * @brief   Request communication mode for a channel
 */
Std_ReturnType ComM_RequestComMode(uint8 Channel, uint8 RequestedMode);

/**
 * @brief   Release communication mode for a channel
 */
Std_ReturnType ComM_ReleaseComMode(uint8 Channel);

/**
 * @brief   Get version information
 */
void ComM_GetVersionInfo(Std_VersionInfoType *versioninfo);

#endif /* COMM_H */