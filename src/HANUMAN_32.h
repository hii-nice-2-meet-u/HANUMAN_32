
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *
 *	File		:	HANUMAN_32.h
 *	Release		:	v0.1.2
 *
 *	Created on	:	Tue 27 Jan 2026
 *		Author	:	hii-nice-2-meet-u
 *
 */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
|
|    This product includes Bluepad32, which is licensed under the Apache License, Version 2.0.
|
|    Copyright (c) Ricardo Quesada and contributors.
|
|    You may obtain a copy of the Apache License, Version 2.0 at:
|        http://www.apache.org/licenses/LICENSE-2.0
|
|    Unless required by applicable law or agreed to in writing, software
|    distributed under the License is distributed on an "AS IS" BASIS,
|    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
|    See the License for the specific language governing permissions and
|    limitations under the License.
|
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef INC_HANUMAN_32_H
#define INC_HANUMAN_32_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <Arduino.h>

#include "HANUMAN_32__Encoder.h"
#include "HANUMAN_32__MotorCtrl.h"
#include "HANUMAN_32__SwitchAndKnob.h"
#include "HANUMAN_32__ADC_MCP3008.h"
#include "HANUMAN_32__TFT_ST7735S.h"
#include "HANUMAN_32__IMU_BNO055.h"
#include "HANUMAN_32__PWM_PCA9685.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// ================================================================================================================================

#define sleep(x)    delay(x)
#define delay_us(x) delayMicroseconds(x)

/// ================================================================================================================================

Encoder       enc;
MotorCtrl     mtr;
SwitchAndKnob sw;
ADC_MCP3008   adc;
TFT_ST7735S   tft;
IMU_BNO055    imu;
PWM_PCA9685   pwm;

/// ================================================================================================================================
//\ • Switch and Knob
/// ================================================================================================================================

//- ================ Switch - A ================================

#define wait_swA(void) swA()

void swA_Press(void)
{
	while (!sw.getState_Switch_A())
		;
	delay(25);
}

void swA_unPress(void)
{
	while (sw.getState_Switch_A())
		;
	delay(100);
}

void swA(void)
{
	swA_Press();
	swA_unPress();
}

bool is_swA(void)
{
	return sw.getState_Switch_A();
}

//- ================ Switch - B ================================

#define wait_swB(void) swB()

void swB_Press(void)
{
	while (!sw.getState_Switch_B())
		;
	delay(25);
}

void swB_unPress(void)
{
	while (sw.getState_Switch_B())
		;
	delay(100);
}

void swB(void)
{
	swB_Press();
	swB_unPress();
}

bool is_swB(void)
{
	return sw.getState_Switch_B();
}

//- ================ Knob ================================

#define Knob knob
#define KNOB knob

int16_t knob(void)
{
	return sw.getKnobValue(0, 1000);
}

int16_t knob(int16_t maxValue)
{
	return sw.getKnobValue(0, maxValue);
}

int16_t knob(int16_t minValue, int16_t maxValue)
{
	return sw.getKnobValue(minValue, maxValue);
}

//- ================================================================

/// ================================================================================================================================
//\ • ADC - MCP3008
/// ================================================================================================================================

//- ================ Analog Read ================================

#define Analog(channel) analog(channel)

uint16_t analog(uint8_t channel)
{
	if (channel > 7)
	{
		switch (channel)
		{
		case 8:
			return analogRead(14);

		case 9:
			return analogRead(0);

		default:
			return 0;
		}
	}
	return adc.ReadValue(channel);
}

uint16_t analog(uint8_t channel, uint16_t maxValue)
{
	return (analog(channel) * maxValue) / 1023;
}

uint16_t analog(uint8_t channel, uint16_t minValue, uint16_t maxValue)
{
	return (analog(channel) * (maxValue - minValue)) / 1023 + minValue;
}

//- ================ Digital Read ================================

#define in(channel) digital(channel)
#define IN(channel) digital(channel)

uint8_t digital(uint8_t channel)
{
	if (channel > 7)
	{
		switch (channel)
		{

		case 8:
			return digitalRead(14);

		case 9:
			return digitalRead(15);

		default:
			return 0;
		}
	}
	return (adc.ReadValue(channel) > 512) ? 1 : 0;
}

