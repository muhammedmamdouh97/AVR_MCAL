/****************************************************
 * 		File Name:	DIO_Prog.c
 *  	Author: Muhammed Mamdouh
 *  	Created on: Apr 9, 2023
 *      SWC: DIO
 *      Arch Layer: MCAL
 *      Version: 1.0
 ****************************************************/

#include "DIO_Private.h"


/*********************************************************************************************
 *\Syntax		   : void MCAL_EXTI_VdInit(void)
 *\Description	   : This function initializes DIO
 *\Sync\Async      : Synchronous
 *\Reentrancy      : Non Reentrant
 *\Parameters (in) : None
 *\Parameters (out): None
 *\Return value    : void
 **********************************************************************************************/

void MCAL_DIO_vdInit(void)
{
	// PORTA INIT
	#if DIO_DDRA_INIT == DIO_PORT_INPUT
		DDRA= DIO_PORT_INPUT;
		#if DIO_PORTA_INIT == DIO_INPUT_PULLDOWN
			PINA= DIO_INPUT_PULLDOWN;
		#elif DIO_PORTA_INIT == DIO_INPUT_PULLUP
			PINA= DIO_INPUT_PULLUP;
		#endif

	#elif DIO_DDRA_INIT == DIO_PORT_OUTPUT
			DDRA= DIO_PORT_OUTPUT;
		#if DIO_PORTA_INIT == DIO_OUTPUT_HIGH
			PORTA= DIO_OUTPUT_HIGH;
		#elif DIO_PORTA_INIT == DIO_OUTPUT_LOW
			PORTA= DIO_OUTPUT_LOW;
		#endif

	#endif

	// PORTB INIT
	#if DIO_DDRB_INIT == DIO_PORT_INPUT
			DDRB= DIO_PORT_INPUT;
		#if DIO_PORTB_INIT == DIO_INPUT_PULLDOWN
			PINB= DIO_INPUT_PULLDOWN;
		#elif DIO_PORTB_INIT == DIO_INPUT_PULLUP
			PINB= DIO_INPUT_PULLUP;
		#endif

	#elif DIO_DDRB_INIT == DIO_PORT_OUTPUT
		DDRB= DIO_PORT_OUTPUT;
		#if DIO_PORTB_INIT == DIO_OUTPUT_HIGH
			PORTB= DIO_OUTPUT_HIGH;
		#elif DIO_PORTB_INIT == DIO_OUTPUT_LOW
			PORTB= DIO_OUTPUT_LOW;
		#endif
	#endif

	// PORTC INIT
	#if DIO_DDRC_INIT == DIO_PORT_INPUT
		DDRC= DIO_PORT_INPUT;
		#if DIO_PORTC_INIT == DIO_INPUT_PULLDOWN
			PINC= DIO_INPUT_PULLDOWN;
		#elif DIO_PORTC_INIT == DIO_INPUT_PULLUP
			PINC= DIO_INPUT_PULLUP;
		#endif

	#elif DIO_DDRC_INIT == DIO_PORT_OUTPUT
		DDRC= DIO_PORT_OUTPUT;
		#if DIO_PORTC_INIT == DIO_OUTPUT_HIGH
			PORTC= DIO_OUTPUT_HIGH;
		#elif DIO_PORTC_INIT == DIO_OUTPUT_LOW
			PORTC= DIO_OUTPUT_LOW;
		#endif

	#endif

	// PORTD INIT
	#if DIO_DDRD_INIT == DIO_PORT_INPUT
		DDRD= DIO_PORT_INPUT;
		#if DIO_PORTD_INIT == DIO_INPUT_PULLDOWN
			PIND= DIO_INPUT_PULLDOWN;
		#elif DIO_PORTD_INIT == DIO_INPUT_PULLUP
			PIND= DIO_INPUT_PULLUP;
		#endif

	#elif DIO_DDRD_INIT == DIO_PORT_OUTPUT
		DDRD= DIO_PORT_OUTPUT;
		#if DIO_PORTA_INIT == DIO_OUTPUT_HIGH
			PORTD= DIO_OUTPUT_HIGH;
		#elif DIO_PORTD_INIT == DIO_OUTPUT_LOW
			PORTD= DIO_OUTPUT_LOW;
		#endif

	#endif

}


