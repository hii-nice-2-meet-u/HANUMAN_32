
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *
 *	File		:	HANUMAN_32__SwitchAndKnob.cpp
 *	Release		:	v0.1.1
 *
 *	Created on	:	Tue 27 Jan 2026
 *		Author	:	hii-nice-2-meet-u
 *
 */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "HANUMAN_32__SwitchAndKnob.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

SwitchAndKnob::SwitchAndKnob(void)
{
	pinMode(__DEFINE__SW_A, INPUT);
	pinMode(__DEFINE__SW_B, INPUT);
}

//"" --------------------------------

bool SwitchAndKnob::getState_Switch_A(void)
{
	return (bool)(analogRead(__DEFINE__SW_A) < __DEFINE__SWITCH_A_THRESHOLD);
}

bool SwitchAndKnob::getState_Switch_B(void)
{
	return !((bool)(digitalRead(__DEFINE__SW_B)));
}

int16_t SwitchAndKnob::getKnobValue(int16_t MinValue, int16_t MaxValue)
{
	short KnobValue = analogRead(__DEFINE__SW_A);
	if (KnobValue > 1)
	{
		_lastKnobValue = constrain(map(KnobValue, __DEFINE__KNOB_MIN_VALUE, __DEFINE__KNOB_MAX_VALUE, MinValue, MaxValue), MinValue, MaxValue);
	}
	return _lastKnobValue;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~