#include<iostream.h>
#include<conio.h>
#include<math.h>
double bin(double m, double n)
	{
	  if ((m==0)&&(n==0)) return 1;
	  if ((m==1)&&(n==1)) return 1;
else return ((m*(n-1))+((m-1)*(n-1)));
	}
void main()
{clrscr();
long int n,m;
cout<<"enter m,n         [0<m<n]"<<endl;
cin>>m>>n;
cout<<"rec="<<bin(n,m);
getch();}
