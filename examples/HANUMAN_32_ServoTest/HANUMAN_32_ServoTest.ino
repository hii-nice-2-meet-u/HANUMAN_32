#include <HANUMAN_32.h>

void setup()
{
	Serial.begin(115200);
}

void loop()
{
	delay(400);
	servo(0, 0);
	servo(1, 0);
	servo(2, 0);
	servo(3, 0);
	servo(4, 0);
	servo(5, 0);
	servo(6, 0);
	servo(7, 0);

	delay(400);
	servo(0, 90);
	servo(1, 90);
	servo(2, 90);
	servo(3, 90);
	servo(4, 90);
	servo(5, 90);
	servo(6, 90);
	servo(7, 90);

	delay(400);
	servo(0, 180);
	servo(1, 180);
	servo(2, 180);
	servo(3, 180);
	servo(4, 180);
	servo(5, 180);
	servo(6, 180);
	servo(7, 180);

	// Fre all servos
	servo(0, -1);
	servo(1, -1);
	servo(2, -1);
	servo(3, -1);
	servo(4, -1);
	servo(5, -1);
	servo(6, -1);
	servo(7, -1);

	delay(200);
}