//*********************************PORT Functions*********************************************

/*********************************************************************************************
 *\Syntax		   : STD_Type MCAL_DIO_u8SetPortDirection(u8 LOC_u8PortId, u8 LOC_u8PortDirection)
 *\Description	   : This function sets the direction of DIO_Port
 *\Sync\Async      : Synchronous
 *\Reentrancy      : Non Reentrant
 *\Parameters (in) : LOC_u8PortId  (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
 *					 LOC_u8PortDirection (DIO_PORT_OUTPUT, DIO_PORT_INPUT, DIO_PORT_LOW_Nibble, DIO_PORT_HIGH_Nibble)
 *\Parameters (out): None
 *\Return value    : LOC_u8ReturnValue  E_OK
 *							 			E_NOT_OK
 **********************************************************************************************/

STD_Type MCAL_DIO_u8SetPortDirection(u8 LOC_u8PortId, u8 LOC_u8PortDirection)
{
	u8 LOC_u8ReturnValue = E_NOT_OK ;

	if (LOC_u8PortId <= DIO_PORT_NO)
		{
			switch(LOC_u8PortId)
			{
				case DIO_PORTA: DDRA = LOC_u8PortDirection;
					LOC_u8ReturnValue = E_OK;
					break;
				case DIO_PORTB: DDRB = LOC_u8PortDirection;
					LOC_u8ReturnValue = E_OK;
					break;
				case DIO_PORTC: DDRC = LOC_u8PortDirection;
					LOC_u8ReturnValue = E_OK;
					break;
				case DIO_PORTD: DDRD = LOC_u8PortDirection;
					LOC_u8ReturnValue = E_OK;
					break;
				default: LOC_u8ReturnValue = E_NOT_OK;
			}
		}

		else
		{
			LOC_u8ReturnValue = E_NOT_OK;
		}

	return LOC_u8ReturnValue;
}


/*********************************************************************************************
 *\Syntax		   : STD_Type MCAL_DIO_u8SetPortValue(u8 LOC_u8PortId,u8 LOC_u8PortValue)
 *\Description	   : This function sets the value of DIO_Port
 *\Sync\Async      : Synchronous
 *\Reentrancy      : Non Reentrant
 *\Parameters (in) : LOC_u8PortId    (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
 *					 LOC_u8PortValue (DIO_PORT_HIGH, DIO_PORT_LOW)
 *\Parameters (out): None
 *\Return value    : LOC_u8ReturnValue  E_OK
 *							 			E_NOT_OK
 **********************************************************************************************/

STD_Type MCAL_DIO_u8SetPortValue(u8 LOC_u8PortId,u8 LOC_u8PortValue)
{
	u8 LOC_u8ReturnValue = E_NOT_OK ;

	if (LOC_u8PortId <= DIO_PORT_NO)
	{
		switch(LOC_u8PortId)
		{
			case DIO_PORTA: PORTA = LOC_u8PortValue;
				LOC_u8ReturnValue = E_OK;
				break;
			case DIO_PORTB: PORTB = LOC_u8PortValue;
				LOC_u8ReturnValue = E_OK;
				break;
			case DIO_PORTC: PORTC = LOC_u8PortValue;
				LOC_u8ReturnValue = E_OK;
				break;
			case DIO_PORTD: PORTD = LOC_u8PortValue;
				LOC_u8ReturnValue = E_OK;
				break;
			default: LOC_u8ReturnValue = E_NOT_OK;
		}
	}

	else
	{
		LOC_u8ReturnValue = E_NOT_OK;
	}

	return LOC_u8ReturnValue;
}


/*********************************************************************************************
 *\Syntax		   : STD_Type MCAL_DIO_u8TogglePortValue(u8 LOC_u8PortId)
 *\Description	   : This function toggles the value of DIO_Port
 *\Sync\Async      : Synchronous
 *\Reentrancy      : Non Reentrant
 *\Parameters (in) : LOC_u8PortId  (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
 *\Parameters (out): None
 *\Return value    : LOC_u8ReturnValue  E_OK
 *							 			E_NOT_OK
 **********************************************************************************************/

