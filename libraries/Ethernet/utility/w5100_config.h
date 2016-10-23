#ifndef __W5100_PIN_CONFIG__
#define __W5100_PIN_CONFIG__

#include "wirish.h"

/* Define SPI port and chip select pin */
#define DEF_SPI_PORT		HardwareSPI SPI(2)
#define ETHERNET_SS_PIN		BOARD_SPI2_NSS_PIN 
#ifdef BOARD_STM32VLD
#define ETHERNET_SPI_FREQ	SPI_6MHZ 
#else
#	define ETHERNET_SPI_FREQ	SPI_4_5MHZ 
#endif

/* w5200/w5100 "nSCS" chip select pin config */
#define _initSS()			pinMode(      ETHERNET_SS_PIN, OUTPUT)
#define _setSS()			digitalWrite( ETHERNET_SS_PIN, 0 )
#define _resetSS()			digitalWrite( ETHERNET_SS_PIN, 1 ) 

#endif /* __W5100_PIN_CONFIG__ */

