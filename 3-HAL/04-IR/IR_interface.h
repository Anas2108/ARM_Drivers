/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/26/2023 m-d-y                                         */
/*******************************************************************/
#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H

#define IR_ACTIVE_HIGH_H     1
#define IR_ACTIVE_HIGH_L     0

#define IR_ACTIVE_LOW_H      0
#define IR_ACTIVE_LOW_L      1

void IR_voidInit(u8 Copy_u8Port , u8 Copy_u8Pin);
u8 IR_u8getIRvalue();


#endif