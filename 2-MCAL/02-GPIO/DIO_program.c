/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 7/29/2023                                               */
/*******************************************************************/

#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void MGPIO_voidSetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
   if (Copy_u8Pin >=0 && Copy_u8Pin <=15) 
   {
     switch (Copy_u8Port)
    {
    case GPIO_PORTA :
        if (Copy_u8Value == GPIO_HIGH)
        {
            SET_BIT(GPIOA_ODR,Copy_u8Pin);
        }
        else if (Copy_u8Value == GPIO_LOW)
        {
            CLR_BIT(GPIOA_ODR,Copy_u8Pin);
        }
        break;

    case GPIO_PORTB :
            if (Copy_u8Value == GPIO_HIGH)
            {
                SET_BIT(GPIOB_ODR,Copy_u8Pin);
            }
            else if (Copy_u8Value == GPIO_LOW)
            {
                CLR_BIT(GPIOB_ODR,Copy_u8Pin);
            }
            break; 

    case GPIO_PORTC:
        if (Copy_u8Value == GPIO_HIGH)
        {
            SET_BIT(GPIOC_ODR,Copy_u8Pin);
        }
        else if (Copy_u8Value == GPIO_LOW)
        {
            CLR_BIT(GPIOC_ODR,Copy_u8Pin);
        }
        break;     
    
    default: /**< RETURN ERROR STATUS */ break;
    }
   }

   else {/**< RETURN ERROR STATUS */}
   
}

void MGPIO_voidSetPinDirection (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode)
{
    if (Copy_u8Pin >=0 && Copy_u8Pin <= 15)
    {
        switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        if (Copy_u8Pin <= 7)
        {
         GPIOA_CRL &= ~((0b1111) <<  (Copy_u8Pin*4));      /*To clear the 4 bits of specific pin*/
         GPIOA_CRL |= ((Copy_u8Mode) <<  (Copy_u8Pin*4)); /*To set the mode on specific pin*/
        }
        else if (Copy_u8Pin <=15)
        {
            Copy_u8Pin=Copy_u8Pin-8;
         GPIOA_CRH &= ~((0b1111) <<  (Copy_u8Pin*4));    
         GPIOA_CRH |= ((Copy_u8Mode) <<  (Copy_u8Pin*4));
        }

        

        break;

    case GPIO_PORTB:
        if (Copy_u8Pin <= 7)
        {
         GPIOB_CRL &= ~((0b1111) <<  (Copy_u8Pin*4)); 
         GPIOB_CRL |= ((Copy_u8Mode) <<  (Copy_u8Pin*4));
        }
        else if (Copy_u8Pin <=15)
        {
            Copy_u8Pin=Copy_u8Pin-8;
         GPIOB_CRH &= ~((0b1111) <<  (Copy_u8Pin*4)); 
         GPIOB_CRH |= ((Copy_u8Mode) <<  (Copy_u8Pin*4));
        }
        
        break;

    case GPIO_PORTC:
        if (Copy_u8Pin <= 7)
        {
         GPIOC_CRL &= ~((0b1111) <<  (Copy_u8Pin*4)); 
         GPIOC_CRL |= ((Copy_u8Mode) <<  (Copy_u8Pin*4));
        }
        else if (Copy_u8Pin <=15)
        {
            Copy_u8Pin=Copy_u8Pin-8;
         GPIOC_CRH &= ~((0b1111) <<  (Copy_u8Pin*4)); 
         GPIOC_CRH |= ((Copy_u8Mode) <<  (Copy_u8Pin*4));
        }
       
        break;

        default :/**< RETURN ERROR STATUS */ break;
    
    }
  }

  else {/**< RETURN ERROR STATUS */}
}

u8 MGPIO_voidGetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin )
{
    u8 LOC_u8ReturnValue=0;
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
       LOC_u8ReturnValue=GET_BIT(GPIOA_IDR,Copy_u8Pin);
        break;

    case GPIO_PORTB:
       LOC_u8ReturnValue=GET_BIT(GPIOB_IDR,Copy_u8Pin);
        break;

    case GPIO_PORTC:
       LOC_u8ReturnValue=GET_BIT(GPIOC_IDR,Copy_u8Pin);
        break;   

    default:
    /**< RETURN ERROR STATUS */
    break;
    }

    return LOC_u8ReturnValue;
}

void MGPIO_voidSetEightPinsDirection (u8 Copy_u8Port,u8 Copy_u8Section ,u8 Copy_u8SectionMode)
{
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        if (Copy_u8Section == GPIO_LOWER_SECTION)
        {
            GPIOA_CRL = Copy_u8SectionMode;
        }

        else if (Copy_u8Section == GPIO_UPPER_SECTION)
        {
             GPIOA_CRH = Copy_u8SectionMode;
        }
        
        break;

    case GPIO_PORTB:
        if (Copy_u8Section == GPIO_LOWER_SECTION)
        {
            GPIOB_CRL = Copy_u8SectionMode;
        }

        else if (Copy_u8Section == GPIO_UPPER_SECTION)
        {
             GPIOB_CRH = Copy_u8SectionMode;
        }
        
        break;

    case GPIO_PORTC:
        if (Copy_u8Section == GPIO_LOWER_SECTION)
        {
            GPIOC_CRL = Copy_u8SectionMode;
        }

        else if (Copy_u8Section == GPIO_UPPER_SECTION)
        {
             GPIOC_CRH = Copy_u8SectionMode;
        }
        
        break;        
    

    default:
    /**< RETURN ERROR STATUS */
        break;
    }
}

void MGPIO_voidSetEightPinsValue (u8 Copy_u8Port,u8 Copy_u8Section ,u8 Copy_u8SectionValue)
{
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        if (Copy_u8Section == GPIO_LOWER_SECTION)
        {
           GPIOA_ODR &= 0b1111111100000000;
           GPIOA_ODR |= Copy_u8SectionValue;

        }

        else if (Copy_u8Section == GPIO_UPPER_SECTION)
        {
             GPIOA_ODR &= 0b0000000011111111;
             GPIOA_ODR |= (Copy_u8SectionValue<<8);
        }
        
        break;

    case GPIO_PORTB:
        if (Copy_u8Section == GPIO_LOWER_SECTION)
        {
           GPIOB_ODR &= 0b1111111100000000;
           GPIOB_ODR |= Copy_u8SectionValue;
        }

        else if (Copy_u8Section == GPIO_UPPER_SECTION)
        {
            GPIOB_ODR &= 0b0000000011111111;
            GPIOB_ODR |= (Copy_u8SectionValue<<8);
        }
        
        break;

    case GPIO_PORTC:
        if (Copy_u8Section == GPIO_LOWER_SECTION)
        {
            GPIOB_ODR &= 0b1111111100000000;
           GPIOB_ODR |= Copy_u8SectionValue;
        }

        else if (Copy_u8Section == GPIO_UPPER_SECTION)
        {
             GPIOB_ODR &= 0b0000000011111111;
            GPIOB_ODR |= (Copy_u8SectionValue<<8);
        }
        
        break;        
    

    default:
    /**< RETURN ERROR STATUS */
        break;
    }
}