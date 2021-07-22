#include "time_base.h"

 Void TIME_NVIC_Configuration(void)//If the system generates multiple interrupts, then there is a priority for the interrupt response
{
    NVIC_InitTypeDef NVIC_InitStructure;
         NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //Set priority grouping
         NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn; //Specify the IRQ channel
         NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //Specify preemption priority
         NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3; //From priority
         NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //Is the defined IRQ enabled or disabled?
    NVIC_Init(&NVIC_InitStructure);  
}
 
 Void TIME_Configuration(void)//Configure TIM6
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE); 
         TIM_TimeBaseStructure.TIM_Period = 5000; //Set the value of the auto-reload register cycle for the next update event load activity. The range is 0x0000-0xFFFF
         TIM_TimeBaseStructure.TIM_Prescaler = (7200-1); //Set the prescaler value used as the TIMx clock frequency divisor
    TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure); 
         TIM_ITConfig(TIM6, TIM_IT_Update|TIM_IT_Trigger, ENABLE); / / enable or disable TIM interrupt, see Figure 1 in the appendix
    TIM_Cmd(TIM6, ENABLE);  
}
