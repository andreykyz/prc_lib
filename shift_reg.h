/*
 * shiFt_reg.h
 *
 *  Created on: 27.04.2011
 *      Author: kyznecov
 */

#ifndef SHIFT_REG_H_
#define SHIFT_REG_H_

#define CLK	1
#define D	2
#define D_IN	0
#define STR_OUT	3
#define STR_IN	4 // PORTD


void send_data(unsigned char);
unsigned int recv_data();
void rele_on(unsigned char);
void rele_off(unsigned char);

#endif /* SHIFT_REG_H_ */
