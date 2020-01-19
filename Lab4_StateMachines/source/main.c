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
enum C_States{ START, INIT, INC, DEC,RESET, WAIT} C_STATE;
	

    
    unsigned char count =0;
    unsigned char tempC = 0x00;
    unsigned char tempA = 0x00;
   // unsigned char PINA0 =0x00;
   // unsigned char PINA1 = 0x00;
   // unsigned char BOTH = 0x00;
void C_Tick(){

//unsigned char PENA0 = PINA & 0x01;
//	unsigned char PENA1 = PINA & 0x02;
//	unsigned char BOTH = PINA & 0xFC;
	 
	tempA = PINA & 0x03;
	switch(C_STATE){
		
		case START:
			C_STATE= INIT;
			break;
		
		case INIT:
			if(tempA == 0x01){
				C_STATE = INC;
			}
			else if(tempA == 0x02){
				C_STATE = DEC;
			}
			
			else if(tempA == 0x03){
				C_STATE = RESET;
			}
			
			else if(tempA == 0x00){
				C_STATE = WAIT;
			}
	
			break;

			
		case INC:
			if(tempA == 0x02){
				C_STATE = DEC;
			}
			
			else if(tempA == 0x03){
			 	C_STATE = RESET;
			}
			
			else if(tempA == 0x00){
				C_STATE = WAIT;
			}
			
			else if(tempA == 0x01){

			C_STATE = INC;
		}
			
			break;

		case DEC:
			if(tempA == 0x01){
				C_STATE = INC;
			}
				
			else if(tempA == 0x03){
				C_STATE = RESET;
			}

			else if(tempA == 0x00){
		
				C_STATE = WAIT;
			}
			else if(tempA == 0x02){

				C_STATE = DEC;
			}
			break;
		

		case RESET:
			   if(tempA == 0x01){
				C_STATE = INC;
			}
			
		      	else if(tempA == 0x02){
	        			C_STATE = DEC;
			}
			
			else if(tempA == 0x00){
			
				C_STATE = WAIT;
			}
			

			break;

		case WAIT:
			if(tempA == 0x01){
				C_STATE = INC;
			}
			
			else if(tempA ==0x02){

				C_STATE = DEC;
			}
			
			else if(tempA = 0x03){
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
				tempC= tempC + 1;
				}
				break;
			
			case DEC:
				if(tempC > 0x00){
				tempC = tempC - 1;
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
//	count =0x07;
    /* Insert your solution below */
    while (1) {
	C_Tick();
		
    }
    return 1;
}
