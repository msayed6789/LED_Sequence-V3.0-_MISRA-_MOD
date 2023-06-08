#include "exint.h"

/***************************Pointer to function for ISr************/
static void (*pf_INT0)(void)=NULLPTR;
static void (*pf_INT1)(void)=NULLPTR;
static void (*pf_INT2)(void)=NULLPTR;

/************************************Call back Function***********/
bool_error_exint_t EXI_SetCallBack(ExInterruptSource_type Interrupt,void(*pf)(void))
{
	bool_error_exint_t state=EXINT_DONE;
	switch (Interrupt)
	{
		case EX_INT0:
		pf_INT0 =pf;
		break;
		case EX_INT1:
		pf_INT1 =pf;
		break;
		case EX_INT2:
		pf_INT2 =pf;
		break;
		default:
		state=EXINT_ERROR;
	}
	return state;
}



/*****************Enable/Disable/Trigger Interrupt Functions*******/

bool_error_exint_t EXI_Enable (ExInterruptSource_type Interrupt)
{
	bool_error_exint_t state=EXINT_DONE;
	switch (Interrupt)
	{
		case EX_INT0:
		Set_Bit(GICR,INT0);
		break;
		case EX_INT1:
		Set_Bit(GICR,INT1);
		break;
		case EX_INT2:
		Set_Bit(GICR,INT2);
		break;
		default:
		state=EXINT_ERROR;
	}
	return state;
}
bool_error_exint_t EXI_Disable (ExInterruptSource_type Interrupt)
{
	bool_error_exint_t state=EXINT_DONE;
	switch (Interrupt)
	{
		case EX_INT0:
		CLR_Bit(GICR,INT0);
		break;
		case EX_INT1:
		CLR_Bit(GICR,INT1);
		break;
		case EX_INT2:
		CLR_Bit(GICR,INT2);
		break;
		default:
		state=EXINT_ERROR;
	}
	return state;
}
bool_error_exint_t EXI_Trigger(ExInterruptSource_type Interrupt,TriggerEdge_type trigger)
{
	bool_error_exint_t state=EXINT_DONE;
	if (Interrupt!=EX_INT2)
	{
		switch(trigger)
		{
			case LOW_LEVEL:
			if (Interrupt==EX_INT0)
			{
				CLR_Bit (MCUCR,ISC00);
				CLR_Bit (MCUCR,ISC01);
			}
			else if (Interrupt==EX_INT1)
			{
				CLR_Bit (MCUCR,ISC10);
				CLR_Bit (MCUCR,ISC11);
			}
			else
			{
				state=EXINT_ERROR;
			}
			break;
			case ANY_LOGIC_CHANGE:
			if (Interrupt==EX_INT1)
			{
				CLR_Bit (MCUCR,ISC11);
				Set_Bit (MCUCR,ISC10);
			}
			else if (Interrupt==EX_INT0)
			{
				CLR_Bit (MCUCR,ISC01);
				Set_Bit (MCUCR,ISC00);
			}
			else
			{
				state=EXINT_ERROR;
			}
			break;
			case FALLING_EDGE:
			if (Interrupt==EX_INT1)
			{
				Set_Bit (MCUCR,ISC11);
				CLR_Bit (MCUCR,ISC10);
			}
			else if (Interrupt==EX_INT0)
			{
				Set_Bit (MCUCR,ISC01);
				CLR_Bit (MCUCR,ISC00);
			}
			else
			{
				state=EXINT_ERROR;
			}
			break;
			case RISING_EDGE:
			if (Interrupt==EX_INT1)
			{
				Set_Bit (MCUCR,ISC11);
				Set_Bit (MCUCR,ISC10);
			}
			else if (Interrupt==EX_INT0)
			{
				Set_Bit (MCUCR,ISC01);
				Set_Bit (MCUCR,ISC00);
			}
			else
			{
				state=EXINT_ERROR;
			}
			break;
			default:
			state=EXINT_ERROR;
		}
	}
	else
	{
		switch(trigger)
		{
			case FALLING_EDGE:
			CLR_Bit (MCUCSR,ISC2);
			break;
			case RISING_EDGE:
			Set_Bit (MCUCSR,ISC2);
			break;
			default:
			CLR_Bit (MCUCSR,ISC2);
			state=EXINT_ERROR;
		}
		
	}
	return state;
}

ISR (INT0_vect)
{
	if (pf_INT0!=NULLPTR)
	{
		pf_INT0();
	}
}

ISR (INT1_vect)
{
	if (pf_INT1!=NULLPTR)
	{
		pf_INT1();
	}
}

ISR (INT2_vect)
{
	if (pf_INT2!=NULLPTR)
	{
		pf_INT2();
	}
}