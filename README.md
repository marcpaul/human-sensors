# human-sensors
This was part of a project for a "dream study".
The device was battery powered so the patient could stay at home in his normal environment.
The data sampled could be written on sd-card or transfered via bluetooth.

Sensors included:
- 3-axis leg sensors
- ecg
- 8-channel eeg
- emg
- eog
- 3-axis accelerometer for general movement

Hardware setup:

- [Olimex Olimexino-STM32](https://www.olimex.com/Products/Duino/STM32/OLIMEXINO-STM32/open-source-hardware) board with STM32F103RBT6 microcontroller
- [Olimex MOD-MAG](https://www.olimex.com/Products/Modules/Sensors/MOD-MAG/open-source-hardware) 3-axis magnetometer MAG3110
- [Olimex MOD-LCD3310](https://www.olimex.com/Products/Modules/LCD/MOD-LCD3310/open-source-hardware) Nokia 3310 LCD
- [Olimex MOD-BT](https://www.olimex.com/Products/Modules/RF/MOD-BT/) bluetooth module
- [Olimex SHIELD-EKG-EMG](https://www.olimex.com/Products/Duino/Shields/SHIELD-EKG-EMG/open-source-hardware) ecg/emg shield for STM32 board
- [ti MSP430G2553](http://www.ti.com/product/msp430g2533)
- [Maxim DS1337](https://www.maximintegrated.com/en/products/digital/real-time-clocks/DS1337.html) real-time clock
- a bunch of standard electronic parts


Software:

- libmaple
- library for DS1337
- library for LCD3310
- library for MAG3110
- Ethernet and SdFat library
- library for MPU6050
