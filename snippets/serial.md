# Serial Interface Overview

The serial interface (the TX and RX pins) is how files are uploaded to the chip. 

The Wemos exposes this via USB-Mircro using the CH340G chip (part of the Wemos board)

If the Wemos is left connected to the computer, the serial port can be used to communicate with it in plain text, akin to telnet.

You can view the serial port communcations in the Atom/Platformio IDE by using the plug button on the left button bar, 3rd from the bottom.

# Usage

You have to initialize the serial port with a baud rate (bits per second). It is a static global class.

You can then send strings to the serial port. When trying to view the output from the monitor, make sure to pick the right baud rate.

In the following example, I'd have to open the serial monitor in the IDE with the 115200 rate.

```C++
#include <Arduino.h>

void setup(void){
  Serial.begin(115200);
}

// Send hello world through the serial port once a second.
void loop(void){
  delay(1000);
  Serial.print("Hello ");
  Serial.println("World!");
}
```

## ToDo

Explain serial input.
