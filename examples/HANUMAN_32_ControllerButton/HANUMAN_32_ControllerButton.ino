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

		if (isController_A_Press())
			Serial.println("A pressed");
		if (isController_B_Press())
			Serial.println("B pressed");
		if (isController_X_Press())
			Serial.println("X pressed");
		if (isController_Y_Press())
			Serial.println("Y pressed");

		if (isController_L1_Press())
			Serial.println("L1 pressed");
		if (isController_R1_Press())
			Serial.println("R1 pressed");
		if (isController_L2_Press())
			Serial.println("L2 pressed");
		if (isController_R2_Press())
			Serial.println("R2 pressed");

		if (isController_UP_Click())
			Serial.println("PAD-UP click");
		if (isController_DOWN_Click())
			Serial.println("PAD-DOWN click");
		if (isController_LEFT_Click())
			Serial.println("PAD-LEFT click");
		if (isController_RIGHT_Click())
			Serial.println("PAD-RIGHT click");

		if (isController_Home_Click())
			Serial.println("Home click");
		if (isController_Share_Click())
			Serial.println("Share click");
		if (isController_Option_Click())
			Serial.println("Option click");

		if (isController_LeftStick_Click())
			Serial.println("LeftStick click");
		if (isController_RightStick_Click())
			Serial.println("RightStick click");
	}
}
