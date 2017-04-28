#include<iostream.h>
#include<conio.h>
#include<math.h>
double rec(int n)
{if (n==1) return sqrt(23-2);
if (n==2) return sqrt((23)-2*sqrt(23));
else return	(sqrt(23-2)*rec(n-1));}
void main()
{clrscr();
int n;
cout<<"enter n \n";
cin>>n;
cout<<"rec="<<rec(n);
getch();}

