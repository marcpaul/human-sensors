/*
 * storage.cpp
 *
 *  Created on: 25.10.2013
 *      Author: marcpaul
 */

#include "storage.h"

Sd2Card card;
SdVolume volume;
SdFile root;
SdFile file;
uint32_t sectorSize;
uint32_t sdsize;

/**
 * TODO
 * maybe change name
 * the name of file on sd-card
 */
char name[] = "PPBF_00.TXT";

#ifdef __arm__
extern "C" char* sbrk(int incr);
#else  // __ARM__
extern char *__brkval;
extern char __bss_end;
#endif  // __arm__

int FreeRam() {
  char top;
#ifdef __arm__
  return &top - reinterpret_cast<char*>(sbrk(0));
#else  // __arm__
  return __brkval ? &top - __brkval : &top - &__bss_end;
#endif  // __arm__
}

int initSD() {
	switchLED(1);
	uint8_t r = card.init(SPI_FULL_SPEED);
	if (!r) {
		return false;
	}

	if (!volume.init(&card)) {
		return false;
	}
	if (!root.openRoot(&volume)) {
		return false;
	}
	return true;
}

uint32_t getTotal() {
	sdsize = (card.cardSize() / 1000) * 512;
	return sdsize;
}

uint32_t getFree() {
	uint32_t freeKB = ((volume.freeClusterCount() * volume.blocksPerCluster())
			/ 1000) * 512;
	return freeKB;
}

/**
 * TODO
 * check header
 * a little fun header for the file
 */
void writeHeader(const char *date) {

	file.println("@@@@@@@   @@@@@@@   @@@@@@@   @@@@@@@@");
	file.println("@@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@");
	file.println("@@!  @@@  @@!  @@@  @@!  @@@  @@!");
	file.println("!@!  @!@  !@!  @!@  !@   @!@  !@!");
	file.println("@!@@!@!   @!@@!@!   @!@!@!@   @!!!:!");
	file.println("!!@!!!    !!@!!!    !!!@!!!!  !!!!!:");
	file.println("!!:       !!:       !!:  !!!  !!:");
	file.println(":!:       :!:       :!:  !:!  :!:");
	file.println(" ::        ::        :: ::::   ::");
	file.println(" :         :        :: : ::    :");
	file.println("");
	file.println("");
	file.print(date);
	file.println("");
	file.println("");
}

char* openSDFile(const char *date) {

	for (uint8_t i = 0; i < 100; i++) {
		name[5] = i / 10 + '0';
		name[6] = i % 10 + '0';
		if (file.open(&root, name, O_CREAT | O_EXCL | O_WRITE))
			break;
	}

	if (file.isOpen()) {
		writeHeader(date);
	}
	return name;
}

uint8_t closeSDFile() {
	if (file.close()) {
		return 1;
	} else {
		return 0;
	}
}

void appendFile(const char *data) {
	file.println(data);
}

uint8_t isSD() {
	if (root.read() == -1) {
		return 0;
	} else {
		return 1;
	}
}
