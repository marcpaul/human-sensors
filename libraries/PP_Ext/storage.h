/*
 * storage.h
 *
 *  Created on: 25.10.2013
 *      Author: marcpaul
 */

#ifndef STORAGE_H_
#define STORAGE_H_

#include <Ethernet/Ethernet.h>
#include <SdFat/SD.h>
#include <SdFat/SdFat.h>
#include <SdFat/SdFatUtil.h>
#include <PP_Ext/analog.h>
#include <string>

int FreeRam();
int initSD();
uint32_t getTotal();
uint32_t getFree();
void writeHeader(const char *date);
char* openSDFile(const char *date);
uint8_t closeSDFile();
void appendFile(const char *data);
uint8_t isSD();

#endif /* STORAGE_H_ */
