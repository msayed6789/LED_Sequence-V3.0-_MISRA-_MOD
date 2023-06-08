
#ifndef DIO_H_
#define DIO_H_

#include "../../COMMON/memmap.h"
#include "../../COMMON/standard_type.h"
#include "../../COMMON/utlise.h"
/************************************************PINS***********************************************************************************************/
#define PINs_Total 32

   /*PortA*/
#define PINA0  0
#define PINA1  1
#define PINA2  2
#define PINA3  3
#define PINA4  4
#define PINA5  5
#define PINA6  6
#define PINA7  7

   /*PortB*/
 #define PINB0  8
 #define PINB1  9
 #define PINB2  10
 #define PINB3  11
 #define PINB4  12
 #define PINB5  13
 #define PINB6  14
 #define PINB7  15
 
   /*PortC*/
 #define PINC0  16
 #define PINC1  17
 #define PINC2  18
 #define PINC3  19
 #define PINC4  20
 #define PINC5  21
 #define PINC6  22
 #define PINC7  23
 
   /*PortD*/
 #define PIND0  24
 #define PIND1  25
 #define PIND2  26
 #define PIND3  27
 #define PIND4  28
 #define PIND5  29
 #define PIND6  30
 #define PIND7  31
/************************************************Enums********************************************************************************************/
typedef enum{
	OUTPUT,
	INFREE,
	INPUT
}PIN_Status;

typedef enum {
	PA,
	PB,
	PC,
	PD
}PORT_Type;

typedef enum {
	LOW=0,
	HIGH
}Voltage_type;

typedef enum
{
	DIO_ERROR=0,
	DIO_DONE=1
}bool_error_dio_t;

/***************************************************Functions**************************************************************************************/

bool_error_dio_t DIO_InitPin (u8 pin ,PIN_Status status );

void DIO_init (void);

bool_error_dio_t DIO_WRitePin (u8 pin ,Voltage_type s);

bool_error_dio_t DIO_WritePort(PORT_Type Port,u8 data);

Voltage_type DIO_ReadPin(u8 pin);






#endif /* DIO_H_ */