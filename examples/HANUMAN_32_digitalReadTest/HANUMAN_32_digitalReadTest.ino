#include <HANUMAN_32.h>

void setup()
{
	Serial.begin(115200);
}

void loop()
{
	Serial.println("\n==============================================\n");

	Serial.print("A0 :\t");
	Serial.println(in(0));

	Serial.print("A1 :\t");
	Serial.println(in(1));

	Serial.print("A2 :\t");
	Serial.println(in(2));

	Serial.print("A3 :\t");
	Serial.println(in(3));

	Serial.print("A4 :\t");
	Serial.println(in(4));

	Serial.print("A5 :\t");
	Serial.println(in(5));

	Serial.print("A6 :\t");
	Serial.println(in(6));

	Serial.print("A7 :\t");
	Serial.println(in(7));

	Serial.print("A8, IO14 :\t");
	Serial.println(in(8));

	Serial.print("A9, IO15 :\t");
	Serial.println(in(9));

	tft.text(0, 0, "A0 : %d     ", in(0));
	tft.text(1, 0, "A1 : %d     ", in(1));
	tft.text(2, 0, "A2 : %d     ", in(2));
	tft.text(3, 0, "A3 : %d     ", in(3));
	tft.text(4, 0, "A4 : %d     ", in(4));
	tft.text(5, 0, "A5 : %d     ", in(5));
	tft.text(6, 0, "A6 : %d     ", in(6));
	tft.text(7, 0, "A7 : %d     ", in(7));
	tft.text(8, 0, "A8 : %d     ", in(8));
	tft.text(9, 0, "A9 : %d     ", in(9));

	delay(100);
}
