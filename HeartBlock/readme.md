
Heart Block 
Mock simulation of heart

Purpose of this program is to learn GPIO

Following is how it works
   a) Make the Ready signal go high
    b) Wait for AS to be 0, switch to be pressed
    c) Make the Ready signal go low
    d) Wait 10ms
    e) Wait for AS to be 1, switch to be released
    f) Wait 250ms
    g) Make the VT signal go high
    h) Wait 250ms
    i) Make the VT signal go low
