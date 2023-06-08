 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/dio/dio.h"

/***************************Button Configuration********************************/
typedef enum
{
	PULLUP_STATE,
	PULLDOWN_STATE
}button_state_en;

typedef struct
{
	u8                            pin;
	button_state_en              state;
}button_init_st;
/*******************************************************************************/
typedef enum{
	Pressed,
	NotPressed
}Button_Status;

typedef enum
{
	button_ERROR=0,
	button_DONE =1
}bool_error_button_t;

/**************************************Functions*************************************************/

bool_error_button_t Button_Init(button_init_st* button);

Button_Status Button_Check(button_init_st* button);




#endif /* BUTTON_H_ */