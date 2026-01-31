
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *
 *	File		:	HANUMAN_32__TFT_ST7735S.cpp
 *	Release		:	v0.1.1
 *
 *	Created on	:	Tue 27 Jan 2026
 *		Author	:	hii-nice-2-meet-u
 *
 */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "HANUMAN_32__TFT_ST7735S.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

TFT_ST7735S::TFT_ST7735S(void)
{
	SPI_Device.begin();

	pinMode(__DEFINE__SPI_TFT_CS, OUTPUT);
	pinMode(__DEFINE__SPI_TFT_DC, OUTPUT);
	digitalWrite(__DEFINE__SPI_TFT_CS, HIGH);
	digitalWrite(__DEFINE__SPI_TFT_DC, HIGH);

	set_SleepMode(0);
	// SoftwareReset();

	SendCommandAndData_8b(0xC0, 0x10);
	SendCommandAndData_8b(0xC1, 0x05);
	SendCommandAndData_16b(0xC2, (uint16_t)0x0A << 8);
	SendCommandAndData_8b(0xC5, 0x3E);
	SendCommandAndData_8b(0x3A, 0x05);

	SendCommand(0xE0);
	uint8_t gammaPos[] = {0x0F, 0x1A, 0x0F, 0x18, 0x2F, 0x28, 0x20, 0x22, 0x1F, 0x1B, 0x23, 0x37, 0x00, 0x07, 0x02, 0x10};
	SendDataBytes(gammaPos, 16);

	SendCommand(0xE1);
	uint8_t gammaNeg[] = {0x0F, 0x1B, 0x0F, 0x17, 0x33, 0x2C, 0x29, 0x2E, 0x30, 0x30, 0x39, 0x3F, 0x00, 0x07, 0x03, 0x10};
	SendDataBytes(gammaNeg, 16);

	set_RotationMode(0);
	set_InvertMode(0);
	set_Display_ON(1);

	fill_Screen(0x00);
}

//"" --------------------------------

void TFT_ST7735S::text(uint8_t line, uint8_t col, const char* text, ...)
{
	if (TFT_ST7735S::_height == 159)
	{
		if (line > 16 || col > 20)
			return;
	}
	else
	{
		if (line > 13 || col > 25)
			return;
	}

	uint8_t posX = 2 + col * 6;
	uint8_t posY = 2 + line * 9;

	char  buffer[36] = "";
	char* ptr        = buffer;

	va_list args;
	va_start(args, text);
	vsnprintf(buffer, sizeof(buffer), text, args);
	va_end(args);

	uint8_t cursor_x = posX;
	while (*ptr)
	{
		draw_Char(cursor_x, posY, *ptr, TFT_ST7735S::_TextColor);
		cursor_x += 6;
		ptr++;

		if (cursor_x > _width)
			break;
	}
}

void TFT_ST7735S::textWithBackground(uint8_t line, uint8_t col, const char* text, ...)
{
	if (TFT_ST7735S::_height == 159)
	{
		if (line > 16 || col > 20)
			return;
	}
	else
	{
		if (line > 13 || col > 25)
			return;
	}

	uint8_t posX = 2 + col * 6;
	uint8_t posY = 2 + line * 9;

	char*   ptr;
	char    buffer[36] = "";
	uint8_t counter    = 0;

	va_list args;
	va_start(args, text);
	vsnprintf(buffer, sizeof(buffer), text, args);
	va_end(args);

	ptr = buffer;
	while (*ptr)
	{
		counter++;
		ptr++;
	}
	ptr = buffer;

	uint16_t totalPixel = 11 * (3 + (counter * 6));
	SetAddrWindow((posX - 2), (posY - 2), (posX + (counter * 6)), (posY + 8));
	for (uint16_t iii = 0; iii < totalPixel; iii++)
		SendData_16b(TFT_ST7735S::_TextBackgroundColor);

	uint8_t cursor_x = posX;
	uint8_t character;
	while (*ptr)
	{
		character = *ptr;

		if (character < 32 || character > 127)
			character = 32;
		character -= 32;

		const uint8_t* _bitmap = TFT_ST7735S::BitmapFont[character];
		SetAddrWindow(cursor_x, posY, cursor_x + 4, posY + 7);

		digitalWrite(__DEFINE__SPI_TFT_DC, HIGH);
		digitalWrite(__DEFINE__SPI_TFT_CS, LOW);
		privSPI_TFT->beginTransaction(SPISettings_TFT_ST7735S);

		uint16_t _area = (((5 * 8) + 7) / 8);
		do
		{
			uint8_t jjj = 7;
			do
			{
				if (*_bitmap & (1 << jjj))
				{
					privSPI_TFT->write16(TFT_ST7735S::_TextColor);
				}
				else
				{
					privSPI_TFT->write16(TFT_ST7735S::_TextBackgroundColor);
				}
			} while (jjj--);
			_bitmap++;
		} while (--_area);

		privSPI_TFT->endTransaction();
		digitalWrite(__DEFINE__SPI_TFT_CS, HIGH);

		cursor_x += 6;
		ptr++;

		if (cursor_x > _width)
			break;
	}
}

