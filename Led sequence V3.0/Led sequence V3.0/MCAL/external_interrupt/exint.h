


#ifndef EXINT_H_
#define EXINT_H_


#include "../../COMMON/memmap.h"
#include "../../COMMON/standard_type.h"
#include "../../COMMON/utlise.h"

typedef enum {
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}TriggerEdge_type;

typedef enum{
	EX_INT0,
	EX_INT1,
	EX_INT2,
}ExInterruptSource_type;


/**************************************************Error state**********************************************************************/
typedef enum
{
	EXINT_ERROR =0,
	EXINT_DONE  =1
}bool_error_exint_t;

/********************************************Functions************************************************************/

bool_error_exint_t EXI_Enable (ExInterruptSource_type Interrupt);

bool_error_exint_t EXI_Disable (ExInterruptSource_type Interrupt);

bool_error_exint_t EXI_Trigger(ExInterruptSource_type Interrupt,TriggerEdge_type trigger);

bool_error_exint_t EXI_SetCallBack(ExInterruptSource_type Interrupt,void(*pf)(void));



#endif /* EXINT_H_ */