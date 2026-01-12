
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *
 *	File		:	HANUMAN_32__IMU_BNO055.cpp
 *	Release		:	v0.1
 *
 *	Created on	:	-----
 *		Author	:	hii-nice-2-meet-u
 *
 */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "HANUMAN_32__IMU_BNO055.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void IMU_BNO055::__init__(void)
{
	I2C_Device.begin();

	WriteRegister(BNO055_REG_ADDRESS__SYS_TRIGGER, 0x20);
	delay(500);

	WriteRegister(BNO055_REG_ADDRESS__OPR_MODE, 0x00);
	delay(50);

	WriteRegister(BNO055_REG_ADDRESS__SYS_TRIGGER, 0x80);
	delay(250);

	WriteRegister(BNO055_REG_ADDRESS__UNIT_SEL, 0x80);
	delay(50);

	WriteRegister(BNO055_REG_ADDRESS__OPR_MODE, 0x0C);
	delay(50);
}

//"" --------------------------------

void IMU_BNO055::getVector(bno055_vector_address_t vector_reg)
{
	privI2C_IMU->beginTransmission(__DEFINE__I2C_BNO055_ADDRESS);
	privI2C_IMU->write(vector_reg);
	privI2C_IMU->endTransmission(false);
	privI2C_IMU->requestFrom(__DEFINE__I2C_BNO055_ADDRESS, 6);

	while (!privI2C_IMU->available())
		;
	int16_t _x = privI2C_IMU->read() | (privI2C_IMU->read() << 8);
	int16_t _y = privI2C_IMU->read() | (privI2C_IMU->read() << 8);
	int16_t _z = privI2C_IMU->read() | (privI2C_IMU->read() << 8);

	switch (vector_reg)
	{
	case VECTOR_ACCELEROMETER:
		acc.x = ((double)_x) / 100.0;
		acc.y = ((double)_y) / 100.0;
		acc.z = ((double)_z) / 100.0;
		break;

	case VECTOR_MAGNETOMETER:
		mag.x = ((double)_x) / 16.0;
		mag.y = ((double)_y) / 16.0;
		mag.z = ((double)_z) / 16.0;
		break;

	case VECTOR_GYROSCOPE:
		gyr.x = ((double)_x) / 16.0;
		gyr.y = ((double)_y) / 16.0;
		gyr.z = ((double)_z) / 16.0;
		break;

	case VECTOR_EULER:
		eul.x = ((double)_x) / 16.0;
		eul.y = ((double)_y) / 16.0;
		eul.z = ((double)_z) / 16.0;
		break;

	case VECTOR_LINEAR_ACCEL:
		lia.x = ((double)_x) / 100.0;
		lia.y = ((double)_y) / 100.0;
		lia.z = ((double)_z) / 100.0;
		break;

	case VECTOR_GRAVITY:
		grv.x = ((double)_x) / 100.0;
		grv.y = ((double)_y) / 100.0;
		grv.z = ((double)_z) / 100.0;
		break;
	}
}

//"" --------------------------------

void IMU_BNO055::WriteRegister(uint8_t reg, uint8_t value)
{
	privI2C_IMU->beginTransmission(__DEFINE__I2C_BNO055_ADDRESS);
	privI2C_IMU->write(reg);
	privI2C_IMU->write(value);
	privI2C_IMU->endTransmission(true);
}

uint8_t IMU_BNO055::ReadRegister8b(uint8_t reg)
{
	privI2C_IMU->beginTransmission(__DEFINE__I2C_BNO055_ADDRESS);
	privI2C_IMU->write(reg);
	privI2C_IMU->endTransmission(false);
	privI2C_IMU->requestFrom(__DEFINE__I2C_BNO055_ADDRESS, 1);

	while (!privI2C_IMU->available())
		;
	return privI2C_IMU->read();
}

uint16_t IMU_BNO055::ReadRegister16b(uint8_t reg)
{
	privI2C_IMU->beginTransmission(__DEFINE__I2C_BNO055_ADDRESS);
	privI2C_IMU->write(reg);
	privI2C_IMU->endTransmission(false);
	privI2C_IMU->requestFrom(__DEFINE__I2C_BNO055_ADDRESS, 2);

	while (!privI2C_IMU->available())
		;
	return (uint16_t)(privI2C_IMU->read() | (privI2C_IMU->read() << 8));
}

//"" --------------------------------

