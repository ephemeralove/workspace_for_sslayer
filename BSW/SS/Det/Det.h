/*
 * Det.h - AUTOSAR Development Error Tracer Interface
 *
 *  Created on: 2023-xx-xx
 *      Author: BSW Team
 *
 *  Description: This file contains the interface definition for the
 *               Development Error Tracer module for Infineon TC377
 */

#ifndef DET_H
#define DET_H

/* Include AUTOSAR standard types */
#include "Std_Types.h"

/* AUTOSAR Version information */
#define DET_VENDOR_ID                    (0x1234)
#define DET_MODULE_ID                    (0x000A)
#define DET_AR_RELEASE_MAJOR_VERSION     (4)
#define DET_AR_RELEASE_MINOR_VERSION     (4)
#define DET_AR_RELEASE_REVISION_VERSION  (0)
#define DET_SW_MAJOR_VERSION             (1)
#define DET_SW_MINOR_VERSION             (0)
#define DET_SW_PATCH_VERSION             (0)

/* Check AUTOSAR version compatibility */
#if ((STD_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
     (STD_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
#error "AUTOSAR version mismatch between Det.h and Std_Types.h"
#endif

/* API service IDs */
#define DET_INIT_SID                     (0x00u)
#define DET_REPORT_ERROR_SID             (0x01u)
#define DET_GET_VERSION_INFO_SID         (0x02u)
#define DET_REPORT_RUNTIME_ERROR_SID     (0x03u)

/* Error codes */
#define DET_E_PARAM_POINTER              (0x01u)
#define DET_E_INIT_FAILED                (0x02u)
#define DET_E_ALREADY_INITIALIZED        (0x03u)

/* Function prototypes */

/**
 * @brief   Initialize the Development and Error Tracer module
 * @details This function initializes the DET module. It should be called
 *          during startup.
 * @param   None
 * @return  None
 */
void Det_Init(void);

/**
 * @brief   Report a development error
 * @details This function reports an error detected by a module to the DET.
 * @param   ModuleId    Id of the reporting module
 * @param   InstanceId  Index of the module instance
 * @param   ApiId       Id of the API service in which the error is detected
 * @param   ErrorId     Id of the detected error
 * @return  None
 */
void Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

/**
 * @brief   Report a runtime error
 * @details This function reports a runtime error detected by a module to the DET.
 * @param   ModuleId    Id of the reporting module
 * @param   InstanceId  Index of the module instance
 * @param   ApiId       Id of the API service in which the error is detected
 * @param   ErrorId     Id of the detected error
 * @return  None
 */
void Det_ReportRuntimeError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

/**
 * @brief   Get version information of the DET module
 * @details This function returns the version information of the DET module.
 * @param   versioninfo Pointer to where to store the version information
 * @return  None
 */
void Det_GetVersionInfo(Std_VersionInfoType *versioninfo);

/* DET is initialized by default to allow early error reporting */
#define DET_AR_RELEASE_VERSION           (DET_AR_RELEASE_MAJOR_VERSION << 16u | \
                                          DET_AR_RELEASE_MINOR_VERSION << 8u | \
                                          DET_AR_RELEASE_REVISION_VERSION)

#endif /* DET_H */