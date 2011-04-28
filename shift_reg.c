/*
 * shift_reg.c
 *
 *  Created on: 27.04.2011
 *      Author: kyznecov
 */
#include <avr/io.h>
#include "shift_reg.h"

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
}

unsigned int recv_data() {
	unsigned int data = 0x0000;
	PORTD &= ~_BV(STR_IN);
	PORTD |= _BV(STR_IN);
	PORTD &= ~_BV(STR_IN);
	asm("nop");
	PORTB &= ~_BV(CLK);
	for (int i = 0; i < 8; i++) {
		if(	bit_is_set(PINB,D_IN)) {
			data = data << 1;
			data++;
		}
		else {
			data = data << 1;

		}
		PORTB &= ~_BV(CLK);
		asm("nop");
		PORTB |= _BV(CLK);
		asm("nop");
	}
	return data;
}
