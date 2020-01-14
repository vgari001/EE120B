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

      unsigned char PINA0  = 0x00;
	unsigned char PINB0 = 0x00;	
	unsigned char i=0x00;
	unsigned char counter = 0x00;
    /* Insert your solution below */
    while (1) {
	
 
       PINA0 = PINA & 0x01;
       PINB0 = PINB & 0x01;
	counter =  0;

	for(i=0; i<8; ++i){
		
		if(PINA0  == 0x01){

			counter++;
		
		}
	PORTA>>1;

		if(PINB0 == 0x01){
		counter++;
		}

	PORTB>>1;

    }
 }
    return 1;
}
