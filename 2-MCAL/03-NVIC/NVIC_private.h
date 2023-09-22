/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/9/2023 m-d-y                                          */
/*******************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/*NVIC base address*/
#define NVIC_BASE_ADDRESS   0xE000E100

/*Registers difinition*/
#define NVIC_ISER0          *((u32 *)(NVIC_BASE_ADDRESS + 0x000))
#define NVIC_ISER1          *((u32 *)(NVIC_BASE_ADDRESS + 0x004))

#define NVIC_ICER0          *((u32 *)(NVIC_BASE_ADDRESS + 0x080))
#define NVIC_ICER1          *((u32 *)(NVIC_BASE_ADDRESS + 0x084))

#define NVIC_ISPR0          *((u32 *)(NVIC_BASE_ADDRESS + 0x100))
#define NVIC_ISPR1          *((u32 *)(NVIC_BASE_ADDRESS + 0x104))

#define NVIC_ICPR0          *((u32 *)(NVIC_BASE_ADDRESS + 0x180))
#define NVIC_ICPR1          *((u32 *)(NVIC_BASE_ADDRESS + 0x184))

#define NVIC_IABR0          *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x200))
#define NVIC_IABR1          *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x204))

#define NVIC_IPR             ((volatile u8  *)(NVIC_BASE_ADDRESS + 0x300))   

#define SCB_AIRCR           *((volatile u32 *)(0xE000ED00 + 0x0C))






#endif