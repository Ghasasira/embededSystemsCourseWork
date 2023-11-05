#include "lcd.h"
#include <avr/io.h>
#include <util/delay.h>

#define rs PB2
#define rw PB1
#define enable PB0
#define dataline PORTA

void latch()
{
	PORTB |= (1 << enable);
	_delay_ms(15);
	PORTB &= ~(1 << enable);
	_delay_ms(15);
}

void lcd_cmd(unsigned char cmd)
{
	latch();
	PORTB &= ~(1 << rs);
	_delay_ms(5);
	PORTB &= ~(1 << rw);
	dataline = cmd;
	latch();
}
void lcd_init()
{
	// Configure the control pins (rs, rw, enable) as output
	//DDRB |= (1 << rs) | (1 << rw) | (1 << enable);
	// Configure the data lines (PORTA) as output
	//DDRA = 0xFF;

	_delay_ms(15); // Wait for LCD to power up
	lcd_cmd(0x38); // 8-bit mode, 2 lines, 5x7 font
	lcd_cmd(0x01); // Clear the display
	lcd_cmd(0x0F); // Display on, cursor on
	lcd_cmd(0x06); // Increment cursor
}



void lcd_data(unsigned char data)
{
	latch();
	PORTB |= (1 << rs);
	_delay_ms(5);
	PORTB |= (1 << rw);
dataline = data;
	latch();
}

void lcd_string(const char* str)
{
	// Display a string on the LCD
	while (*str)
	{
		lcd_data(*str);
		str++;
	}
}
