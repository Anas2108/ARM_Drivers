/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V02                                                     */
/*Date   : 9/3/2023 m-d-y                                          */
/*******************************************************************/


#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

#define MOTOR1 0
#define MOTOR2 1

void MOTOR_voidInitMotors(u8 Copy_u8Port , u8 Copy_u8LeftTop,u8 Copy_u8LeftBot,u8 Copy_u8RightTop,u8 Copy_u8RightBot);
void MOTOR_voidSetMotorSpeed (u8 Copy_u8MotorSpeed, u8 Copy_u8MotorID);
void MOTOR_voidMoveForward (u8 Copy_u8Port , u8 Copy_u8LeftTop,u8 Copy_u8LeftBot,u8 Copy_u8RightTop,u8 Copy_u8RightBot);
void MOTOR_voidMoveBackward (u8 Copy_u8Port , u8 Copy_u8LeftTop,u8 Copy_u8LeftBot,u8 Copy_u8RightTop,u8 Copy_u8RightBot);
void MOTOR_voidMoveLeft (u8 Copy_u8Port , u8 Copy_u8LeftTop,u8 Copy_u8LeftBot,u8 Copy_u8RightTop,u8 Copy_u8RightBot);
void MOTOR_voidMoveRight (u8 Copy_u8Port , u8 Copy_u8LeftTop,u8 Copy_u8LeftBot,u8 Copy_u8RightTop,u8 Copy_u8RightBot);
void MOTOR_voidStop (u8 Copy_u8Port , u8 Copy_u8LeftTop,u8 Copy_u8LeftBot,u8 Copy_u8RightTop,u8 Copy_u8RightBot);

#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
