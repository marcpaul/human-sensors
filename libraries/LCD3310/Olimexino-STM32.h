#ifndef __OLIMEXINO_STM32_H
#define __OLIMEXINO_STM32_H

#ifdef __cplusplus
 extern "C" {
#endif

// LCD3310
#define PIN_LOW(PIN)   digitalWrite (PIN, 1)
#define PIN_HIGH(PIN)  digitalWrite (PIN, 0)

// RB10
#define LCD3310_RST_PORT   GPIOB
#define LCD3310_RST_PIN    (10)
#define LCD3310_RST_MASK   (1<<LCD3310_RST_PIN)
//#define	LCD3310_RST_DNUM   29
#define	LCD3310_RST_DNUM   26

// RB5
#define LCD3310_CS_PORT   GPIOB
#define LCD3310_CS_PIN    (5)
#define LCD3310_CS_MASK   (1<<LCD3310_CS_PIN)
//#define LCD3310_CS_DNUM   4
#define LCD3310_CS_DNUM   37

// RB11
#define LCD3310_CD_PORT   GPIOB
#define LCD3310_CD_PIN    (11)
#define LCD3310_CD_MASK   (1<<LCD3310_CD_PIN)
//#define LCD3310_CD_DNUM   30
#define LCD3310_CD_DNUM   27

// RA5
#define LCD3310_SCK_PORT   GPIOA
#define LCD3310_SCK_PIN    (5)
#define LCD3310_SCK_MASK   (1<<LCD3310_SCK_PIN)
//#define LCD3310_SCK_DNUM   13
#define LCD3310_SCK_DNUM   36

// RA7
#define LCD3310_MOSI_PORT   GPIOA
#define LCD3310_MOSI_PIN    (7)
#define LCD3310_MOSI_MASK   (1<<LCD3310_MOSI_PIN)
//#define LCD3310_MOSI_DNUM   11
#define LCD3310_MOSI_DNUM   35

#ifdef __cplusplus
}
#endif
  
#endif /* __OLIMEXINO_STM32_H */
