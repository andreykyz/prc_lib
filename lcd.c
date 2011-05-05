/*
 * lcd.c
 *
 *  Created on: 03.05.2011
 *      Author: kyznecov
 */

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"



void lcd_init() {
	lcd_com(0b00101100); //Шина 4 бит lcd 2 строки
	_delay_us(100);
	lcd_com(0b00001101); //Диспелй включен,курсор в виде квадрата, мигает
//	lcd_com(0x01);
	_delay_us(100);
	lcd_com(0b00000001); //Очистка дисплея и курсор в начало
//	lcd_com(0x06);
//	lcd_com(0x0D);
}
/*Запись байта команды*/
void lcd_com(uint8_t byte_d) {
	PORT_LCD_RS &= ~_BV(LCD_RS);
	lcd_byte(byte_d);
}

/*Запись байта данных*/
void lcd_dat(uint8_t byte_d) {
	PORT_LCD_RS |= _BV(LCD_RS);
	lcd_byte(byte_d);
}

/*передача ниббла*/
void lcd_bit(uint8_t byte_d) {
	if (0b0001 & byte_d) {
		PORT_D0 |= _BV(D0);
	}
	else {
		PORT_D0 &= ~_BV(D0);
	}
	if (0b0010 & byte_d) {
		PORT_D1 |= _BV(D1);
	}
	else {
		PORT_D1 &= ~_BV(D1);
	}
	if (0b0100 & byte_d) {
		PORT_D2 |= _BV(D2);
	}
	else {
		PORT_D2 &= ~_BV(D2);
	}
	if (0b1000 & byte_d) {
		PORT_D3 |= _BV(D3);
	}
	else {
		PORT_D3 &= ~_BV(D3);
	}
}

/*Запись байта данных или комманды*/
void lcd_byte(uint8_t byte_d) {
	PORT_LCD_E |= _BV(LCD_E);
	lcd_bit(byte_d >> 4); //старший нибл
	_delay_us(100);
	PORT_LCD_E &= ~_BV(LCD_E);
	_delay_us(100);
	PORT_LCD_E |= _BV(LCD_E);
	lcd_bit(byte_d); //младший нибл
	_delay_us(100);
	PORT_LCD_E &= ~_BV(LCD_E);
	_delay_us(100);
}

void lcd_bin_out(uint16_t word_d) {
	lcd_X(0);
	for (int i=0; i<16;i++) {
		lcd_dat((word_d & 0b1) + 0b00110000);
		word_d <<= 1;
	}
}
