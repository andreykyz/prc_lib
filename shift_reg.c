/*
 * shift_reg.c
 *
 *  Created on: 27.04.2011
 *      Author: kyznecov
 */
#include <avr/io.h>
#include "shift_reg.h"
#include <util/delay.h>

unsigned char data_buff = 0x00;
/*запись данных в сдвиговый регистр*/
void send_data(unsigned char data) {
//	PORTB &= ~_BV(CLK);
//	PORTB |= _BV(CLK);
	for (int i = 0; i < 8; i++) {
		if (data & 0x80) {
			PORTB |= _BV(D);
		} else {
			PORTB &= ~_BV(D);
		}
		PORTB &= ~_BV(CLK);
		data = data << 1;
		PORTB |= _BV(CLK);
	}
	PORTB &= ~_BV(STR_OUT);
	PORTB |= _BV(STR_OUT);
	_delay_ms(10);
}

/*чтение данных из 2-х последовательных сдвиговых регистров*/
unsigned int recv_data() {
	unsigned int data = 0x0000;
	PORTD |= _BV(STR_IN);
	PORTD &= ~_BV(STR_IN);
	PORTD |= _BV(STR_IN);
	for (int i = 0; i < 16; i++) {
		data <<= 1;
		data |= bit_is_set(PINB,D_IN) ? 1:0;

		PORTB &= ~_BV(CLK);
		PORTB |= _BV(CLK);
	}
	return data;
}

void rele_on(unsigned char rele_pin) {
	data_buff |= _BV(rele_pin);
	send_data(data_buff);
}

void rele_off(unsigned char rele_pin) {
	data_buff &= ~_BV(rele_pin);
	send_data(data_buff);
}
