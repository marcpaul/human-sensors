#ifndef _LCD_3310_H
#define _LCD_3310_H

#ifdef __cplusplus
 extern "C" {
#endif

/* definitions */
#define SEND_CMD                   0
#define SEND_CHR                   1

#define LCD_X_RES                  84
#define LCD_Y_RES                  48

#define PIXEL_OFF                  0
#define PIXEL_ON                   1
#define PIXEL_XOR                  2

#define FONT_1X                    1
#define FONT_2X                    2

// this is the buffer size
#define LCD_CACHE_SIZE             ((LCD_X_RES * LCD_Y_RES) / 8)

void LCDInit(void);

void LCDSend(unsigned char data, unsigned char cd);

void LCDUpdate ( void );

void LCDClear(void);

void LCDPixel (unsigned char x, unsigned char y, unsigned char mode );

void LCDChrXY (unsigned char x, unsigned char y, unsigned char ch );

void LCDChrXYInverse (unsigned char x, unsigned char y, unsigned char ch );

void LCDContrast(unsigned char contrast);

void LCDStr(unsigned char row, const unsigned char *dataPtr, unsigned char inv);

void Delay(volatile unsigned long a);
void Delayc(volatile unsigned char a);

#ifdef __cplusplus
}
#endif

#endif // _LCD_3310_H
