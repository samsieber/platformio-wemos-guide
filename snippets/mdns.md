# Purpose 

The MDNS service allows a device to publish it's host name so that you don't have to know it's ip address to find it.

This should be built in.

## Usage

```C++
#include <ESP8266mDNS.h>

// Declaring globally
MDNSResponder mdns;

void setup(void){
  // I'm not sure what happens if you call this before the WiFi has been connected.
  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }
}
```

Now the device can be found at whatever WiFi.localIP() is, as well as "esp8266.local" - note that the method automatically appends the '.local'.
