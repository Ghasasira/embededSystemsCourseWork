/*
 * virtualMonitor.h
 *
 * Created: 28/10/2023 19:32:48
 *  Author: HP
 */ 


#ifndef VIRTUALMONITOR_H_
#define VIRTUALMONITOR_H_


void UART_init();
void transmit_char(char data);
uint8_t read_data(uint16_t address);
void write_data(uint16_t address, uint8_t data);
char receive_char();
void intro_text();
//void print_commands();
//void handle_input();


#endif /* VIRTUALMONITOR_H_ */