Purpose of this program is to use UART to show the data.
Output data in UART


Part a) You will write an I/O driver routine that outputs strings to the UART0 device. See the comments in the UART.h and UART.c for more detailed descriptions of how this UART_OutString function is to work.

Part b) You will write an I/O driver routine that outputs an unsigned decimal number to the UART0 device. See the comments in the UART.h and UART.c for more detailed descriptions of how these UART_ConvertUDec and UART_OutUDec functions are to work.

Parameter

UART       display

0          ″   0 ″

10         ″  10 ″

999        ″ 999 ″

1000       ″1000 ″

9999       ″9999 ″  

10000      ″**** ″
or more


Part c) Assume the system stores the integers 0 to 9999, but the values mean 0.000 to 9.999 cm. 
For example, in the software a variable might contain 1234, but that value actually means 1.234 cm. 


UART             display

0               ″0.000 cm″

1               ″0.001 cm″

999             ″0.999 cm″

1000            ″1.000 cm″

9999            ″9.999 cm″

10000 or more   ″*.*** cm″

Table 11.2. Specification for the UART_OutDistance function (do not display the quotes”).

