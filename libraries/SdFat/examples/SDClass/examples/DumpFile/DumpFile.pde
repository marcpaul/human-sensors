/*
  SD card file dump
 
 This example shows how to read a file from the SD card using the
 SD library and send it over the serial port.
 	
 The circuit:
 * SD card attached to SPI bus as follows:
	Refer to "libraries/SdFat/Sd2Card_config.h" 
 
 created  22 December 2010
 
created   Nov 2010
 by David A. Mellis
 updated 2 Dec 2010
 by Tom Igoe
 	 
 This example code is in the public domain.
 modified for Maple(STM32 micros)/libmaple
 17 Mar 2012
 by dinau	 
 */

#include <Ethernet.h>
#include <SD.h>

// change this to match your SD shield or module;
const int chipSelect = SD_CHIP_SELECT_PIN;

void setup()
{
  Serial.begin(BPS_115200);
  PgmPrintln("Type any character to start");
  while (!Serial.available());
  Serial.print("Initializing SD card...");
  //pinMode(10, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt");

  // if the file is available, write to it:
  if (dataFile) {
    while (dataFile.available()) {
      Serial.write(dataFile.read());
    }
    dataFile.close();
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  } 
}

void loop()
{
}

