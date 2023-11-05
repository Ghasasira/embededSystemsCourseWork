/*
 * courseworkC.c
 *
 * Created: 25/10/2023 22:14:06
 * Author : HP
 */ 

#include <avr/io.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd.h"
#include "fridge.h"
#include "gate.h"
#include "virtualMonitor.h"




ISR(INT0_vect){
	//startMotor();
	//startMotor();
	_delay_ms(5);
	PORTC =0xff;
	_delay_ms(2000);
	PORTC =0x00;

}

ISR(INT1_vect){
	//startMotor();
	_delay_ms(5);
	PORTC =0xff;
	_delay_ms(1000);
	PORTC =0x00;
	
}



int main(void)
{
	DDRF=0xff;
	DDRH=0xff;
	DDRD=0x0;
	DDRA = 0xff;  // Data lines as output
	DDRB = 0xff;  // Control lines as output
	
	DDRJ=0b00001111;
	DDRK=0xff;
	DDRC=0xff;
	
	sei();
	EIMSK|=(1<<INT0)|(1<<INT1);
	EICRA|=(1<<ISC01)|(1<<ISC11);	
	
	PORTJ=0xff;
	
	//PORTA = 0x0;
	//PORTB = 0x0;
	PORTK=0x0;
	PORTD=0x0;
	PORTC=0x00;
	
	
	keypad();
	lcd_init();
	lcd_data('w');
	//lcd_data('w');
	//initBell();
	//initInterrupt();
	
	// Initialize USART1 communication
	UART_init();
	transmit_char('a');

	/*transmit_char('H');
	transmit_char('e');
	transmit_char('l');
	transmit_char('p');
	transmit_char('\n');
	transmit_char('W');
	transmit_char('- Write data to EEPROM\n\r ');
	transmit_char('R');
	transmit_char('- Read data from EEPROM\n\r');*/

	// Example data to write and read from EEPROM
	//uint16_t eeprom_address = 0;
	//uint8_t data_to_write = 42;
	//uint8_t data_read;
	
	/* Replace with your application code */
	while (1)
	{
	
	//intro_text();

}
return 0;

}