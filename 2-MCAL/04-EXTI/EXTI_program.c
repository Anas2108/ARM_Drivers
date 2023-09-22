/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/12/2023 m-d-y                                         */
/*******************************************************************/

#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

/*Set the Line and the mode before Run time*/
void MEXTI_voidInit()
{
    #if     EXTI_MODE == EXTI_RISING_TRIGGER_MODE
        SET_BIT(EXTI ->RTSR ,EXTI_LINE);

    #elif   EXTI_MODE == EXTI_FALLING_TRIGGER_MODE
        SET_BIT (EXTI->FTSR,EXTI_LINE); 

    #elif   EXTI_MODE == EXTI_FALLING_TRIGGER_MODE
        SET_BIT (EXTI->FTSR,EXTI_LINE); 
        SET_BIT(EXTI ->RTSR ,EXTI_LINE); 
    #elif
         /**< RETURN ERROR STATUS */     
    #endif

    /*Disable interrupt*/
	CLR_BIT(EXTI->IMR , EXTI_LINE);
}


void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
    SET_BIT (EXTI->IMR,Copy_u8Line);
}

void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
    CLR_BIT (EXTI->IMR,Copy_u8Line);
}

void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
    SET_BIT (EXTI->SWIER,Copy_u8Line);
}

void MEXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode)
{
    switch (Copy_u8Mode)
    {
    case EXTI_RISING_TRIGGER_MODE:
        SET_BIT(EXTI ->RTSR ,EXTI_LINE);break;

    case EXTI_FALLING_TRIGGER_MODE:
        SET_BIT (EXTI->FTSR,EXTI_LINE);break;

    case EXTI_ON_CHANGE_MODE :
         SET_BIT(EXTI ->RTSR ,EXTI_LINE);
         SET_BIT (EXTI->FTSR,EXTI_LINE);break;

    default: /**< RETURN ERROR STATUS */break;
    }
}