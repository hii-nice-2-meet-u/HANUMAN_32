
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *
 *	File		:	HANUMAN_32__Encoder.h
 *	Release		:	v0.1
 *
 *	Created on	:	-----
 *		Author	:	hii-nice-2-meet-u
 *
 */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef INC_HANUMAN_32__ENCODER_H
#define INC_HANUMAN_32__ENCODER_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "HANUMAN_32____MACRO.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

static const int8_t lookupTable_CW[16]  = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};
static const int8_t lookupTable_CCW[16] = {0, 1, -1, 0, -1, 0, 0, 1, 1, 0, 0, -1, 0, -1, 1, 0};

class EncoderBase
{

public:
	EncoderBase(uint8_t a, uint8_t b) : pin_EncoderA(a), pin_EncoderB(b) {}
	void    __init__(void);
	void    start(void);
	void    stop(void);
	int32_t getPosition(void);
	void    setPosition(int32_t value = 0);
	void    setDirection(bool direction);

private:
	const uint8_t          pin_EncoderA, pin_EncoderB;
	volatile const int8_t* _lookupTable = lookupTable_CW;
	volatile int32_t       _position    = 0;
	volatile uint8_t       _lastPos     = 0;

	static void isrWrapper(void* arg)
	{
		static_cast<EncoderBase*>(arg)->update();
	}

	void IRAM_ATTR update(void)
	{
		uint8_t state_A = digitalRead(pin_EncoderA);
		uint8_t state_B = digitalRead(pin_EncoderB);
		uint8_t current = (state_A << 1) | state_B;
		uint8_t change  = (_lastPos << 2) | current;

		_position += _lookupTable[change];
		_lastPos = current;
	}
};

class Encoder
{

public:
	Encoder() : ENC1(__DEFINE__ENC1_A, __DEFINE__ENC1_B),
	            ENC2(__DEFINE__ENC2_A, __DEFINE__ENC2_B) {}

	void    __init__(void);
	void    start(uint8_t encoder = 0);
	void    stop(uint8_t encoder = 0);
	int32_t getPos(uint8_t encoder);
	void    setPos(uint8_t encoder, int32_t value = 0);
	void    setDir(uint8_t encoder, bool direction);

private:
	EncoderBase ENC1;
	EncoderBase ENC2;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~