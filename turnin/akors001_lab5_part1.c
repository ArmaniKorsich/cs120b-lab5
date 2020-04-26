/*	Author: akors001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char level = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char i = 0x00;
    /* Insert your solution below */
    while (1) {

	i = 0x00;
	level = 0x00;
	tmpC = 0x00;
	PORTC = 0x00;
	
	//Turn PA3..PA0 into a number
	for (i = 0x01; i <= 0x08; i = 2 * i)
	{
		if((PINA & i) == 0)
		{
			level = level  + i;
		}
	}

	
	//
	tmpC = 0;
	if (level == 0)
	{
		tmpC = 0b01000000;
	}
	else if (level <= 2)
	{
		tmpC = 0b01100000;	
	}
	else if (level <= 4)
	{
		tmpC = 0b01110000;
	}
	else if (level <= 6)
	{
		tmpC = 0b00111000;
	}
	else if (level <= 9)
	{
		tmpC = 0b00111100;
	}
	else if (level <= 12)
	{
		tmpC = 0b00111110;	
	}
	else //13- 15
	{
		tmpC = 0b00111111;	
	}
		
	PORTC = tmpC;

    }
    return 1;
}
