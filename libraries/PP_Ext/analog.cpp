/*
 * analog.cpp
 *
 *  Created on: 26.10.2013
 *      Author: marcpaul
 */

#include "analog.h"

// timer for sensors
// TODO: implement
HardwareTimer sens_timer(2);

// using mag3110 sensor
mag3110 mag;

/**
 * TODO
 * implement security
 */
void init_bt() {
	switchLED(0);
	Serial1.begin(115200);
	Serial1.print("ATE0\r\n");
	Serial1.print("AT+BTLNM=\"PPBF\"\r\n");
	//Serial1.print("AT+BTSEC=1\r\n");
	//Serial1.print("AT+BTPIN=\"1111\"\r\n");
	Serial1.print("AT+BTSRV=1\r\n");
}

void close_bt() {
	Serial1.flush();
	delay(200);
	Serial1.print("+++\r\n");
	delay(200);
	Serial1.end();
	switchLED(0);
}

void sensorTimer(int dev) {

	if (dev == 1) {
		mag.configMag();
		init_bt();
		sens_timer.pause();
		sens_timer.setPeriod(1000000);
		sens_timer.attachInterrupt(2, updateLegSensors);
		sens_timer.refresh();
		sens_timer.resume();
	} else if (dev == 2) {
		mag.configMag();
		init_bt();
		sens_timer.pause();
		sens_timer.setPeriod(1000000);
		sens_timer.attachInterrupt(2, updateAllSensors);
		sens_timer.refresh();
		sens_timer.resume();
	}
}

void stopSensorTimer() {
	sens_timer.pause();
	close_bt();
}

void updateLegSensors() {
	int x = mag.readx();
	int y = mag.ready();
	int z = mag.readz();
	int t = mag.readTemp();

	char xc[16];
	sprintf(xc, "%d", x);

	char yc[16];
	sprintf(yc, "%d", y);

	char zc[16];
	sprintf(zc, "%d", z);

	char tc[8];
	sprintf(tc, "%d", t);

	std::basic_string<char> magpos = "";

	magpos.append(xc);
	magpos.append(";");
	magpos.append(yc);
	magpos.append(";");
	magpos.append(zc);
	magpos.append(";");
	magpos.append(tc);

	Serial1.println(magpos.data()); // transfer data with bt
}

void updateAllSensors() {

	uint8_t temp = 0;
	uint8_t hum = 0;

	Wire.requestFrom(99, 2);

	if (Wire.available()) {
		temp = Wire.receive();
		hum = Wire.receive();
	}

	char tbuf[8];
	sprintf(tbuf, "%u", temp);

	char hbuf[8];
	sprintf(hbuf, "%u", hum);

	int x = mag.readx();
	int y = mag.ready();
	int z = mag.readz();
	int t = mag.readTemp();

	char xc[16];
	sprintf(xc, "%d", x);

	char yc[16];
	sprintf(yc, "%d", y);

	char zc[16];
	sprintf(zc, "%d", z);

	char tc[8];
	sprintf(tc, "%d", t);

	std::basic_string<char> magpos = "";

	magpos.append(xc);
	magpos.append(";");
	magpos.append(yc);
	magpos.append(";");
	magpos.append(zc);
	magpos.append(";");
	magpos.append(tc);
	magpos.append(";");
	magpos.append(tbuf);
	magpos.append(";");
	magpos.append(hbuf);

	Serial1.println(magpos.data()); // transfer data with bt
}

// communicating with MSP430G2553 microcontroller
void switchLED(int l) {
	switch (l) {
	case 0:
		Wire.beginTransmission(2);
		Wire.send(0);
		Wire.endTransmission();
		break;
	case 1:
		Wire.beginTransmission(2);
		Wire.send(1);
		Wire.endTransmission();
		break;
	case 2:
		Wire.beginTransmission(2);
		Wire.send(2);
		Wire.endTransmission();
		break;
	case 3:
		Wire.beginTransmission(2);
		Wire.send(3);
		Wire.endTransmission();
		break;
	case 4:
		Wire.beginTransmission(2);
		Wire.send(4);
		Wire.endTransmission();
		break;
	case 5:
		Wire.beginTransmission(2);
		Wire.send(5);
		Wire.endTransmission();
		break;
	case 6:
		Wire.beginTransmission(2);
		Wire.send(6);
		Wire.endTransmission();
		break;
	case 7:
		Wire.beginTransmission(2);
		Wire.send(7);
		Wire.endTransmission();
		break;
	case 8:
		Wire.beginTransmission(2);
		Wire.send(8);
		Wire.endTransmission();
		break;
	case 9:
		Wire.beginTransmission(2);
		Wire.send(9);
		Wire.endTransmission();
		break;
	}
}
