/*
 * lcd.h
 *
 *  Created on: 03.05.2011
 *      Author: kyznecov
 */

#ifndef LCD_H_
#define LCD_H_

//Память данных индикатора (PORTC)

#define D0 2
#define D1 3
#define D2 4
#define D3 5

#define LCD_E 7 // (PORTD)
#define LCD_RS 6 // (PORTC)

#define PORT_D0 PORTC
#define PORT_D1 PORTC
#define PORT_D2 PORTC
#define PORT_D3 PORTC
#define PORT_LCD_E PORTD // (PORTD)
#define PORT_LCD_RS PORTC // (PORTC)

#define lcd_X(pos) lcd_com((0x80|( (pos)&(0x0f) )|( ((pos)&(0xf0) )<<2 )))

//commands
#define RET_HOME 0x2

void lcd_init();
void lcd_com(uint8_t);
void lcd_byte(uint8_t);
void lcd_dat(uint8_t);
void lcd_bin_out(uint16_t);

#endif /* LCD_H_ */
