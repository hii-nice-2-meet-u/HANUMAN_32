#include <HANUMAN_32.h>

void setup()
{
	Serial.begin(115200);
}

void loop()
{
	Serial.println("\n==============================================\n");

	imu.update();

	Serial.print("Accelerometer X : ");
	Serial.print(imu.acc.x);

	Serial.print("\tY : ");
	Serial.print(imu.acc.y);

	Serial.print("\tZ : ");
	Serial.println(imu.acc.z);

	Serial.print("Linearaccel X : ");
	Serial.print(imu.lia.x);

	Serial.print("\tY : ");
	Serial.print(imu.lia.y);

	Serial.print("\tZ : ");
	Serial.println(imu.lia.z);

	Serial.print("Euler X : ");
	Serial.print(imu.eul.x);

	Serial.print("\tY : ");
	Serial.print(imu.eul.y);

	Serial.print("\tZ : ");
	Serial.println(imu.eul.z);

	Serial.print("Magnetometer X : ");
	Serial.print(imu.mag.x);

	Serial.print("\tY : ");
	Serial.print(imu.mag.y);

	Serial.print("\tZ : ");
	Serial.println(imu.mag.z);

	Serial.print("Gyroscope X : ");
	Serial.print(imu.gyr.x);

	Serial.print("\tY : ");
	Serial.print(imu.gyr.y);

	Serial.print("\tZ : ");
	Serial.println(imu.gyr.z);

	Serial.print("Gravity X : ");
	Serial.print(imu.grv.x);

	Serial.print("\tY : ");
	Serial.print(imu.grv.y);

	Serial.print("\tZ : ");
	Serial.println(imu.grv.z);

	Serial.println();

	tft.text(0, 0, "     X       Y      Z");
	tft.text(1, 0, "Acc %.2f   ", imu.acc.x);
	tft.text(1, 11, "%.2f   ", imu.acc.y);
	tft.text(1, 19, "%.2f   ", imu.acc.z);

	tft.text(3, 0, "Lia %.2f   ", imu.lia.x);
	tft.text(3, 11, "%.2f   ", imu.lia.y);
	tft.text(3, 19, "%.2f   ", imu.lia.z);

	tft.text(5, 0, "Eul %.2f   ", imu.eul.x);
	tft.text(5, 11, "%.2f   ", imu.eul.y);
	tft.text(5, 19, "%.2f   ", imu.eul.z);

	tft.text(7, 0, "Mag %.2f   ", imu.mag.x);
	tft.text(7, 11, "%.2f   ", imu.mag.y);
	tft.text(7, 19, "%.2f   ", imu.mag.z);

	tft.text(9, 0, "Gyr %.2f   ", imu.gyr.x);
	tft.text(9, 11, "%.2f   ", imu.gyr.y);
	tft.text(9, 19, "%.2f   ", imu.gyr.z);

	tft.text(11, 0, "Grv %.2f   ", imu.grv.x);
	tft.text(11, 11, "%.2f   ", imu.grv.y);
	tft.text(11, 19, "%.2f   ", imu.grv.z);

	delay(100);
}

/*

========================================================================
    BNO055 IMU Interface (HANUMAN_32)
========================================================================

[ ฟังก์ชันหลัก ]
-----------------------------------------------------------------------
    imu.update()
        อัปเดตข้อมูลจากเซนเซอร์ทั้งหมด

    imu.update(datatype)
        อัปเดตข้อมูลตามชนิดที่กำหนด

    imu.read(datatype)
        อ่านค่าข้อมูลตามชนิดที่กำหนด


[ ชนิดข้อมูลที่รองรับ (datatype) ]
-----------------------------------------------------------------------
    all        : อัปเดตข้อมูลทุกประเภท

    _acc         : Accelerometer        (ความเร่ง)
    _mag         : Magnetometer         (สนามแม่เหล็ก)
    _gyr         : Gyroscope            (อัตราการหมุน)
    _eul         : Euler Angle          (มุมทิศทาง)
    _lia         : Linear Acceleration  (ความเร่งเชิงเส้น)
    _grv         : Gravity              (แรงโน้มถ่วง)

    tempC     : อุณหภูมิ (องศาเซลเซียส °C)


[ ค่ารายแกน (Axis Data) ]
-----------------------------------------------------------------------
    Accelerometer           : accX , accY , accZ
    Magnetometer            : magX , magY , magZ
    Gyroscope               : gyrX , gyrY , gyrZ
    Euler Angle             : eulX , eulY , eulZ
    Linear Acceleration     : liaX , liaY , liaZ
    Gravity                 : grvX , grvY , grvZ


[ ฟังก์ชันลัด (อัปเดตและอ่านค่าในคำสั่งเดียว) ]
-----------------------------------------------------------------------
    imu_accX(), imu_accY(), imu_accZ()
    imu_liaX(), imu_liaY(), imu_liaZ()
    imu_eulX(), imu_eulY(), imu_eulZ()
    imu_magX(), imu_magY(), imu_magZ()
    imu_gyrX(), imu_gyrY(), imu_gyrZ()
    imu_grvX(), imu_grvY(), imu_grvZ()


[ โครงสร้างตัวแปร ]
-----------------------------------------------------------------------
    ใช้งานหลังเรียก imu.update()
    imu.acc.x , imu.acc.y , imu.acc.z     // Accelerometer
    imu.lia.x , imu.lia.y , imu.lia.z     // Linear Acceleration
    imu.eul.x , imu.eul.y , imu.eul.z     // Euler Angle
    imu.mag.x , imu.mag.y , imu.mag.z     // Magnetometer
    imu.gyr.x , imu.gyr.y , imu.gyr.z     // Gyroscope
    imu.grv.x , imu.grv.y , imu.grv.z     // Gravity

========================================================================
*/
