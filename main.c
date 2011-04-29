#define F_CPU 11059200UL

#include <avr/io.h>
//#include <util/delay.h>
#include "main.h"
#include "shift_reg.h"

unsigned char data_buff = 0x00;

int main() {
	DDRB = 0b1110;
	DDRD = 0b10000;
//	PORTB|= 0b1;
	while (1) {
		send_data((unsigned char)recv_data());
	}
}
void rele_on(unsigned char rele_pin) {
	data_buff |= _BV(rele_pin);

	send_data(data_buff);
}

void rele_off(unsigned char rele_pin) {
	data_buff &= ~_BV(rele_pin);
	send_data(data_buff);
}

