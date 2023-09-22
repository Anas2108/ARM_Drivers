/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/31/2023 m-d-y                                         */
/*******************************************************************/

#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"

#include "TIMER2_interface.h"
#include "TIMER2_config.h"
#include "TIMER2_private.h"


void TIMER2_VoidInitPwm()
{   
     /*Disable clock*/
    CLR_BIT(TIMER_CR1,0);

    /*Auto-reload preload enable*/
	SET_BIT(TIMER_CR1,7);

    /*to enable PWM mode and Preload register on TIMx_CCR1 and TIMx_CCR2 enabled */
    TIMER_CCMR1 = 0x6868 ;

    /* OC1 signal is output on the corresponding output pin.*/
	SET_BIT(TIMER_CCER,0); //ch1
    SET_BIT(TIMER_CCER,4); //ch2
    SET_BIT(TIMER_CCER,8); //ch3

    /*Set timer period*/
	TIMER_ARR = 1000;

    /*Enable clock*/
    SET_BIT(TIMER_CR1,0);


}

void TIMER2_VoidSetDutyCycleCh1(u32 Copy_U32_DutyCycle)
{
	TIMER_CCR1 = Copy_U32_DutyCycle;
}

void TIMER2_VoidSetDutyCycleCh2(u32 Copy_U32_DutyCycle)
{
	TIMER_CCR2 = Copy_U32_DutyCycle;
}

void TIMER2_VoidSetDutyCycleCh3(u32 Copy_U32_DutyCycle)
{
	TIMER_CCR3 = Copy_U32_DutyCycle;
}




