#include <HANUMAN_32.h>

/*
    ===== Switch Input Functions =====

    Switch A (swA)
    - wait_swA(), swA()   : Wait for press and release of Switch A
    - swA_Press()         : Wait until Switch A is pressed
    - swA_unPress()       : Wait until Switch A is released
    - is_swA()            : Read current state of Switch A (returns 0 or 1)

    Switch B (swB)
    - wait_swB(), swB()   : Wait for press and release of Switch B
    - swB_Press()         : Wait until Switch B is pressed
    - swB_unPress()       : Wait until Switch B is released
    - is_swB()            : Read current state of Switch B (returns 0 or 1)
*/

void setup()
{
	Serial.begin(115200);
}

void loop()
{
	Serial.println("\n==============================================\n");

	Serial.print("swA : ");
	Serial.print(is_swA());
	Serial.print("\tswB : ");
	Serial.println(is_swB());

	tft.text(0, 0, "swA : %d   ", is_swA());
	tft.text(1, 0, "swB : %d   ", is_swB());

	delay(100);
}
