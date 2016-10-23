/*
#include <FatStructs.h>
#include <Sd2Card.h>
#include <Sd2PinMap.h>
#include <SdFatmainpage.h>
#include <SdFatUtil.h>
#include <SdInfo.h>
*/

#include <Ethernet.h>
#include <SdFat.h>

Sd2Card card;
SdVolume volume;
SdFile root;
SdFile file;

void setup() 
{
  Serial.begin(BPS_115200);
  Serial.println("> type any char to start");
  while (!Serial.available());
  Serial.println();

  if (!card.init(SPI_HALF_SPEED)) 
    Serial.println("> card.init failed");
  else
    Serial.println("> card.init passed");
//  spi.end();
  
  SD_SPI.begin(SPI_HIGH_CLOCK, MSBFIRST, 0);
  
  delay(100);
  
  // initialize a FAT volume
  if (!volume.init(&card,1)) 
    Serial.println("> volume.init failed");
  else
    Serial.println("> volume.init passed");
    
  // open the root directory
  if (!root.openRoot(&volume)) 
    Serial.println("> openRoot failed");
  else
    Serial.println("> openRoot passed");
    
  // open a file
  if (file.open(&root, "Read.txt", O_READ)) 
  {
    Serial.println("> Opened Read.txt");
    Serial.println("> Reading ...");
    Serial.println();
    for(int i=0; i<15; i++)
      Serial.print((char)file.read());
    Serial.println("");
  }
  else
  {
    Serial.println("file.open failed");
  }
  Serial.println();  
  Serial.println("> Reading remained data...");
  Serial.println();  
  int16_t n;
  uint8_t buf[7];// nothing special about 7, just a lucky number.
  while ((n = file.read(buf, sizeof(buf))) > 0) 
  {
    for (uint8_t i = 0; i < n; i++) 
      Serial.print((char)buf[i]);
  }
  /* easier way
  int16_t c;
  while ((c = file.read()) > 0) Serial.print((char)c);
  */
  file.close();
  Serial.println("\n> Done");
  SD_SPI.end();
  
}

void loop() 
{
}

