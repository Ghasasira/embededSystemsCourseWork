/*
 * fridge.c
 *
 * Created: 26/10/2023 18:00:54
 *  Author: HP
 */ 
#include "fridge.h"
#include <avr/io.h>
#include <util/delay.h>
#define rs PF2
#define rw PF1
#define enable PF0
#define dataline PORTH




void dispenseWater(int x) {
	PORTK=0b00000010;
	_delay_ms(2000);
	PORTK=0x0;
}

void collectMoney() {
	PORTK=0b00001000; // for rotate clock wise
	_delay_ms(2000);
	PORTK=0b00000100;
	PORTK=0x0; // for rotate clock wise
	_delay_ms(100);
	//PORTK &= ~(1 << 1); //stop the motor
}



/*
void rotate(unsigned int number){
	PORTK=0b00000010; // for rotate clock wise
	_delay_ms(2000);
	PORTK=0b00000001; // for anti clockwise
	_delay_ms(2000);

	
}*/

void fridge_latch()
{
	PORTF &=~(1<<enable);
	_delay_ms(10);
	PORTF |=(1<<enable);
	_delay_ms(10);
	
}

void fridge_lcd_init(){
	_delay_ms(15);  // Wait for LCD to power up
	
	fridge_lcd_cmd(0x38); // 8-bit mode, 2 lines, 5x7 font
	fridge_lcd_cmd(0x01); // Clear the display
	fridge_lcd_cmd(0x0F); // Display on, cursor on
	fridge_lcd_cmd(0x06); // Increment cursor
}

	


void fridge_lcd_cmd(unsigned char cmd){
	dataline = cmd;
	fridge_latch();
	PORTF &=~(1<<rs);
	_delay_ms(5);
	PORTF &=~(1<<rw);
	
	fridge_latch();
}

void fridge_lcd_data(unsigned char data){
	dataline = data;
	fridge_latch();
	PORTF |=(1<<rs);
	_delay_ms(5);
	PORTF &=~(1<<rw);
	
	fridge_latch();
	
}



void fridge_lcd_string(char *str) {
	// Display a string on the LCD
	while (*str) {
		lcd_data(*str);
		str++;
	}
	//fridge_lcd_data(str);
}









void keypad(){
	PORTK=0x0;
	PORTF = 0xff;
	PORTH = 0xff;
	DDRJ=0b00001111;
	PORTJ=0xff;
	
	fridge_lcd_init();
	
	
	while(1){
		
		//rotate(2);
		PORTH=0xff;  
		PORTJ=0xff;
		PORTJ&=~(1<<3);
		if ((PINJ&(1<<4))==0)
		{ 
			collectMoney();
			//on
			//stopMotor();
			//rotate(2);
		}else if ((PINJ&(1<<5))==0)
		{
			fridge_lcd_data('1');
			//0
			//rotate(2);
			//rotate(5);
		}else if ((PINJ&(1<<6))==0)
		{
			//=
			//rotate(8);
		}
		PORTJ=0xff;
		PORTJ&=~(1<<2);
		if ((PINJ&(1<<4))==0)
		{
			//1
			//rotate(2);
		}else if ((PINJ&(1<<5))==0)
		{
			dispenseWater(5);
			//2
			//rotate(5);
		}else if ((PINJ&(1<<6))==0)
		{
			//3
			//rotate(8);
		}
		PORTJ=0xff;
		PORTJ&=~(1<<1);
		if ((PINJ&(1<<4))==0)
		{
			//4
		}else if ((PINJ&(1<<5))==0)
		{
			//5
		}else if ((PINJ&(1<<6))==0)
		{
			//6
		}
		PORTJ=0xff;
		PORTJ&=~(1);
		if ((PINJ&(1<<4))==0)
		{
			//7
			
		}else if ((PINJ&(1<<5))==0)
		{
			//8
			//stopMotor();
			//rotate(5);
		}else if ((PINJ&(1<<6))==0)
		{
			//9
		}
		
	}
}

