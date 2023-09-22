/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/3/2023                                               */
/*******************************************************************/

#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "../../1-LIB/STD_TYPES.h"

#define SWITCH_PULL_UP          0
#define SWITCH_PULL_DOWN        1

#define SWITCH_READ_PP_HIGH     0
#define SWITCH_READ_PP_LOW      1

#define SWITCH_READ_PD_HIGH     1
#define SWITCH_READ_PD_LOW      0


typedef struct {

	u8 portId;
	u8 pinId;
    u8 switchMode;

}Switch_str;



void SWITCH_voidSetSwitchDir(Switch_str *Add_strPtrswitch);


u8 SWITCH_voidSetSwitchRead(Switch_str *Add_strPtrswitch);


#endif