/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/12/2023 m-d-y                                         */
/*******************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* EXTI Lines */
#define EXTI_LINE0  0
#define EXTI_LINE1  1
#define EXTI_LINE2  2
#define EXTI_LINE3  3
#define EXTI_LINE4  4
#define EXTI_LINE5  5
#define EXTI_LINE6  6
#define EXTI_LINE7  7
#define EXTI_LINE8  8
#define EXTI_LINE9  9
#define EXTI_LINE10 10
#define EXTI_LINE11 11
#define EXTI_LINE12 12
#define EXTI_LINE13 13
#define EXTI_LINE14 14
#define EXTI_LINE15 15

/*EXTI Modes*/
#define EXTI_RISING_TRIGGER_MODE    0
#define EXTI_FALLING_TRIGGER_MODE   1
#define EXTI_ON_CHANGE_MODE         2


void MEXTI_voidInit();
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);
void MEXTI_voidSwTrigger(u8 Copy_u8Line);
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode);

#endif