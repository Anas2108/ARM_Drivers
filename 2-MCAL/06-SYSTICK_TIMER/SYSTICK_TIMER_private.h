/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V02                                                     */
/*Date   : 8/19/2023 m-d-y                                         */
/*******************************************************************/

#ifndef SYS_PRIVATE_H
#define SYS_PRIVATE_H

#define SYSTICK_BASE_ADDRESS 0xE000E010

/*Register definition*/
#define STK_CTRL   *((volatile u32 *)(SYSTICK_BASE_ADDRESS + 0x00))
#define STK_LOAD   *((volatile u32 *)(SYSTICK_BASE_ADDRESS + 0x04))
#define STK_VAL    *((volatile u32 *)(SYSTICK_BASE_ADDRESS + 0x08))
#define STK_CALIB  *((volatile u32 *)(SYSTICK_BASE_ADDRESS + 0x0C))

/*clock source options*/
#define AHB_DEVIDED_8_CLOCK 0
#define AHB_CLOCK           1

/*Interval Modes */
#define MSTK_SINGLE_INTERVAL_MODE    0
#define MSTK_PERIODIC_INTERVALS_MODE 1

#endif