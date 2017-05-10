#include<iostream>
#include<conio.h>

     using namespace std;
    void swap(int a, int b)
     {
         int t;
         t = b;
         b = a;
         a = t;
     }

     int main()
     {
         int a = 3, b = 5;
         swap(a, b);

         cout <<a <<" " << b << endl;
         getch();
         return 0;
     }

