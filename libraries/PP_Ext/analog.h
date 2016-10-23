/*
 * analog.h
 *
 *  Created on: 26.10.2013
 *      Author: marcpaul
 */

#ifndef ANALOG_H_
#define ANALOG_H_

#include <cstdio>
#include <timer.h>
#include <string.h>
#include <string>
#include <stdarg.h>
#include <PP_Ext/storage.h>
#include <PP_Ext/display.h>
#include <Wire/Wire.h>
#include <mag3110/mag3110.h>

void init_bt(); // init bluetooth
void close_bt(); // close bluetooth
void sensorTimer(int dev);
void stopSensorTimer();
void updateAllSensors(); // still in development
void updateLegSensors();

void switchLED(int l); // switch leds in front panel

#endif /* ANALOG_H_ */
