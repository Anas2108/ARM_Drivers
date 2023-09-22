/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/15/2023 m-d-y                                         */
/*******************************************************************/

#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"


void	MAFIO_voidSetEXTIPort(u8 Copy_u8Line ,u8 Copy_u8PortMap)
{
    u8 LOC_u8Index=0;
    if (Copy_u8Line <=3)
    {
        Copy_u8Line %=4;
        LOC_u8Index = Copy_u8Line /4;
    }

    else if (Copy_u8Line <=7)
    {
        Copy_u8Line %=4;
        LOC_u8Index = Copy_u8Line /4;
    }
    else if (Copy_u8Line <=11)
    {
        Copy_u8Line %=4;
        LOC_u8Index = Copy_u8Line /4;
    }

    else if (Copy_u8Line <=15)
    {
        Copy_u8Line %=4;
        LOC_u8Index = Copy_u8Line /4;
    }

    else 
    {
        /*RETURN <Error>*/
    }
    AFIO->EXTICR[LOC_u8Index] &= ~((0b1111) << (Copy_u8Line * 4));
    AFIO->EXTICR[LOC_u8Index] |= ((Copy_u8PortMap) << (Copy_u8Line * 4));
}