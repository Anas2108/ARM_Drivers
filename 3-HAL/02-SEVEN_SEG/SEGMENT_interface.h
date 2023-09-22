/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/3/2023                                               */
/*******************************************************************/

#ifndef SEGMENT_INTERFACE_H
#define SEGMENT_INTERFACE_H

#include "../../1-LIB/STD_TYPES.h"
//TYPE OF 7-SEGMENT
#define SEGMENT_COMMON_CATHOD 1
#define SEGMENT_COMMON_ANODE 0

//STRUCT OF THE 7-SEGMENT

typedef struct {
    u8 section;
	u8 portId;
	u8 segmentType;


}segment_str;


void SEGMENT_voidSetSegmentDir(segment_str *Add_segmentStrPointer);

void SEGMENT_voidSetSegmentVal(segment_str *Add_segmentStrPointer,u8 Copy_segmentVal);


#endif