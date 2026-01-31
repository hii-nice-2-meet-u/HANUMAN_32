#include <HANUMAN_32.h>

void setup()
{
	Serial.begin(115200);
	enc_start();
}

void loop()
{
	Serial.println("\n==============================================\n");

	Serial.print("encoder 1 : ");
	Serial.println(enc_getPos(1));

	Serial.print("encoder 2 : ");
	Serial.println(enc_getPos(2));

	Serial.println();

	tft.text(0, 0, "encoder 1 : %d          ", enc_getPos(1));
	tft.text(1, 0, "encoder 2 : %d          ", enc_getPos(2));
	tft.text(2, 0, "swA : set zero");

	if (is_swA())
	{
		enc_setPos(1, 0);
		enc_setPos(2, 0);
	}

	delay(100);
}
