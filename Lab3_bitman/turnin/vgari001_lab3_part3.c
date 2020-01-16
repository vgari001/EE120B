/*	Author: vgari001
 *  Partner(s) Name: Victoria Albezer
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
    

        DDRA = 0x00; PORTA =0xFF;
	DDRC = 0xFF ; PORTC = 0x00;

	unsigned char fuelLevel =0x00;
	unsigned char levelLight = 0x00;
	unsigned char tempA = 0x00;
    	
    while (1) {
	
		fuelLevel = PINA & 0xFF;
		tempA = PINA & 0x70;

		switch(fuelLevel){
			
			case 0x00:
				levelLight = 0x40;
				break;

			case 0x01:
			case 0x02:
				levelLight = 0x60;
				break;

			case 0x03: 
			case 0x04:
				levelLight = 0x70;
				break;
			case 0x05:
			case 0x06:
				levelLight = 0x38;
				break;

			case 0x07:
			case 0x08:
			case 0x09:
				levelLight = 0x3C;
				break;


			case 0x0A:
			case 0x0B:
			case 0x0C:
				levelLight = 0x3E;
				break;
			
			case 0x0D:
			case 0x0E:
			case 0x0F:
				levelLight = 0x3F;
				break;
			}
			
			if(tempA == 0x30){
				levelLight = 0x80;
			}
	PORTC = levelLight;
	levelLight = 0x00;				

}	
    return 1;
}