void IMU_BNO055::update(bno055_dataType_t dataType)
{
	if (dataType < 7)
	{
		switch (dataType)
		{
		case all:
			getVector(VECTOR_ACCELEROMETER);
			getVector(VECTOR_MAGNETOMETER);
			getVector(VECTOR_GYROSCOPE);
			getVector(VECTOR_EULER);
			getVector(VECTOR_LINEAR_ACCEL);
			getVector(VECTOR_GRAVITY);
			return;

		case _acc:
			getVector(VECTOR_ACCELEROMETER);
			return;

		case _mag:
			getVector(VECTOR_MAGNETOMETER);
			return;

		case _gyr:
			getVector(VECTOR_GYROSCOPE);
			return;

		case _eul:
			getVector(VECTOR_EULER);
			return;

		case _lia:
			getVector(VECTOR_LINEAR_ACCEL);
			return;

		case _grv:
			getVector(VECTOR_GRAVITY);
			return;

		default:
			return;
		}
	}

	switch (dataType)
	{
	case tempC:
		temp = (int8_t)ReadRegister8b(BNO055_REG_ADDRESS__TEMP);
		return;

	case accX:
		acc.x = ReadRegister16b(BNO055_REG_ADDRESS__ACC_DATA_X_LSB) / 100.0;
		return;
	case accY:
		acc.y = ReadRegister16b(BNO055_REG_ADDRESS__ACC_DATA_Y_LSB) / 100.0;
		return;
	case accZ:
		acc.z = ReadRegister16b(BNO055_REG_ADDRESS__ACC_DATA_Z_LSB) / 100.0;
		return;

	case magX:
		mag.x = ReadRegister16b(BNO055_REG_ADDRESS__MAG_DATA_X_LSB) / 16.0;
		return;
	case magY:
		mag.y = ReadRegister16b(BNO055_REG_ADDRESS__MAG_DATA_Y_LSB) / 16.0;
		return;
	case magZ:
		mag.z = ReadRegister16b(BNO055_REG_ADDRESS__MAG_DATA_Z_LSB) / 16.0;
		return;

	case gyrX:
		gyr.x = ReadRegister16b(BNO055_REG_ADDRESS__GYR_DATA_X_LSB) / 16.0;
		return;
	case gyrY:
		gyr.y = ReadRegister16b(BNO055_REG_ADDRESS__GYR_DATA_Y_LSB) / 16.0;
		return;
	case gyrZ:
		gyr.z = ReadRegister16b(BNO055_REG_ADDRESS__GYR_DATA_Z_LSB) / 16.0;
		return;

	case eulX:
		eul.x = ReadRegister16b(BNO055_REG_ADDRESS__EUL_HEADING_LSB) / 16.0;
		return;
	case eulY:
		eul.y = ReadRegister16b(BNO055_REG_ADDRESS__EUL_ROLL_LSB) / 16.0;
		return;
	case eulZ:
		eul.z = ReadRegister16b(BNO055_REG_ADDRESS__EUL_PITCH_LSB) / 16.0;
		return;

	case liaX:
		lia.x = ReadRegister16b(BNO055_REG_ADDRESS__LIA_DATA_X_LSB) / 100.0;
		return;
	case liaY:
		lia.y = ReadRegister16b(BNO055_REG_ADDRESS__LIA_DATA_Y_LSB) / 100.0;
		return;
	case liaZ:
		lia.z = ReadRegister16b(BNO055_REG_ADDRESS__LIA_DATA_Z_LSB) / 100.0;
		return;

	case grvX:
		grv.x = ReadRegister16b(BNO055_REG_ADDRESS__GRV_DATA_X_LSB) / 100.0;
		return;
	case grvY:
		grv.y = ReadRegister16b(BNO055_REG_ADDRESS__GRV_DATA_Y_LSB) / 100.0;
		return;
	case grvZ:
		grv.z = ReadRegister16b(BNO055_REG_ADDRESS__GRV_DATA_Z_LSB) / 100.0;
		return;

	default:
		return;
	}
}

double IMU_BNO055::read(bno055_dataType_t dataType)
{

	if (dataType < 7)
		return 0;

	switch (dataType)
	{
	case tempC:
		return (double)ReadRegister8b(BNO055_REG_ADDRESS__TEMP);

	case accX:
		return (double)ReadRegister16b(BNO055_REG_ADDRESS__ACC_DATA_X_LSB) / 100.0;
	case accY:
		return (double)ReadRegister16b(BNO055_REG_ADDRESS__ACC_DATA_Y_LSB) / 100.0;
	case accZ:
		return (double)ReadRegister16b(BNO055_REG_ADDRESS__ACC_DATA_Z_LSB) / 100.0;

	case magX:
		return (double)ReadRegister16b(BNO055_REG_ADDRESS__MAG_DATA_X_LSB) / 16.0;
	case magY:
		return (double)ReadRegister16b(BNO055_REG_ADDRESS__MAG_DATA_Y_LSB) / 16.0;
	case magZ:
		return (double)ReadRegister16b(BNO055_REG_ADDRESS__MAG_DATA_Z_LSB) / 16.0;

	case gyrX:
		return (double)ReadRegister16b(BNO055_REG_ADDRESS__GYR_DATA_X_LSB) / 16.0;
	case gyrY:
		return (double)ReadRegister16b(BNO055_REG_ADDRESS__GYR_DATA_Y_LSB) / 16.0;
	case gyrZ:
		return (double)ReadRegister16b(BNO055_REG_ADDRESS__GYR_DATA_Z_LSB) / 16.0;

	case eulX:
		return (double)ReadRegister16b(BNO055_REG_ADDRESS__EUL_HEADING_LSB) / 16.0;
	case eulY:
		return (double)ReadRegister16b(BNO055_REG_ADDRESS__EUL_ROLL_LSB) / 16.0;
	case eulZ:
		return (double)ReadRegister16b(BNO055_REG_ADDRESS__EUL_PITCH_LSB) / 16.0;

	case liaX:
		return (double)ReadRegister16b(BNO055_REG_ADDRESS__LIA_DATA_X_LSB) / 100.0;
	case liaY:
		return (double)ReadRegister16b(BNO055_REG_ADDRESS__LIA_DATA_Y_LSB) / 100.0;
	case liaZ:
		return (double)ReadRegister16b(BNO055_REG_ADDRESS__LIA_DATA_Z_LSB) / 100.0;

	case grvX:
		return (double)ReadRegister16b(BNO055_REG_ADDRESS__GRV_DATA_X_LSB) / 100.0;
	case grvY:
		return (double)ReadRegister16b(BNO055_REG_ADDRESS__GRV_DATA_Y_LSB) / 100.0;
	case grvZ:
		return (double)ReadRegister16b(BNO055_REG_ADDRESS__GRV_DATA_Z_LSB) / 100.0;

	default:
		return 0;
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
