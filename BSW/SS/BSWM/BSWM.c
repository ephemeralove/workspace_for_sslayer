/*
 * BSWM.c - AUTOSAR Basic Software Mode Manager Implementation
 *
 * Created on: 2023-xx-xx
 * Author: BSW Team
 */

#include "BSWM.h"
#include "Det.h"
#include "ComM.h"
#include "CanSM.h"

/* Internal variables */
static uint8 BSWM_CurrentMode = BSWM_MODE_NORMAL;

void BSWM_Init(void)
{
    BSWM_CurrentMode = BSWM_MODE_NORMAL;
}

void BSWM_RequestMode(uint8 source, uint8 mode)
{
    /* Validate parameters */
    if(source > BSWM_REQUEST_SOURCE_DIAG || mode > BSWM_MODE_DIAG) {
        Det_ReportError(BSWM_MODULE_ID, 0, BSWM_REQUEST_MODE_SID, DET_E_PARAM);
        return;
    }
    
    /* Process mode request */
    switch(mode) {
        case BSWM_MODE_NORMAL:
            CanSM_RequestComMode(COMM_FULL_COMMUNICATION);
            break;
            
        case BSWM_MODE_SILENT:
            CanSM_RequestComMode(COMM_SILENT_COMMUNICATION);
            break;
            
        case BSWM_MODE_DIAG:
            CanSM_RequestComMode(COMM_FULL_COMMUNICATION);
            break;
    }
    
    BSWM_CurrentMode = mode;
}

uint8 BSWM_GetCurrentMode(void)
{
    return BSWM_CurrentMode;
}