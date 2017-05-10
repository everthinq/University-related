#define F_CPU 1000000UL
#define time 4

#include <avr/io.h>
#include <avr/iom8.h>
#include <math.h>
#include <avr/delay.h>

#include <avr/io.h>

unsigned char word[]={
							0,	  0,	0,	  0,	0,	  0,	
                            0x00, 0x89, 0x89, 0x89, 0x76, 0x00, 0x00, 0x00,  //з
							0xFF, 0x04, 0x08, 0x10, 0x20, 0x40, 0xFF, 0x00,  //и
							0xFF, 0x40, 0x20, 0x10, 0x20, 0x40, 0xff, 0x00,  //м
							0x00, 0x3f, 0x44, 0x84, 0x84, 0xff, 0x00, 0x00,  //а 
							0,	  0,     0,   0,    0,    0
												
				   	   };
void DrawEight(int n)
{
	PORTD=255-128;
	for (unsigned int i=n, j=0; j<8; j++,i++)
		{
		 if (PORTD==0xff) PORTD=0b11111110;
		 PORTB=word[i];
		 _delay_ms(time);
		 PORTD=(PORTD<<1)+1;
		}
}

int main(void)
{
   DDRB=0xFF;
   DDRD=0xFF;
   PORTD=0b01111111;
   unsigned int step=-1;

    while(1)
    {
	    if (step>=42) step=0;
		else step++;

		DrawEight(step);
		//_delay_ms(time);

    }
}
