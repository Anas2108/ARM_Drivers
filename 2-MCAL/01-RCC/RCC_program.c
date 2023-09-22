/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 7/22/2023                                               */
/*******************************************************************/

#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
    #if     RCC_SYSTEM_CLOCK_TYPE == RCC_HSE_CRYSTAL_OCILLATOR
        RCC_CR = 0x00010000;    /* Enable HSE with no bypass*/
        RCC_CFGR = 0x00000001;  /* Select HSE to be SYS Clock*/

    #elif   RCC_SYSTEM_CLOCK_TYPE == RCC_HSE_RC
        RCC_CR = 0x00050000;    /* Enable HSE with bypass*/
        RCC_CFGR = 0x00000001;  /* Select HSE to be SYS Clock*/

    #elif   RCC_SYSTEM_CLOCK_TYPE == RCC_HSI
        RCC_CR = 0x00000081;   /* HSI Enable + Trimming=0 (defualt value) */
        RCC_CFGR = 0x00000000; /* Select HSI to be SYS Clock*/
    #elif   RCC_SYSTEM_CLOCK_TYPE == RCC_PLL

        #if   RCC_PLL_INPUT == RCC_PLL_IN_HSE
            RCC_CFGR = 0x00010000;  /*Select HSE as PLL input*/

        #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
             RCC_CFGR = 0x00030000; /*Select HSE as PLL input + div /2*/
             

        #elif RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
             RCC_CFGR = 0x00000000; /*Select HSI as PLL input + div /2*/

        #endif

        ////////////////////
        #if   RCC_PLL_MUL_VAL == 2
           CLR_BIT (RCC_CFGR,18);
           CLR_BIT (RCC_CFGR,19);
           CLR_BIT (RCC_CFGR,20);
           CLR_BIT (RCC_CFGR,21);

        #elif  RCC_PLL_MUL_VAL == 3
           SET_BIT (RCC_CFGR,18);
           CLR_BIT (RCC_CFGR,19);
           CLR_BIT (RCC_CFGR,20);
           CLR_BIT (RCC_CFGR,21);
             

        #elif  RCC_PLL_MUL_VAL == 4
           CLR_BIT (RCC_CFGR,18);
           SET_BIT (RCC_CFGR,19);
           CLR_BIT (RCC_CFGR,20);
           CLR_BIT (RCC_CFGR,21);

        #elif  RCC_PLL_MUL_VAL == 5
           SET_BIT (RCC_CFGR,18);
           SET_BIT (RCC_CFGR,19);
           CLR_BIT (RCC_CFGR,20);
           CLR_BIT (RCC_CFGR,21);

        #elif  RCC_PLL_MUL_VAL == 6
           CLR_BIT (RCC_CFGR,18);
           CLR_BIT (RCC_CFGR,19);
           SET_BIT (RCC_CFGR,20);
           CLR_BIT (RCC_CFGR,21);

        #elif  RCC_PLL_MUL_VAL == 7
           SET_BIT (RCC_CFGR,18);
           CLR_BIT (RCC_CFGR,19);
           SET_BIT (RCC_CFGR,20);
           CLR_BIT (RCC_CFGR,21);
        #elif  RCC_PLL_MUL_VAL == 8
           CLR_BIT (RCC_CFGR,18);
           SET_BIT (RCC_CFGR,19);
           SET_BIT (RCC_CFGR,20);
           CLR_BIT (RCC_CFGR,21);

        #elif  RCC_PLL_MUL_VAL == 9
           SET_BIT (RCC_CFGR,18);
           SET_BIT (RCC_CFGR,19);
           SET_BIT (RCC_CFGR,20);
           CLR_BIT (RCC_CFGR,21);

        #elif  RCC_PLL_MUL_VAL == 10
           CLR_BIT (RCC_CFGR,18);
           CLR_BIT (RCC_CFGR,19);
           CLR_BIT (RCC_CFGR,20);
           SET_BIT (RCC_CFGR,21);

        #elif  RCC_PLL_MUL_VAL == 11
           SET_BIT (RCC_CFGR,18);
           CLR_BIT (RCC_CFGR,19);
           CLR_BIT (RCC_CFGR,20);
           SET_BIT (RCC_CFGR,21);

        #elif  RCC_PLL_MUL_VAL == 12
           CLR_BIT (RCC_CFGR,18);
           SET_BIT (RCC_CFGR,19);
           CLR_BIT (RCC_CFGR,20);
           SET_BIT (RCC_CFGR,21);

        #elif  RCC_PLL_MUL_VAL == 13
           SET_BIT (RCC_CFGR,18);
           SET_BIT (RCC_CFGR,19);
           CLR_BIT (RCC_CFGR,20);
           SET_BIT (RCC_CFGR,21);

        #elif  RCC_PLL_MUL_VAL == 14
           CLR_BIT (RCC_CFGR,18);
           CLR_BIT (RCC_CFGR,19);
           SET_BIT (RCC_CFGR,20);
           SET_BIT (RCC_CFGR,21);

        #elif  RCC_PLL_MUL_VAL == 15
           SET_BIT (RCC_CFGR,18);
           CLR_BIT (RCC_CFGR,19);
           SET_BIT (RCC_CFGR,20);
           SET_BIT (RCC_CFGR,21);

        #elif  RCC_PLL_MUL_VAL == 16
           CLR_BIT (RCC_CFGR,18);
           SET_BIT (RCC_CFGR,19);
           SET_BIT (RCC_CFGR,20);
           SET_BIT (RCC_CFGR,21);
            

        #endif
        /////////////////
         RCC_CR = 0x01000000;    /* Enable PLL */
         SET_BIT (RCC_CFGR,1);  /*Select PLL as clock input*/
    #else
		#error("You chosed Wrong Clock type")
	#endif
}

void RCC_voidEnableClock (u8 Copy_u8BusID ,u8 Copy_u8PerId )
{
    if (Copy_u8PerId <=31)
    {
        switch(Copy_u8BusID)
        {
            case RCC_AHB  : SET_BIT(RCC_AHBENR,Copy_u8PerId);  break;
            case RCC_APB1 : SET_BIT(RCC_APB1ENR,Copy_u8PerId); break;
            case RCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_u8PerId); break;
        
        }

    }

    else 
    {
        /*Return error*/
    }
}


void RCC_voidDisableClock (u8 Copy_u8BusID ,u8 Copy_u8PerId )
{
    if (Copy_u8PerId <=31)
    {
        switch(Copy_u8BusID)
        {
            case RCC_AHB  : CLR_BIT(RCC_AHBENR,Copy_u8PerId);  break;
            case RCC_APB1 : CLR_BIT(RCC_APB1ENR,Copy_u8PerId); break;
            case RCC_APB2 : CLR_BIT(RCC_APB2ENR,Copy_u8PerId); break;
        
        }

    }

    else 
    {
        /*Return error*/
    }
}