//- ================================================================

/// ================================================================================================================================
//\ • IMU - BNO055
/// ================================================================================================================================

//- ================ IMU - Update/Read ================================

void imu_update(bno055_dataType_t dataType = all)
{
	imu.update(dataType);
}

double imu_read(bno055_dataType_t dataType)
{
	return imu.read(dataType);
}

//- ================ IMU - GetValue ================================

double imu_accX(void)
{
	imu.update(accX);
	return imu.acc.x;
}

double imu_accY(void)
{
	imu.update(accY);
	return imu.acc.y;
}

double imu_accZ(void)
{
	imu.update(accZ);
	return imu.acc.z;
}

double imu_magX(void)
{
	imu.update(magX);
	return imu.mag.x;
}

double imu_magY(void)
{
	imu.update(magY);
	return imu.mag.y;
}

double imu_magZ(void)
{
	imu.update(magZ);
	return imu.mag.z;
}

double imu_gyrX(void)
{
	imu.update(gyrX);
	return imu.gyr.x;
}

double imu_gyrY(void)
{
	imu.update(gyrY);
	return imu.gyr.y;
}

double imu_gyrZ(void)
{
	imu.update(gyrZ);
	return imu.gyr.z;
}

double imu_eulX(void)
{
	imu.update(eulX);
	return imu.eul.x;
}

double imu_eulY(void)
{
	imu.update(eulY);
	return imu.eul.y;
}

double imu_eulZ(void)
{
	imu.update(eulZ);
	return imu.eul.z;
}

double imu_liaX(void)
{
	imu.update(liaX);
	return imu.lia.x;
}

double imu_liaY(void)
{
	imu.update(liaY);
	return imu.lia.y;
}

double imu_liaZ(void)
{
	imu.update(liaZ);
	return imu.lia.z;
}

double imu_grvX(void)
{
	imu.update(grvX);
	return imu.grv.x;
}

double imu_grvY(void)
{
	imu.update(grvY);
	return imu.grv.y;
}

double imu_grvZ(void)
{
	imu.update(grvZ);
	return imu.grv.z;
}

//- ================================================================

/// ================================================================================================================================
//\ • Encoder
/// ================================================================================================================================

//- ================ Encoder Start/Stop ================================

void enc_start(uint8_t encoder = 0)
{
	return enc.start(encoder);
}

void enc_stop(uint8_t encoder = 0)
{
	return enc.stop(encoder);
}

//- ================ Encoder Get/Set ================================

int32_t enc_getPos(uint8_t encoder)
{
	return enc.getPos(encoder);
}

void enc_setPos(uint8_t encoder, int32_t value = 0)
{
	enc.setPos(encoder, value);
}

void enc_setDir(uint8_t encoder, bool direction)
{
	return enc.setDir(encoder, direction);
}

//- ================================================================

/// ================================================================================================================================
//\ • Motor Control
/// ================================================================================================================================

//- ================ Motor - Control ================================

#define Motor motor
#define MOTOR motor

void motor(uint8_t channel, int16_t speed)
{
	if (channel > 4)
		return;

	switch (channel)
	{
	case 1:
		mtr.M1(speed);
		return;

	case 2:
		mtr.M2(speed);
		return;

	case 3:
		mtr.M3(speed);
		return;

	case 4:
		mtr.M4(speed);
		return;

	default:
		return;
	}
}

void motor(int16_t speed_M1, int16_t speed_M2, int16_t speed_M3, int16_t speed_M4)
{
	mtr.M1(speed_M1);
	mtr.M2(speed_M2);
	mtr.M3(speed_M3);
	mtr.M4(speed_M4);
}

//- ================ Motor - Stop ================================

#define motor_stop(void) mtr.Stop()
#define MOTOR_STOP(void) mtr.Stop()
#define ao(void)         mtr.Stop()
#define AO(void)         mtr.Stop()

//- ================ Motor - Function ================================

#define M(LSp, RSp) m(LSp, RSp)

void m(int16_t left_speed, int16_t right_speed)
{
	mtr.M1(left_speed);
	mtr.M2(right_speed);
}

