This is SdFat library for Maple(STM32 micors) ported and derived from both
maple-sdfat ( http://code.google.com/p/maple-sdfat/downloads/list )
and Arduino1.0 SD class and File class.

You can use the primariy functions of SdFat and the wrapper functions as SD
class ported from Arduino1.0.

Prerequisite:
  You have to install the Ethernet library for Maple.
     https://bitbucket.org/dinau/ethernetmaple/downloads

Environment:
  MapleIDE v0.0.11, v0.0.12, libmaple-v0.0.12
  
Install:
  Unzip archives. Copy SdFat folder and Ethernet folder to "libraries" folder 
  in MapleIDE installed, then restart MapleIDE.

Configuration:
  To decide SPI port and change default settings, edit "libraies/SdFat/Sd2Card_config.h".
 
Usage:
   To open examples from menu,  File - Examples - SdFat, 
   you can complie and execute almost examples.

License:
  This library is under GPL3 same as maple-sdfat lib and Arduino1.0 SD Class and File class.
  Modified and porting, (C) Copyright 2012 dinau.
  http://avr.paslog.jp/article/2408032.html


by dinau 2012/03.

References:
  Maple STM32
  http://leaflabs.com/
  Arduino1.0
  http://arduino.cc/en/Main/Software
  maple-sdfat
  http://code.google.com/p/maple-sdfat/downloads/list 
  sdfatlib
  http://code.google.com/p/sdfatlib/




** SD - a slightly more friendly wrapper for sdfatlib **

This library aims to expose a subset of SD card functionality in the
form of a higher level "wrapper" object.

License: GNU General Public License V3
         (Because sdfatlib is licensed with this.)

(C) Copyright 2010 SparkFun Electronics

Now better than ever with optimization, multiple file support, directory handling, etc - ladyada!

