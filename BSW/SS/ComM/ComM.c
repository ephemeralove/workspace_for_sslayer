/*
 * ComM.c - AUTOSAR Communication Manager Implementation
 *
 * Created on: 2023-xx-xx
 * Author: BSW Team
 *
 * Description: This file contains the implementation of the
 *              Communication Manager module for Infineon TC377
 */

#include "ComM.h"
#include "Det.h"

/* Internal variables */
static boolean ComM_Initialized = FALSE;

/* Communication channel states */
typedef struct {
    uint8 currentMode;
    uint8 requestedMode;
    boolean isActive;
} ComM_ChannelType;

static ComM_ChannelType ComM_Channels[COMM_MAX_CHANNELS];

/**
 * @brief   Initialize the Communication Manager module
 */
void ComM_Init(void)
{
    if (ComM_Initialized == FALSE)
    {
        /* Initialize all channels to NO_COMMUNICATION state */
        for (uint8 i = 0; i < COMM_MAX_CHANNELS; i++)
        {
            ComM_Channels[i].currentMode = COMM_NO_COMMUNICATION;
            ComM_Channels[i].requestedMode = COMM_NO_COMMUNICATION;
            ComM_Channels[i].isActive = FALSE;
        }
        
        ComM_Initialized = TRUE;
    }
    else
    {
        Det_ReportError(COMM_MODULE_ID, 0, COMM_INIT_SID, DET_E_ALREADY_INITIALIZED);
    }
}

/**
 * @brief   Request communication mode for a channel
 */
Std_ReturnType ComM_RequestComMode(uint8 Channel, uint8 RequestedMode)
{
    Std_ReturnType retVal = E_NOT_OK;
    
    if (Channel < COMM_MAX_CHANNELS)
    {
        if (RequestedMode <= COMM_FULL_COMMUNICATION)
        {
            ComM_Channels[Channel].requestedMode = RequestedMode;
            retVal = E_OK;
        }
        else
        {
            Det_ReportError(COMM_MODULE_ID, 0, COMM_REQUEST_COMM_SID, DET_E_PARAM_INVALID);
        }
    }
    else
    {
        Det_ReportError(COMM_MODULE_ID, 0, COMM_REQUEST_COMM_SID, DET_E_PARAM_INVALID);
    }
    
    return retVal;
}

/**
 * @brief   Release communication mode for a channel
 */
Std_ReturnType ComM_ReleaseComMode(uint8 Channel)
{
    Std_ReturnType retVal = E_NOT_OK;
    
    if (Channel < COMM_MAX_CHANNELS)
    {
        ComM_Channels[Channel].requestedMode = COMM_NO_COMMUNICATION;
        retVal = E_OK;
    }
    else
    {
        Det_ReportError(COMM_MODULE_ID, 0, COMM_RELEASE_COMM_SID, DET_E_PARAM_INVALID);
    }
    
    return retVal;
}

/**
 * @brief   Get version information
 */
void ComM_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    if (versioninfo != NULL_PTR)
    {
        versioninfo->vendorID = COMM_VENDOR_ID;
        versioninfo->moduleID = COMM_MODULE_ID;
        versioninfo->sw_major_version = COMM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = COMM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = COMM_SW_PATCH_VERSION;
    }
    else
    {
        Det_ReportError(COMM_MODULE_ID, 0, COMM_GET_VERSION_INFO_SID, DET_E_PARAM_POINTER);
    }
}