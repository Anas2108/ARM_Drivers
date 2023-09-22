/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/26/2023 m-d-y                                         */
/*******************************************************************/

#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H

#define TASK_READY 0
#define TASK_SUSBENDED 1
#define TASK_DELETE 2


void SRTOS_voidCreatTask(u8 Copy_u8TaskPeriority, u16 Copy_u16TaskPeriodicity, void(*taskFunc)(void),u16 Copy_u8TaskIntiallDelay,u8 Copy_u8TaskState);
void SRTOS_voidStartOS(void);
void SRTOS_voidResumeTask(u8 Copy_u8TaskPeriority);
void SRTOS_voidSuspendTask(u8 Copy_u8TaskPeriority);
void SRTOS_voidDeleteTask(u8 Copy_u8TaskPeriority);
#endif