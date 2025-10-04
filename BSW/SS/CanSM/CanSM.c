/*
 * CanSM.c - AUTOSAR CAN State Manager Implementation
 *
 * Created on: 2023-xx-xx
 * Author: BSW Team
 *
 * Description: This file contains the implementation of
 *              CAN-FD communication for motor control
 */

#include "CanSM.h"
#include "Det.h"
#include "ComM.h"

/* Internal variables */
static CanSM_StateType CanSM_CurrentState = CANSM_UNINIT;

/* CAN-FD Hardware Abstraction */
extern void CanFdHw_Init(void);
extern void CanFdHw_SetBaudrate(uint32 baudrate);
extern Std_ReturnType CanFdHw_Transmit(const CanSM_FdFrameType *frame);
extern Std_ReturnType CanFdHw_Receive(CanSM_FdFrameType *frame);

/**
 * @brief Initialize CAN State Manager
 */
void CanSM_Init(void)
{
    if (CanSM_CurrentState == CANSM_UNINIT)
    {
        /* Initialize CAN-FD hardware */
        CanFdHw_Init();
        CanFdHw_SetBaudrate(2000000); /* 2Mbps data rate */
        
        CanSM_CurrentState = CANSM_INIT;
        ComM_RequestComMode(COMM_FULL_COMMUNICATION);
    }
}

/**
 * @brief Set CAN State Manager state
 * @param state Target state
 */
void CanSM_SetState(CanSM_StateType state)
{
    if (CanSM_CurrentState != CANSM_UNINIT)
    {
        CanSM_CurrentState = state;
    }
}

/**
 * @brief Transmit CAN-FD frame
 * @param frame Pointer to frame data
 * @return Transmission status
 */
Std_ReturnType CanSM_TransmitFdFrame(const CanSM_FdFrameType *frame)
{
    if (CanSM_CurrentState >= CANSM_READY && frame != NULL_PTR)
    {
        return CanFdHw_Transmit(frame);
    }
    return E_NOT_OK;
}

/**
 * @brief Receive CAN-FD frame
 * @param frame Pointer to store received data
 * @return Reception status
 */
Std_ReturnType CanSM_ReceiveFdFrame(CanSM_FdFrameType *frame)
{
    if (CanSM_CurrentState >= CANSM_READY && frame != NULL_PTR)
    {
        return CanFdHw_Receive(frame);
    }
    return E_NOT_OK;
}

/* Motor Control Specific Functions */
void CanSM_SendMotorCmd(uint16 speed, int16 torque, uint8 mode)
{
    CanSM_FdFrameType frame;
    frame.id = 0x100; /* MOTOR_CMD ID */
    frame.length = 8;
    frame.brs = TRUE;
    
    /* Pack data according to DBC format */
    frame.data[0] = (uint8)(speed & 0xFF);
    frame.data[1] = (uint8)(speed >> 8);
    frame.data[2] = (uint8)(torque & 0xFF);
    frame.data[3] = (uint8)(torque >> 8);
    frame.data[4] = mode;
    
    (void)CanSM_TransmitFdFrame(&frame);
}

void CanSM_GetMotorStatus(uint16 *speed, int16 *torque, uint8 *fault)
{
    CanSM_FdFrameType frame;
    
    if (CanSM_ReceiveFdFrame(&frame) == E_OK && frame.id == 0x101)
    {
        /* Unpack data according to DBC format */
        if (speed != NULL_PTR)
            *speed = (uint16)(frame.data[0] | (frame.data[1] << 8));
        if (torque != NULL_PTR)
            *torque = (int16)(frame.data[2] | (frame.data[3] << 8));
        if (fault != NULL_PTR)
            *fault = frame.data[4];
    }
}