//MPU6050 I2C library for ARM STM32F103xx Microcontrollers - Header file has defines
// to choose I2C peripheral, speed & pins. 
// 23/05/2012 by Harinadha Reddy Chintalapalli <harinath.ec@gmail.com>
// Changelog:
//     2012-05-23 - initial release.
/* ============================================================================================
MPU6050 device I2C library code for ARM STM32F103xx is placed under the MIT license
Copyright (c) 2012 Harinadha Reddy Chintalapalli

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
================================================================================================
*/

/* Define to prevent recursive inclusion*/
#ifndef __HAL_MPU6050_H
#define __HAL_MPU6050_H

#include <inttypes.h>
#include <stdbool.h>


 typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
 #define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

 /*!< STM32F10x Standard Peripheral Library old types (maintained for legacy purpose) */
 typedef int32_t  s32;
 typedef int16_t s16;
 typedef int8_t  s8;

 typedef const int32_t sc32;  /*!< Read Only */
 typedef const int16_t sc16;  /*!< Read Only */
 typedef const int8_t sc8;   /*!< Read Only */

 typedef uint32_t  u32;
 typedef uint16_t u16;
 typedef uint8_t  u8;

 typedef const uint32_t uc32;  /*!< Read Only */
 typedef const uint16_t uc16;  /*!< Read Only */
 typedef const uint8_t uc8;   /*!< Read Only */

/**
* @addtogroup  MPU6050_I2C_Define
* @{
*/

#define MPU6050_I2C                  I2C2
#define MPU6050_I2C_RCC_Periph       RCC_APB1Periph_I2C2
#define MPU6050_I2C_Port             GPIOB
#define MPU6050_I2C_SCL_Pin          GPIO_Pin_10
#define MPU6050_I2C_SDA_Pin          GPIO_Pin_11
#define MPU6050_I2C_RCC_Port         RCC_APB2Periph_GPIOB
#define MPU6050_I2C_Speed            100000 // 100kHz standard mode

/**
*@}
*/ /* end of group MPU6050_I2C_Define */ 


#endif /* __HAL___MPU6050_H */

/******************* (C) COPYRIGHT 2012 Harinadha Reddy Chintalapalli *****END OF FILE****/
