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
	DDRB =0x00; PORTB = 0xFF;
	DDRC = 0xFF ; PORTC = 0x00;

       // unsigned char PENA0  = 0x00;
//	unsigned char PENB0 = 0x00;	
	unsigned char i=0x00;
	unsigned short counter = 0x00;
	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;

    
    while (1) {
  //     PENA0 = PINA & 0x01;
    //   PENB0 = PINA & 0x01;
	counter =  0x00;
	tempA = PINA;
	tempB = PINB;

	for(i=0; i<9; ++i){
		
		if(tempA  & 0x01){

			counter++;
		
		}
	tempA =	tempA>>1;

		if(tempB & 0x01){

		counter++;
		}

	tempB = tempB>>1;

    }
      PORTC= counter;

    }
    return 1;
}
