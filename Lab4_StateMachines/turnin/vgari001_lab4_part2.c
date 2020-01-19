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
#define A0 PINA & 0x01
#define A1 PINA & 0x02
 enum C_States{ START, INIT, INC, DEC,RESET, WAIT} C_STATE;

    unsigned char tempC = 0x00;

void C_Tick(){
	


	switch(C_STATE){
		
		case START:
			C_STATE= INIT;
			break;
		
		case INIT:
			if(A0 & (!A1)){
				C_STATE = INC;
			}
			else if((!A0) & A1 ){
				C_STATE = DEC;
			}
	
			else if((!A0) & (!A1)){
				C_STATE =INIT;
			}
			break;

		case INC:
			if(A0 & A1){
				C_STATE = RESET;
			}
			
			else if((!A0)  & A1){
			 	C_STATE = DEC;
			}
			
			else if((!A0) & (!A1)){

				C_STATE = WAIT;
			break;

		case DEC:
			if(A0 & (!A1)){
				C_STATE = INC;
			}
				
			else if((!A0) & A1){
				C_STATE = WAIT;
			}
			
			else if(A0 & A1){
				C_STATE = RESET
			}

			break;

		case RESET:
			   if(A0 & (!A1)){
				C_STATE = INC;
			}
			
		      	else if( !A0 & A1){
	        			C_STATE = DEC;
			}

			else if((!A0) & (!A1)){
				C_STATE = WAIT;
			}

			break;

		case WAIT:
			if(A0 & (!A1)){
				C_STATE = INC;
			}
			
			else if((!A0) & A1 ){

				C_STATE = DEC;
			}
			
			else if(A0 & A1){
				C_STATE = RESET;
			}

			break;

		default:
			C_STATE = START;
			break;
	}
	
	switch(C_STATE){
                         
			case START:
				break;
			
			case INIT: 
				tempC = 0x07;
				break;
			
			case INC:
				 if(tempC < 0x09){
				tempC= tempC + 0x01;
				}
				break;
			
			case DEC:
				if(tempC > 0x00){
				tempC = tempC - 0x01;
				}
				break;
		
			case WAIT:
				tempC = 0x00;
				break;
			default:
				break;
		}

	PORTC = tempC;
	}
	

int main(void) {
	
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	    
	C_STATE = START;
    /* Insert your solution below */
    while (1) {
	C_Tick();
		
    }
    return 1;
}
