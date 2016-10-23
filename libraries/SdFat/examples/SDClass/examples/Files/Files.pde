/*
  SD card basic file example
 
 This example shows how to create and destroy an SD card file 	
 The circuit:
 * SD card attached to SPI bus as follows:
	Refer to "libraries/SdFat/Sd2Card_config.h" 
 
 
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

File myFile;

// change this to match your SD shield or module;
const int chipSelect = SD_CHIP_SELECT_PIN;

void setup()
{
  Serial.begin(BPS_115200);
  PgmPrintln("Type any character to start");
  while (!Serial.available());
  Serial.print("Initializing SD card...");
  //pinMode(10, OUTPUT);

  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  if (SD.exists((char *)"example.txt")) {
    Serial.println("example.txt exists.");
  }
  else {
    Serial.println("example.txt doesn't exist.");
  }

  // open a new file and immediately close it:
  Serial.println("Creating example.txt...");
  myFile = SD.open("example.txt", FILE_WRITE);
  myFile.close();

  // Check to see if the file exists: 
  if (SD.exists((char *)"example.txt")) {
    Serial.println("example.txt exists.");
  }
  else {
    Serial.println("example.txt doesn't exist.");  
  }

  // delete the file:
  Serial.println("Removing example.txt...");
  SD.remove((char *)"example.txt");

  if (SD.exists((char *)"example.txt")){ 
    Serial.println("example.txt exists.");
  }
  else {
    Serial.println("example.txt doesn't exist.");  
  }
}

void loop()
{
  // nothing happens after setup finishes.
}



