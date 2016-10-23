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
 modified for Maple(STM32 micros)/libmaple
 17 Mar 2012
 by dinau	  
 
 This example code is in the public domain.
 	 
 */
#include <Ethernet.h>
#include <SD.h>

File root;

// change this to match your SD shield or module;
const int chipSelect = SD_CHIP_SELECT_PIN;

void printDirectory(File dir, int numTabs); /* Forward definition */

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

  root = SD.open("/");
  
  printDirectory(root, 0);
  
  Serial.println("done!");
}

void loop()
{
  // nothing happens after setup finishes.
}

void printDirectory(File dir, int numTabs) {
   while(true) {
     
     File entry =  dir.openNextFile();
     if (! entry) {
       // no more files
       //Serial.println("**nomorefiles**");
       break;
     }
     for (uint8_t i=0; i<numTabs; i++) {
       Serial.print('\t');
     }
     Serial.print(entry.name());
     if (entry.isDirectory()) {
       Serial.println("/");
       printDirectory(entry, numTabs+1);
     } else {
       // files have sizes, directories do not
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC);
     }
     entry.close();
   }
}

