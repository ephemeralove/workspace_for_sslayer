/*
 * Std_Types.h - AUTOSAR Basic Software Standard Types
 *
 *  Created on: 2023-xx-xx
 *      Author: BSW Team
 *
 *  Description: This file contains the AUTOSAR standard types definitions
 *               for Infineon TC377 platform
 */

#ifndef STD_TYPES_H
#define STD_TYPES_H

/* AUTOSAR Version information */
#define STD_VENDOR_ID                   (0x1234)        /* Vendor ID */
#define STD_MODULE_ID                   (0x0000)        /* Module ID */
#define STD_AR_RELEASE_MAJOR_VERSION    (4)             /* AUTOSAR Release Major Version */
#define STD_AR_RELEASE_MINOR_VERSION    (4)             /* AUTOSAR Release Minor Version */
#define STD_AR_RELEASE_REVISION_VERSION (0)             /* AUTOSAR Release Revision Version */
#define STD_SW_MAJOR_VERSION            (1)             /* Software Major Version */
#define STD_SW_MINOR_VERSION            (0)             /* Software Minor Version */
#define STD_SW_PATCH_VERSION            (0)             /* Software Patch Version */

/* Platform Types */
#include <Platform_Types.h>

/* Define NULL pointer */
#ifndef NULL_PTR
#define NULL_PTR        ((void *)0)
#endif

/* Boolean Data Type */
#ifndef FALSE
#define FALSE           (0u)
#endif

#ifndef TRUE
#define TRUE            (1u)
#endif

typedef uint8_least boolean;

/* Standard Return Type */
typedef uint8 Std_ReturnType;
#define E_OK            ((Std_ReturnType)0x00u)
#define E_NOT_OK        ((Std_ReturnType)0x01u)

/* AUTOSAR Error Codes */
#define STD_HIGH        0x01u    /* Physical state 5V or 3.3V */
#define STD_LOW         0x00u    /* Physical state 0V */

#define STD_ACTIVE      0x01u    /* Logical state active */
#define STD_IDLE        0x00u    /* Logical state idle */

#define STD_ON          0x01u    /* Standard ON */
#define STD_OFF         0x00u    /* Standard OFF */

/* Version Info Structure */
typedef struct {
    uint16  vendorID;
    uint16  moduleID;
    uint8   sw_major_version;
    uint8   sw_minor_version;
    uint8   sw_patch_version;
} Std_VersionInfoType;

#endif /* STD_TYPES_H */