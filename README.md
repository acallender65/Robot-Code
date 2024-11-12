# Follow-the-line robot

Here are the pins:
 - pinMode(3, OUTPUT); // speed
-  pinMode(5, OUTPUT); // right wheels on/off
 - pinMode(6, OUTPUT); // left wheels on/off
 - pinMode(7, OUTPUT); // right wheels direction 
 - pinMode(8, OUTPUT); // left wheels direction 
 - pinMode(A0, INPUT); // RIGHT SENSOR
 - pinMode(A1, INPUT); // CENTRAL SENSOR
 - pinMode(A2, INPUT); // LEFT SENSOR


Here is the truth table for our robot:
| Right | Central | Left | Action |
| -- | -- | -- | -- |
| T | T | T | turn right (convention) |
| T | T | F | turn right (less) |
| T | F | T | ? |
| T | F | F | turn right (more) |
| F | T | T | turn left (less) |
| F | T | F | go straight |
| F | F | T | turn left (more) |
| F | F | F | spin in circles? |