void TFT_ST7735S::clear(void)
{
	TFT_ST7735S::fill_Screen(COLOR_BLACK);
}

void TFT_ST7735S::fill_Screen(uint16_t color)
{
	SetAddrWindow(0, 0, _width, _height);

	digitalWrite(__DEFINE__SPI_TFT_DC, HIGH);
	digitalWrite(__DEFINE__SPI_TFT_CS, LOW);

	privSPI_TFT->beginTransaction(SPISettings_TFT_ST7735S);
	for (uint32_t i = 0; i < 20480UL; i++)
	{
		privSPI_TFT->write16(color);
	}
	privSPI_TFT->endTransaction();
	digitalWrite(__DEFINE__SPI_TFT_CS, HIGH);
}

void TFT_ST7735S::draw_Bitmap(uint8_t posX, uint8_t posY, const uint8_t* _bitmap, uint8_t width, uint8_t length, uint16_t color)
{
	SetAddrWindow(posX, posY, posX + width - 1, posY + length - 1);

	digitalWrite(__DEFINE__SPI_TFT_DC, HIGH);
	digitalWrite(__DEFINE__SPI_TFT_CS, LOW);

	privSPI_TFT->beginTransaction(SPISettings_TFT_ST7735S);

	uint16_t _area = (((width * length) + 7) / 8);
	do
	{
		uint8_t jjj = 7;
		do
		{
			if (*_bitmap & (1 << jjj))
			{
				privSPI_TFT->write16(color);
			}
			else
			{
				privSPI_TFT->write16(TFT_ST7735S::_BackgroundColor);
			}
		} while (jjj--);
		_bitmap++;
	} while (--_area);

	privSPI_TFT->endTransaction();

	digitalWrite(__DEFINE__SPI_TFT_CS, HIGH);
}

void TFT_ST7735S::draw_Bitmap(uint8_t posX, uint8_t posY, uint8_t* _bitmap, uint8_t width, uint8_t length, uint16_t color)
{
	draw_Bitmap(posX, posY, (const uint8_t*)_bitmap, width, length, color);
}

void TFT_ST7735S::draw_BitmapColor(uint8_t posX, uint8_t posY, const uint16_t* _bitmap, uint8_t width, uint8_t length)
{
	SetAddrWindow(posX, posY, posX + width - 1, posY + length - 1);

	digitalWrite(__DEFINE__SPI_TFT_DC, HIGH);
	digitalWrite(__DEFINE__SPI_TFT_CS, LOW);

	privSPI_TFT->beginTransaction(SPISettings_TFT_ST7735S);

	uint16_t _area = (width * length);
	do
	{
		privSPI_TFT->write16(*_bitmap++);
	} while (--_area);

	privSPI_TFT->endTransaction();

	digitalWrite(__DEFINE__SPI_TFT_CS, HIGH);
}

void TFT_ST7735S::draw_BitmapColor(uint8_t posX, uint8_t posY, uint16_t* _bitmap, uint8_t width, uint8_t length)
{
	draw_BitmapColor(posX, posY, (const uint16_t*)_bitmap, width, length);
}

