/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/26/2023 m-d-y                                         */
/*******************************************************************/

#include "../1-LIB/STD_TYPES.h"
#include "../1-LIB/BIT_MATH.h"

#include "../2-MCAL/06-SYSTICK_TIMER/SYSTICK_TIMER_interface.h"

#include "RTOS_interface.h"
#include "RTOS_config.h"
#include "RTOS_private.h"

void SRTOS_voidCreatTask(u8 Copy_u8TaskPeriority, u16 Copy_u16TaskPeriodicity, void(*taskFunc)(void), u16 Copy_u8TaskIntiallDelay, u8 Copy_u8TaskState)
{
    /*set the task periodicity*/
    RTOS_tasks[Copy_u8TaskPeriority].periodicity = Copy_u16TaskPeriodicity;
    /*set the function of the task*/
    RTOS_tasks[Copy_u8TaskPeriority].funcPtr = taskFunc;
    /*set intial delay*/
    RTOS_tasks[Copy_u8TaskPeriority].firstDelay = Copy_u8TaskIntiallDelay;
    /*set the state of task*/
    RTOS_tasks[Copy_u8TaskPeriority].state = Copy_u8TaskState;
}

void SRTOS_voidStartOS(void)
{
    /*set the clock to AHB/8 */
    MSTK_voidInit();

    /* call the schuduler every 1ms*/
    MSTK_voidSetIntervalPeriodic(1000, SCHEDULER);

}

void SRTOS_voidResumeTask(u8 Copy_u8TaskPeriority)
{
    RTOS_tasks[Copy_u8TaskPeriority].state = TASK_READY;
}
void SRTOS_voidSuspendTask(u8 Copy_u8TaskPeriority)
{
    RTOS_tasks[Copy_u8TaskPeriority].state = TASK_SUSBENDED;
}

void SRTOS_voidDeleteTask(u8 Copy_u8TaskPeriority)
{
    RTOS_tasks[Copy_u8TaskPeriority].state = TASK_DELETE;
}
