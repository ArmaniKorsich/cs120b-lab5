/*	Author: armanikorsich
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	VIDEO LINK::::::
 *	https://www.youtube.com/watch?v=LIaJKuIqBG0
 *	VIDEO LINK::::::
 */	
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum SM_States { first, second} state;
unsigned char count = 0;
unsigned char arrfirst[] = {0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
void TickFct() {

	switch(state) {
		case first:
			if ((PINA & 0x01) == 0x00) {
				state = second;
				count = count + 1;
			} else {
				state = first;
			}
			break;
		case second:
			if ((PINA & 0x01) == 0x00) {
				state = second;
			} else {
				state = first;
			}
			break;
		default:
			state = first;
			break;

	}

	switch(state) {
		case first:
			if (count == 9) {
				count = 0;
			}
			PORTC = arrfirst[count];
			break;
		case second:
			break;
		default:
			count = 0;
			break;
	}
	
}


int main(void) {
    /* Insert DDR and PORT initializations */
   count = 0;
   state = first;
   DDRA = 0x00; PORTA = 0xFF;
   DDRC = 0xFF; PORTC = 0x00;


    /* Insert your solution below */
    while (1) {
	TickFct();
    }
    return 1;
}
