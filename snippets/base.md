# Overview

Any code (or sketch in Arduino terms) you'd like to run on the Wemos must have at the very least, 3 things:

1. Import the arduino header file
2. Implement the setup function
3. Implement the loop function

So, with platformio, as long as you've specified your using the Wemos, the following is the minimal viable program:

```
#include <Arduino.h>

void setup(){}
void loop(){}

Note: This is different than using the arduino ide because that ide automagically includes the arduino header file for you (and a couple other things, like call the files .ino files instead of .cpp)
