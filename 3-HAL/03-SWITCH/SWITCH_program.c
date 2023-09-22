/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/3/2023                                               */
/*******************************************************************/

#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"

#include "../../2-MCAL/02-GPIO/DIO_interface.h"

#include "SWITCH_interface.h"

void SWITCH_voidSetSwitchDir(Switch_str *Add_strPtrswitch)
{
    MGPIO_voidSetPinDirection (Add_strPtrswitch->portId, Add_strPtrswitch->pinId , GPIO_INPUT_PP_OR_PD);

    if (Add_strPtrswitch->switchMode == SWITCH_PULL_UP )
    MGPIO_voidSetPinValue (Add_strPtrswitch->portId ,Add_strPtrswitch->pinId, GPIO_HIGH);

    else if (Add_strPtrswitch->switchMode == SWITCH_PULL_DOWN )
    MGPIO_voidSetPinValue (Add_strPtrswitch->portId ,Add_strPtrswitch->pinId, GPIO_LOW);
}




u8 SWITCH_voidSetSwitchRead(Switch_str *Add_strPtrswitch)
{
    return MGPIO_voidGetPinValue(Add_strPtrswitch->portId, Add_strPtrswitch->pinId);
}