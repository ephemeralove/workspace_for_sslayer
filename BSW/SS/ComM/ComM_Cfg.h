/*
 * ComM_Cfg.h - AUTOSAR Communication Manager Configuration
 *
 * Created on: 2023-xx-xx
 * Author: BSW Team
 *
 * Description: This file contains the configuration definitions for the
 *              Communication Manager module for Infineon TC377
 */

#ifndef COMM_CFG_H
#define COMM_CFG_H

/* Include AUTOSAR standard types */
#include "Std_Types.h"

/* Communication modes */
#define COMM_NO_COMMUNICATION        (0x00u)
#define COMM_SILENT_COMMUNICATION    (0x01u)
#define COMM_FULL_COMMUNICATION      (0x02u)

/* Maximum number of communication channels */
#define COMM_MAX_CHANNELS            (4u)

/* Channel identifiers */
#define COMM_CHANNEL_CAN             (0u)
#define COMM_CHANNEL_LIN             (1u)
#define COMM_CHANNEL_FR              (2u)
#define COMM_CHANNEL_ETH             (3u)

/* Configuration structure */
typedef struct {
    uint8 defaultMode;
    uint16 timeoutMs;
    boolean wakeupSupport;
} ComM_ChannelConfigType;

/* Channel configurations */
const ComM_ChannelConfigType ComM_ChannelConfig[COMM_MAX_CHANNELS] = {
    /* CAN channel */
    {COMM_FULL_COMMUNICATION, 1000, TRUE},
    /* LIN channel */
    {COMM_SILENT_COMMUNICATION, 500, FALSE},
    /* FR channel */
    {COMM_NO_COMMUNICATION, 0, FALSE},
    /* ETH channel */
    {COMM_FULL_COMMUNICATION, 2000, TRUE}
};

#endif /* COMM_CFG_H */