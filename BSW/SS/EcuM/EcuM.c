/*
 * EcuM.c - AUTOSAR ECU State Manager Implementation
 *
 * Created on: 2023-xx-xx
 * Author: BSW Team
 *
 * Description: This file contains the implementation of the
 *              ECU State Manager module for Infineon TC377
 */

#include "EcuM.h"
#include "Det.h"

/* Internal variables */
static boolean EcuM_Initialized = FALSE;
static EcuM_StateType EcuM_CurrentState = ECUM_STATE_STARTUP;

/**
 * @brief   Initialize the ECU State Manager module
 */
void EcuM_Init(void)
{
    if (EcuM_Initialized == FALSE)
    {
        /* Initialize internal variables */
        EcuM_CurrentState = ECUM_STATE_STARTUP;
        EcuM_Initialized = TRUE;
    }
    else
    {
        Det_ReportError(ECUM_MODULE_ID, 0, ECUM_INIT_SID, DET_E_ALREADY_INITIALIZED);
    }
}

/**
 * @brief   Start the ECU state machine
 */
void EcuM_Startup(void)
{
    if (EcuM_Initialized)
    {
        /* Initialize MCAL modules */
        Mcu_Init();
        Port_Init();
        Dio_Init();
        
        /* Initialize communication stacks */
        Can_Init();
        
        /* Transition to RUN state */
        EcuM_CurrentState = ECUM_STATE_RUN;
    }
    else
    {
        Det_ReportError(ECUM_MODULE_ID, 0, ECUM_STARTUP_SID, DET_E_NOT_INITIALIZED);
    }
}

/**
 * @brief   Shutdown the ECU
 */
void EcuM_Shutdown(void)
{
    if (EcuM_Initialized)
    {
        /* Transition to SHUTDOWN state */
        EcuM_CurrentState = ECUM_STATE_SHUTDOWN;
        
        /* Perform shutdown sequence */
        /* Stop communication stacks */
        Can_DeInit();
        
        /* Deinitialize MCAL modules */
        Dio_DeInit();
        Port_DeInit();
        Mcu_DeInit();

        /* Shutdown target modes */
void EcuM_SelectShutdownTarget(EcuM_ShutdownTargetType target) {
    /* Validate target mode */
    if(target > ECUM_SHUTDOWN_TARGET_OFF) {
        Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SHUTDOWN_SID, ECUM_E_PARAM_POINTER);
        return;
    }
    
    /* Apply shutdown target */
    switch(target) {
        case ECUM_SHUTDOWN_TARGET_SLEEP:
            /* Prepare for sleep mode */
            PwmIf_Stop(PWM_CHANNEL_1);
            AdcIf_StopConversion(ADC_CHANNEL_1);
            break;
            
        case ECUM_SHUTDOWN_TARGET_RESET:
            /* Prepare for reset */
            PwmIf_DeInit();
            AdcIf_DeInit();
            break;
            
        case ECUM_SHUTDOWN_TARGET_OFF:
            /* Prepare for power off */
            PwmIf_DeInit();
            AdcIf_DeInit();
            break;
    }
}
    }
    else
    {
        Det_ReportError(ECUM_MODULE_ID, 0, ECUM_SHUTDOWN_SID, DET_E_NOT_INITIALIZED);
    }
}

/**
 * @brief   Get current ECU state
 */
EcuM_StateType EcuM_GetState(void)
{
    if (EcuM_Initialized)
    {
        return EcuM_CurrentState;
    }
    else
    {
        Det_ReportError(ECUM_MODULE_ID, 0, ECUM_GETSTATE_SID, DET_E_NOT_INITIALIZED);
        return ECUM_STATE_RESET;
    }
}

/**
 * @brief   Get version information
 */
void EcuM_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    if (versioninfo != NULL_PTR)
    {
        versioninfo->vendorID = ECUM_VENDOR_ID;
        versioninfo->moduleID = ECUM_MODULE_ID;
        versioninfo->sw_major_version = ECUM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = ECUM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = ECUM_SW_PATCH_VERSION;
    }
    else
    {
        Det_ReportError(ECUM_MODULE_ID, 0, ECUM_GET_VERSION_INFO_SID, DET_E_PARAM_POINTER);
    }
}