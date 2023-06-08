

#include "App.h"
static void Blank_Change(void);
u32 Blank_typ[Max_noBlanks][2]={{100,900},{200,800},{300,700},{500,500},{900,100}};
volatile u8 Flag_ON=0;
volatile u8 Blank=blank_1;
u8 Press_count=0;
u8 LED1_Status=1;
u8 LED2_Status=0;
u8 LED3_Status=0;
u8 LED4_Status=0;

/*********************************Button Initalization*************************************************************************************/
button_init_st Button1=
{
	.pin        =PINC4,
	.state      =PULLDOWN_STATE
};

/*********************************Led Initalization*************************************************************************************/
led_init_st LED1=
{
	.pin              =PINB4,
	.state            =OFF_STATE
};
led_init_st LED2=
{
	.pin              =PINB5,
	.state            =OFF_STATE
};
led_init_st LED3=
{
	.pin              =PINB6,
	.state            =OFF_STATE
};
led_init_st LED4=
{
	.pin              =PINB7,
	.state            =OFF_STATE
};

void APP_Init()
{
	sei();
	LED_Init(&LED1);
	LED_Init(&LED2);
	LED_Init(&LED3);
	LED_Init(&LED4);
	Button_Init(&Button1);
	EXI_Trigger(EX_INT2,FALLING_EDGE);
	EXI_SetCallBack(EX_INT2,Blank_Change);
	EXI_Enable (EX_INT2);
	u8 i=0;
	for ( i=0;i<Max_noBlanks;i++)
	{
		LED_Blank_init(Blank_typ[i][0],Blank_typ[i][1],i);
	}
}
void APP_Start()
{
	if (Button_Check(&Button1)==Pressed)
	{
		Press_count+=1;
		if (Press_count==9)
		{
			Press_count=1;
		}
		else
		{
			//do nothing
		}
		if(Press_count==1)
		{
			LED_Blank(Blank);
		}
		else
		{
			//do nothing
		}
	}
	else
	{
		//do nothing
	}
	
	switch(Press_count)
	{
		case 1:
		LED1_Status=1;
		break;
		case 2:
		LED2_Status=1;
		break;
		case 3:
		LED3_Status=1;
		break;
		case 4:
		LED4_Status=1;
		break;
		case 5:
		LED_OFF(&LED1);
		LED1_Status=0;
		break;
		case 6:
		LED_OFF(&LED2);
		LED2_Status=0;
		break;
		case 7:
		LED_OFF(&LED3);
		LED3_Status=0;
		break;
		case 8:
		LED_OFF(&LED4);
		LED4_Status=0;
		//LED_StopBlank();
		break;
		default:
		//do nothing
		break;
	}
	if (LED1_Status==1)
	{
		if (Flag_ON==1)
		{
			LED_ON(&LED1);
		}
		else
		{
			LED_OFF(&LED1);
		}
	}
	else
	{
		//do nothing
	}
	if (LED2_Status==1)
	{
		if (Flag_ON==1)
		{
			LED_ON(&LED2);
		}
		else
		{
			LED_OFF(&LED2);
		}
	}
	else
	{
		//do nothing
	}
	if (LED3_Status==1)
	{
		if (Flag_ON==1)
		{
			LED_ON(&LED3);
		}
		else
		{
			LED_OFF(&LED3);
		}
	}
	else
	{
		//do nothing
	}
	if (LED4_Status==1)
	{
		if (Flag_ON==1)
		{
			LED_ON(&LED4);
		}
		else
		{
			LED_OFF(&LED4);
		}
	}
	else
	{
		//do nothing
	}
}

static void Blank_Change(void)
{
	static u8 B2_count=1;
	B2_count++;
	switch(B2_count)
	{
		case 2:
		Blank=blank_2;
		break;
		case 3:
		Blank=blank_3;
		break;
		case 4:
		Blank=blank_4;
		break;
		case 5:
		Blank=blank_5;
		break;
		case 6:
		Blank=blank_1;
		B2_count=1;
		break;
		default:
		// do nothing
		break;
	}
	if (Press_count!=8 && Press_count!=0 )
	{
		LED_Blank(Blank);
	}
	else
	{
		//do nothing
	}
}