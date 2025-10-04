/*
 * main.c - AUTOSAR Application Main Entry Point
 * 
 * Created on: 2023-xx-xx
 * Author: BSW Team
 *
 * Description: Main application entry point for Infineon TC377
 */

#include "Std_Types.h"
#include "Det.h"
#include "EcuM.h"
#include "ComM.h"

/**
 * @brief   Main function - AUTOSAR application entry point
 */
int main(void)
{
    /* 1. Initialize DET module for error reporting */
    Det_Init();
    
    /* 2. Initialize ECU State Manager */
    EcuM_Init();
    
    /* 3. Initialize Communication Manager */
    ComM_Init();
    
    /* 4. Start the ECU */
    EcuM_Startup();
    
    /* 5. Main application loop */
    while(1)
    {
        /* Placeholder for periodic tasks */
        /* - Watchdog refresh */
        /* - Communication handling */
        /* - Application logic */
    }
    
    return 0;
}