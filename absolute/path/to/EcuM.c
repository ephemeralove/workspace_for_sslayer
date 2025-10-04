void EcuM_Shutdown(void)
{
    /* 仅关闭PWM输出 */
    PwmIf_SetDutyCycle(0);
    EcuM_CurrentState = ECUM_STATE_SHUTDOWN;
}