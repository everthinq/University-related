#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

void main()
{
clrscr();

int n;
cout<<"enter n"<<endl;
cin>>n;

int *mass=new int[n];

randomize();
for(int i=0;i<n;i++)
{
 mass[i]=random(10);
}

for (i=0;i<n;i++)
 {
  cout<<mass[i]<<" ";
 }
cout<<endl;

int counter=0;

for (i=0;i<n-1;i++)
{
 if ( mass[i] < mass[i+1] ) counter++;
}

cout<<"uchastki, gde elementi vosrastaut: "<<counter;

getch();
}