#include <HANUMAN_32.h>

void setup()
{
	Serial.begin(115200);
}

void loop()
{
	Serial.println("\n==============================================\n");

	Serial.print("knob() : ");
	Serial.println(knob());

	Serial.print("knob(200) : ");
	Serial.println(knob(200));

	Serial.print("knob(200, 800) : ");
	Serial.println(knob(200, 800));

	Serial.println();

	tft.text(0, 0, "knob()          : %d     ", knob());
	tft.text(1, 0, "knob(200)       : %d     ", knob(200));
	tft.text(2, 0, "knob(100, 1000) : %d     ", knob(200, 1000));

	delay(100);
}
