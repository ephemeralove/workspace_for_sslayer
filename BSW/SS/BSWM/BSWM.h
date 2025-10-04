/*
 * BSWM.h - AUTOSAR Basic Software Mode Manager
 *
 * Created on: 2023-xx-xx
 * Author: BSW Team
 */

#ifndef BSWM_H
#define BSWM_H

#include "Std_Types.h"

/* Mode request sources */
#define BSWM_REQUEST_SOURCE_COMM  0x01u
#define BSWM_REQUEST_SOURCE_DIAG  0x02u

/* Mode types */
#define BSWM_MODE_NORMAL         0x00u
#define BSWM_MODE_SILENT         0x01u
#define BSWM_MODE_DIAG           0x02u

/* API function prototypes */
void BSWM_Init(void);
void BSWM_RequestMode(uint8 source, uint8 mode);
uint8 BSWM_GetCurrentMode(void);

#endif /* BSWM_H */