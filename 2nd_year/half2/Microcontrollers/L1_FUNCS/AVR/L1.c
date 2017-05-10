#define F_CPU 1000000L
#define delay_time 150
#include <math.h>
#include <avr/io.h>
#include <avr/iom8.h>
#include <avr/delay.h>

    unsigned char   i = 0;
	unsigned char   a = 0;
	unsigned char   b = 0;
	unsigned char   c = 0; 
    unsigned char   d = 0; 
	
unsigned char ferst()
{
	PORTB = 0;
	_delay_ms(delay_time);
	PORTB = 1;
	for(i = 0; i <= 7; i++)
    {  	
		_delay_ms(delay_time);
		PORTB = PORTB << 1;
		if (PORTB == 128) 
		{
            for (i = 0; i <= 7; i++)
	        {
	 		   _delay_ms(delay_time); 
			   PORTB = (PORTB >> 1);
		    }
		}   		 
	}
	PORTB = 0;
}  

unsigned char second()
{
	for(i = 0; i <= 7; i++)
    { 
		_delay_ms(delay_time);
		PORTB = (PORTB << 1) + 1;
		if (PORTB == 255) 
		{
           for (i = 0; i <= 7; i++)
		   {
			   _delay_ms(delay_time); 
			   PORTB = PORTB >> 1;
			}	
		}			 
	}
}

unsigned char third()
{
	_delay_ms(delay_time);
	for (int i = 0; i < 8; i++) 
  {
		   if ((a == 0) && (b == 0))
		   {
               a = 0b10000000;
		       b = 0b00000001;		  
		   }
			 
	PORTB = a | b;
		
	_delay_ms(delay_time);
	a = a >> 1;	  
	b = b << 1;
  } 
  PORTB = 0;	
}

unsigned char fourth()
{
	for(i = 0; i <= 7; i++)
    { 
		_delay_ms(delay_time);
		PORTB = (PORTB << 1) + 1;
		if (PORTB == 255) 
		{
               for (i = 0; i <= 7; i++)
		    {
			   _delay_ms(delay_time); 
			   PORTB = PORTB << 1;
			}	
		}			 
	}
	PORTB = 0;
}

unsigned char fifth()
{	
	PORTB = 0x01; 
	for(i = 0; i <= 7; i++)
    { 
		_delay_ms(delay_time);
		PORTB = (PORTB << 1) + 1;
		
	}
	//PORTB = 0;
}

int main()
{ 
   DDRB = 0b11111111;
   PORTB = 1;
 
   while(1)
   {
	 ferst();
	 second();
	 third();
	 fourth();
	 //fifth();
   }
}
