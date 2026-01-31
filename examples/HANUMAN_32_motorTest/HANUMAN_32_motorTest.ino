#include <HANUMAN_32.h>

void setup()
{
	Serial.begin(115200);
}

void loop()
{
	// ----- Individual motor test -----

	motor(1, 100); // Run motor 1 at speed 100
	delay(500);    // Wait 500 ms
	ao();          // Stop all motors

	motor(2, 100); // Run motor 2 at speed 100
	delay(500);
	ao();

	motor(3, 100); // Run motor 3 at speed 100
	delay(500);
	ao();

	motor(4, 100); // Run motor 4 at speed 100
	delay(500);
	ao();

	// ----- Basic movement (lowercase commands) -----

	fd(100); // Move forward at speed 100
	delay(500);

	fd2(100, 100); // Move forward with left and right speed control
	delay(500);

	bk(100); // Move backward at speed 100
	delay(500);

	bk2(100, 100); // Move backward with left and right speed control
	delay(500);

	tl(100); // Turn left at speed 100
	delay(500);

	tr(100); // Turn right at speed 100
	delay(500);

	sl(100); // Slide left at speed 100
	delay(500);

	sr(100); // Slide right at speed 100
	delay(500);

	ao(); // Stop all motors
	delay(500);

	// ----- Advanced / capital-letter movement commands -----

	FD(100); // Move forward (alternative / faster / different mode)
	delay(500);

	FD2(100, 100); // Forward movement with independent wheel speeds
	delay(500);

	BK(100); // Move backward
	delay(500);

	BK2(100, 100); // Backward movement with independent wheel speeds
	delay(500);

	TL(100); // Turn left
	delay(500);

	TR(100); // Turn right
	delay(500);

	SL(100); // Slide left
	delay(500);

	SR(100); // Slide right
	delay(500);

	ao(); // Stop all motors before looping again
	delay(500);
}
