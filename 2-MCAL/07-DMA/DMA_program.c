/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/28/2023 m-d-y                                         */
/*******************************************************************/

#include "../../1-LIB/STD_TYPES.h"
#include "../../1-LIB/BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_config.h"
#include "DMA_private.h"



void DMA_voidChannelInit(channel *Add_DMAptr)
{

	CLR_BIT(DMA->Channel[Add_DMAptr->channelID].CCR, 0); //disable channel before congif
	
		switch(Add_DMAptr->INTSource)
		{
		case TRANSFER :
			DMA->Channel[Add_DMAptr->channelID].CCR &= ~((0b111)<<1); //to clear the INT bits
			DMA->Channel[Add_DMAptr->channelID].CCR |= ((TRANSFER)<<1);
			break;

		case TRANSFER_HALF_TRANSFER :
			DMA->Channel[Add_DMAptr->channelID].CCR &= ~((0b111)<<1); //to clear the INT bits
			DMA->Channel[Add_DMAptr->channelID].CCR |= ((TRANSFER_HALF_TRANSFER)<<1);
			break;

		case HALF_TRANSFER :
			DMA->Channel[Add_DMAptr->channelID].CCR &= ~((0b111)<<1); //to clear the INT bits
			DMA->Channel[Add_DMAptr->channelID].CCR |= ((HALF_TRANSFER)<<1);
			break;

		case ERROR_TRANSFER :
			DMA->Channel[Add_DMAptr->channelID].CCR &= ~((0b111)<<1); //to clear the INT bits
			DMA->Channel[Add_DMAptr->channelID].CCR |= ((ERROR_TRANSFER)<<1); //to clear the INT bits
			break;

		case ALL_INT :
			DMA->Channel[Add_DMAptr->channelID].CCR &= ~((0b111)<<1); //to clear the INT bits
			DMA->Channel[Add_DMAptr->channelID].CCR |= ((ALL_INT)<<1); //to clear the INT bits
			break;

		default : break;


		}


		switch(Add_DMAptr->MINC)
		{
		case INCREMENT_ENABLE :  SET_BIT(DMA->Channel[Add_DMAptr->channelID].CCR, 7); break;
		case INCREMENT_DISABLE : CLR_BIT(DMA->Channel[Add_DMAptr->channelID].CCR, 7); break;
		default : break;
		}


		switch(Add_DMAptr->PINC)
		{
		case INCREMENT_ENABLE :  SET_BIT(DMA->Channel[Add_DMAptr->channelID].CCR, 6); break;
		case INCREMENT_DISABLE : CLR_BIT(DMA->Channel[Add_DMAptr->channelID].CCR, 6); break;
		default : break;
		}

		switch(Add_DMAptr->circularMode)
		{
		case CIRCULAR_MODE_ENABLE  : SET_BIT(DMA->Channel[Add_DMAptr->channelID].CCR, 5); break;
		case CIRCULAR_MODE_DISABLE : CLR_BIT(DMA->Channel[Add_DMAptr->channelID].CCR, 5); break;
		default : break;
		}

		switch(Add_DMAptr->direction)
		{
		case READ_FROM_MEMOREY : SET_BIT(DMA->Channel[Add_DMAptr->channelID].CCR, 4); break;
		case READ_FROM_PERIPHERAL : CLR_BIT(DMA->Channel[Add_DMAptr->channelID].CCR, 4); break;
		default : break;
		}


		switch(Add_DMAptr->memoreySize)
		{
		case _8_BIT_SIZE :
			DMA->Channel[Add_DMAptr->channelID].CCR &= ~((0b11)<<10);
			DMA->Channel[Add_DMAptr->channelID].CCR |= ((_8_BIT_SIZE)<<10);
			break;

		case _16_BIT_SIZE :
			DMA->Channel[Add_DMAptr->channelID].CCR &= ~((0b11)<<10);
			DMA->Channel[Add_DMAptr->channelID].CCR |= ((_16_BIT_SIZE)<<10);
			break;

		case _32_BIT_SIZE :
			DMA->Channel[Add_DMAptr->channelID].CCR &= ~((0b11)<<10);
			DMA->Channel[Add_DMAptr->channelID].CCR |= ((_32_BIT_SIZE)<<10);
			break;

		default : break;
		}


		switch(Add_DMAptr->peripheralSize)
		{
		case _8_BIT_SIZE :
			DMA->Channel[Add_DMAptr->channelID].CCR &= ~((0b11)<<8);
			DMA->Channel[Add_DMAptr->channelID].CCR |= ((_8_BIT_SIZE)<<8);
			break;

		case _16_BIT_SIZE :
			DMA->Channel[Add_DMAptr->channelID].CCR &= ~((0b11)<<8);
			DMA->Channel[Add_DMAptr->channelID].CCR |= ((_16_BIT_SIZE)<<8);
			break;

		case _32_BIT_SIZE :
			DMA->Channel[Add_DMAptr->channelID].CCR &= ~((0b11)<<8);
			DMA->Channel[Add_DMAptr->channelID].CCR |= ((_32_BIT_SIZE)<<8);
			break;

		default : break;
		}

		switch(Add_DMAptr->periority)
		{
		case LOW :
			DMA->Channel[Add_DMAptr->channelID].CCR &= ~((0b11)<<12);
			DMA->Channel[Add_DMAptr->channelID].CCR |= ((LOW)<<12);
			break;

		case MEDIUM :
			DMA->Channel[Add_DMAptr->channelID].CCR &= ~((0b11)<<12);
			DMA->Channel[Add_DMAptr->channelID].CCR |= ((MEDIUM)<<12);
			break;

		case HIGH :
			DMA->Channel[Add_DMAptr->channelID].CCR &= ~((0b11)<<12);
			DMA->Channel[Add_DMAptr->channelID].CCR |= ((HIGH)<<12);
			break;

		case VERY_HIGH :
			DMA->Channel[Add_DMAptr->channelID].CCR &= ~((0b11)<<12);
			DMA->Channel[Add_DMAptr->channelID].CCR |= ((VERY_HIGH)<<12);
			break;

		default : break;
		}

		switch(Add_DMAptr->mode)
		{
		case MEMOREY_AND_MEMOREY: SET_BIT(DMA->Channel[Add_DMAptr->channelID].CCR, 14) ;break;
		case MEMOREY_AND_PERIPHERAL: CLR_BIT(DMA->Channel[Add_DMAptr->channelID].CCR, 14) ;break;
		default : break;

		}





}

