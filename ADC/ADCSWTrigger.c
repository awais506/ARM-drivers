


#include "tm4c123gh6pm.h"

// This initialization function sets up the ADC according to the
// following parameters.  Any parameters not explicitly listed
// below are not modified:
// Max sample rate: <=125,000 samples/second
// Sequencer 0 priority: 1st (highest)
// Sequencer 1 priority: 2nd
// Sequencer 2 priority: 3rd
// Sequencer 3 priority: 4th (lowest)
// SS3 triggering event: software trigger
// SS3 1st sample source: Ain1 (PE2)
// SS3 interrupts: flag set on completion but no interrupt requested
void ADC0_InitSWTriggerSeq3_Ch1(int pinNo){
  //int pinNo=7;
	int i=0;
	volatile unsigned long delay;
	//for E port
	if(pinNo==0 || pinNo==1 || pinNo==2 || pinNo==3 || pinNo==8 ||pinNo==9 )
	{	
  SYSCTL_RCGC2_R |= 0x00000010;   // 1) activate clock for Port E
		delay = SYSCTL_RCGC2_R;         //    allow time for clock to stabilize
		switch(pinNo)
		{
			case 0:
    	GPIO_PORTE_DIR_R &= ~0x08;      // 2) make PE3 input
      GPIO_PORTE_AFSEL_R |= 0x08;     // 3) enable alternate function on PE3
      GPIO_PORTE_DEN_R &= ~0x08;      // 4) disable digital I/O on PE3
      GPIO_PORTE_AMSEL_R |= 0x08;     // 5) enable analog function on PE3
			break;
		  case 1:
    	GPIO_PORTE_DIR_R &= ~0x04;      // 2) make PE2 input
      GPIO_PORTE_AFSEL_R |= 0x04;     // 3) enable alternate function on PE2
      GPIO_PORTE_DEN_R &= ~0x04;      // 4) disable digital I/O on PE2
      GPIO_PORTE_AMSEL_R |= 0x04;     // 5) enable analog function on PE2
			break;
		  case 2:
    	GPIO_PORTE_DIR_R &= ~0x02;      // 2) make PE1 input
      GPIO_PORTE_AFSEL_R |= 0x02;     // 3) enable alternate function on PE1
      GPIO_PORTE_DEN_R &= ~0x02;      // 4) disable digital I/O on PE1
      GPIO_PORTE_AMSEL_R |= 0x02;     // 5) enable analog function on PE1
			break;
			case 3:
    	GPIO_PORTE_DIR_R &= ~0x01;      // 2) make PE0 input
      GPIO_PORTE_AFSEL_R |= 0x01;     // 3) enable alternate function on PE0
      GPIO_PORTE_DEN_R &= ~0x01;      // 4) disable digital I/O on PE0
      GPIO_PORTE_AMSEL_R |= 0x01;     // 5) enable analog function on PE0
			break;
			case 8:
    	GPIO_PORTE_DIR_R &= ~0x20;      // 2) make PE5 input
      GPIO_PORTE_AFSEL_R |= 0x20;     // 3) enable alternate function on PE5
      GPIO_PORTE_DEN_R &= ~0x20;      // 4) disable digital I/O on PE5
      GPIO_PORTE_AMSEL_R |= 0x20;     // 5) enable analog function on PE5
			break;
			case 9:
    	GPIO_PORTE_DIR_R &= ~0x10;      // 2) make PE4 input
      GPIO_PORTE_AFSEL_R |= 0x10;     // 3) enable alternate function on PE4
      GPIO_PORTE_DEN_R &= ~0x10;      // 4) disable digital I/O on PE4
      GPIO_PORTE_AMSEL_R |= 0x10;     // 5) enable analog function on PE4
			break;
		}
     }
	
		 //*****for port D********
	else if(pinNo==4 || pinNo==5 || pinNo==6 || pinNo==7  )
	{	
  SYSCTL_RCGC2_R |= 0x00000008;   // 1) activate clock for Port D
		switch(pinNo)
		{
			case 4:
    	GPIO_PORTD_DIR_R &= ~0x08;      // 2) make PD3 input
      GPIO_PORTD_AFSEL_R |= 0x08;     // 3) enable alternate function on PD3
      GPIO_PORTD_DEN_R &= ~0x08;      // 4) disable digital I/O on PD3
      GPIO_PORTD_AMSEL_R |= 0x08;     // 5) enable analog function on PD3
			break;
		  case 5:
    	GPIO_PORTD_DIR_R &= ~0x04;      // 2) make PD2 input
      GPIO_PORTD_AFSEL_R |= 0x04;     // 3) enable alternate function on PD2
      GPIO_PORTD_DEN_R &= ~0x04;      // 4) disable digital I/O on PD2
      GPIO_PORTD_AMSEL_R |= 0x04;     // 5) enable analog function on PD2
			break;
		  case 6:
    	GPIO_PORTD_DIR_R &= ~0x02;      // 2) make PD1 input
      GPIO_PORTD_AFSEL_R |= 0x02;     // 3) enable alternate function on PD1
      GPIO_PORTD_DEN_R &= ~0x02;      // 4) disable digital I/O on PD1
      GPIO_PORTD_AMSEL_R |= 0x02;     // 5) enable analog function on PD1
			break;
			case 7:
    	GPIO_PORTD_DIR_R &= ~0x01;      // 2) make PD0 input
      GPIO_PORTD_AFSEL_R |= 0x01;     // 3) enable alternate function on PD0
      GPIO_PORTD_DEN_R &= ~0x01;      // 4) disable digital I/O on PD0
      GPIO_PORTD_AMSEL_R |= 0x01;     // 5) enable analog function on PD0
			break;
		}
	  }
	
		//*******for port B********
	else if(pinNo==10 || pinNo==11  )
	{	
  SYSCTL_RCGC2_R |= 0x00000002;   // 1) activate clock for Port B
		switch(pinNo)
		{
		case 11:
    	GPIO_PORTB_DIR_R &= ~0x20;      // 2) make PB5 input
      GPIO_PORTB_AFSEL_R |= 0x20;     // 3) enable alternate function on PB5
      GPIO_PORTB_DEN_R &= ~0x20;      // 4) disable digital I/O on PB5
      GPIO_PORTB_AMSEL_R |= 0x20;     // 5) enable analog function on PB5
			break;
			case 10:
    	GPIO_PORTB_DIR_R &= ~0x10;      // 2) make PB4 input
      GPIO_PORTB_AFSEL_R |= 0x10;     // 3) enable alternate function on PB4
      GPIO_PORTB_DEN_R &= ~0x10;      // 4) disable digital I/O on PB4
      GPIO_PORTB_AMSEL_R |= 0x10;     // 5) enable analog function on PB4
			break;
		
		}
		
	  }
  
		
  SYSCTL_RCGC0_R |= 0x00010000;   // 6) activate ADC0 
  delay = SYSCTL_RCGC2_R;         
  SYSCTL_RCGC0_R &= ~0x00000300;  // 7) configure for 125K 
  ADC0_SSPRI_R = 0x0123;          // 8) Sequencer 3 is highest priority
  ADC0_ACTSS_R &= ~0x0008;        // 9) disable sample sequencer 3
  ADC0_EMUX_R &= ~0xF000;         // 10) seq3 is software trigger
		//For channel Number Selection
		for(i=0;i<=11;i++){
			if(i==pinNo){
      ADC0_SSMUX3_R = (ADC0_SSMUX3_R&0xFFFFFFF0)+i; // 11) channel Ain(i) 
				break;
			}
		}
  ADC0_SSCTL3_R = 0x0006;         // 12) no TS0 D0, yes IE0 END0
  ADC0_ACTSS_R |= 0x0008;         // 13) enable sample sequencer 3
}






//------------ADC0_InSeq3------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: 12-bit result of ADC conversion
unsigned long ADC0_InSeq3(int pinNo){ 

	unsigned long result;
  ADC0_PSSI_R = 0x0008;            // 1) initiate SS3
  while((ADC0_RIS_R&0x08)==0){};   // 2) wait for conversion done
  result = ADC0_SSFIFO3_R&0xFFF;   // 3) read result
  ADC0_ISC_R = 0x0008;             // 4) acknowledge completion
  return result;
}



unsigned long ADC2Voltage(int adcValue){ 

	unsigned long Voltage;
  Voltage=(3.3/4096)*adcValue;
  return Voltage;
}