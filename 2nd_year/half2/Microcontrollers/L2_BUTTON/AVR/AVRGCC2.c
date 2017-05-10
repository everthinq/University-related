#define F_CPU 1000000L
#define time 200

#include <avr/io.h>
#include <avr/iom8.h>
#include <math.h>
#include <avr/delay.h>

unsigned char t, t1, t2, t3;

// B5 = (B1 | B2) ^ B3
 
 void main(void)
 {
    DDRB = 0b00100000;
   PORTB = 0b00001110;
   
   while(1)
   {
     t1 = PINB << 4; //B1
     t2 = PINB << 3; //B2
     t3 = PINB << 2; //B3

     t = (t1 | t2) ^ t3;
	
    PORTB = PORTB & 0b11011111 | t; //& 0b00100000;
    //_delay_ms(500);
   }
 }
 
