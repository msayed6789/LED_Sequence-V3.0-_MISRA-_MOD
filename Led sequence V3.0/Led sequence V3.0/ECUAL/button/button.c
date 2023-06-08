

 #include "Button.h"
 
 
 
 bool_error_button_t Button_Init(button_init_st* button)
 {
	 bool_error_button_t state=button_DONE;
	 state=DIO_InitPin(button->pin,INPUT);
	 if (button->state==PULLDOWN_STATE)
	 {
		 state=DIO_WRitePin(button->pin,HIGH);
	 }
	 else if (button->state==PULLUP_STATE)
	 {
		 state=DIO_WRitePin(button->pin,LOW);
	 }
	 else
	 {
		 state=button_ERROR;
	 }
	 return state;
 }
 
 Button_Status Button_Check(button_init_st* button)
 {
	 Button_Status status=NotPressed;
	 switch (button->state)
	 {
		 case PULLDOWN_STATE:
			if(DIO_ReadPin(button->pin)==LOW)
			{
				while (!DIO_ReadPin(button->pin));
				status=Pressed;
			}
			else
			{
				status=NotPressed;
			} 
			break;
			case PULLUP_STATE:
			if(DIO_ReadPin(button->pin)==HIGH)
			{
				while (DIO_ReadPin(button->pin));
				status=Pressed;
			}
			else
			{
				status=NotPressed;
			}
			break;
	 }
	 return status; 
 }