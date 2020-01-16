/*	Author: vgari001
 *  Partner(s) Name: Victoria
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
#define A0 PINA & 0x001
 enum LED_States{ START, INIT, BOFF} LED_STATE;

unsigned char tempB = 0x00;

void LED_Tick(){
	
	switch(LED_STATE){
		
		case START:
			LED_STATE = INIT;
			break;
		
		case INIT:
			if(!A0){
				LED_STATE = INIT;
			}
			else if(A0){
				LED_STATE = BOFF;
			}
			break;

		case BOFF:
			if(!A0){
				LED_STATE = BOFF;
			}
			
			else if(A0){
				LED_STATE = INIT;
			}
			break;

		default:
			LED_STATE = START;
			break;
	}
	
	switch(LED_STATE){
                         tempB = PINB;
				case START:
				break;
			
			case INIT: 
				tempB =0x01;
				break;
			
			case BOFF:
				tempB = 0x02;
				break;
	
			default:
				break;
		}

	PORTB = tempB;
	}
	

int main(void) {
    
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	LED_STATE = START;
    /* Insert your solution below */
    while (1) {
	LED_Tick();
		
    }
    return 1;
}