void TFT_ST7735S::draw_Char(uint8_t posX, uint8_t posY, uint8_t character, uint16_t color)
{
	if (character < 32 || character > 127)
		character = 32;
	character -= 32;

	draw_Bitmap(posX, posY, TFT_ST7735S::BitmapFont[character], 5, 8, color);
}

void TFT_ST7735S::draw_Pixel(uint8_t posX, uint8_t posY, uint16_t color)
{
	SetAddrWindow(posX, posY, posX, posY);
	SendData_16b(color);
}

void TFT_ST7735S::draw_HorizonLine(uint8_t posX, uint16_t color)
{
	SetAddrWindow(posX, 0, posX, _height);

	digitalWrite(__DEFINE__SPI_TFT_DC, HIGH);
	digitalWrite(__DEFINE__SPI_TFT_CS, LOW);

	privSPI_TFT->beginTransaction(SPISettings_TFT_ST7735S);
	for (uint32_t i = 0; i < _height; i++)
	{
		privSPI_TFT->write16(color);
	}
	privSPI_TFT->endTransaction();
	digitalWrite(__DEFINE__SPI_TFT_CS, HIGH);
}

void TFT_ST7735S::draw_VerticalLine(uint8_t posY, uint16_t color)
{
	SetAddrWindow(0, posY, _width, posY);

	digitalWrite(__DEFINE__SPI_TFT_DC, HIGH);
	digitalWrite(__DEFINE__SPI_TFT_CS, LOW);

	privSPI_TFT->beginTransaction(SPISettings_TFT_ST7735S);
	for (uint32_t i = 0; i < _width; i++)
	{
		privSPI_TFT->write16(color);
	}
	privSPI_TFT->endTransaction();
	digitalWrite(__DEFINE__SPI_TFT_CS, HIGH);
}

void TFT_ST7735S::draw_Line(uint8_t posX0, uint8_t posY0, uint8_t posX1, uint8_t posY1, uint16_t color)
{
	if (posX0 > _width || posY0 > _height || posX1 > _width || posY1 > _height)
		return;

	int dx = abs(posX1 - posX0);
	int dy = abs(posY1 - posY0);
	int sx = posX0 < posX1 ? 1 : -1;
	int sy = posY0 < posY1 ? 1 : -1;

	int x = posX0;
	int y = posY0;
	if (dx > dy)
	{
		int err = dx / 2;
		while (x != posX1)
		{
			TFT_ST7735S::draw_Pixel(x, y, color);
			err -= dy;
			if (err < 0)
			{
				y += sy;
				err += dx;
			}
			x += sx;
		}
	}
	else
	{
		int err = dy / 2;
		while (y != posY1)
		{
			TFT_ST7735S::draw_Pixel(x, y, color);
			err -= dx;
			if (err < 0)
			{
				x += sx;
				err += dy;
			}
			y += sy;
		}
	}
	TFT_ST7735S::draw_Pixel(posX1, posY1, color);
}

void TFT_ST7735S::draw_Rectangle(uint8_t posX0, uint8_t posY0, uint8_t posX1, uint8_t posY1, uint16_t color)
{
	uint8_t x0 = min(posX0, posX1);
	uint8_t x1 = max(posX0, posX1);
	uint8_t y0 = min(posY0, posY1);
	uint8_t y1 = max(posY0, posY1);

	if (x0 > _width || y0 > _height || x1 > _width || y1 > _height)
		return;

	TFT_ST7735S::draw_Line(x0, y0, x1, y0, color);
	TFT_ST7735S::draw_Line(x1, y0, x1, y1, color);
	TFT_ST7735S::draw_Line(x1, y1, x0, y1, color);
	TFT_ST7735S::draw_Line(x0, y1, x0, y0, color);
}

