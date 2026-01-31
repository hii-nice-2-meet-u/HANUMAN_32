
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *
 *	File		:	HANUMAN_32__PWM_PCA9685.h
 *	Release		:	v0.1.1
 *
 *	Created on	:	Tue 27 Jan 2026
 *		Author	:	hii-nice-2-meet-u
 *
 */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef INC_HANUMAN_32__PWM_PCA9685_H
#define INC_HANUMAN_32__PWM_PCA9685_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "HANUMAN_32____MACRO.h"
#include "HANUMAN_32___I2C_Device.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class PWM_PCA9685
{

public:
	void __init__(void);
	void Set_Frequency(uint16_t freq);
	void Set_RangePulseServo(uint16_t minPulse, uint16_t maxPulse);
	void Set_ChannelPWM(uint8_t channel, uint16_t on, uint16_t off);
	void Set_ChannelServoPulse(uint8_t channel, uint16_t microseconds);
	void Set_ChannelServoAngle(uint8_t channel, uint8_t angle);
	void Set_Channel_On(uint8_t channel);
	void Set_Channel_Off(uint8_t channel);
	void Set_Channel_Off(void);

private:
	TwoWire* privI2C_PWM     = &Wire;
	uint16_t __minPulseServo = 500;
	uint16_t __maxPulseServo = 2650;
	void     WriteRegister(uint8_t reg, uint8_t value);
	uint8_t  ReadRegister(uint8_t reg);
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~