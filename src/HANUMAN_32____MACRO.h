
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *
 *	File		:	HANUMAN_32___MACRO.h
 *	Release		:	v0.1.1
 *
 *	Created on	:	Tue 27 Jan 2026
 *		Author	:	hii-nice-2-meet-u
 *
 */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef INC_HANUMAN_32__MACRO_H
#define INC_HANUMAN_32__MACRO_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <Arduino.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//* ----------------------------------------------------------------

#define __DEFINE__M1_PWM 33
#define __DEFINE__M1_DIR 2

#define __DEFINE__M2_PWM 32
#define __DEFINE__M2_DIR 27

#define __DEFINE__M3_PWM 26
#define __DEFINE__M3_DIR 13

#define __DEFINE__M4_PWM 25
#define __DEFINE__M4_DIR 12

#define __DEFINE__SPI_MISO 19
#define __DEFINE__SPI_MOSI 23
#define __DEFINE__SPI_SCLK 18
#define __DEFINE__SPI_CS   5

#define __DEFINE__SPI_ADC_CS 4
#define __DEFINE__SPI_TFT_CS 9
#define __DEFINE__SPI_TFT_DC 10

#define __DEFINE__I2C_SDA 21
#define __DEFINE__I2C_SCL 22

#define __DEFINE__UART_TX 1
#define __DEFINE__UART_RX 3

#define __DEFINE__SW_A 36
#define __DEFINE__SW_B 37

#define __DEFINE__ENC1_A 38
#define __DEFINE__ENC1_B 39
#define __DEFINE__ENC2_A 34
#define __DEFINE__ENC2_B 35

//* ----------------------------------------------------------------

#define __DEFINE__SWITCH_A_THRESHOLD 100
#define __DEFINE__KNOB_MIN_VALUE     400
#define __DEFINE__KNOB_MAX_VALUE     4095

//* ----------------------------------------------------------------

#define __DEFINE__SPI_FREQ_ADC_MCP3008 3600000
#define __DEFINE__SPI_FREQ_TFT_ST7735S 40000000

//* ----------------------------------------------------------------

#define __DEFINE__I2C_FREQ            400000
#define __DEFINE__I2C_BNO055_ADDRESS  0x28
#define __DEFINE__I2C_PCA9685_ADDRESS 0x40

//* ----------------------------------------------------------------

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~1