#include <HANUMAN_32.h>

void setup(void)
{
	Serial.begin(115200);
	Controller_Connect();
}

void loop(void)
{
	if (Controller_Update())
	{
		Controller_setColor(0, 0, 255);
		delay(250);
		Controller_setColor(255, 0, 255);
		delay(250);
		Controller_setColor(255, 0, 0);
		delay(250);
		Controller_setColor(255, 255, 0);
		delay(250);
		Controller_setColor(0, 255, 0);
		delay(250);
		Controller_setColor(0, 255, 255);
		delay(250);
		Controller_setColor(255, 255, 255);
		delay(250);

		Controller_Rumble();
		delay(500);
	}
}
