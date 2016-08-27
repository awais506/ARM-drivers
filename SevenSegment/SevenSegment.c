// ***** 0. Documentation Section *****
// SevenSegment.c 
// Runs on LM4F120/TM4C123
// Use  programming structures in C Run on a  Seven Segment and Button
//      Name:       Counter
//      Descrption: As you press button, it will count and show numbers 0-9
//      Date:       Feb 11, 2016
//      Student:    Muhammad Awais 2012-EE-506
//      Class:      UTAustinX: UT.6.03x Embedded Systems - Shape the World 

// ***** 1. Pre-processor Directives Section *****

#include "tm4c123gh6pm.h"
//Bit specfic adressing for PE0 and PE1 
//base adress of PORTE is 0x40024000
#define SW_PE0   (*((volatile unsigned long *)0x40024004))

// ***** 2. Global Declarations Section *****

// FUNCTION PROTOTYPES: Each subroutine defined
void PORTE_Init(void);
void SevenSeg_Init(void);
void clear7Seg(void);
void SevenSegment(int data);
void Delay1ms(unsigned long msec);


// ***** 3. Subroutines Section *****
//GPIO_PORTE_DATA_R
//GPIO_PORTB_DATA_R
// PE0 connected to positive logic momentary switch using 10k ohm pull down resistor
// PB1-PB7 connected to Common Anode Seven Segment
int main(void){ 
//**********************************************************************
// The following version tests input on PE0 and output on PE1
//**********************************************************************
  int count=0;
	PORTE_Init();      // Initlizes PORTE for switch
	SevenSeg_Init();   // Initlizes PORTB for Seven Segment
  SevenSegment(0);   // Seven Segment is showing 0 on reset
  while(1)           //Infinte loop
		{ 
		
			/*
			For Simple Counter Without Button
			for(count;count<=9;count++)
			{
			SevenSegment(count);
				Delay1ms(1000);
				clear7Seg();
			}
			*/
		if (count>9)      						//When count=9 it makes it zero
		{
			count=0;
			SevenSegment(count);
		}
		
		if(SW_PE0==0x01)  						//If switch is presses
		{
			count=count+1; 				 			//incremetn counter
			clear7Seg();								//Clears seven segment to write new data
			SevenSegment(count);				//Writes number on Seven Segment
			Delay1ms(100);              //Dealy for button debouncing and other factors

		}
		
  }
  
}

/*
Descrption: Initilizes PE0==>Input 
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
  GPIO_PORTE_AFSEL_R &= 0x00;        // 5) no alternate function       
  GPIO_PORTE_DEN_R |= 0x01;          // 6) enable digital pins PE4-PE1

}

/*
Descrption: Initilizes PB1 to PB7 as output
Input: None
Output: None
*/
void SevenSeg_Init(void)
{
  volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000002;      // 1) B clock
  delay = SYSCTL_RCGC2_R;            // delay to allow clock to stabilize     
  GPIO_PORTB_AMSEL_R &= 0x00;        // 2) disable analog function
  GPIO_PORTB_PCTL_R &= 0x00000000;   // 3) GPIO clear bit PCTL  
  GPIO_PORTB_DIR_R |= 0xFF;          // 4) PB output  
  GPIO_PORTB_AFSEL_R &= 0x00;        // 5) no alternate function       
  GPIO_PORTB_DEN_R |= 0xFF;          // 6) enable digital AT PB

}

/*
Descrption: Clears all 1-7 pins of PortB
Input: None
Output: None
*/
void clear7Seg()
{
	GPIO_PORTB_DATA_R=0xff;
}

/*
Descrption: All the pins who will show number on Seven Segment will be zero 
It is for common anode type, to make it for common cathode add ~ before all cases
Input: Number to be printed on Seven Segment
Output: None
*/

void SevenSegment(int data){

	switch(data)
	{
		case 0: GPIO_PORTB_DATA_R=0x11  ;
		break;
	  case 1: GPIO_PORTB_DATA_R=0x7D;
		break;
		case 2: GPIO_PORTB_DATA_R=0x89;
		break;
		case 3: GPIO_PORTB_DATA_R=0x29;
		break;
		case 4: GPIO_PORTB_DATA_R=0x65;
		break;
		case 5: GPIO_PORTB_DATA_R=0x23;
		break;
		case 6: GPIO_PORTB_DATA_R=0x03;
		break;
		case 7: GPIO_PORTB_DATA_R=0x79;
		break;
		case 8: GPIO_PORTB_DATA_R=0x01;
		break;
		case 9: GPIO_PORTB_DATA_R=0x21;
		break;
	}

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
