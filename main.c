#define F_CPU 11059200UL

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

#include "shift_reg.h"



int main() {
	DDRA = 0b10111111;
	DDRB = 0b11111110;
	DDRC = 0b01111100;
	DDRD = 0b10011111;
	lcd_init();
	_delay_us(100);
	lcd_com(0b00010100);
	_delay_us(100);
	lcd_com(RET_HOME);
	lcd_dat(0x41);
	int b =0;
	while (1) {
//		_delay_ms(20);
		send_data((unsigned char)recv_data());
//		lcd_init();
//		lcd_bin_out(recv_data());
        _delay_ms(5000);
        send_data((unsigned char)(recv_data() >> 8));
        lcd_com(RET_HOME);
    	for(uint8_t i=0;i<32;i++) {
    	lcd_dat(b+i);
    	}
    	b+=15;
    	if (b>255) b=0;
	}
}
