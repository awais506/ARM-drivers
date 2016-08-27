// ***** 0. Documentation Section *****
// SwitchLEDInterface.c 
// Runs on LM4F120/TM4C123
// Use simple programming structures in C to toggle an LED
// while a button is pressed and turn the LED on when the
//      Date:    Feb 11, 2016
//      Student: Muhammad Awais 2012-EE-506
//      Contact Info: Fb/awais12506
//      Class:   UTAustinX: UT.6.03x Embedded Systems - Shape the World 

// ***** 1. Pre-processor Directives Section *****

#include "tm4c123gh6pm.h"

//Bit specfic adressing for PE0 and PE1 
//base adress of PORTE is 0x40024000
#define SW_PE0   (*((volatile unsigned long *)0x40024004))
#define LED_PE1   (*((volatile unsigned long *)0x40024008))
// ***** 2. Global Declarations Section *****

// FUNCTION PROTOTYPES: Each subroutine defined
void PORTE_Init(void);
void Delay1ms(unsigned long msec);
// ***** 3. Subroutines Section *****
//GPIO_PORTE_DATA_R
// PE0, PB0, or PA2 connected to positive logic momentary switch using 10k ohm pull down resistor
// PE1, PB1, or PA3 connected to positive logic LED through 470 ohm current limiting resistor
int main(void){ 
//**********************************************************************
// The following version tests input on PE0 and output on PE1
//**********************************************************************
 
	PORTE_Init();      // Initlizes PORTE 
	LED_PE1=0x02;      //On LED connected at PE1
	Delay1ms(100);     // Delay 100ms
  while(1)           //Infinte loop
		{     
    
		if(SW_PE0==0x01)  //If switch is presses
		{
		LED_PE1^=0x02;    //Toggle LED 
			Delay1ms(100); 

		}
		else               //else Just on it
			LED_PE1=0x02;
		
  }
  
}


/*
Descrption: Initilizes PE0==>Input PE1==> Output
Input: None
Output: None
*/
void PORTE_Init(void)
{
  volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000010;      // 1) E clock
  delay = SYSCTL_RCGC2_R;            // delay to allow clock to stabilize     
  GPIO_PORTE_AMSEL_R &= 0x00;        // 2) disable analog function
  GPIO_PORTE_PCTL_R &= 0x00000000;   // 3) GPIO clear bit PCTL  
  GPIO_PORTE_DIR_R &= ~0x01;         // 4.1) PE0 input,
  GPIO_PORTE_DIR_R |= 0x02;          // 4.2) PE1 output  
  GPIO_PORTE_AFSEL_R &= 0x00;        // 5) no alternate function       
  GPIO_PORTE_DEN_R |= 0x03;          // 6) enable digital pins PE4-PE1

}

/*
Descrption: Uses time of a instruction to delay time
Almost 1ms for each cycle
Input: Number of ms to delay
Output: None
*/
void Delay1ms(unsigned long msec){
// write this function
	unsigned long i;
	
  while(msec > 0){
    i = 13333;  // this number means 1ms
    while(i > 0){
      i = i - 1;
    }
    msec = msec - 1; // decrements every 1 ms
  }

}
