/*****************************************************
 *      File Name: DIO_Config.h
 *  	Author: Muhammed Mamdouh
 *  	Created on: Apr 9, 2023
 *      SWC: DIO
 *      Arch Layer: MCAL
 *      Version: 1.0
 ****************************************************/

#ifndef MCAL_DIO_DIO_CONFIG_H_
#define MCAL_DIO_DIO_CONFIG_H_

#include "DIO_Private.h"


/*****************************************
 *
 *  DIO_DDRx_INIT Options:
 *
 *   1- DIO_PORT_INPUT
 *   2- DIO_PORT_OUTPUT
 *
 *****************************************/

/*#define DIO_DDRx_INIT DIO_PORT_INPUT*/


#define DIO_DDRA_INIT    DIO_PORT_INPUT
#define DIO_DDRB_INIT    DIO_PORT_INPUT
#define DIO_DDRC_INIT    DIO_PORT_INPUT
#define DIO_DDRD_INIT    DIO_PORT_INPUT


/***********************************************
 *
 *  DIO_PORTx_INIT Options:
 *
 *  1- DIO_PORT_OUTPUT_LOW
 *  2- DIO_PORT_OUTPUT_HIGH
 *  3- DIO_INPUT_PULLDOWN
 *  4- DIO_INPUT_PULLUP
 *
 *
 ***********************************************/

/*#define DIO_PORTx_INIT DIO_INPUT_PULLDOWN*/

#define DIO_PORTA_INIT  DIO_INPUT_PULLDOWN
#define DIO_PORTB_INIT  DIO_INPUT_PULLDOWN
#define DIO_PORTC_INIT  DIO_INPUT_PULLDOWN
#define DIO_PORTD_INIT  DIO_INPUT_PULLDOWN


#endif /* MCAL_DIO_DIO_CONFIG_H_ */
