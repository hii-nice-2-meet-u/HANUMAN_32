
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *
 *	File		:	HANUMAN_32__MotorCtrl.cpp
 *	Release		:	v0.1
 *
 *	Created on	:	-----
 *		Author	:	hii-nice-2-meet-u
 *
 */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "HANUMAN_32__MotorCtrl.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

MotorCtrl::MotorCtrl(void)
{
	pinMode(__DEFINE__M1_DIR, OUTPUT);
	pinMode(__DEFINE__M2_DIR, OUTPUT);
	pinMode(__DEFINE__M3_DIR, OUTPUT);
	pinMode(__DEFINE__M4_DIR, OUTPUT);

	digitalWrite(__DEFINE__M1_DIR, LOW);
	digitalWrite(__DEFINE__M2_DIR, LOW);
	digitalWrite(__DEFINE__M3_DIR, LOW);
	digitalWrite(__DEFINE__M4_DIR, LOW);

	pinMode(__DEFINE__M1_PWM, OUTPUT);
	pinMode(__DEFINE__M2_PWM, OUTPUT);
	pinMode(__DEFINE__M3_PWM, OUTPUT);
	pinMode(__DEFINE__M4_PWM, OUTPUT);

	analogWrite(__DEFINE__M1_PWM, 0);
	analogWrite(__DEFINE__M2_PWM, 0);
	analogWrite(__DEFINE__M3_PWM, 0);
	analogWrite(__DEFINE__M4_PWM, 0);
}

//"" --------------------------------

void MotorCtrl::M1(short Speed)
{
	if (Speed < 0)
	{
		Speed = abs(Speed);
		digitalWrite(__DEFINE__M1_DIR, 1);
	}
	else
	{
		digitalWrite(__DEFINE__M1_DIR, 0);
	}
	if (Speed > 100)
	{
		Speed = 100;
	}

	Speed = map(Speed, 0, 100, 0, 255);
	analogWrite(__DEFINE__M1_PWM, Speed);
}

void MotorCtrl::M2(short Speed)
{
	if (Speed < 0)
	{
		Speed = abs(Speed);
		digitalWrite(__DEFINE__M2_DIR, 1);
	}
	else
	{
		digitalWrite(__DEFINE__M2_DIR, 0);
	}
	if (Speed > 100)
	{
		Speed = 100;
	}

	Speed = map(Speed, 0, 100, 0, 255);
	analogWrite(__DEFINE__M2_PWM, Speed);
}

void MotorCtrl::M3(short Speed)
{
	if (Speed < 0)
	{
		Speed = abs(Speed);
		digitalWrite(__DEFINE__M3_DIR, 1);
	}
	else
	{
		digitalWrite(__DEFINE__M3_DIR, 0);
	}
	if (Speed > 100)
	{
		Speed = 100;
	}

	Speed = map(Speed, 0, 100, 0, 255);
	analogWrite(__DEFINE__M3_PWM, Speed);
}

void MotorCtrl::M4(short Speed)
{
	if (Speed < 0)
	{
		Speed = abs(Speed);
		digitalWrite(__DEFINE__M4_DIR, 1);
	}
	else
	{
		digitalWrite(__DEFINE__M4_DIR, 0);
	}
	if (Speed > 100)
	{
		Speed = 100;
	}

	Speed = map(Speed, 0, 100, 0, 255);
	analogWrite(__DEFINE__M4_PWM, Speed);
}

void MotorCtrl::Stop(void)
{
	analogWrite(__DEFINE__M1_PWM, 0);
	analogWrite(__DEFINE__M2_PWM, 0);
	analogWrite(__DEFINE__M3_PWM, 0);
	analogWrite(__DEFINE__M4_PWM, 0);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~