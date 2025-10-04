while(1)
{
    /* 1. 读取ADC反馈 */
    AdcIf_StartConversion(ADCIF_CHANNEL_0);
    
    /* 2. 执行控制算法 */
    float duty = ControlAlgorithm(adcValue);
    
    /* 3. 更新PWM输出 */
    PwmIf_SetDutyCycle(duty);
    
    /* 4. 延时 */
    Delay(10); // 10ms控制周期
}