STD_Type MCAL_DIO_u8TogglePortValue(u8 LOC_u8PortId)
{
	u8 LOC_u8ReturnValue = E_NOT_OK ;

	if (LOC_u8PortId <= DIO_PORT_NO)
	{
		switch(LOC_u8PortId)
		{
			case DIO_PORTA: PORTA =~(PORTA);
				LOC_u8ReturnValue = E_OK;
				break;
			case DIO_PORTB: PORTB =~(PORTB);
				LOC_u8ReturnValue = E_OK;
				break;
			case DIO_PORTC: PORTC =~(PORTC);
				LOC_u8ReturnValue = E_OK;
				break;
			case DIO_PORTD: PORTD =~(PORTD);
				LOC_u8ReturnValue = E_OK;
				break;
			default: LOC_u8ReturnValue = E_NOT_OK;
		}
	}

	else
	{
		LOC_u8ReturnValue = E_NOT_OK;
	}

	return LOC_u8ReturnValue;
}

/*********************************************************************************************
 *\Syntax		   : STD_Type MCAL_DIO_u8GetPortValue(u8 LOC_u8PortId, u8 *LOC_pu8PortStatus)
 *\Description	   : This function gets the value of DIO_PIN
 *\Sync\Async      : Synchronous
 *\Reentrancy      : Non Reentrant
 *\Parameters (in) : LOC_u8PortId       (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
 *					 *LOC_pu8PortStatus (HIGH, LOW)
 *\Parameters (out): None
 *\Return value    : LOC_u8ReturnValue  E_OK
 *							 			E_NOT_OK
 **********************************************************************************************/

STD_Type MCAL_DIO_u8GetPortValue(u8 LOC_u8PortId, u8 *LOC_pu8PortStatus)
{
	u8 LOC_u8ReturnValue = E_NOT_OK;

	if (LOC_u8PortId <= DIO_PORT_NO)
	{
		switch(LOC_u8PortId)
		{
			case DIO_PORTA: *LOC_pu8PortStatus= PINA;
				LOC_u8ReturnValue = E_OK;
				break;
			case DIO_PORTB: *LOC_pu8PortStatus= PINB;
				LOC_u8ReturnValue = E_OK;
				break;
			case DIO_PORTC: *LOC_pu8PortStatus= PINC;
				LOC_u8ReturnValue = E_OK;
				break;
			case DIO_PORTD: *LOC_pu8PortStatus= PIND;
				LOC_u8ReturnValue = E_OK;
				break;
			default: LOC_u8ReturnValue = E_NOT_OK;
		}
	}

	else
	{
		LOC_u8ReturnValue = E_NOT_OK;
	}

	return LOC_u8ReturnValue;
}

//***********************************PIN FUNCTIONS*******************************************

/*********************************************************************************************
 *\Syntax		   : STD_Type MCAL_DIO_u8SetPinDirection(u8 LOC_u8PortId, u8 LOC_u8PinId, u8 LOC_u8PinDirection)
 *\Description	   : This function sets the direction of DIO_Pin
 *\Sync\Async      : Synchronous
 *\Reentrancy      : Non Reentrant
 *\Parameters (in) : LOC_u8PortId  (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
 *					 LOC_u8PinId   (DIO_PIN 0:7)
 *					 LOC_u8PinDirection (DIO_PIN_INPUT, DIO_PIN_OUTPUT)
 *\Parameters (out): None
 *\Return value    : LOC_u8ReturnValue  E_OK
 *							 			E_NOT_OK
 **********************************************************************************************/

