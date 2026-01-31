#include <HANUMAN_32.h>

void setup()
{
	Serial.begin(115200);
}

void loop()
{
	beep();
	delay(500);

	beep(200);
	delay(500);
}