void fd(int8_t speed)
{
	mtr.M1(speed);
	mtr.M2(speed);
}

void fd2(int8_t left_speed, int8_t right_speed)
{
	mtr.M1(left_speed);
	mtr.M2(right_speed);
}

void bk(int8_t speed)
{
	mtr.M1(-speed);
	mtr.M2(-speed);
}

void bk2(int8_t left_speed, int8_t right_speed)
{
	mtr.M1(-left_speed);
	mtr.M2(-right_speed);
}

void tl(int8_t speed)
{
	mtr.M1(0);
	mtr.M2(speed);
}

void tr(int8_t speed)
{
	mtr.M1(speed);
	mtr.M2(0);
}

void sl(int8_t speed)
{
	mtr.M1(-speed);
	mtr.M2(speed);
}

void sr(int8_t speed)
{
	mtr.M1(speed);
	mtr.M2(-speed);
}

void FD(int8_t speed)
{
	mtr.M1(speed);
	mtr.M2(speed);
	mtr.M3(speed);
	mtr.M4(speed);
}

void FD2(int8_t left_speed, int8_t right_speed)
{
	mtr.M1(left_speed);
	mtr.M2(left_speed);
	mtr.M3(right_speed);
	mtr.M4(right_speed);
}

void BK(int8_t speed)
{
	mtr.M1(-speed);
	mtr.M2(-speed);
	mtr.M3(-speed);
	mtr.M4(-speed);
}

void BK2(int8_t left_speed, int8_t right_speed)
{
	mtr.M1(-left_speed);
	mtr.M2(-left_speed);
	mtr.M3(-right_speed);
	mtr.M4(-right_speed);
}

void TL(int8_t speed)
{
	mtr.M1(0);
	mtr.M2(0);
	mtr.M3(speed);
	mtr.M4(speed);
}

void TR(int8_t speed)
{
	mtr.M1(speed);
	mtr.M2(speed);
	mtr.M3(0);
	mtr.M4(0);
}

void SL(int8_t speed)
{
	mtr.M1(-speed);
	mtr.M2(-speed);
	mtr.M3(speed);
	mtr.M4(speed);
}

void SR(int8_t speed)
{
	mtr.M1(speed);
	mtr.M2(speed);
	mtr.M3(-speed);
	mtr.M4(-speed);
}

//- ================================================================

/// ================================================================================================================================
//\ • PWM - PCA9685
/// ================================================================================================================================

//- ================ Servo ================================

void servo(uint8_t channel, int16_t angle)
{
	if (channel > 7)
		return;

	if (angle < 0)
	{
		pwm.Set_ChannelServoPulse(channel, 0);
		return;
	}
	pwm.Set_ChannelServoAngle(channel, angle);
}

//- ================ Digital Write ================================

static const uint8_t sv0 = 10;
static const uint8_t sv1 = 11;
static const uint8_t sv2 = 12;
static const uint8_t sv3 = 13;
static const uint8_t sv4 = 14;
static const uint8_t sv5 = 15;
static const uint8_t sv6 = 16;
static const uint8_t sv7 = 17;

#define out(channel, value) digital(channel, value)
#define OUT(channel, value) digital(channel, value)

void digital(uint8_t channel, uint8_t value)
{
	if (channel < 8)
	{
		return;
	}
	switch (channel)
	{

	case 8:
		digitalWrite(14, value);
		break;

	case 9:
		digitalWrite(15, value);
		break;

	default:
		if (channel > 17)
			return;

		channel -= 10;
		if (value)
			pwm.Set_Channel_On(channel);
		else
			pwm.Set_Channel_Off(channel);

		return;
	}
}

//- ================ Buzzer ================================

#define Beep(void) beep
#define BEEP(void) beep

void beep(uint16_t duration = 50)
{
	pwm.Set_Channel_On(15);
	delay(duration);
	pwm.Set_Channel_Off(15);
}

//- ================================================================

/// ================================================================================================================================
//\ • Controller
/// ================================================================================================================================

#ifdef CONFIG_BLUEPAD32_PLATFORM_CUSTOM

//- ================================================================

#include <Bluepad32.h>

GamepadPtr myGamepad;

//- ================================================================

