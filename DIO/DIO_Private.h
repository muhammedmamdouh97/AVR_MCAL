/*****************************************************
*       File Name: DIO_Private.h
*  		Author: Muhammed Mamdouh
*  		Created on: Apr 9, 2023
*       SWC: DIO
*       Arch Layer: MCAL
*       Version: 1.0
 ****************************************************/

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MCU.h"
#include "../../LIB/STD_TYPES.h"
#include "DIO_Config.h"

#define DIO_PORT_NO 3
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PORT_INPUT  0x00
#define DIO_PROT_OUTPUT 0xFF

#define DIO_PORT_HIGH_Nibble 0xF0
#define DIO_PORT_LOW_Nibble  0x0F

#define DIO_PORT_OUTPUT_LOW  0x00
#define DIO_PORT_INPUT_HIGH 0xFF

#define DIO_INPUT_PULLDOWN  0
#define DIO_INPUT_PULLUP  1


#define DIO_PIN_NO 7
#define DIO_PIN0  PIN0
#define DIO_PIN1  PIN1
#define DIO_PIN2  PIN2
#define DIO_PIN3  PIN3
#define DIO_PIN4  PIN4
#define DIO_PIN5  PIN5
#define DIO_PIN6  PIN6
#define DIO_PIN7  PIN7

#define DIO_PIN_INPUT 0
#define DIO_PIN_OUTPUT 1

#define DIO_PIN_LOW 0
#define DIO_PIN_HIGH 1


//DIO Initialization
void MCAL_DIO_vdInit(void);

// PORT functions Prototype
STD_Type MCAL_DIO_u8SetPortDirection(u8 LOC_u8PortId, u8 LOC_u8PortDirection);
STD_Type MCAL_DIO_u8SetPortValue(u8 LOC_u8PortId,u8 LOC_u8PortValue);
STD_Type MCAL_DIO_u8TogglePortValue(u8 LOC_u8PortId);
STD_Type MCAL_DIO_u8GetPortValue(u8 LOC_u8PortId, u8 *LOC_pu8PortStatus);


// PIN functions Prototype
STD_Type MCAL_DIO_u8SetPinDirection(u8 LOC_u8PortId, u8 LOC_u8PinId, u8 LOC_u8PinDirection);
STD_Type MCAL_DIO_u8SetPinValue(u8 LOC_u8PortId, u8 LOC_u8PinId, u8 LOC_u8PinValue);
STD_Type MCAL_DIO_u8TogglePinValue(u8 LOC_u8PortId, u8 LOC_u8PinId);
STD_Type MCAL_DIO_u8GetPinValue(u8 LOC_u8PortId, u8 LOC_u8PinId,  u8 *LOC_pu8PinStatus);


#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
