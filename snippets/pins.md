## Overview

When working with external devices, you specify the pin number by passing an number.

Example: 
```C++
#include "arduino.h"

...
  // somewhere in setup
  // OUTPUT is a constant defined in Arduino.h (or it's includes)
  // 2 is the number of the pin we're putting in output mode
  pinMode(2, OUTPUT);
...
```

Learn more about pins at [Arduino's website](https://www.arduino.cc/en/Tutorial/DigitalPins)

### Aliases
You should be able to use the following constants when working with the wemos:
* D0
* D1
* D2
* D3
* D4
* D5
* D6
* D7
* D8
* TX
* RX
* BUILTIN_LED *or* LED_BUILTIN (the same as D4)
* SDA (the same as D2)
* SLC (the same as D1)

Thus the previous example becomes: 
```C++
#include "arduino.h"

...
  // somewhere in setup
  // OUTPUT is a constant defined in Arduino.h (or it's includes)
  // 2 is the number of the pin we're putting in output mode
  pinMode(LED_OUTPUT, OUTPUT);
...
```

You can see the source file that defines them here: https://github.com/esp8266/Arduino/blob/master/variants/d1_mini/pins_arduino.h#L31-L47
