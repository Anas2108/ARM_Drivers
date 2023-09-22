/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/3/2023                                               */
/*******************************************************************/

#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"

#include "../../2-MCAL/02-GPIO/DIO_interface.h"

#include "LED_interface.h"

void LED_voidSetLedDir(Led_str *Add_ledStrPointer)
{
    MGPIO_voidSetPinDirection(Add_ledStrPointer->portId,Add_ledStrPointer->pinId,GPIO_OUTPUT_10MHZ_PP);
}

void LED_voidTurnOn(Led_str * Add_ledStrPointer)
{
    if (Add_ledStrPointer->Active_State == LED_u8_Active_High)
    {
        MGPIO_voidSetPinValue(Add_ledStrPointer->portId,Add_ledStrPointer->pinId,LED_u8_Active_High_H);

        Add_ledStrPointer->Curent_State = LED_u8_Active_High_H;
    }

    else if (Add_ledStrPointer->Active_State == LED_u8_Active_Low)
    {
        MGPIO_voidSetPinValue(Add_ledStrPointer->portId,Add_ledStrPointer->pinId,LED_u8_Active_Low_H);

        Add_ledStrPointer->Curent_State = LED_u8_Active_Low_H;
    }
}


void LED_voidTurnOff(Led_str * Add_ledStrPointer)
{
    if (Add_ledStrPointer->Active_State == LED_u8_Active_High)
    {
        MGPIO_voidSetPinValue(Add_ledStrPointer->portId,Add_ledStrPointer->pinId,LED_u8_Active_High_L);

        Add_ledStrPointer->Curent_State = LED_u8_Active_High_L;
    }

    else if (Add_ledStrPointer->Active_State == LED_u8_Active_Low)
    {
        MGPIO_voidSetPinValue(Add_ledStrPointer->portId,Add_ledStrPointer->pinId,LED_u8_Active_Low_L);

        Add_ledStrPointer->Curent_State = LED_u8_Active_Low_L;
    }
}

void LED_voidToggle(Led_str * Add_ledStrPointer)
{
    switch (Add_ledStrPointer->Active_State)
    {
    case LED_u8_Active_High :
        if (Add_ledStrPointer->Curent_State == LED_u8_Active_High_H)
        {
             MGPIO_voidSetPinValue(Add_ledStrPointer->portId,Add_ledStrPointer->pinId,LED_u8_Active_High_L);

             Add_ledStrPointer->Curent_State = LED_u8_Active_High_L;
        }

        else if (Add_ledStrPointer->Curent_State == LED_u8_Active_High_L)
        {
            MGPIO_voidSetPinValue(Add_ledStrPointer->portId,Add_ledStrPointer->pinId,LED_u8_Active_High_H);

             Add_ledStrPointer->Curent_State = LED_u8_Active_High_H;
        }
        
        break;

    case LED_u8_Active_Low :
        if (Add_ledStrPointer->Curent_State == LED_u8_Active_Low_H)
        {
             MGPIO_voidSetPinValue(Add_ledStrPointer->portId,Add_ledStrPointer->pinId,LED_u8_Active_Low_L);

             Add_ledStrPointer->Curent_State = LED_u8_Active_Low_L;
        }

        else if (Add_ledStrPointer->Curent_State == LED_u8_Active_Low_L)
        {
            MGPIO_voidSetPinValue(Add_ledStrPointer->portId,Add_ledStrPointer->pinId,LED_u8_Active_Low_H);

             Add_ledStrPointer->Curent_State = LED_u8_Active_Low_H;
        }
        
        break;
    
    default:
        break;
    }
}