void TFT_ST7735S::draw_Circle(uint8_t posX, uint8_t posY, uint8_t radius, uint16_t color)
{

	if (radius == 0)
	{
		draw_Pixel(posX, posY, color);
		return;
	}

	int8_t cx  = radius;
	int8_t cy  = 0;
	int8_t err = 3 - 2 * radius;

	while (cx >= cy)
	{

		draw_Pixel(posX + cx, posY + cy, color);
		draw_Pixel(posX + cy, posY + cx, color);
		draw_Pixel(posX - cy, posY + cx, color);
		draw_Pixel(posX - cx, posY + cy, color);
		draw_Pixel(posX - cx, posY - cy, color);
		draw_Pixel(posX - cy, posY - cx, color);
		draw_Pixel(posX + cy, posY - cx, color);
		draw_Pixel(posX + cx, posY - cy, color);

		if (err <= 0)
		{
			err += 4 * cy + 6;
		}
		else
		{
			err += 4 * (cy - cx) + 10;
			cx--;
		}
		cy++;
	}
}

void TFT_ST7735S::fill_Rectangle(uint8_t posX0, uint8_t posY0, uint8_t posX1, uint8_t posY1, uint16_t color)
{
	uint8_t x0 = min(posX0, posX1);
	uint8_t x1 = max(posX0, posX1);
	uint8_t y0 = min(posY0, posY1);
	uint8_t y1 = max(posY0, posY1);

	if (x0 > _width || y0 > _height || x1 > _width || y1 > _height)
		return;

	SetAddrWindow(x0, y0, x1, y1);
	uint16_t TotalPixel = (x1 - x0 + 1) * (y1 - y0 + 1);
	for (uint16_t iii = 0; iii < TotalPixel; iii++)
		SendData_16b(color);
}

void TFT_ST7735S::fill_Circle(uint8_t posX, uint8_t posY, uint8_t radius, uint16_t color)
{
	if (radius == 0)
	{
		draw_Pixel(posX, posY, color);
		return;
	}

	int8_t cx = 0;
	int8_t cy = radius;
	int8_t d  = 1 - radius;

	if (posX + radius < 0 || posX - radius >= _width || posY + radius < 0 || posY - radius >= _height)
		return;

	while (cx <= cy)
	{
		draw_FastHorizonLine(posX - cx, posY + cy, cx * 2 + 1, color);
		draw_FastHorizonLine(posX - cy, posY + cx, cy * 2 + 1, color);
		draw_FastHorizonLine(posX - cx, posY - cy, cx * 2 + 1, color);
		draw_FastHorizonLine(posX - cy, posY - cx, cy * 2 + 1, color);
		cx++;

		if (d < 0)
		{
			d += 2 * cx + 1;
		}
		else
		{
			cy--;
			d += 2 * (cx - cy) + 1;
		}
	}
}

void TFT_ST7735S::set_TextSize(uint8_t size)
{
	if (size > 2)
		size = 2;
	TFT_ST7735S::_TextSize = size;
}

void TFT_ST7735S::set_TextColor(uint16_t color)
{
	TFT_ST7735S::_TextColor = color;
}

void TFT_ST7735S::set_TextBackgroundColor(uint16_t color)
{
	TFT_ST7735S::_TextBackgroundColor = color;
}

void TFT_ST7735S::set_BackgroundColor(uint16_t color)
{
	TFT_ST7735S::_BackgroundColor = color;
}

void TFT_ST7735S::set_RotationMode(uint8_t RotationMode)
{
	SendCommand(0x36);

	TFT_ST7735S::_RotationMode = RotationMode % 4;
	switch (_RotationMode)
	{
	case 0:
		SendData_8b(0x60);
		break;
	case 1:
		SendData_8b(0xC0);
		break;
	case 2:
		SendData_8b(0xA0);
		break;
	case 3:
		SendData_8b(0x00);
		break;

	default:
		break;
	}

	if (TFT_ST7735S::_RotationMode % 2)
	{
		TFT_ST7735S::_height = 159;
		TFT_ST7735S::_width  = 127;
	}
	else
	{
		TFT_ST7735S::_height = 127;
		TFT_ST7735S::_width  = 159;
	}
}

void TFT_ST7735S::set_Display_ON(bool DisplayStatus)
{
	if (DisplayStatus)
		SendCommand(0x29);
	else
		SendCommand(0x28);
}

void TFT_ST7735S::set_InvertMode(bool InvertMode)
{
	if (InvertMode)
		SendCommand(0x21);
	else
		SendCommand(0x20);
}

