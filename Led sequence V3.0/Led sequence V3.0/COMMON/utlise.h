/*
 * utlise.h
 *
 * Created: 07/06/2023 10:11:47 ص
 *  Author: AIO
 */ 


#ifndef UTLISE_H_
#define UTLISE_H_

#define Read_Bit(reg,bit)         ((reg>>bit) & 1)
#define Set_Bit(reg,bit)          (reg|=1<<bit)
#define CLR_Bit(reg,bit)          (reg&=~(1<<bit))
#define TOG_BIT(reg,bit)          (reg=reg^(1<<bit))



#endif /* UTLISE_H_ */