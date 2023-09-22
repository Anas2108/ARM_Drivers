/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/28/2023 m-d-y                                         */
/*******************************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

/**********Channels configuration**************/
/*Channels ID*/
#define CHANNEL1 0
#define CHANNEL2 1
#define CHANNEL3 2
#define CHANNEL4 3
#define CHANNEL5 4
#define CHANNEL6 5
#define CHANNEL7 6

/*Channel Mode*/
#define MEMOREY_AND_MEMOREY    0
#define MEMOREY_AND_PERIPHERAL 1

/*Channel periority*/
#define LOW         0b00
#define MEDIUM      0b01
#define HIGH        0b10
#define VERY_HIGH   0b11

/* Memorey and peripheral  size*/
#define _8_BIT_SIZE  0b00
#define _16_BIT_SIZE 0b01
#define _32_BIT_SIZE 0b10

/*Channel Direction*/
#define READ_FROM_PERIPHERAL 0
#define READ_FROM_MEMOREY    1
 
/*Increment options*/
#define INCREMENT_ENABLE    1
#define INCREMENT_DISABLE   0

/*Circular mode*/
#define CIRCULAR_MODE_DISABLE 0
#define CIRCULAR_MODE_ENABLE  1

/*INT source*/

#define TRANSFER                     0b001
#define HALF_TRANSFER                0b010
#define ERROR_TRANSFER               0b100
#define TRANSFER_HALF_TRANSFER       0b011
#define ALL_INT                      0b111



typedef struct 
{
    u8 channelID;
    u8 mode;
    u8 periority;
    u8 memoreySize;
    u8 peripheralSize;
    u8 direction;
    u8 PINC;
    u8 MINC;
    u8 circularMode;
    u8 INTSource;

  
}channel;

void DMA_voidChannelInit(channel *Add_DMAptr);


void DMA_voidChannelStart(channel *Add_DMAptr, u32* Copy_pu32SourceAddress, u32* Copy_pu32DestinationAddress, u16 Copy_u16BlockLength);

#endif
