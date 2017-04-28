#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

long int x,y;
void data (int mas[], int n)
{
 randomize();
{
 int m=rand();
 for ( int i=0; i<n; i++)
 mas[i]=random(m);
}
}

int print (int mas[], int n)
 {
  cout<<"massiv1:\n";
  for (int i=1; i<n; i++)
  {cout<<mas[i]<<" ";
   x=x+mas[i];}
   x=x/n;
   cout<<"\n\n";
 cout<<x;

 cout<<"\n";
 cout<<"\n";

return x;
}






void dataa (int mas[], int n)
{

 randomize();
{
 int m=rand();
 for ( int i=9; i<n; i++)
 mas [i]=random(m);
}
}

 int printt ( int mas[], int n)
 {

  cout<<"massiv2:\n";
  for (int i=1; i<n; i++)
  {cout<<mas[i]<<" ";
  y=y+mas[i];}
  y=y/n;
  cout<<"\n\n";
  cout<<y;
 return y;
 }

main()
{
clrscr();
int a[10], n=10;
data(a,n);
print(a,n);
dataa(a,n);
printt(a,n);
cout << "\n\n x = " << x;
cout << "\n y = " << y;
if (x>y) cout<<"\n x > y";
else cout<<"\n x < y";

getch();}