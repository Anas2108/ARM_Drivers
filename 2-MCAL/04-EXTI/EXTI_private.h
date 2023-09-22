/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/12/2023 m-d-y                                         */
/*******************************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

typedef struct 
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
} EXTI_t;

#define EXTI  ((volatile EXTI_t*)0x40010400)

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


#endif