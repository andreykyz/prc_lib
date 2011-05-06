

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
//#include <>
#include "shift_reg.h"



int main() {
	DDRA = 0b10111111;
	DDRB = 0b11111110;
	DDRC = 0b01111100;
	DDRD = 0b10011111;
	lcd_init();

/*	lcd_dat(0x41);
	lcd_dat(0x41);
	lcd_com(DDRAM+0x40);
	lcd_dat(0x42);
	lcd_dat(0x42);*/
	send_data(1);
	lcd_com(DDRAM+0x00);

	while (1) {
		_delay_ms(2000);
		send_data((unsigned char)recv_data());
///		lcd_init();
//		lcd_bin_out(recv_data());
//        _delay_ms(2000);
//        send_data((unsigned char)(recv_data() >> 8));
//        lcd_com(1);
        _delay_ms(50);
        lcd_com(DDRAM+0x00);
//        _delay_ms(2);
        lcd_bin_out(recv_data());
	}
}
