/*
  SD card datalogger
 
 This example shows how to log data from three analog sensors 
 to an SD card using the SD library.
 	
 The circuit:
 * analog sensors on analog ins 0, 1, and 2
 * SD card attached to SPI bus as follows:
	Refer to "libraries/SdFat/Sd2Card_config.h" 
 
 created  24 Nov 2010
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
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  //pinMode(10, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
}

char dataString[100];
char sdata[10];
int lpcount=10;
void loop()
{
	if( lpcount-- == 0 ){ while(1); }

  // make a string for assembling the data to log:
  //String dataString = "";
	dataString[0]='\0';
  // read three sensors and append to the string:
  for (int analogPin = 0; analogPin < 3; analogPin++) {
    int sensor = analogRead(analogPin);
    //dataString += String(sensor);
	sprintf(sdata, "%d", sensor );
	strcat( dataString, sdata);
    if (analogPin < 2) {
      //dataString += ",";
	  strcat( dataString, ",");
    }
  }

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  } 
}









