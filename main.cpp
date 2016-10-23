// must be first to avoid errors
#include <stdlib.h>

#include <PP_Ext/display.h>
#include <PP_Ext/storage.h>
#include <PP_Ext/analog.h>

#include <string.h>
#include <string>

#include <scb.h>
#include <pwr.h>

#include <Wire/Wire.h>
#include <ds1337/ds1337.h>

#define BUTTON_DELAY delay(300)	// debounce buttons

HardwareTimer lcd_timer(1); // timer to update lcd

int rotfunc = 0; // which function is chosen by rotary switch

byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;

int isBatLow = 1;

// show status of sd-card
void showSdStatus() {
	uint32_t p = (getFree() * 100) / getTotal();

	char buf[12];
	snprintf(buf, sizeof buf, "%lu", p);

	std::basic_string<char> s = "SD: ";
	s.append(buf);
	s.append(" % free");

	appendMsg(3, s.data(), 1);
}

// show free system ram
void showFreeRam() {
	uint32_t r = (FreeRam() * 100) / 20480;

	char rbuf[12];
	snprintf(rbuf, sizeof rbuf, "%lu", r);

	std::basic_string<char> sr = "RAM: ";
	sr.append(rbuf);
	sr.append(" % free");

	appendMsg(2, sr.data(), 1);
}

// update display with timer
void updateDisplay() {
	int rotval = analogRead(15);

	if (rotval > 3900) {
		appendMsg(4, "init bt       ", 0);
		rotfunc = 1;
	}
	if (rotval > 3500 && rotval < 3900) {
		appendMsg(4, "init sd-card  ", 0);
		rotfunc = 2;
	}
	if (rotval > 3100 && rotval < 3500) {
		appendMsg(4, "ext vcc on/off", 0);
		rotfunc = 3;
	}
	if (rotval > 2800 && rotval < 3100) {
		appendMsg(4, "leg sensors   ", 0);
		rotfunc = 4;
	}
	if (rotval > 2500 && rotval < 2800) {
		appendMsg(4, "all sensors   ", 0);
		rotfunc = 5;
	}
	if (rotval > 2000 && rotval < 2500) {
		appendMsg(4, "pos. 6        ", 0);
		rotfunc = 6;
	}
	if (rotval > 1600 && rotval < 2000) {
		appendMsg(4, "pos. 7        ", 0);
		rotfunc = 7;
	}
	if (rotval > 1200 && rotval < 1600) {
		appendMsg(4, "pos. 8        ", 0);
		rotfunc = 8;
	}
	if (rotval > 1000 && rotval < 1200) {
		appendMsg(4, "pos. 9        ", 0);
		rotfunc = 9;
	}
	if (rotval > 600 && rotval < 1000) {
		appendMsg(4, "pos. 10       ", 0);
		rotfunc = 10;
	}
	if (rotval > 200 && rotval < 600) {
		appendMsg(4, "pos. 11       ", 0);
		rotfunc = 11;
	}
	if (rotval < 200) {
		appendMsg(4, "pos. 12       ", 0);
		rotfunc = 12;
	}

	getDateDs1307(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);

	char* dow;

	switch (dayOfWeek) {
	case 1:
		dow = (char *) "SUN";
		break;
	case 2:
		dow = (char *) "MON";
		break;
	case 3:
		dow = (char *) "TUE";
		break;
	case 4:
		dow = (char *) "WED";
		break;
	case 5:
		dow = (char *) "THU";
		break;
	case 6:
		dow = (char *) "FRI";
		break;
	case 7:
		dow = (char *) "SAT";
		break;
	}

	char dom[8];

	sprintf(dom, "%.2d", dayOfMonth);

	char mon[8];

	sprintf(mon, "%.2d", month);

	char yea[8];

	sprintf(yea, "%.2d", year);

	std::basic_string<char> theDate = "";

	theDate.append(dow);
	theDate.append(" ");
	theDate.append(dom);
	theDate.append(".");
	theDate.append(mon);
	theDate.append(".");
	theDate.append(yea);

	appendMsg(0, theDate.data(), 0);

	char hou[8];

	sprintf(hou, "%.2d", hour);

	char min[8];

	sprintf(min, "%.2d", minute);

	char sec[8];

	sprintf(sec, "%.2d", second);

	std::basic_string<char> theTime = "";

	theTime.append(hou);
	theTime.append(":");
	theTime.append(min);
	theTime.append(":");
	theTime.append(sec);

	if (isBatLow) {
		theTime.append("  |||");
	} else {
		theTime.append("     ");
	}

	appendMsg(1, theTime.data(), 0);

	showFreeRam();
}

/**
 * 		update display
 * 		period = 10 seconds
 */
void setupTimer() {
	lcd_timer.pause();
	lcd_timer.setPeriod(1000000);
	lcd_timer.attachInterrupt(1, updateDisplay);
	lcd_timer.refresh();
	lcd_timer.resume();
}

