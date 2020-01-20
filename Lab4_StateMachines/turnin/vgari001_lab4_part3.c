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
#define PENA 0xFF & PINA
enum LOCK_States{ START, INIT, LOCK, WAIT,UNLOCK, Y} LOCK_STATE;
	

    
    unsigned char tempC = 0x00;
   // unsigned char xbut =0x00;
   // unsigned char ybut = 0x00;
   // unsigned char pbut = 0x00;
   // // unsigned char butlock = 0x00;
  
   //
void LOCK_Tick(){

// unsigned char xbut =PINA&0x01;
//unsigned char ybut = PINA&0x02;
// unsigned char pbut = PINA&0x04;
// unsigned char butlock = PINA&0x00;
//
	switch(LOCK_STATE){
		
		case START:
			C_STATE= INIT;
			break;
		
		case INIT:
			if(PENA == 0x00){
				LOCK_STATE = LOCK;
			}
			else{
				LOCK_STATE = INIT;
			}
	
			break;

			
		case LOCK:
			if(PENA == 0x04){
				LOCK_STATE = WAIT;
			}
			
			else{
			 	LOCK_STATE = LOCK;
			}
	
			break;

		case WAIT:
			if(PENA == 0x04){
				LOCK_STATE = WAIT;
			}
				
			else if(PENA == 0x00){
				LOCK_STATE = Y;
			}

			else{
			     LOCK_STATE = LOCK;
			}
			break;
			
		

		case UNLOCK:
			if(PENA == 0x80){
				LOCK_STATE = LOCK;
			}
			
			else{

				LOCK_STATE = UNLOCK;
			}
			
	

			break;
		 case Y:
                           if(PENA == 0x00){
                                LOCK_STATE = Y;
                        }

                        else if(PENA == 0x02){
                                        LOCK_STATE = UNLOCK;
                        }

                        else{

                                LOCK_STATE = WAIT;
                        }


                        break;


		default:
			LOCK_STATE = START;
			break;
	}
	
	switch(LOCK_STATE){
                         
			case START:
				break;
			
			case INIT: 
				tempC = 0x00;
				break;
			
			case LOCK:
				tempC= 0x00;
				break;
			
			case WAIT:
				tempC = 0x00;
				break;
		
			case UNLOCK:
				tempC = 0x01;
				break;
			case Y:
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
		    
	LOCK_STATE = START;
//	count =0x07;
    /* Insert your solution below */
    while (1) {
	LOCK_Tick();
		
    }
    return 1;
}
