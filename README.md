# Getting started with the Wemos D1 Mini using PlatformIO.

This repo holds examples and help for people getting started with the Wemos D1 mini. 

The rest of this readme covers how to get setup to run code on the wemos, and get a basic "BLINK" program running.

## Getting setup

You'll need a couple things to get started when getting started with a microprocessor: a serial driver, an IDE and the libraries.

Here's a good reference page for installing the drivers: http://kig.re/2014/12/31/how-to-use-arduino-nano-mini-pro-with-CH340G-on-mac-osx-yosemite.html - the serial driver is what allows us to upload the program to the chip, so you must have this installed to use the wemos. (*Note: other esp8266 variants might use a different serial chip, and thus use a different serial driver*).

After you install that you'll need the libraries and an IDE. This repo assumes you are using [Platformio], which provides both a library manager and IDE support. You can follow the official guide to install the Atom/Platformio variant:  http://docs.platformio.org/en/stable/ide/atom.html#python-interpreter  - just follow it through the third step (or until the quickstart section.)

## Creating a project - Blink

You can continue on that page and follow the [quickstart guide](http://docs.platformio.org/en/stable/ide/atom.html#quick-start). 

Notes:
 * Make sure you select the Wemos as your board when creating the project
 * With the blink example, for the Wemos, LOW is actually on, and HIGH is actually off.
 * After creating the source file, you should be able to click on the right arrow in the left side bar - that's the upload button and will build and upload your code to the wemos (provided of course that the wemos is plugged in).
 
At this point, you should have a blinking led on your wemos, congratulations! :)

