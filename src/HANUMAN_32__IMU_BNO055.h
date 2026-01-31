
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *
 *	File		:	HANUMAN_32__IMU_BNO055.h
 *	Release		:	v0.1.1
 *
 *	Created on	:	Tue 27 Jan 2026
 *		Author	:	hii-nice-2-meet-u
 *
 */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef INC_HANUMAN_32__IMU_BNO055_H
#define INC_HANUMAN_32__IMU_BNO055_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "HANUMAN_32____MACRO.h"
#include "HANUMAN_32___I2C_Device.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

typedef enum
{
	all,
	_acc,
	_mag,
	_gyr,
	_eul,
	_lia,
	_grv,
	tempC,
	accX,
	accY,
	accZ,
	magX,
	magY,
	magZ,
	gyrX,
	gyrY,
	gyrZ,
	eulX,
	eulY,
	eulZ,
	liaX,
	liaY,
	liaZ,
	grvX,
	grvY,
	grvZ
} bno055_dataType_t;

typedef struct Vector
{
	double x;
	double y;
	double z;
} Vector;

class IMU_BNO055
{

public:
	void   __init__(void);
	int8_t temp = 0;
	Vector acc  = {0, 0, 0};
	Vector mag  = {0, 0, 0};
	Vector gyr  = {0, 0, 0};
	Vector eul  = {0, 0, 0};
	Vector lia  = {0, 0, 0};
	Vector grv  = {0, 0, 0};

private:
	//* BNO055 Registers Map*//
	typedef enum
	{
		BNO055_REG_ADDRESS__MAG_RADIUS_MSB   = 0x6A,
		BNO055_REG_ADDRESS__MAG_RADIUS_LSB   = 0x69,
		BNO055_REG_ADDRESS__ACC_RADIUS_MSB   = 0x68,
		BNO055_REG_ADDRESS__ACC_RADIUS_LSB   = 0x67,
		BNO055_REG_ADDRESS__GYR_OFFSET_Z_MSB = 0x66,
		BNO055_REG_ADDRESS__GYR_OFFSET_Z_LSB = 0x65,
		BNO055_REG_ADDRESS__GYR_OFFSET_Y_MSB = 0x64,
		BNO055_REG_ADDRESS__GYR_OFFSET_Y_LSB = 0x63,
		BNO055_REG_ADDRESS__GYR_OFFSET_X_MSB = 0x62,
		BNO055_REG_ADDRESS__GYR_OFFSET_X_LSB = 0x61,
		BNO055_REG_ADDRESS__MAG_OFFSET_Z_MSB = 0x60,
		BNO055_REG_ADDRESS__MAG_OFFSET_Z_LSB = 0x5F,
		BNO055_REG_ADDRESS__MAG_OFFSET_Y_MSB = 0x5E,
		BNO055_REG_ADDRESS__MAG_OFFSET_Y_LSB = 0x5D,
		BNO055_REG_ADDRESS__MAG_OFFSET_X_MSB = 0x5C,
		BNO055_REG_ADDRESS__MAG_OFFSET_X_LSB = 0x5B,
		BNO055_REG_ADDRESS__ACC_OFFSET_Z_MSB = 0x5A,
		BNO055_REG_ADDRESS__ACC_OFFSET_Z_LSB = 0x59,
		BNO055_REG_ADDRESS__ACC_OFFSET_Y_MSB = 0x58,
		BNO055_REG_ADDRESS__ACC_OFFSET_Y_LSB = 0x57,
		BNO055_REG_ADDRESS__ACC_OFFSET_X_MSB = 0x56,
		BNO055_REG_ADDRESS__ACC_OFFSET_X_LSB = 0x55,
		BNO055_REG_ADDRESS__AXIS_MAP_SIGN    = 0x42,
		BNO055_REG_ADDRESS__AXIS_MAP_CONFIG  = 0x41,
		BNO055_REG_ADDRESS__TEMP_SOURCE      = 0x40,
		BNO055_REG_ADDRESS__SYS_TRIGGER      = 0x3F,
		BNO055_REG_ADDRESS__PWR_MODE         = 0x3E,
		BNO055_REG_ADDRESS__OPR_MODE         = 0x3D,
		BNO055_REG_ADDRESS__UNIT_SEL         = 0x3B,
		BNO055_REG_ADDRESS__SYS_ERR          = 0x3A,
		BNO055_REG_ADDRESS__SYS_STATUS       = 0x39,
		BNO055_REG_ADDRESS__SYS_CLK_STATUS   = 0x38,
		BNO055_REG_ADDRESS__INT_STA          = 0x37,
		BNO055_REG_ADDRESS__ST_RESULT        = 0x36,
		BNO055_REG_ADDRESS__CALIB_STAT       = 0x35,
		BNO055_REG_ADDRESS__TEMP             = 0x34,
		BNO055_REG_ADDRESS__GRV_DATA_Z_MSB   = 0x33,
		BNO055_REG_ADDRESS__GRV_DATA_Z_LSB   = 0x32,
		BNO055_REG_ADDRESS__GRV_DATA_Y_MSB   = 0x31,
		BNO055_REG_ADDRESS__GRV_DATA_Y_LSB   = 0x30,
		BNO055_REG_ADDRESS__GRV_DATA_X_MSB   = 0x2F,
		BNO055_REG_ADDRESS__GRV_DATA_X_LSB   = 0x2E,
		BNO055_REG_ADDRESS__LIA_DATA_Z_MSB   = 0x2D,
		BNO055_REG_ADDRESS__LIA_DATA_Z_LSB   = 0x2C,
		BNO055_REG_ADDRESS__LIA_DATA_Y_MSB   = 0x2B,
		BNO055_REG_ADDRESS__LIA_DATA_Y_LSB   = 0x2A,
		BNO055_REG_ADDRESS__LIA_DATA_X_MSB   = 0x29,
		BNO055_REG_ADDRESS__LIA_DATA_X_LSB   = 0x28,
		BNO055_REG_ADDRESS__QUA_DATA_Z_MSB   = 0x27,
		BNO055_REG_ADDRESS__QUA_DATA_Z_LSB   = 0x26,
		BNO055_REG_ADDRESS__QUA_DATA_Y_MSB   = 0x25,
		BNO055_REG_ADDRESS__QUA_DATA_Y_LSB   = 0x24,
		BNO055_REG_ADDRESS__QUA_DATA_X_MSB   = 0x23,
		BNO055_REG_ADDRESS__QUA_DATA_X_LSB   = 0x22,
		BNO055_REG_ADDRESS__QUA_DATA_W_MSB   = 0x21,
		BNO055_REG_ADDRESS__QUA_DATA_W_LSB   = 0x20,
		BNO055_REG_ADDRESS__EUL_PITCH_MSB    = 0x1F,
		BNO055_REG_ADDRESS__EUL_PITCH_LSB    = 0x1E,
		BNO055_REG_ADDRESS__EUL_ROLL_MSB     = 0x1D,
		BNO055_REG_ADDRESS__EUL_ROLL_LSB     = 0x1C,
		BNO055_REG_ADDRESS__EUL_HEADING_MSB  = 0x1B,
		BNO055_REG_ADDRESS__EUL_HEADING_LSB  = 0x1A,
		BNO055_REG_ADDRESS__GYR_DATA_Z_MSB   = 0x19,
		BNO055_REG_ADDRESS__GYR_DATA_Z_LSB   = 0x18,
		BNO055_REG_ADDRESS__GYR_DATA_Y_MSB   = 0x17,
		BNO055_REG_ADDRESS__GYR_DATA_Y_LSB   = 0x16,
		BNO055_REG_ADDRESS__GYR_DATA_X_MSB   = 0x15,
		BNO055_REG_ADDRESS__GYR_DATA_X_LSB   = 0x14,
		BNO055_REG_ADDRESS__MAG_DATA_Z_MSB   = 0x13,
		BNO055_REG_ADDRESS__MAG_DATA_Z_LSB   = 0x12,
		BNO055_REG_ADDRESS__MAG_DATA_Y_MSB   = 0x11,
		BNO055_REG_ADDRESS__MAG_DATA_Y_LSB   = 0x10,
		BNO055_REG_ADDRESS__MAG_DATA_X_MSB   = 0x0F,
		BNO055_REG_ADDRESS__MAG_DATA_X_LSB   = 0x0E,
		BNO055_REG_ADDRESS__ACC_DATA_Z_MSB   = 0x0D,
		BNO055_REG_ADDRESS__ACC_DATA_Z_LSB   = 0x0C,
		BNO055_REG_ADDRESS__ACC_DATA_Y_MSB   = 0x0B,
		BNO055_REG_ADDRESS__ACC_DATA_Y_LSB   = 0x0A,
		BNO055_REG_ADDRESS__ACC_DATA_X_MSB   = 0x09,
		BNO055_REG_ADDRESS__ACC_DATA_X_LSB   = 0x08,
		BNO055_REG_ADDRESS__PAGE_ID          = 0x07,
		BNO055_REG_ADDRESS__BL_REV_ID        = 0x06,
		BNO055_REG_ADDRESS__SW_REV_ID_MSB    = 0x05,
		BNO055_REG_ADDRESS__SW_REV_ID_LSB    = 0x04,
		BNO055_REG_ADDRESS__GYR_ID           = 0x03,
		BNO055_REG_ADDRESS__MAG_ID           = 0x02,
		BNO055_REG_ADDRESS__ACC_ID           = 0x01,
		BNO055_REG_ADDRESS__CHIP_ID          = 0x00
	} bno055_reg_address_t;

	typedef enum
	{
		VECTOR_ACCELEROMETER = BNO055_REG_ADDRESS__ACC_DATA_X_LSB,
		VECTOR_MAGNETOMETER  = BNO055_REG_ADDRESS__MAG_DATA_X_LSB,
		VECTOR_GYROSCOPE     = BNO055_REG_ADDRESS__GYR_DATA_X_LSB,
		VECTOR_EULER         = BNO055_REG_ADDRESS__EUL_HEADING_LSB,
		VECTOR_LINEAR_ACCEL  = BNO055_REG_ADDRESS__LIA_DATA_X_LSB,
		VECTOR_GRAVITY       = BNO055_REG_ADDRESS__GRV_DATA_X_LSB
	} bno055_vector_address_t;

	TwoWire* privI2C_IMU = &Wire;
	void     getVector(bno055_vector_address_t vector_reg);
	void     WriteRegister(uint8_t reg, uint8_t value);
	uint8_t  ReadRegister8b(uint8_t reg);
	uint16_t ReadRegister16b(uint8_t reg);

public:
	void   update(bno055_dataType_t dataType = all);
	double read(bno055_dataType_t dataType);
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~