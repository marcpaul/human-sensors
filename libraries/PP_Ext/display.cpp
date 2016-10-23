/*
 * display.cpp
 *
 *  Created on: 25.10.2013
 *      Author: marcpaul
 */

#include "display.h"
#include <string.h>

void initLCD() {
	LCDInit();
	LCDContrast(0x70);
}

void showLogo() {
	LCDStr(0, (unsigned char *) " _ \\_ \\_ ) __\\", 0);
	LCDStr(1, (unsigned char *) " __/__/_ \\ _\\ ", 0);
	LCDStr(2, (unsigned char *) "_\\ _\\ ___/_\\  ", 0);
	LCDStr(3, (unsigned char *) "", 0);
	LCDStr(4, (unsigned char *) "", 0);
	LCDStr(5, (unsigned char *) "", 0);
}

void showMsg(const char *msg, int inv) {
	LCDClear();
	LCDStr(0, (unsigned char *) msg, inv);
}

void appendMsg(int row, const char *msg, int inv) {
	LCDStr(row, (unsigned char *) msg, inv);
}

void updateLCD() {
	LCDUpdate();
}

void clearLCD() {
	LCDClear();
}