STD_Type MCAL_DIO_u8SetPinDirection(u8 LOC_u8PortId, u8 LOC_u8PinId, u8 LOC_u8PinDirection)
{
	u8 LOC_u8ReturnValue = E_NOT_OK;

	if ( (LOC_u8PortId <= DIO_PORT_NO) && (LOC_u8PinId <= DIO_PIN_NO) )
	{
		if (LOC_u8PinDirection == DIO_PIN_OUTPUT)
		{
			switch(LOC_u8PortId)
			{
				case DIO_PORTA: SET_BIT(DDRA,LOC_u8PinId);
					LOC_u8ReturnValue = E_OK;
					break;
				case DIO_PORTB: SET_BIT(DDRB,LOC_u8PinId);
					LOC_u8ReturnValue = E_OK;
					break;
				case DIO_PORTC: SET_BIT(DDRC,LOC_u8PinId);
					LOC_u8ReturnValue = E_OK;
					break;
				case DIO_PORTD: SET_BIT(DDRD,LOC_u8PinId);
					LOC_u8ReturnValue = E_OK;
					break;
				default: LOC_u8ReturnValue = E_NOT_OK;
			}
		}

		else if (LOC_u8PinDirection == DIO_PIN_INPUT)
		{
			switch(LOC_u8PortId)
			{
				case DIO_PORTA: CLR_BIT(DDRA,LOC_u8PinId);
					LOC_u8ReturnValue = E_OK;
					break;
				case DIO_PORTB: CLR_BIT(DDRB,LOC_u8PinId);
					LOC_u8ReturnValue = E_OK;
					break;
				case DIO_PORTC: CLR_BIT(DDRC,LOC_u8PinId);
					LOC_u8ReturnValue = E_OK;
					break;
				case DIO_PORTD: CLR_BIT(DDRD,LOC_u8PinId);
					LOC_u8ReturnValue = E_OK;
					break;
				default: LOC_u8ReturnValue = E_NOT_OK;
			}
		}

		else
		{
			LOC_u8ReturnValue = E_NOT_OK;
		}
	}

	else
	{
		LOC_u8ReturnValue = E_NOT_OK;
	}

	return LOC_u8ReturnValue;
}

/*********************************************************************************************
 *\Syntax		   : STD_Type MCAL_DIO_u8SetPinDirection(u8 LOC_u8PortId, u8 LOC_u8PinId, u8 LOC_u8PinDirection)
 *\Description	   : This function sets the value of DIO_Pin
 *\Sync\Async      : Synchronous
 *\Reentrancy      : Non Reentrant
 *\Parameters (in) : LOC_u8PortId  (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
 *					 LOC_u8PinId   (DIO_PIN 0:7)
 *					 LOC_u8PinValue (DIO_PIN_HIGH, DIO_PIN_LOW)
 *\Parameters (out): None
 *\Return value    : LOC_u8ReturnValue  E_OK
 *							 			E_NOT_OK
 **********************************************************************************************/

STD_Type MCAL_DIO_u8SetPinValue(u8 LOC_u8PortId, u8 LOC_u8PinId, u8 LOC_u8PinValue)
{
	u8 LOC_u8ReturnValue = E_NOT_OK;

	if ( (LOC_u8PortId <= DIO_PORT_NO) && (LOC_u8PinId <= DIO_PIN_NO) )
	{
		if (LOC_u8PinValue == DIO_PIN_HIGH)
		{
			switch(LOC_u8PortId)
			{
				case DIO_PORTA: SET_BIT(PORTA, LOC_u8PinId);
					LOC_u8ReturnValue = E_OK;
					break;
				case DIO_PORTB: SET_BIT(PORTB, LOC_u8PinId);
					LOC_u8ReturnValue = E_OK;
					break;
				case DIO_PORTC: SET_BIT(PORTC, LOC_u8PinId);
					LOC_u8ReturnValue = E_OK;
					break;
				case DIO_PORTD: SET_BIT(PORTD, LOC_u8PinId);
					LOC_u8ReturnValue = E_OK;
					break;
				default:LOC_u8ReturnValue = E_NOT_OK;
			}
		}

		else if (LOC_u8PinValue == DIO_PIN_LOW)
		{
			switch(LOC_u8PortId)
			{
				case DIO_PORTA: CLR_BIT(PORTA,LOC_u8PinId);
					LOC_u8ReturnValue = E_OK;
					break;
				case DIO_PORTB: CLR_BIT(PORTB,LOC_u8PinId);
					LOC_u8ReturnValue = E_OK;
					break;
				case DIO_PORTC: CLR_BIT(PORTC,LOC_u8PinId);
					LOC_u8ReturnValue = E_OK;
					break;
				case DIO_PORTD: CLR_BIT(PORTD,LOC_u8PinId);
					LOC_u8ReturnValue = E_OK;
					break;
				default:LOC_u8ReturnValue = E_NOT_OK;
			}
		}

		else
		{
			LOC_u8ReturnValue = E_NOT_OK;
		}
	}

	else
	{
		LOC_u8ReturnValue = E_NOT_OK;
	}

	return LOC_u8ReturnValue;
}