//"" --------------------------------

void TFT_ST7735S::SendCommand(uint8_t cmd)
{
	digitalWrite(__DEFINE__SPI_TFT_DC, LOW);
	digitalWrite(__DEFINE__SPI_TFT_CS, LOW);
	privSPI_TFT->beginTransaction(SPISettings_TFT_ST7735S);
	privSPI_TFT->write(cmd);
	privSPI_TFT->endTransaction();
	digitalWrite(__DEFINE__SPI_TFT_CS, HIGH);
}

void TFT_ST7735S::SendCommandAndData_8b(uint8_t cmd, uint8_t data)
{
	TFT_ST7735S::SendCommand(cmd);
	TFT_ST7735S::SendData_8b(data);
}

void TFT_ST7735S::SendCommandAndData_16b(uint8_t cmd, uint16_t data)
{
	TFT_ST7735S::SendCommand(cmd);
	TFT_ST7735S::SendData_16b(data);
}

void TFT_ST7735S::SendData_8b(uint8_t data)
{
	digitalWrite(__DEFINE__SPI_TFT_DC, HIGH);
	digitalWrite(__DEFINE__SPI_TFT_CS, LOW);

	privSPI_TFT->beginTransaction(SPISettings_TFT_ST7735S);
	privSPI_TFT->write(data);
	privSPI_TFT->endTransaction();
	digitalWrite(__DEFINE__SPI_TFT_CS, HIGH);
}

void TFT_ST7735S::SendData_16b(uint16_t data)
{
	digitalWrite(__DEFINE__SPI_TFT_DC, HIGH);
	digitalWrite(__DEFINE__SPI_TFT_CS, LOW);

	privSPI_TFT->beginTransaction(SPISettings_TFT_ST7735S);
	privSPI_TFT->write16(data);
	privSPI_TFT->endTransaction();
	digitalWrite(__DEFINE__SPI_TFT_CS, HIGH);
}

void TFT_ST7735S::SendDataBytes(const uint8_t* buffer, uint16_t size_of_buffer)
{
	digitalWrite(__DEFINE__SPI_TFT_DC, HIGH);
	digitalWrite(__DEFINE__SPI_TFT_CS, LOW);

	privSPI_TFT->beginTransaction(SPISettings_TFT_ST7735S);
	for (uint16_t i = 0; i < size_of_buffer; i++)
	{
		privSPI_TFT->write(buffer[i]);
	}
	privSPI_TFT->endTransaction();
	digitalWrite(__DEFINE__SPI_TFT_CS, HIGH);
}

void TFT_ST7735S::SetAddrWindow(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1)
{
	if (TFT_ST7735S::_height == 159)
	{
		y0++;
		y1++;
		x0 += 2;
		x1 += 2;
	}
	else
	{
		x0++;
		x1++;
		y0 += 2;
		y1 += 2;
	}

	SendCommand(0x2A);
	SendData_16b(x0);
	SendData_16b(x1);

	SendCommand(0x2B);
	SendData_16b(y0);
	SendData_16b(y1);

	SendCommand(0x2C);
}

void TFT_ST7735S::SoftwareReset(void)
{
	SendCommand(0x01);
	delay(250);
}

void TFT_ST7735S::set_SleepMode(bool SleepMode)
{
	if (SleepMode)
		SendCommand(0x10);
	else
		SendCommand(0x11);

	delay(125);
}

void TFT_ST7735S::draw_FastHorizonLine(uint8_t posX, uint8_t posY, uint8_t length, uint16_t color)
{
	if (posX > _width || posY > _height || length == 0)
		return;

	SetAddrWindow(posX, posY, posX + length - 1, posY);
	for (uint16_t iii = 0; iii < length; iii++)
		SendData_16b(color);
}

void TFT_ST7735S::draw_FastVerticalLine(uint8_t posX, uint8_t posY, uint8_t length, uint16_t color)
{
	if (posX > _width || posY > _height || length == 0)
		return;

	SetAddrWindow(posX, posY, posX, posY + length - 1);
	for (uint16_t iii = 0; iii < length; iii++)
		SendData_16b(color);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
