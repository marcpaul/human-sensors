#ifndef __SD2CARD_CONFIG_H__
#define __SD2CARD_CONFIG_H__

#include "wirish.h"

#define SD_SPI_NUMBER	2				/* Specify HardwareSPI number */

#if defined( BOARD_STM32VLD )
/* For STM32VLDicovery */
#define SD_CHIP_SELECT_PIN	PB(10)		/* for STM32VLDicovery SPI CS pin */
#define SPI_LOW_CLOCK	SPI_3MHZ		/* = SPI_HALF_SPEED */
#define SPI_HIGH_CLOCK	SPI_6MHZ		/* = SPI_FULL_SPEED */
#define Serial Serial1					/* Use real UART port */
#define BPS_4800	4800
#define BPS_9600	9600
#define BPS_115200	115200
#else
/* For other Maple families */
#define SD_CHIP_SELECT_PIN	25			/* for Olimexino-STM32 MMC CS/D25 pin */
//#define SPI_LOW_CLOCK	SPI_281_250KHZ	/* = SPI_HALF_SPEED */ 
#define SPI_LOW_CLOCK	SPI_4_5MHZ		/* = SPI_FULL_SPEED */
#define SPI_HIGH_CLOCK	SPI_9MHZ		/* = SPI_FULL_SPEED */
//#define SPI_HIGH_CLOCK	SPI_18MHZ		/* = SPI_FULL_SPEED */
#define Serial SerialUSB				/* Use USB CDC port */
#define BPS_4800	/* Nothing */ 
#define BPS_9600	/* Nothing */ 
#define BPS_115200 	/* Nothing */ 
#endif


#endif /* __SD2CARD_CONFIG_H__ */

