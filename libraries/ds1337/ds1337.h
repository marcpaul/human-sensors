/*
 DS1337.h - library for DS1337 rtc
 */

// ensure this library description is only included once
#ifndef DS1337_h
#define DS1337_h

// include types & constants of Wire ic2 lib
#include <Wire/Wire.h>

#define DS1307_I2C_ADDRESS 0x68

byte decToBcd(byte val);
byte bcdToDec(byte val);
void setDateDs1307(byte second,        // 0-59
                   byte minute,        // 0-59
                   byte hour,          // 1-23
                   byte dayOfWeek,     // 1-7
                   byte dayOfMonth,    // 1-28/29/30/31
                   byte month,         // 1-12
                   byte year);
void getDateDs1307(byte *second,
          byte *minute,
          byte *hour,
          byte *dayOfWeek,
          byte *dayOfMonth,
          byte *month,
          byte *year);


#endif