void onConnectedGamepad(GamepadPtr gp)
{
	myGamepad = gp;
}

void onDisconnectedGamepad(GamepadPtr gp)
{
	myGamepad = nullptr;
}

void Controller_Connect(void)
{
	BP32.setup(&onConnectedGamepad, &onDisconnectedGamepad);
	BP32.forgetBluetoothKeys();
	BP32.enableVirtualDevice(false);
}

bool Controller_Update(void)
{
	if (BP32.update())
	{
		return (myGamepad && myGamepad->isConnected());
	}
	return 0;
}

//- ================================================================

bool isController_A(void)
{
	return myGamepad->a();
}

bool isController_B(void)
{
	return myGamepad->b();
}

bool isController_X(void)
{
	return myGamepad->x();
}

bool isController_Y(void)
{
	return myGamepad->y();
}

//- ================================================================

bool isController_L1(void)
{
	return myGamepad->l1();
}

bool isController_R1(void)
{
	return myGamepad->r1();
}

bool isController_L2(void)
{
	return myGamepad->l2();
}

bool isController_R2(void)
{
	return myGamepad->r2();
}

//- ================================================================

bool isController_UP(void)
{
	return myGamepad->dpad() & DPAD_UP;
}

bool isController_DOWN(void)
{
	return myGamepad->dpad() & DPAD_DOWN;
}

bool isController_LEFT(void)
{
	return myGamepad->dpad() & DPAD_LEFT;
}

bool isController_RIGHT(void)
{
	return myGamepad->dpad() & DPAD_RIGHT;
}

//- ================================================================

bool isController_Home(void)
{
	return myGamepad->miscButtons() & 0x01;
}

bool isController_Share(void)
{
	return myGamepad->miscButtons() & 0x02;
}

bool isController_Option(void)
{
	return myGamepad->miscButtons() & 0x04;
}

//- ================================================================

bool isController_LeftStick(void)
{
	return myGamepad->buttons() & BUTTON_THUMB_L;
}

bool isController_RightStick(void)
{
	return myGamepad->buttons() & BUTTON_THUMB_R;
}

//- ================================================================

int32_t Controller_getLX(void)
{
	return myGamepad->axisX();
}

int32_t Controller_getLY(void)
{
	return myGamepad->axisY();
}

int32_t Controller_getRX(void)
{
	return myGamepad->axisRX();
}

int32_t Controller_getRY(void)
{
	return myGamepad->axisRY();
}

//- ================================================================

int32_t Controller_getL2(void)
{
	return myGamepad->brake();
}

int32_t Controller_getR2(void)
{
	return myGamepad->throttle();
}

//- ================================================================

uint8_t Controller_getBattery(void)
{
	return myGamepad->battery() / 255.00 * 100;
}

//- ================================================================

void Controller_Rumble(void)
{
	return myGamepad->playDualRumble(0, 250, 0x80, 0x80);
}

void Controller_Rumble(uint16_t duration, uint8_t strong, uint8_t weak)
{
	return myGamepad->playDualRumble(0, duration, strong, weak);
}

//- ================================================================

void Controller_setColor(uint8_t red, uint8_t green, uint8_t blue)
{
	myGamepad->setColorLED(red, green, blue);
}

//- ================================================================

int32_t Controller_gyroX(void)
{
	return myGamepad->gyroX();
}

int32_t Controller_gyroY(void)
{
	return myGamepad->gyroY();
}

int32_t Controller_gyroZ(void)
{
	return myGamepad->gyroZ();
}

int32_t Controller_accelX(void)
{
	return myGamepad->accelX();
}

int32_t Controller_accelY(void)
{
	return myGamepad->accelY();
}

int32_t Controller_accelZ(void)
{
	return myGamepad->accelZ();
}

//- ================================================================

#endif

/// ================================================================================================================================
//\ • Initialization
/// ================================================================================================================================

void __initialize_Hanuman32(void)
{
	imu.__init__();
	pwm.__init__();
	enc.__init__();
}

/// ================================================================================================================================
//\ ================================================================================================================================

void initVariant(void)
{
	__initialize_Hanuman32();
}

//\ ================================================================================================================================
/// ================================================================================================================================

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~