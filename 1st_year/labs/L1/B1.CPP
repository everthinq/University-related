#include <iostream.h>
#include <conio.h>
#include <math.h>
double rec_pl_lej(double n, double x)
	{
	  if (n==0) return 1;
	  if (n==1) return x;
else return ((2*n-1)*rec_pl_lej(n-1,x)-(n-1)*rec_pl_lej(n-2,x))/n;
	}
void main ()
 {
  clrscr();
  int n,x;
  cout<<"enter n,x \n";
  cin>>n;
  cin>>x;
  cout<<"REC_PL_LEJ="<<rec_pl_lej(n,x)<<endl;
  getch();}
