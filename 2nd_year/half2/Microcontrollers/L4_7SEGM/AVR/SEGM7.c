#define F_CPU 1000000
#define time 500

#include <avr/io.h>
#include <avr/iom8.h>
#include <math.h>
#include <avr/delay.h>

unsigned char t, a[]={0x7e,0x30, 0x6d, 0x79, 0x33, 0x5b, 0x5f, 0x70, 0x7f, 0x7b};
void main(void){
	DDRB=0xFF;
while (1){
   
   for(t=0; t<=9;t++){
   PORTB= a[t];
   _delay_ms(time);
   } 
}

}

