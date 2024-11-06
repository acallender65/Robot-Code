# Follow-the-line robot

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
