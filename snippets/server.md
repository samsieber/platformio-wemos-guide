# Overview

The ESP8266 libraries include a basic web server.

# Basic Usage

The basic steps are:
 1. Import the library - ESP8266WebServer.h
 1. Create a web server
 2. Add handlers
 3. Start the server
 4. Process the server in the loop
 
## Example

```C++
#import <ESP8266WebServer.h>
ESP8266WebServer server(80);

void setup(void){
  server.on("/", [](){
    server.send(200, "text/plain", "Hello World");
  });
}

void loop(void){
  server.handleClient();
}
```

# Registering handlers

You can either declare a handler and pass the function, or you can declare the handler inline.

Inline:
```C++
...
 server.on("/inline", [](){
    server.send(200, "text/plain", "This is an inline handler");
  });
...
```

Externally:
```C++
...
void myHandler(){
  server.send(200, "text/plain", "This is an external handler");
}

...
  // inside setup()
  server.on("/external", myHandler);

...
```

# Reading / Writing the client

All reading and writing is done through the server object, since this is a sychronous implementation.


