/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/15/2023 m-d-y                                         */
/*******************************************************************/

#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

/*Port Map options : port A,B,C,D,E,F and G*/

#define AFIO_EXTI_PORTA 0b0000
#define AFIO_EXTI_PORTB 0b0001
#define AFIO_EXTI_PORTC 0b0010
#define AFIO_EXTI_PORTD 0b0011
#define AFIO_EXTI_PORTE 0b0100
#define AFIO_EXTI_PORTF 0b0101
#define AFIO_EXTI_PORTG 0b0110

void	MAFIO_voidSetEXTIPort(u8 Copy_u8Line ,u8 Copy_u8PortMap);

#endif