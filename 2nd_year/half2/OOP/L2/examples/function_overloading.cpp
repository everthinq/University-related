#pragma argsused
#include <iostream.h>
#include <conio.h>

int add_values(int a,int b) 
{
   return(a + b);
}

int add_values (int a, int b, int c)
{
   return(a + b + c);
}

int add_values (int a, int b, int c, int d)
{
   return(a + b + c + d);
}

void main(void)
{
   cout << "2 values:                200 + 801 = " << add_values(200, 801) << endl;
   cout << "3 values:          100 + 201 + 700 = " << add_values(100, 201, 700) << endl;
   cout << "4 values: 100 + 201 + 700 + 100500 = " << add_values(100, 201, 700, 100500) << endl;
   getch();
}

