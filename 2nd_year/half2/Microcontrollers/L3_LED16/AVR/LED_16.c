#define F_CPU 1000000
#define time 50

#include <avr/io.h>
#include <avr/iom8.h>
#include <math.h>
#include <avr/delay.h>

void move_line_left();
void move_line_right();
void move_fill_left();
void clear_from_right();
void clear_from_left();
void move_line_left_fill();
void clear_from_right_fill();

void first() //переключение диодов слева направо и справо налево.
 {
   move_line_left();
   move_line_right();
 }

void second () //переключение диодов только справа налево
 {
   move_line_left();
 }

void third () //заполнение слова направо и отчистка справа налево
 {
     move_fill_left();
	 PORTB=0x00; PORTD=0x00;
	 _delay_ms(time);
     clear_from_right();
 }

void fourth() //переключение с двух сторон
 {
      PORTD=0x01;
	  PORTB=128;
	  _delay_ms(time);

	  for(int i=0; i<8; i++)
	  {
	   PORTB=PORTB>>1;
	   PORTD=PORTD<<1;
	   _delay_ms(time);
	  }

	  PORTD=128;
	  PORTB=1;
	  _delay_ms(time);

	  for(int i=0; i<8;i++)
	  {
	   PORTB=PORTB<<1;
	   PORTD=PORTD>>1;
	   _delay_ms(time);
	  }
 }

//--------------MAIN-------------------
int main ()
 {
   DDRB=0b11111111;
   DDRD=0xff;
  while(1)
   {
    PORTB=0; PORTD=0;
	first(); 
	second();
    third();
	fourth();
   }
 }


//---------------------------
void move_line_left() //движение диода по одному в линию слева
 {
   PORTD=0x01;
   for (int i=0; i<8; i++)
   {
    _delay_ms(time);
    PORTD=PORTD<<1;
   }
   
   PORTB=0x01;
   for (int i=0; i<8; i++)
   {
    _delay_ms(time);
    PORTB=PORTB<<1;
   }
   _delay_ms(time);

   
 }

void move_line_right() //движение диода по одному в линию справа
 {
   PORTB=0b10000000;
   for (int i=0; i<8; i++)
    {
      _delay_ms(time);
	  PORTB=PORTB>>1;
	}

	PORTD=128;
   for (int i=0; i<8; i++)
   {
    _delay_ms(time);
    PORTD=PORTD>>1;
   }
 }

void move_fill_left() //движение диода по одному с заполнением влево
 {
   PORTD=0x01;
   for (int i=0; i<8; i++)
    {
      _delay_ms(time);
	  PORTD=(PORTD<<1)+1;
	}

   PORTB=0x01;
   for (int i=0; i<8; i++)
    {
      _delay_ms(time);
	  PORTB=(PORTB<<1)+1;
	}
 }

 void clear_from_right() //отчищение полоски диодов справа
  {
   PORTB=0b11111111; PORTD=0xff;
   for (int i=0; i<8; i++)
    {
      _delay_ms(time);
	  PORTB=PORTB>>1;
	}
   _delay_ms(time);

	for (int i=0; i<=8; i++)
    {
      _delay_ms(time);
	  PORTD=PORTD>>1;
	}
  }





