
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *
 *	File		:	HANUMAN_32__Encoder.cpp
 *	Release		:	v0.1
 *
 *	Created on	:	-----
 *		Author	:	hii-nice-2-meet-u
 *
 */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "HANUMAN_32__Encoder.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void EncoderBase::__init__(void)
{
	pinMode(this->pin_EncoderA, INPUT);
	pinMode(this->pin_EncoderB, INPUT);
	this->start();
}

//"" --------------------------------

void EncoderBase::start(void)
{
	attachInterruptArg(digitalPinToInterrupt(this->pin_EncoderA), EncoderBase::isrWrapper, this, CHANGE);
	attachInterruptArg(digitalPinToInterrupt(this->pin_EncoderB), EncoderBase::isrWrapper, this, CHANGE);
	this->_lastPos = (digitalRead(this->pin_EncoderA) << 1) | digitalRead(this->pin_EncoderB);
}

void EncoderBase::stop(void)
{
	detachInterrupt(digitalPinToInterrupt(this->pin_EncoderA));
	detachInterrupt(digitalPinToInterrupt(this->pin_EncoderB));
	this->_lastPos = 0;
}

int32_t EncoderBase::getPosition(void)
{
	noInterrupts();
	int32_t value = this->_position;
	interrupts();

	return value;
}

void EncoderBase::setPosition(int32_t value)
{
	noInterrupts();
	this->_position = value;
	interrupts();
}

void EncoderBase::setDirection(bool direction)
{
	if (direction)
		this->_lookupTable = lookupTable_CCW;
	else
		this->_lookupTable = lookupTable_CW;
}

//"" ================================

void Encoder::__init__(void)
{
	this->ENC1.__init__();
	this->ENC1.stop();
	this->ENC2.__init__();
	this->ENC2.stop();
}

void Encoder::start(uint8_t encoder)
{
	switch (encoder)
	{
	case 0:
		this->ENC1.start();
		this->ENC2.start();
		return;

	case 1:
		this->ENC1.start();
		return;

	case 2:
		this->ENC2.start();
		return;

	default:
		return;
	}
}

void Encoder::stop(uint8_t encoder)
{
	switch (encoder)
	{
	case 0:
		[[fallthrough]];
	case 12:
		this->ENC1.stop();
		this->ENC2.stop();
		return;

	case 1:
		this->ENC1.stop();
		return;

	case 2:
		this->ENC2.stop();
		return;

	default:
		return;
	}
}

int32_t Encoder::getPos(uint8_t encoder)
{
	switch (encoder)
	{
	case 1:
		return this->ENC1.getPosition();

	case 2:
		return this->ENC2.getPosition();

	default:
		return 0;
	}
}

void Encoder::setPos(uint8_t encoder, int32_t value)
{
	switch (encoder)
	{
	case 0:
		[[fallthrough]];
	case 12:
		this->ENC1.setPosition(value);
		this->ENC2.setPosition(value);
		return;

	case 1:
		this->ENC1.setPosition(value);
		return;

	case 2:
		this->ENC2.setPosition(value);
		return;

	default:
		return;
	}
}

void Encoder::setDir(uint8_t encoder, bool direction)
{
	switch (encoder)
	{
	case 0:
		[[fallthrough]];
	case 12:
		this->ENC1.setDirection(direction);
		this->ENC2.setDirection(direction);
		return;

	case 1:
		this->ENC1.setDirection(direction);
		return;

	case 2:
		this->ENC2.setDirection(direction);
		return;

	default:
		return;
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
