#include "RealTimeFramework.h"
#include "PwmIf.h"
#include "AdcIf.h"

/* 电机控制状态定义 */
#define MOTOR_STOPPED 0
#define MOTOR_RUNNING 1
#define MOTOR_FAULT   2

/* 事件定义 */
#define EVENT_START    0x01
#define EVENT_STOP     0x02
#define EVENT_OVERCURRENT 0x03

FSM motor_fsm;

/* 状态处理函数 */
static void HandleStart(void* data);
static void HandleStop(void* data);
static void HandleFault(void* data);

EventTable motor_transitions[] = {
    {EVENT_START, HandleStart},
    {EVENT_STOP, HandleStop},
    {EVENT_OVERCURRENT, HandleFault}
};

void MotorControl_Init(void) {
    motor_fsm.current_state = MOTOR_STOPPED;
    motor_fsm.transition_table = motor_transitions;
    motor_fsm.transition_table_size = sizeof(motor_transitions)/sizeof(EventTable);
    
    RTF_AddFSM(&motor_fsm);
}

/* 中断服务程序示例 */
void Adc_Isr(void) {
    uint16 current = AdcIf_GetChannelValue(ADC_CHANNEL_MOTOR_CURRENT);
    if(current > OVERCURRENT_THRESHOLD) {
        RTF_ProcessEvent(EVENT_OVERCURRENT, NULL);
    }
}