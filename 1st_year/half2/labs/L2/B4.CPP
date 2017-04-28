#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

void main()
{

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


int count=0;
int elem;
int check=0;

for(int j=0;j<n;j++)
{
 elem=mass[j];
 check=0;

 for(i=0;i<n;i++)
  {
if ( (i!=j) && ( elem == mass[i] ) ) check++;
  }

 if (check==0) count++;
}
cout<<"elements- "<<count;

getch();
}