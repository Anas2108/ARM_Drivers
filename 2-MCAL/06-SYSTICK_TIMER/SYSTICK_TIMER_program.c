/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/19/2023 m-d-y                                         */
/*******************************************************************/

#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"

#include "SYSTICK_TIMER_interface.h"
#include "SYSTICK_TIMER_private.h"
#include "SYSTICK_TIMER_config.h"

/* Define Callback Global Variable */
static void(*MSTK_CallBack)(void);

/* Define Variable for interval mode */
static u8 MSTK_u8ModeOfInterval;

void MSTK_voidInit(void)
{
    CLR_BIT(STK_CTRL, 0); //disable systick timer

    #if SYSTICK_CLOCK == AHB_DEVIDED_8_CLOCK
         CLR_BIT(STK_CTRL, 2);

    #elif SYSTICK_CLOCK == AHB_CLOCK
         SET_BIT(STK_CTRL, 2);

    #else
    /*<RETURN ERROR>*/     
    #endif
}

void MSTK_voidSetBusyWait( u32 Copy_u32Ticks )
{
    STK_LOAD = Copy_u32Ticks;

    CLR_BIT(STK_CTRL, 1); //disable interrupt
    SET_BIT(STK_CTRL, 0); //Enable systick timer

    while (GET_BIT(STK_CTRL, 16) == 0);

    CLR_BIT(STK_CTRL, 0); //disable systick timer

    // CLR_REG(STK_LOAD);
    // CLR_REG(STK_VAL);

}


void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
    STK_LOAD = Copy_u32Ticks;

    MSTK_CallBack = Copy_ptr;

    MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL_MODE;

    SET_BIT(STK_CTRL, 1); //Enable interrupt
    SET_BIT(STK_CTRL, 0); //Enable systick timer
}


void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
    STK_LOAD = Copy_u32Ticks;

    MSTK_CallBack = Copy_ptr;

    MSTK_u8ModeOfInterval = MSTK_PERIODIC_INTERVALS_MODE;

    SET_BIT(STK_CTRL, 1); //Enable interrupt
    SET_BIT(STK_CTRL, 0); //Enable systick timer
}


void MSTK_voidStopInterval(void)
{
    CLR_BIT(STK_CTRL, 1); //Enable interrupt
    CLR_BIT(STK_CTRL, 0); //Enable systick timer
}

u32  MSTK_u32GetElapsedTime(void)
{
    u32 LOC_u32ElapsedTime = STK_LOAD - STK_VAL;

    return LOC_u32ElapsedTime;
}

u32  MSTK_u32GetRemainingTime(void)
{
    u32 LOC_u32RemainingTime =  STK_VAL;

    return LOC_u32RemainingTime;
}

void SysTick_Handler(void)
{
    u8 Local_u8Temporary;

    if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL_MODE)
    {
        CLR_BIT(STK_CTRL, 1); //Disable interrupt
        CLR_BIT(STK_CTRL, 0); //Disable systick timer
    }

    MSTK_CallBack ();

    	
	Local_u8Temporary = GET_BIT(STK_CTRL,16); // Clear interrupt flag 
}