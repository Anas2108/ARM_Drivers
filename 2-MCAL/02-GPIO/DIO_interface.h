/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 7/29/2023                                               */
/*******************************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define GPIO_PORTA  0
#define GPIO_PORTB  1
#define GPIO_PORTC  2

#define PIN0        0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7
#define PIN8        8
#define PIN9        9
#define PIN10       10
#define PIN11       11
#define PIN12       12
#define PIN13       13
#define PIN14       14
#define PIN15       15
////////////////////////////////

/* Pin Modes */

/*10MHZ Output*/
#define GPIO_OUTPUT_10MHZ_PP       0b0001
#define GPIO_OUTPUT_10MHZ_OD       0b0101
#define GPIO_OUTPUT_10MHZ_AFPP     0b1001
#define GPIO_OUTPUT_10MHZ_AFOD     0b1101

/*2MHZ Output*/
#define GPIO_OUTPUT_2MHZ_PP        0b0010
#define GPIO_OUTPUT_2MHZ_OD        0b0110
#define GPIO_OUTPUT_2MHZ_AFPP      0b1010
#define GPIO_OUTPUT_2MHZ_AFOD      0b1110

/*50MHZ Output*/
#define GPIO_OUTPUT_50MHZ_PP        0b0011
#define GPIO_OUTPUT_50MHZ_OD        0b0111
#define GPIO_OUTPUT_50MHZ_AFPP      0b1011
#define GPIO_OUTPUT_50MHZ_AFOD      0b1111

/*Input*/
#define GPIO_INPUT_ANALOG           0b0000
#define GPIO_INPUT_FLOATING         0b0100
#define GPIO_INPUT_PP_OR_PD         0b1000
//////////////////////////////////

/* Output Pin Value */
#define GPIO_HIGH 1
#define GPIO_LOW  0 

////////////////////////////////////////////////////////
/*Port Sections (8-pins)*/
#define GPIO_UPPER_SECTION 1
#define GPIO_LOWER_SECTION 0

                    /*Sections mode*/

/*10MHZ Output*/
#define GPIO_OUTPUT_10MHZ_PP_SECTION        0x11111111
#define GPIO_OUTPUT_10MHZ_OD_SECTION        0x55555555
#define GPIO_OUTPUT_10MHZ_AFPP_SECTION      0x99999999
#define GPIO_OUTPUT_10MHZ_AFOD_SECTION      0xDDDDDDDD

/*2MHZ Output*/
#define GPIO_OUTPUT_2MHZ_PP_SECTION         0x22222222
#define GPIO_OUTPUT_2MHZ_OD_SECTION         0x66666666
#define GPIO_OUTPUT_2MHZ_AFPP_SECTION       0xAAAAAAAA
#define GPIO_OUTPUT_2MHZ_AFOD_SECTION       0xEEEEEEEE

/*50MHZ Output*/
#define GPIO_OUTPUT_50MHZ_PP_SECTION         0x33333333
#define GPIO_OUTPUT_50MHZ_OD_SECTION         0x77777777
#define GPIO_OUTPUT_50MHZ_AFPP_SECTION       0xBBBBBBBB
#define GPIO_OUTPUT_50MHZ_AFOD_SECTION       0xFFFFFFFF

/*Input*/
#define GPIO_INPUT_ANALOG_SECTION            0x00000000
#define GPIO_INPUT_FLOATING_SECTION          0x44444444
#define GPIO_INPUT_PP_OR_PD_SECTION          0x88888888


void MGPIO_voidSetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);

void MGPIO_voidSetPinDirection (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode);

void MGPIO_voidSetEightPinsDirection (u8 Copy_u8Port,u8 Copy_u8Section ,u8 Copy_u8SectionMode);

void MGPIO_voidSetEightPinsValue (u8 Copy_u8Port,u8 Copy_u8Section ,u8 Copy_u8SectionValue);

u8 MGPIO_voidGetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin );


#endif