/*********************************************************************************************
 *\Syntax		   : STD_RetType MCAL_DIO_stdTogglePinValue(u8 LOC_u8PortId, u8 LOC_u8PinId)
*\Description	   : This function toggles the value of DIO_Pin
 *\Sync\Async      : Synchronous
 *\Reentrancy      : Non Reentrant
 *\Parameters (in) : LOC_u8PortId  (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
 *					 LOC_u8PinId   (DIO_PIN 0:7)
 *\Parameters (out): None
 *\Return value    : LOC_u8ReturnValue  E_OK
 *							 			E_NOT_OK
 **********************************************************************************************/

STD_Type MCAL_DIO_u8TogglePinValue(u8 LOC_u8PortId, u8 LOC_u8PinId)
{
	u8 LOC_u8ReturnValue = E_NOT_OK;

	if ( (LOC_u8PortId <= DIO_PORT_NO) && (LOC_u8PinId <= DIO_PIN_NO) )
	{
		switch(LOC_u8PortId){
			case DIO_PORTA: TOG_BIT(PORTA,LOC_u8PinId);
				LOC_u8ReturnValue = E_OK;
				break;
			case DIO_PORTB: TOG_BIT(PORTB,LOC_u8PinId);
				LOC_u8ReturnValue = E_OK;
				break;
			case DIO_PORTC: TOG_BIT(PORTC,LOC_u8PinId);
				LOC_u8ReturnValue = E_OK;
				break;
			case DIO_PORTD: TOG_BIT(PORTD,LOC_u8PinId);
				LOC_u8ReturnValue = E_OK;
				break;
			default:LOC_u8ReturnValue = E_NOT_OK;
		}
	}

	else
	{
		LOC_u8ReturnValue = E_NOT_OK;
	}

	return LOC_u8ReturnValue;
}


/*********************************************************************************************
 *\Syntax		   : STD_Type MCAL_DIO_u8GetPinValue(u8 LOC_u8PortId, u8 LOC_u8PinId, u8 *LOC_u8PinStatus)
 *\Description	   : This function gets the value of DIO_Pin
 *\Sync\Async      : Synchronous
 *\Reentrancy      : Non Reentrant
 *\Parameters (in) : LOC_u8PortId  (DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
 *					 LOC_u8PinId   (DIO_PIN 0:7)
 *					 *LOC_pu8PinStatus (HIGH, LOW)
 *\Parameters (out): None
 *\Return value    : LOC_u8ReturnValue  E_OK
 *							 			E_NOT_OK
 **********************************************************************************************/

STD_Type MCAL_DIO_u8GetPinValue(u8 LOC_u8PortId, u8 LOC_u8PinId, u8 *LOC_pu8PinStatus)
{
	u8 LOC_u8ReturnValue = E_NOT_OK;

	if ( (LOC_u8PortId <= DIO_PORT_NO) && (LOC_u8PinId <= DIO_PIN_NO) )
	{
		switch(LOC_u8PortId)
		{
			case DIO_PORTA: *LOC_pu8PinStatus=GET_BIT(PINA,LOC_u8PinId);
				LOC_u8ReturnValue = E_OK;
				break;
			case DIO_PORTB: *LOC_pu8PinStatus=GET_BIT(PINB,LOC_u8PinId);
				LOC_u8ReturnValue = E_OK;
				break;
			case DIO_PORTC: *LOC_pu8PinStatus=GET_BIT(PINC,LOC_u8PinId);
				LOC_u8ReturnValue = E_OK;
				break;
			case DIO_PORTD: *LOC_pu8PinStatus=GET_BIT(PIND,LOC_u8PinId);
				LOC_u8ReturnValue = E_OK;
				break;
		default: LOC_u8ReturnValue = E_NOT_OK;
		}
	}

	else
	{
		LOC_u8ReturnValue = E_NOT_OK;
	}

	return LOC_u8ReturnValue;
}
