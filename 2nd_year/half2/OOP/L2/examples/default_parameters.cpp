#include <iostream.h>
#include <conio.h>

void showparameters (int a, int b = 4, int c = 3)
{
    cout << "a: " << a << " b: " << b << " c: " << c << endl << endl;
}

void main(void)
{
   showparameters(1001);
   showparameters(1001, 2002);
   showparameters(1001, 2002, 3003);
   getch();
} 

