/*	Author: vgari001
 *  Partner(s) Name: Victoria Albezer
 *	Lab Section: 022
 *	Assignment: Lab #3  Exercise #1
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
	DDRA = 0x00; PORTA =0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF ; PORTC = 0x00;

        unsigned char PENA0  = 0x00;
	unsigned char PENB0 = 0x00;	
	unsigned char i=0x00;
	unsigned char counter = 0x00;
	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;
    /* Insert your solution below */
    while (1) {
	
	 
       PENA0 = PINA & 0x01;
       PENB0 = PINA & 0x01;
	counter =  0;
	tempA = PENA0;
	tempB = PENB0;
	for(i=0; i<8; ++i){
		
		if(tempA  == 0x01){

			counter++;
		
		}
	tempA =	PENA0>>1;

		if(tempB == 0x01){
		counter++;
		}

	tempB = PENB0>>1;

    }
      PORTC= counter;
 }
    return 1;
}
