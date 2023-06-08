
#ifndef LED_H_
#define LED_H_
#include "../../MCAL/dio/dio.h"
#include "../../MCAL/timer/timer.h"


/***************************LED Configuration******************************************************/
typedef enum
{
	ON_STATE,
	OFF_STATE
}led_state_en;

typedef struct
{
	u8                        pin;
	led_state_en              state;
}led_init_st;
/*************************************************************************************************/

/*****************************************Blank Configuration************************************************/
#define Max_noBlanks           5              //The Maximum number of blanks that you can use is 5
/*
Description the blank function:-
The CPU Frequency = 8MHz
The Prescaler = 256
The Minimum Blank Time = 8.2ms
The Maximum Blank Time = 2050ms
*/
/************************************************************************************************************/
typedef enum{
	blank_1=0,
	blank_2,
	blank_3,
	blank_4,
	blank_5
}Blank_Type;
typedef enum{
	Wrong_Time,
	Done
}Blank_Status;
/**************************************************Error state**********************************************************************/
typedef enum
{
	led_ERROR=0,
	led_DONE =1
}bool_error_led_t;

/***************************************************Functions****************************************/
bool_error_led_t LED_Init(led_init_st* led);

bool_error_led_t LED_ON (led_init_st* led);

bool_error_led_t LED_OFF (led_init_st* led);

Blank_Status LED_Blank_init(u32 Time_ON,u32 Time_Off,Blank_Type blank);

bool_error_led_t LED_Blank(Blank_Type Blank);

void LED_StopBlank(void);




#endif /* LED_H_ */