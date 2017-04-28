#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
clrscr();

int n;
cout<<"enter n"<<endl;
cin>>n;

int k;
cout<<"enter k (k<n)"<<endl;
cin>>k;

int *mass=new int[n];

randomize();

for(int i=0;i<n;i++)
 {
  if (i==k)
{
mass[i]=0;
n++;
}
  else
mass[i]=random(10)+1;
 }

for (i=0;i<n;i++)
 {
  cout<<mass[i]<<" ";
 }
cout<<endl;
getch();
}