void DMA_voidChannelStart(channel *Add_DMAptr, u32* Copy_pu32SourceAddress, u32* Copy_pu32DestinationAddress, u16 Copy_u16BlockLength)
{
	CLR_BIT(DMA->Channel[Add_DMAptr->channelID].CCR, 0); //disable channel before congif

	if (Add_DMAptr->mode == MEMOREY_AND_MEMOREY)
	{
		DMA->Channel[Add_DMAptr->channelID].CPAR = Copy_pu32SourceAddress; //peripheral reg used as source
		DMA->Channel[Add_DMAptr->channelID].CMAR = Copy_pu32DestinationAddress;
	}

	else
	{
		if (Add_DMAptr->direction == READ_FROM_MEMOREY)
		{
			DMA->Channel[Add_DMAptr->channelID].CPAR = Copy_pu32DestinationAddress;
			DMA->Channel[Add_DMAptr->channelID].CMAR = Copy_pu32SourceAddress;
		}

		else
		{
			DMA->Channel[Add_DMAptr->channelID].CPAR = Copy_pu32SourceAddress;
			DMA->Channel[Add_DMAptr->channelID].CMAR = Copy_pu32DestinationAddress;
		}
	}

	DMA->Channel[Add_DMAptr->channelID].CNDTR = Copy_u16BlockLength;

	SET_BIT(DMA->Channel[Add_DMAptr->channelID].CCR, 0); //enable channel
}

