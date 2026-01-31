
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *
 *	File		:	HANUMAN_32__PWM_PCA9685.cpp
 *	Release		:	v0.1.1
 *
 *	Created on	:	Tue 27 Jan 2026
 *		Author	:	hii-nice-2-meet-u
 *
 */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "HANUMAN_32__PWM_PCA9685.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void PWM_PCA9685::__init__(void)
{
	I2C_Device.begin();

	WriteRegister(0x00, 0x00);
	delay(100);
	WriteRegister(0x01, 0x04);
	WriteRegister(0x00, 0xA1);

	Set_Frequency(50);
	Set_Channel_Off();
}

//"" --------------------------------

void PWM_PCA9685::Set_Frequency(uint16_t freq)
{
	float   prescaleval = 25000000.0 / (4095.0 * freq) - 1.0;
	uint8_t prescale    = floor(prescaleval + 0.5);

	uint8_t oldmode = ReadRegister(0x00);
	uint8_t newmode = (oldmode & 0x7F) | 0x10;
	WriteRegister(0x00, newmode);
	WriteRegister(0xFE, prescale);
	WriteRegister(0x00, oldmode);
	delayMicroseconds(500);
	WriteRegister(0x00, oldmode | 0xA1);
}

void PWM_PCA9685::Set_RangePulseServo(uint16_t minPulse, uint16_t maxPulse)
{
	PWM_PCA9685::__minPulseServo = minPulse;
	PWM_PCA9685::__maxPulseServo = maxPulse;
}

void PWM_PCA9685::Set_ChannelPWM(uint8_t channel, uint16_t on, uint16_t off)
{
	uint8_t BASE_REG = 0x06 + (4 * channel);
	privI2C_PWM->beginTransmission(__DEFINE__I2C_PCA9685_ADDRESS);
	privI2C_PWM->write(BASE_REG);
	privI2C_PWM->write((uint8_t)(on & 0xFF));
	privI2C_PWM->write((uint8_t)(on >> 8));
	privI2C_PWM->write((uint8_t)(off & 0xFF));
	privI2C_PWM->write((uint8_t)(off >> 8));
	privI2C_PWM->endTransmission();
}

void PWM_PCA9685::Set_ChannelServoPulse(uint8_t channel, uint16_t microseconds)
{
	uint16_t tick = round(microseconds * 4095.0 / 20000.0); // Assuming 50 Hz (20ms period)
	Set_ChannelPWM(channel, 0, tick);
}

void PWM_PCA9685::Set_ChannelServoAngle(uint8_t channel, uint8_t angle)
{
	if (angle > 180)
		angle = 180;

	uint16_t pulse = map(angle, 0, 180, PWM_PCA9685::__minPulseServo, PWM_PCA9685::__maxPulseServo);
	Set_ChannelServoPulse(channel, pulse);
}

void PWM_PCA9685::Set_Channel_On(uint8_t channel)
{
	uint8_t BASE_REG = 0x06 + (4 * channel);

	privI2C_PWM->beginTransmission(__DEFINE__I2C_PCA9685_ADDRESS);
	privI2C_PWM->write(BASE_REG); // Start at LEDn_ON_L
	privI2C_PWM->write(0x00);     // ON_L = 0
	privI2C_PWM->write(0x10);     // ON_H = 0x10 → FULL_ON bit set
	privI2C_PWM->write(0x00);     // OFF_L = don't care
	privI2C_PWM->write(0x00);     // OFF_H = 0 → FULL_OFF bit clear
	privI2C_PWM->endTransmission();
}

void PWM_PCA9685::Set_Channel_Off(uint8_t channel)
{
	uint8_t BASE_REG = 0x06 + (4 * channel);

	privI2C_PWM->beginTransmission(__DEFINE__I2C_PCA9685_ADDRESS);
	privI2C_PWM->write(BASE_REG);
	privI2C_PWM->write(0x00); // ON_L = don't care
	privI2C_PWM->write(0x00); // ON_H = 0 → FULL_ON bit clear
	privI2C_PWM->write(0x00); // OFF_L = don't care
	privI2C_PWM->write(0x10); // OFF_H = 0x10 → FULL_OFF bit set
	privI2C_PWM->endTransmission();
}

void PWM_PCA9685::Set_Channel_Off(void)
{
	privI2C_PWM->beginTransmission(__DEFINE__I2C_PCA9685_ADDRESS);
	privI2C_PWM->write(0xFA);
	privI2C_PWM->write(0x00); // ALL_ON_L
	privI2C_PWM->write(0x00); // ALL_ON_H (full on bit clear)
	privI2C_PWM->write(0x00); // ALL_OFF_L
	privI2C_PWM->write(0x10); // ALL_OFF_H (full off bit set)
	privI2C_PWM->endTransmission();
}

//"" --------------------------------

void PWM_PCA9685::WriteRegister(uint8_t reg, uint8_t value)
{
	privI2C_PWM->beginTransmission(__DEFINE__I2C_PCA9685_ADDRESS);
	privI2C_PWM->write(reg);
	privI2C_PWM->write(value);
	privI2C_PWM->endTransmission();
}

uint8_t PWM_PCA9685::ReadRegister(uint8_t reg)
{
	privI2C_PWM->beginTransmission(__DEFINE__I2C_PCA9685_ADDRESS);
	privI2C_PWM->write(reg);
	privI2C_PWM->endTransmission();
	privI2C_PWM->requestFrom(__DEFINE__I2C_PCA9685_ADDRESS, 1);
	return privI2C_PWM->read();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
