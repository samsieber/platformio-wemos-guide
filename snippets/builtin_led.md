# Overview

The built-in LED can be accessed through a digital pin. The constant LED_BUILTIN refers to it.

# Usage

You must first set the pin to output mode, and then you can write a value to:
 * HIGH - off
 * LOW - on

Note that these are opposite from most built in LED's because the wemos uses a transistor to pull up the value by defualt. (I need to find where I read that).

##Example

In the loop, we put the LED on for 3 seconds, and then off for one.

```C++
#include <Arduino.h>

uint8_t LED_ON = LOW;
uint8_t LED_OFF = HIGH;

void setup(void){
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED, LED_OFF);
}

void loop(void){
  digitalWrite(BUILTIN_LED, LED_ON);
  delay(3000);
  digitalWrite(BUILTIN_LED, LED_OFF);
  delay(1000);
}
