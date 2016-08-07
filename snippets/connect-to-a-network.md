# Overview

This covers how to get the ESP8266 to connect to a wireless network.

# Usage

The WiFi interface is a static global interface.

Steps:
 1. Attempt to a network, providing a password if necessary
 2. Wait for the connection to succeed.

## Connecting

When connecting you can provid an SSID only (the network name, unsecured) or an SSID and the password (WPA).

Connecting to an unsercured network
```C++
...
const char* ssid = "yourOpenWifiSSID"
...
  // later in setup()
  WiFi.begin(ssid);
...
```

Connecting to a secured network
```C++
...
  const char* ssid = "someWifiName";
  const char* password = "putYourPasswordHere";
...
  // later in setup()
  WiFi.begin(ssid, password);
...
````

## Waiting for success

Probably the easiest way to wait for success is to check the status in a loop after beginning the wifi:

```C++
  // In the setup loop, after calling WiFi.begin
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
```

Another way to check is to use the 'waitForConnectResult' method:
```C++
...
  if(WiFi.waitForConnectResult() != WL_CONNECTED){
      Serial.printf("Could not connect to %s\n", ssid);
  } else {
    //do stuff after success
  }
...
```
