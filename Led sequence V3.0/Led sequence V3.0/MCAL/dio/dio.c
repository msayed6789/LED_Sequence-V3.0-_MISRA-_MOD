

#include "dio.h"

#include "dio_private.h"


bool_error_dio_t DIO_InitPin (u8 pin ,PIN_Status status )
{
	bool_error_dio_t state=DIO_DONE;
	switch(status)
	{
		case OUTPUT:
		if(pin/8 == 0)
		{
			Set_Bit(DDRA,pin%8);
			CLR_Bit(PORTA,pin%8);
		}
		else if(pin/8 == 1)
		{
			Set_Bit(DDRB,pin%8);
			CLR_Bit(PORTB,pin%8);
		}
		else if(pin/8 == 2)
		{
			Set_Bit(DDRC,pin%8);
			CLR_Bit(PORTC,pin%8);
		}
		else if(pin/8 == 3)
		{
			Set_Bit(DDRD,pin%8);
			CLR_Bit(PORTD,pin%8);
		}
		else
		{
			state=DIO_ERROR;
		}
		break;
		case INFREE:
		if(pin/8 == 0)
		{
			CLR_Bit(DDRA,pin%8);
			CLR_Bit(PORTA,pin%8);
		}
		else if(pin/8 == 1)
		{
			CLR_Bit(DDRB,pin%8);
			CLR_Bit(PORTB,pin%8);
		}
		else if(pin/8 == 2)
		{
			CLR_Bit(DDRC,pin%8);
			CLR_Bit(PORTC,pin%8);
		}
		else if(pin/8 == 3)
		{
			CLR_Bit(DDRD,pin%8);
			CLR_Bit(PORTD,pin%8);
		}
		else
		{
			state=DIO_ERROR;
		}
		break;
		case INPUT:
		if(pin/8 == 0)
		{
			CLR_Bit(DDRA,pin%8);
			Set_Bit(PORTA,pin%8);
		}
		else if(pin/8 == 1)
		{
			CLR_Bit(DDRB,pin%8);
			Set_Bit(PORTB,pin%8);
		}
		else if(pin/8 == 2)
		{
			CLR_Bit(DDRC,pin%8);
			Set_Bit(PORTC,pin%8);
		}
		else if(pin/8 == 3)
		{
			CLR_Bit(DDRD,pin%8);
			Set_Bit(PORTD,pin%8);
		}
		else
		{
			state=DIO_ERROR;
		}
		break;
		default:
		state=DIO_ERROR;
	}
	return state;
}



void DIO_init (void)
{
	u8 pin;
	for (pin=PINA0;pin<PINs_Total;pin++)
	{
		DIO_InitPin (pin ,Pin_StatusArray[pin]);
	}
}



bool_error_dio_t DIO_WRitePin (u8 pin ,Voltage_type s)
{
	bool_error_dio_t state=DIO_DONE;
	switch (s)
	{
		case HIGH:
		if(pin/8 == 0)
		{
			Set_Bit (PORTA,pin%8);
		}
		else if(pin/8 == 1)
		{
			Set_Bit (PORTB,pin%8);
		}
		else if(pin/8 == 2)
		{
			Set_Bit (PORTC,pin%8);
		}
		else if(pin/8 == 3)
		{
			Set_Bit (PORTD,pin%8);
		}
		else
		{
			state=DIO_ERROR;
		}
		break;
		case LOW:
		if(pin/8 == 0)
		{
			CLR_Bit (PORTA,pin%8);
		}
		else if(pin/8 == 1)
		{
			CLR_Bit (PORTB,pin%8);
		}
		else if(pin/8 == 2)
		{
			CLR_Bit (PORTC,pin%8);
		}
		else if(pin/8 == 3)
		{
			CLR_Bit (PORTD,pin%8);
		}
		else
		{
			state=DIO_ERROR;
		}
		break;
		default:
		state=DIO_ERROR;
	}
	return state;
}

bool_error_dio_t DIO_WritePort(PORT_Type Port,u8 data)
{
	bool_error_dio_t state=DIO_DONE;
	switch (Port)
	{
		case PA:
		PORTA =data;
		break;
		case PB:
		PORTB =data;
		break;
		case PC:
		PORTC =data;
		break;
		case PD:
		PORTD =data;
		break;
		default:
		state=DIO_ERROR;
	}
	return state;
}

Voltage_type DIO_ReadPin(u8 pin)
{
	Voltage_type volt=LOW;
	if(pin/8 == 0)
	{
		volt=Read_Bit(PINA,pin%8);
	}
	else if(pin/8 == 1)
	{
		volt=Read_Bit(PINB,pin%8);
	}
	else if(pin/8 == 2)
	{
		volt=Read_Bit(PINC,pin%8);
	}
	else if(pin/8 == 3)
	{
		volt=Read_Bit(PIND,pin%8);
	}
	return volt;
	
}