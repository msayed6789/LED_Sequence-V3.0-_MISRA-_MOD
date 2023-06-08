


#ifndef TIMER_H_
#define TIMER_H_

#include "../../COMMON/memmap.h"
#include "../../COMMON/standard_type.h"
#include "../../COMMON/utlise.h"

/**************************************Timer_0************************************************************/

/*********************************Prescaler******************************************************************/
#define TIMER0_STOP                0
#define TIMER0_SCALER_1            1
#define TIMER0_SCALER_8            2
#define TIMER0_SCALER_64           3
#define TIMER0_SCALER_256          4
#define TIMER0_SCALER_1024         5

/**************************************************Enums*********************************************************/
typedef enum
{
	OC0_DISCONNECTED=0,
	OC0_TOGGLE,
	OC0_NON_INVERTING,
	OC0_INVERTING

}OC0Mode_type;

typedef enum {
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE
}Timer0Mode_type;

/**************************************************Error state**********************************************************************/
typedef enum
{
	TIMER_ERROR =0,
	TIMER_DONE  =1
}bool_error_timer_t;

/********************************************Functions************************************************************/

bool_error_timer_t Timer0_init (Timer0Mode_type mode);
bool_error_timer_t Timer_Start(u8 scaler);
bool_error_timer_t TIMER0_OC0Mode(OC0Mode_type mode);
void TIMER0_OV_InterruptEnable(void);
void TIMER0_OV_InterruptDisable(void);
void TIMER0_OC_InterruptEnable(void);
void TIMER0_OC_InterruptDisable(void);
bool_error_timer_t TIMER0_OV_SetCallBack(void(*local_fptr)(void));
bool_error_timer_t TIMER0_OCR_SetCallBack(void(*local_fptr)(void));

#define timer0_set(value)         TCNT0=value
#define timer0_OCR_set(value)     OCR0=value
#define timer0_stop()             TCCR0&=0xf8     //11111000




#endif /* TIMER_H_ */