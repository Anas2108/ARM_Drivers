/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V02                                                     */
/*Date   : 9/3/2023 m-d-y                                          */
/*******************************************************************/

#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"

#include "../../2-MCAL/TIMER2/TIMER2_interface.h"
#include "../../2-MCAL/02-GPIO/DIO_interface.h"

#include "MOTOR_interface.h"
#include "MOTOR_config.h"
#include "MOTOR_private.h"


void MOTOR_voidInitMotors(u8 Copy_u8Port , u8 Copy_u8LeftTop,u8 Copy_u8LeftBot,u8 Copy_u8RightTop,u8 Copy_u8RightBot)
{
    TIMER2_VoidInitPwm();

    MGPIO_voidSetPinDirection(GPIO_PORTA,PIN0,GPIO_OUTPUT_10MHZ_AFPP);
    MGPIO_voidSetPinDirection(GPIO_PORTA,PIN1,GPIO_OUTPUT_10MHZ_AFPP);

    MGPIO_voidSetPinDirection(Copy_u8Port,Copy_u8LeftTop,GPIO_OUTPUT_10MHZ_PP);
    MGPIO_voidSetPinDirection(Copy_u8Port,Copy_u8LeftBot,GPIO_OUTPUT_10MHZ_PP);
    MGPIO_voidSetPinDirection(Copy_u8Port,Copy_u8RightTop,GPIO_OUTPUT_10MHZ_PP);
    MGPIO_voidSetPinDirection(Copy_u8Port,Copy_u8RightBot,GPIO_OUTPUT_10MHZ_PP);
}


void MOTOR_voidSetMotorSpeed (u8 Copy_u8MotorSpeed, u8 Copy_u8MotorID)
{
    if (Copy_u8MotorID == MOTOR1)
    TIMER2_VoidSetDutyCycleCh1(Copy_u8MotorSpeed);

    else if (Copy_u8MotorID == MOTOR2)
    TIMER2_VoidSetDutyCycleCh2(Copy_u8MotorSpeed);

    else
    {
        /*RETURN ERROR*/
    }
    
}

void MOTOR_voidMoveForward (u8 Copy_u8Port , u8 Copy_u8LeftTop,u8 Copy_u8LeftBot,u8 Copy_u8RightTop,u8 Copy_u8RightBot)
{
    /*it gonna be tested soon*/

    /*Forward*/
    MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8LeftTop, GPIO_HIGH);
    MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8LeftBot, GPIO_LOW);

    /*Forward*/
    MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8RightTop, GPIO_HIGH);
    MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8RightBot, GPIO_LOW);
    
}

void MOTOR_voidMoveBackward (u8 Copy_u8Port , u8 Copy_u8LeftTop,u8 Copy_u8LeftBot,u8 Copy_u8RightTop,u8 Copy_u8RightBot)
{
    /*it gonna be tested soon*/

    /*Backward*/
    MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8LeftTop, GPIO_LOW);
    MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8LeftBot, GPIO_HIGH);

    /*Backward*/
    MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8RightTop, GPIO_LOW);
    MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8RightBot, GPIO_HIGH);
}


void MOTOR_voidMoveLeft (u8 Copy_u8Port , u8 Copy_u8LeftTop,u8 Copy_u8LeftBot,u8 Copy_u8RightTop,u8 Copy_u8RightBot)
{


  /*it gonna be tested soon*/

    /*Backward*/
    MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8LeftTop, GPIO_LOW);
    MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8LeftBot, GPIO_HIGH);

    /*Forward*/
    MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8RightTop, GPIO_HIGH);
    MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8RightBot, GPIO_LOW);
}


void MOTOR_voidMoveRight (u8 Copy_u8Port , u8 Copy_u8LeftTop,u8 Copy_u8LeftBot,u8 Copy_u8RightTop,u8 Copy_u8RightBot)
{

    /*it gonna be tested soon*/

    /*Forward*/
    MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8LeftTop, GPIO_HIGH);
    MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8LeftBot, GPIO_LOW);

    /*Backward*/
    MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8RightTop, GPIO_LOW);
    MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8RightBot, GPIO_HIGH);

}


void MOTOR_voidStop (u8 Copy_u8Port , u8 Copy_u8LeftTop,u8 Copy_u8LeftBot,u8 Copy_u8RightTop,u8 Copy_u8RightBot)
{
        MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8LeftTop, GPIO_LOW);
        MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8LeftBot, GPIO_LOW);
        MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8RightTop, GPIO_LOW);
        MGPIO_voidSetPinValue(Copy_u8Port, Copy_u8RightBot, GPIO_LOW);

}
