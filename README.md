# Follow-the-line robot

Here are the pins:
 - 3 - speed
-  5 - right wheels on/off
 - 6 - left wheels on/off
 - 7 - right wheels direction 
 - 8 - left wheels direction 
 - A0 - RIGHT SENSOR
 - A1 - CENTRAL SENSOR
 - A2 - LEFT SENSOR

Here is the truth table for our robot:
| Left | Central | Right | Situation | Action |
| -- | -- | -- | -- | -- |
| T | T | T | T-junction | Turn right (convention) |
| T | T | F | Left turn | Turn left (less) |
| T | F | T | ? | |
| T | F | F | Left turn | Turn left (more) |
| F | T | T | Right turn | Turn right (less) |
| F | T | F | Straight | Go straight |
| F | F | T | Right turn | Turn right (more) |
| F | F | F | ? | |
