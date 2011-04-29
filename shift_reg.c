/*
 * shift_reg.c
 *
 *  Created on: 27.04.2011
 *      Author: kyznecov
 */
#include <avr/io.h>
#include "shift_reg.h"
#include <util/delay.h>

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

unsigned int recv_data() {
	volatile unsigned int data = 0x0000;
	PORTD &= ~_BV(STR_IN);
	PORTD |= _BV(STR_IN);
	PORTD &= ~_BV(STR_IN);
	for (int i = 0; i < 16; i++) {
		if(bit_is_set(PINB,D_IN)) {
			data = data << 1;
			++data;
		}
		else {
			data = data << 1;
		}
		PORTB &= ~_BV(CLK);
		PORTB |= _BV(CLK);
	}
	return data;
}
