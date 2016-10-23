#include "RTClock.h"

	RTClock::RTClock() {
		RTClock(RTCSEL_HSE, 0xf423);
	}

    RTClock::RTClock(rtc_clk_src src) {
		RTClock(src, 0);
	
	}//end RTC

	RTClock::RTClock(rtc_clk_src src, uint16 prescaler ) {
		switch (src) {
	
		case RTCSEL_LSE : {
			rtc_init(RTCSEL_LSE);//LSE should be 32768 Hz.
			if (prescaler != 0) rtc_set_prescaler_load(prescaler); //according to sheet clock/(prescaler + 1) = Hz
			else rtc_set_prescaler_load(0x7fff);
			break;
			}
		case RTCSEL_LSI : {
			rtc_init(RTCSEL_LSI);//LSI is around 40000 Hz (between 30000 and 60000).
			if (prescaler != 0) rtc_set_prescaler_load(prescaler); //according to sheet clock/(prescaler + 1) = Hz 39999Hz = 0x9C3F
			else rtc_set_prescaler_load(0x9C3F);
			break;
			}
		case RTCSEL_HSE : {
			rtc_init(RTCSEL_HSE);//HSE = 8/128MHz = 62500 Hz
			if (prescaler != 0) rtc_set_prescaler_load(prescaler); //according to sheet clock/(prescaler + 1) = Hz 0xF423 = 62499
			else rtc_set_prescaler_load(0xF423);
			break;
			}
		case RTCSEL_DEFAULT: {
			//do nothing. Have a look at the clocks to see the diff between NONE and DEFAULT
			break;
			}
		case RTCSEL_NONE: {
			//do nothing. Have a look at the clocks to see the diff between NONE and DEFAULT
			break;
			}
		
		}//end switch
	}
	
	void RTClock::setTime (time_t time_stamp) {
		rtc_set_count(time_stamp);
	}
	
	void RTClock::setTime (struct tm* tm_ptr) {
		rtc_set_count(mktime (tm_ptr));
	}
	
	time_t RTClock::getTime() {
		return rtc_get_count();
	}
	
	struct tm*  RTClock::getTime(struct tm* tm_ptr) {
		time_t res = rtc_get_count();
		tm_ptr = gmtime(&res); //why not gmtime? 
		return tm_ptr;
	}
	
	void RTClock::createAlarm(voidFuncPtr function, time_t alarm_time_t) {
		rtc_set_alarm(alarm_time_t); //must be int... for standardization sake. 
		rtc_attach_interrupt(RTC_ALARM_SPECIFIC_INTERRUPT, function);
	}
	
	void RTClock::attachSecondsInterrupt(voidFuncPtr function) {
		rtc_attach_interrupt(RTC_SECONDS_INTERRUPT, function);
	}
	void RTClock::detachSecondsInterrupt() {
		rtc_detach_interrupt(RTC_SECONDS_INTERRUPT);
	}

	void RTClock::createAlarm(voidFuncPtr function, tm* alarm_tm) {
		time_t alarm = mktime(alarm_tm);//convert to time_t
		createAlarm(function, alarm);	
	}

//change alarm time	
	void RTClock::setAlarmTime (tm * tm_ptr) {
		time_t time = mktime(tm_ptr);//convert to time_t
		rtc_set_alarm(time); //must be int... for standardization sake. 
	}

	void RTClock::setAlarmTime (time_t alarm_time) {
		rtc_set_alarm(alarm_time);
	}

