
This program implements data dumping for deubugging and monitioring of prgram.

It uses Systick timer for time stamps.


If both PF4 and PF0 switch are not pressed, the PF1 output should be low.
If either PF4 or PF0 switches is pressed, the output is inverted every 50 ms, making it oscillate at 10 Hz (±10%).
Information collected in the Data array matches the I/O on PortF.
50 data points are collected only on a change in input or a change in output. (i.e., no adjacent elements in the array are equal).
