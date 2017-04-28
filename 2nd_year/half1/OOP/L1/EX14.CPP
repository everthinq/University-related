#include<iostream.h>
#include<conio.h>

void main()
{
clrscr();

int *a,*b;
int *c;

a=new int;
b=new int;

*a=15;
*b=-1;

cout<<"a: "<<*a<<"\n"<<endl;
cout<<"b: "<<*b<<"\n"<<endl;

cout<<c<<" "<<a<<" "<<b<<"  no "<<endl;
c=a;
cout<<c<<" "<<a<<" "<<b<<" c=a "<<endl;
a=b;
cout<<c<<" "<<a<<" "<<b<<" a=b \n"<<endl;

cout<<"c: "<<*c<<"\n"<<endl;
cout<<"a: "<<*a<<"\n"<<endl;
cout<<"b: "<<*b<<"\n"<<endl;

delete c;
delete a;
delete b;

getch();
}
