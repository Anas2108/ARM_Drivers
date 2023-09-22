/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/31/2023 m-d-y                                         */
/*******************************************************************/

#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_

#define TIMER_BASE_ADDRESS                        0x40000000

#define TIMER_CR1                           *((u32*)(TIMER_BASE_ADDRESS +0x00))
#define TIMER_CCMR1                         *((u32*)(TIMER_BASE_ADDRESS +0x18))
#define TIMER_CCMR2                         *((u32*)(TIMER_BASE_ADDRESS +0x1C))
#define TIMER_CCER                          *((u32*)(TIMER_BASE_ADDRESS +0x20))
#define TIMER_CCR1                          *((u32*)(TIMER_BASE_ADDRESS +0x34))
#define TIMER_CCR2                          *((u32*)(TIMER_BASE_ADDRESS +0x38))
#define TIMER_CCR3                          *((u32*)(TIMER_BASE_ADDRESS +0x3C))
#define TIMER_ARR                           *((u32*)(TIMER_BASE_ADDRESS +0x2C))




#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
