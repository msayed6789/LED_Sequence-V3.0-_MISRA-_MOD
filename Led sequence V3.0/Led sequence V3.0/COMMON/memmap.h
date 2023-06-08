/*
 * memmap.h
 *
 * Created: 07/06/2023 10:11:03 ص
 *  Author: AIO
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

/*************************DIO*********************/
#define DDRA  (*(volatile unsigned char *)0x3A)
#define PORTA (*(volatile unsigned char *)0x3B)
#define PINA  (*(volatile unsigned char *)0x39)


#define DDRB  (*(volatile unsigned char *)0x37)
#define PORTB (*(volatile unsigned char *)0x38)
#define PINB  (*(volatile unsigned char *)0x36)


#define DDRD  (*(volatile unsigned char *)0x31)
#define PORTD (*(volatile unsigned char *)0x32)
#define PIND  (*(volatile unsigned char *)0x30)


#define DDRC  (*(volatile unsigned char *)0x34)
#define PORTC (*(volatile unsigned char *)0x35)
#define PINC  (*(volatile unsigned char *)0x33)


/*External Interrupt */
#define MCUCSR   (*(volatile unsigned char*)0x54)
#define ISC2 6

#define MCUCR   (*(volatile unsigned char*)0x55)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define GICR     (*(volatile unsigned char*)0x5B)
#define INT1 7
#define INT0 6
#define INT2 5

#define GIFR    (*(volatile unsigned char*)0x5A)
#define INTF1 7
#define INTF0 6
#define INTF2 5
/************************************************************************************************/
/* Timer 0 */
#define TCNT0   (*(volatile unsigned char*)0x52)
#define TCCR0   (*(volatile unsigned char*)0x53)
/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

#define TWCR    (*(volatile unsigned char*)0x56)
#define SPMCR   (*(volatile unsigned char*)0x57)
#define TIFR    (*(volatile unsigned char*)0x58)
#define TIMSK   (*(volatile unsigned char*)0x59)
/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

#define OCR0    (*(volatile unsigned char*)0x5C)
/****************************************************************************************************/

/* Interrupt vectors */
/* External Interrupt Request 0 */
#define INT0_vect			__vector_1
/* External Interrupt Request 1 */
#define INT1_vect			__vector_2
/* External Interrupt Request 2 */
#define INT2_vect			__vector_3
/* Timer/Counter0 Compare Match */
#define TIMER0_OC_vect		__vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect			__vector_11

/*interrupt functions*/

# define sei()  __asm__ __volatile__ ("sei" ::)
# define cli()  __asm__ __volatile__ ("cli" ::)

#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)



#endif /* MEMMAP_H_ */