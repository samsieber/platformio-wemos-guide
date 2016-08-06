# Introduction

This guide assumes you have a:
 * Wemos D1 Mini
 * USB to USB-micro cable
 * A computer
 
If you have those, you should be able to use this guide.

Note: This has only been tested on Mac. There might be deficiencies on other platforms.
# The guide

## Software Setup

You'll need a couple things to get started when getting started with a microprocessor: a serial driver, an IDE and the libraries.

### Serial Driver
The serial chip on the Wemos lets us upload a program to the ESP8266 via the usb-micro port. So we can't run programs until we get the proper serial driver.

The Wemos D1 Mini uses the CH340G serial chip (different from some other ESP8266 break-out boards). Here's a good reference page for installing the drivers: http://kig.re/2014/12/31/how-to-use-arduino-nano-mini-pro-with-CH340G-on-mac-osx-yosemite.html

### Platformio - IDE and Libs

After you install that you'll need the libraries and an IDE. This repo assumes you are using [Platformio], which provides both a library manager and IDE support. 

You can follow the official guide to install the Atom/Platformio variant:  http://docs.platformio.org/en/stable/ide/atom.html#python-interpreter  - just follow it through the third step (or until the quickstart section.)

While platformio does support other IDE's, and has decent docs for them, I tried Atom and found it suitable.

## Creating a project - Blink

You can continue on that page and follow the [quickstart guide](http://docs.platformio.org/en/stable/ide/atom.html#quick-start). 

Notes:
 * Make sure you select the Wemos as your board when creating the project
 * With the blink example, for the Wemos, LOW is actually on, and HIGH is actually off.
 * After creating the source file, you should be able to click on the right arrow in the left side bar - that's the upload button and will build and upload your code to the wemos (provided of course that the wemos is plugged in).
 
At this point, you should have a blinking led on your wemos, congratulations! :)

