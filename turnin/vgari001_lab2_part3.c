#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void){
    /* Insert DDR and PORT initializations */
     DDRA = 0x00; PORTA = 0xFF;
     DDRC = 0xFF; PORTC = 0x00;

     unsigned char PinA3 = 0x00;
      unsigned char PinA2 = 0x00;
      unsigned char PinA1 = 0x00;
      unsigned char PinA0 = 0x00;

     unsigned char countavail = 0x00;
    /* Insert your solution below */
    while (1) {

         PinA3 = PINA & 0x08;
         PinA2 = PINA & 0x04;
          PinA1= PINA & 0x02;
         PinA0 = PINA & 0x01;

        countavail = 4;
        if(PinA3 == 0x08){

                countavail-- ;
        }


        if(PinA2 == 0x04){

                countavail--;
        }
     if(PinA1== 0x02){

                countavail--;
        }

      if(PinA0  == 0x01){

                countavail--;
        }
	
	if (countavail ==0){
		count = count | 0x80;
	}

        PORTC = countavail;
}
  //  return 1;
    }
