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

		if (isController_A())
			Serial.println("A pressed");
		if (isController_B())
			Serial.println("B pressed");
		if (isController_X())
			Serial.println("X pressed");
		if (isController_Y())
			Serial.println("Y pressed");

		if (isController_L1())
			Serial.println("L1 pressed");
		if (isController_R1())
			Serial.println("R1 pressed");
		if (isController_L2())
			Serial.println("L2 pressed");
		if (isController_R2())
			Serial.println("R2 pressed");

		if (isController_UP())
			Serial.println("PAD-UP pressed");
		if (isController_DOWN())
			Serial.println("PAD-DOWN pressed");
		if (isController_LEFT())
			Serial.println("PAD-LEFT pressed");
		if (isController_RIGHT())
			Serial.println("PAD-RIGHT pressed");

		if (isController_Home())
			Serial.println("Home pressed");
		if (isController_Share())
			Serial.println("Share pressed");
		if (isController_Option())
			Serial.println("Option pressed");

		if (isController_LeftStick())
			Serial.println("LeftStick pressed");
		if (isController_RightStick())
			Serial.println("RightStick pressed");
	}
}
