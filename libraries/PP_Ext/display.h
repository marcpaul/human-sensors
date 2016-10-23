/*
 * display.h
 *
 *  Created on: 25.10.2013
 *      Author: marcpaul
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

// using a simple nokia 3310 lcd
#include <LCD3310/lcd3310.h>

void initLCD();
void showLogo();
void showMsg(const char *msg, int inv);
void appendMsg(int row, const char *msg, int inv);
void updateLCD();
void clearLCD();

#endif /* DISPLAY_H_ */
