// main.c
// Runs on LM4F120/TM4C123
// Test main 


// this connection occurs in the USB debugging cable
// U0Rx (PA0) connected to serial port on PC
// U0Tx (PA1) connected to serial port on PC
// Ground connected ground in the USB cable

#include "UART.h"



int main(void){ unsigned long n;
  
  UART_Init();              // initialize UART
  
  UART_OutString("Welcome Here");
  while(1){
    UART_OutString("\n\rInput:");
    n = UART_InUDec();
    UART_OutString(" UART_OutUDec = ");
    UART_OutUDec(n);     
    UART_OutString(",  UART_OutDistance ~ ");
    UART_OutDistance(n); 
  }
}

