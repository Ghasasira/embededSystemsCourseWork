/*
 * lcd.h
 *
 * Created: 26/10/2023 18:26:49
 *  Author: HP
 */ 


#ifndef LCD_H_
#define LCD_H_


void latch();
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char data);
void lcd_init();
//void lcd_clear();
void lcd_string(const char *str);




#endif /* LCD_H_ */