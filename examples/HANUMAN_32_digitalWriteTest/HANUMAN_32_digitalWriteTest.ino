#include <HANUMAN_32.h>

void setup()
{
	Serial.begin(115200);
}

void loop()
{
	out(8, HIGH);
	delay(500);
	out(8, LOW);
	delay(500);

	out(9, HIGH);
	delay(500);
	out(9, LOW);
	delay(500);

	out(sv0, HIGH);
	delay(500);
	out(sv0, LOW);
	delay(500);

	out(sv1, HIGH);
	delay(500);
	out(sv1, LOW);
	delay(500);

	out(sv2, HIGH);
	delay(500);
	out(sv2, LOW);
	delay(500);

	out(sv3, HIGH);
	delay(500);
	out(sv3, LOW);
	delay(500);

	out(sv4, HIGH);
	delay(500);
	out(sv4, LOW);
	delay(500);

	out(sv5, HIGH);
	delay(500);
	out(sv5, LOW);
	delay(500);

	out(sv6, HIGH);
	delay(500);
	out(sv6, LOW);
	delay(500);

	out(sv7, HIGH);
	delay(500);
	out(sv7, LOW);
	delay(500);
}
