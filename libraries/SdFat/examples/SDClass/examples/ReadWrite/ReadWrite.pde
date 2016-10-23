/*
  SD card read/write
 
 This example shows how to read and write data to and from an SD card file 	
 The circuit:
 * SD card attached to SPI bus as follows:
	Refer to "libraries/SdFat/Sd2Card_config.h" 
 
 
 created   Nov 2010
 by David A. Mellis
 updated 2 Dec 2010
 by Tom Igoe
 modified for Maple(STM32 micros)/libmaple
 17 Mar 2012
 by dinau	  
 
 This example code is in the public domain.
 	 
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
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test.txt", FILE_WRITE);
  
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
	// close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  
  // re-open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");
    
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
    	Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
  	// if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void loop()
{
	// nothing happens after setup
}


