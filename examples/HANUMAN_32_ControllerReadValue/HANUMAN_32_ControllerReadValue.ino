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
		Serial.printf(
		    "\nLx :\t%d\tLy :\t%d\tRx :\t%d\tRy :\t%d\tL2 :\t%d\tR2 :\t%d\tBattery : %d",
		    Controller_getLX(),
		    Controller_getLY(),
		    Controller_getRX(),
		    Controller_getRY(),
		    Controller_getL2(),
		    Controller_getR2(),
		    Controller_getBattery());
	}
}
