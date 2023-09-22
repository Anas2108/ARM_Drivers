/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/26/2023 m-d-y                                         */
/*******************************************************************/



#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"

#include "../../2-MCAL/02-GPIO/DIO_interface.h"

#include "IR_interface.h"
#include "IR_config.h"
#include "IR_private.h"

void IR_voidInit(u8 Copy_u8Port , u8 Copy_u8Pin)
{
MGPIO_voidSetPinDirection(Copy_u8Port,Copy_u8Pin,GPIO_INPUT_FLOATING);
}

u8 IR_u8getIRvalue(u8 Copy_u8Port , u8 Copy_u8Pin)
{
    u8 LOC_u8value;
 LOC_u8value = MGPIO_voidGetPinValue(Copy_u8Port,Copy_u8Pin );

return (LOC_u8value);
}