void theLogo() {
	clearLCD();
	showLogo();
}

void setup() {

	pinMode(15, INPUT_ANALOG); // input from rotary switch

	pinMode(17, INPUT_ANALOG); // vcc of secondary battery

	pinMode(19, INPUT); // switch battery led and switch relais on pin 9
	pinMode(20, INPUT); // is battery low

	pinMode(0, INPUT); // ok button
	digitalWrite(0, LOW);

	pinMode(1, INPUT); // switch uext power (button)
	digitalWrite(1, LOW);

	pinMode(2, INPUT); // switch lcd leds (button)
	digitalWrite(2, LOW);

	pinMode(9, OUTPUT); // switch to bat power (relais)
	digitalWrite(9, LOW);

	pinMode(10, OUTPUT); // switch ext. power (relais)
	digitalWrite(10, LOW);

	pinMode(5, OUTPUT); // switch sensor power (relais)
	digitalWrite(5, LOW);

	pinMode(6, OUTPUT); // switch uext power (relais)
	digitalWrite(6, HIGH);

	delay(1000);

	initLCD(); // init lcd display

	theLogo(); // show logo for 3 sec.

	delay(3000);

	Wire.begin(); // init wire as master

	delay(500);

	switchLED(8); // all frontpanel leds OFF

	switchLED(4); // uext power led ON

	// initializing DS1307/DS1337
	second = 0;
	minute = 1;
	hour = 21;
	dayOfWeek = 3;
	dayOfMonth = 25;
	month = 2;
	year = 14;
	setDateDs1307(second, minute, hour, dayOfWeek, dayOfMonth, month, year);

	clearLCD(); // clear lcd

	setupTimer(); // setup display update timer

}

void loop() {

	/**
	 * OK button pressed
	 * determine position of rotary knob and start
	 */
	if (digitalRead(0) == HIGH) {

		switch (rotfunc) {
		case 1:
			// init bluetooth module
			init_bt();
			BUTTON_DELAY;
			break;
		case 2:
			// init sd-card and show status
			initSD();
			showSdStatus();
			BUTTON_DELAY;
			break;
		case 3:
			// switch ext. power on / off
			digitalWrite(10, digitalRead(10) ^ 1);
			switchLED(2);
			BUTTON_DELAY;
			break;
		case 4:
			// switch leg sensors on / off
			switchLED(5); // first switch LED
			if (digitalRead(5) == LOW) {
				digitalWrite(5, digitalRead(5) ^ 1); // apply power to i2c
				delay(500);
				switchLED(7); // open sda and scl
				delay(500);
				sensorTimer(1); // start timer
			} else {
				stopSensorTimer(); // stop timer
				delay(200);
				switchLED(7); // close sda and scl
				delay(200);
				digitalWrite(5, digitalRead(5) ^ 1); // cut power to i2c
			}
			BUTTON_DELAY;
			break;
		case 5:
			// switch all sensors on / off
			switchLED(5); // first switch LED
			if (digitalRead(5) == LOW) {
				digitalWrite(5, digitalRead(5) ^ 1); // apply power to i2c
				delay(500);
				switchLED(7); // open sda and scl
				delay(500);
				sensorTimer(1); // start timer
			} else {
				stopSensorTimer(); // stop timer
				delay(200);
				switchLED(7); // close sda and scl
				delay(200);
				digitalWrite(5, digitalRead(5) ^ 1); // cut power to i2c
			}
			BUTTON_DELAY;
			break;
		}

	}

	/**
	 * UEXT button pressed
	 * switch uext power and led off
	 * switch uext power, led on, init lcd display, setup timer for lcd display
	 */
	if (digitalRead(1) == HIGH) {
		if (digitalRead(6) == HIGH) {
			switchLED(4);
			lcd_timer.pause();
			digitalWrite(6, LOW);
			BUTTON_DELAY;
		} else if (digitalRead(6) == LOW) {
			digitalWrite(6, HIGH);
			switchLED(4);
			delay(500);
			initLCD();
			setupTimer(); // setup display update timer
			BUTTON_DELAY;
		}
	}

	// switch leds on lcd
	if (digitalRead(2) == HIGH) {
		switchLED(6);
		BUTTON_DELAY;
	}

	// switch led and relais (battery power)
	if (digitalRead(19) == LOW && analogRead(17) > 4000) {
		digitalWrite(9, HIGH);
		switchLED(3);
	}

	// is battery low
	if (digitalRead(20) == HIGH) {
		isBatLow = 0;
	}
}

// Force init to be called *first*, i.e. before static object allocation.
// Otherwise, statically allocated objects that need libmaple may fail.
__attribute__((constructor)) void premain() {
	init();
}

int main(void) {
	setup();

	while (true) {
		loop();
	}

	return 0;
}
