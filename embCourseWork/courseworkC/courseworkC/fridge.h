/*
 * fridge.h
 *
 * Created: 26/10/2023 20:13:16
 *  Author: HP
 */ 


#ifndef FRIDGE_H_
#define FRIDGE_H_

void keypad();
void rotate(unsigned int number);
void dispenseWater(int x);
void collectMoney();
void fridge_latch();
void fridge_lcd_cmd(unsigned char cmd);
void fridge_lcd_data(unsigned char data);
void fridge_lcd_init();
void fridge_lcd_clear();
void fridge_lcd_string(char *str);




#endif /* FRIDGE_H_ */