/*
 * CanSM.h - AUTOSAR CAN State Manager Header
 *
 * Created on: 2023-xx-xx
 * Author: BSW Team
 *
 * Description: This file contains the interface definitions
 *              for CAN-FD communication module
 */

#ifndef CANSM_H
#define CANSM_H

#include "Std_Types.h"

/* CAN State Manager States */
typedef enum {
    CANSM_UNINIT,
    CANSM_INIT,
    CANSM_READY,
    CANSM_SILENT,
    CANSM_FULL_COMMUNICATION
} CanSM_StateType;

/* CAN-FD Message Structure */
typedef struct {
    uint32 id;
    uint8 length;
    uint8 data[64];
    boolean brs; /* Bit Rate Switch */
} CanSM_FdFrameType;

/* Function Prototypes */
void CanSM_Init(void);
void CanSM_SetState(CanSM_StateType state);
Std_ReturnType CanSM_TransmitFdFrame(const CanSM_FdFrameType *frame);
Std_ReturnType CanSM_ReceiveFdFrame(CanSM_FdFrameType *frame);

/* Motor Control Specific Messages */
void CanSM_SendMotorCmd(uint16 speed, int16 torque, uint8 mode);
void CanSM_GetMotorStatus(uint16 *speed, int16 *torque, uint8 *fault);

#endif /* CANSM_H */