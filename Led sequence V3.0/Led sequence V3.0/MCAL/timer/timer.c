
 #include "timer.h"
 /****************************************************Pointer to Function (Timer_0)************************************************/
 static void (*Timer0_OVF_Fptr) (void)=NULLPTR;
 static void (*Timer0_OCR0_Fptr) (void)=NULLPTR;

 /*********************************************************TIMER_0 Functions***********************************************/
 bool_error_timer_t Timer0_init (Timer0Mode_type mode)
 {
	 bool_error_timer_t state=TIMER_DONE;
	 //select the mode
	 switch (mode)
	 {
		 case TIMER0_NORMAL_MODE:
		 CLR_Bit(TCCR0,WGM00);
		 CLR_Bit(TCCR0,WGM01);
		 break;
		 case TIMER0_PHASECORRECT_MODE:
		 Set_Bit(TCCR0,WGM00);
		 CLR_Bit(TCCR0,WGM01);
		 break;
		 case TIMER0_CTC_MODE:
		 CLR_Bit(TCCR0,WGM00);
		 Set_Bit(TCCR0,WGM01);
		 break;
		 case TIMER0_FASTPWM_MODE:
		 Set_Bit(TCCR0,WGM00);
		 Set_Bit(TCCR0,WGM01);
		 break;
		 default:
		 state=TIMER_ERROR;
	 }
	return state; 
 }
 
 bool_error_timer_t Timer_Start(u8 scaler)
 {
	 bool_error_timer_t state=TIMER_DONE;
	 //select the prescaler
	 if (scaler<=5)
	 {
		  TCCR0&=0xf8;
		  TCCR0|=scaler;
	 }
	 else
	 {
		state=TIMER_ERROR; 
	 }
	 return state;
 }
 bool_error_timer_t TIMER0_OC0Mode(OC0Mode_type mode)
 {
	 bool_error_timer_t state=TIMER_DONE;
	 switch (mode)
	 {
		 case OC0_DISCONNECTED:
		 CLR_Bit(TCCR0,COM00);
		 CLR_Bit(TCCR0,COM01);
		 break;
		 case OC0_TOGGLE:
		 Set_Bit(TCCR0,COM00);
		 CLR_Bit(TCCR0,COM01);
		 break;
		 case OC0_NON_INVERTING:
		 CLR_Bit(TCCR0,COM00);
		 Set_Bit(TCCR0,COM01);
		 break;
		 case OC0_INVERTING:
		 Set_Bit(TCCR0,COM00);
		 Set_Bit(TCCR0,COM01);
		 break;
		 default:
		 state=TIMER_ERROR; 
	 }
	 return state;
 }
 
 void TIMER0_OV_InterruptEnable(void)
 {
	 Set_Bit(TIMSK,TOIE0);
 }
 
 void TIMER0_OV_InterruptDisable(void)
 {
	 CLR_Bit(TIMSK,TOIE0);
 }
 
 void TIMER0_OC_InterruptEnable(void)
 {
	 Set_Bit(TIMSK,OCIE0);
 }
 
 void TIMER0_OC_InterruptDisable(void)
 {
	 CLR_Bit(TIMSK,OCIE0);
 }
 
 bool_error_timer_t TIMER0_OV_SetCallBack(void(*local_fptr)(void))
 {
	 bool_error_timer_t state=TIMER_DONE;
	 if (local_fptr!=NULLPTR)
	 {
		  Timer0_OVF_Fptr=local_fptr;
	 }
	 else
	 {
		 state=TIMER_ERROR;
	 }
	return state;
 }
 
 bool_error_timer_t TIMER0_OCR_SetCallBack(void(*local_fptr)(void))
 {
	  bool_error_timer_t state=TIMER_DONE;
	  if (local_fptr!=NULLPTR)
  {
	 Timer0_OCR0_Fptr=local_fptr;
  }
  else
  {
	  state=TIMER_ERROR;
  }
  return state;
 }
 
 ISR (TIMER0_OC_vect)
 {
	 if (Timer0_OCR0_Fptr!=NULLPTR)
	 Timer0_OCR0_Fptr();
 }
 
 ISR (TIMER0_OVF_vect)
 {
	 if (Timer0_OVF_Fptr!=NULLPTR)
	 Timer0_OVF_Fptr();
 }