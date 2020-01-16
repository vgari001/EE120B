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
    	unsigned char key = 0x00;
	unsigned char driver =0x00;
	unsigned char seatbelt =0x00;
//	unsigned char fasten =0x00;
    while (1) {
	
		fuelLevel = PINA & 0xFF;
		key = PINA & 0x10;
		driver = PINA & 0x20;
		seatbelt = PINA & 0x60;
	      //fasten = PINA & 0xF0;

		switch(fuelLevel){
		
		case 0x00:		
		 if((driver==0x01) &( key==0x01) & (seatbelt==0x00)){

                    levelLight = 0x80;
               	   }
		
			else{
				
			levelLight=0x00;
			}

				break;

			case 0x01:
			case 0x02:
			
			 if((driver) &( key) & (!seatbelt)){

                             levelLight = 0xC0;
                        }
				

				else{
				levelLight = 0x60;
				}
				break;

			case 0x03: 
			case 0x04:
			
			 if((driver) &( key) & (!seatbelt)){

                        	levelLight = 0xF0;
                  		 }
			else{

				levelLight = 0x70;
			}
				break;
			case 0x05:
			case 0x06:
			
			 if((driver) &( key) & (!seatbelt)){

                        levelLight = 0xB8;
                      }
			else{
				levelLight = 0x38;
				break;
			}	

			case 0x07:
			case 0x08:
			case 0x09:
			
			 if((driver) &( key) & (!seatbelt)){

                        levelLight = 0xBC;
                      }
			else{
				levelLight = 0x3C;
			}
				break;


			case 0x0A:
			case 0x0B:
			case 0x0C:
			 if((driver) &( key) & (!seatbelt)){

                        levelLight = 0xBE;
                      }

			else{
				levelLight = 0x3E;
			}
				break;
			
			case 0x0D:
			case 0x0E:
			case 0x0F:
			
			 if((driver) &( key) & (!seatbelt)){

                        levelLight = 0xBF;
                         }

			else{

				levelLight = 0x3F;
				break;
			}
			}

	PORTC = levelLight;
	levelLight = 0x00;				
	
	
}	
    return 1;
}
