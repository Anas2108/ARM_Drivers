/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/3/2023                                               */
/*******************************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../1-LIB/STD_TYPES.h"

typedef struct {

	u8 portId;
	u8 pinId;
	u8 Active_State;
	u8 Curent_State;


}Led_str;

//FOR active high and active low

#define LED_u8_Active_High 1

#define LED_u8_Active_Low 0


//for the value of active H OR L
#define LED_u8_Active_Low_L 1
#define LED_u8_Active_Low_H 0

#define LED_u8_Active_High_H 1
#define LED_u8_Active_High_L 0


/* To turn the led on */
void LED_voidTurnOn(Led_str * Add_ledStrPointer);

/* To turn the led off */
void LED_voidTurnOff(Led_str * Add_ledStrPointer);

/* set the direction of led (OUTPUT) */
void LED_voidSetLedDir(Led_str *Add_ledStrPointer);

/* To toggle the led H>>L or L>>H */
void LED_voidToggle(Led_str * Add_ledStrPointer);


#endif