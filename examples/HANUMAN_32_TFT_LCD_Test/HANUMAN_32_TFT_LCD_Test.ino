#include <HANUMAN_32.h>

void setup()
{
	Serial.begin(115200);

	tft.fill_Screen(COLOR_BLACK);
	tft.set_TextColor(COLOR_GREEN);

	tft.text(2, 4, "HELLO HANUMAN");
	tft.text(4, 4, "TFT SIMPLE DEMO");

	tft.draw_Line(0, 20, 159, 20, COLOR_CYAN);
	tft.draw_Rectangle(10, 30, 150, 100, COLOR_WHITE);
	tft.draw_Circle(80, 65, 20, COLOR_RED);
}

void loop()
{
}

/*

    TFT_LCD
    tft.text(line, col, text, ...)                                : display text on the screen at a specific line and column without background color
    tft.textWithBackground(line, col, text, ...)                  : display text on the screen at a specific line and column with background color behind the characters.

    tft.clear()                                                   : clear screen
    tft.fill_Screen(color) : fill color screen                    : fill screen with a single color.

        draw_Bitmap(posX, posY, bitmap, width, length,  color)    : draw a monochrome bitmap image at the given position
    tft.draw_BitmapColor(posX, posY, bitmap, width, length)       : draw a full-color bitmap image (RGB565 format) on the screen

    tft.draw_Char(posX, posY, character, color)                   : draw a single character
    tft.draw_Pixel(posX, posY, color)                             : draw one pixel with color at the specified position.
    tft.draw_HorizonLine(posX, color)                             : draw a vertical line with color at a specific X position
    tft.draw_VerticalLine(posY, color)                            : draw a horizontal line with color at a specific Y position
    tft.draw_Line(posX0, posY0, posX1, posY1, color)              : draw a line with color between two points

    tft.draw_Rectangle(posX0, posY0, posX1, posY1, color)         : draw the outline of a rectangle with color
    tft.fill_Rectangle(posX0, posY0, posX1, posY1, color)         : draw a filled rectangle with a single color

    tft.draw_Circle(posX, posY, radius, color)                    : draw the outline of a circle with color
    tft.fill_Circle(posX, posY, radius, color)                    : draw a filled circle with a single color

    tft.set_TextSize(size)                                        : set text size
    tft.set_TextColor(color)                                      : set text color
    tft.set_TextBackgroundColor(color)                            : set text background color
    tft.set_BackgroundColor(color)                                : set background color

    tft.set_RotationMode(RotationMode)                            : set screen rotation mode
    tft.set_Display_ON(DisplayStatus)                             : set display
    tft.set_InvertMode(InvertMode)                                : set color inversion

*/