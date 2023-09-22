/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/3/2023                                               */
/*******************************************************************/

#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"

#include "../../2-MCAL/02-GPIO/DIO_interface.h"

#include "SEGMENT_interface.h"

void SEGMENT_voidSetSegmentDir(segment_str *Add_segmentStrPointer)
{
    MGPIO_voidSetEightPinsDirection(Add_segmentStrPointer->portId, Add_segmentStrPointer->section, GPIO_OUTPUT_10MHZ_PP_SECTION);
}

void SEGMENT_voidSetSegmentVal(segment_str *Add_segmentStrPointer,u8 Copy_segmentVal)
{
    if (Add_segmentStrPointer->segmentType == SEGMENT_COMMON_CATHOD)
    MGPIO_voidSetEightPinsValue(Add_segmentStrPointer->portId, Add_segmentStrPointer->section , Copy_segmentVal);

    else if (Add_segmentStrPointer->segmentType == SEGMENT_COMMON_ANODE)
    MGPIO_voidSetEightPinsValue(Add_segmentStrPointer->portId, Add_segmentStrPointer->section , ~(Copy_segmentVal));

}


