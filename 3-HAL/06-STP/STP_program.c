/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 9/3/2023 m-d-y                                          */
/*******************************************************************/

#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"

#include "../../2-MCAL/02-GPIO/DIO_interface.h"
#include "../../2-MCAL/06-SYSTICK_TIMER/SYSTICK_TIMER_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_congif.h"

void HSTP_voidSendSerial (u8 Copy_u8SendValue)
{
    u8 Loc_u8PinValue ;
    s8 Loc_s8PinIndex;
    
    for (Loc_s8PinIndex = HSTP_NUMBER_OF_SERIAL_PINS ; Loc_s8PinIndex >=0 ; Loc_s8PinIndex--)
    {
        Loc_u8PinValue = GET_BIT(Copy_u8SendValue, Loc_s8PinIndex);
        MGPIO_voidSetPinValue(HSTP_SERIAL_DATA, Loc_u8PinValue);

        MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,GPIO_HIGH);
        MSTK_voidSetBusyWait(1);
        MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,GPIO_LOW);
        MSTK_voidSetBusyWait(1);
    }
    
    
        MGPIO_voidSetPinValue(HSTP_STORE_CLOCK,GPIO_HIGH);
        MSTK_voidSetBusyWait(1);
        MGPIO_voidSetPinValue(HSTP_STORE_CLOCK,GPIO_LOW);
        MSTK_voidSetBusyWait(1);
}