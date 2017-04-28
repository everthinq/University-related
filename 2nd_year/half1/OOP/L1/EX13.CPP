#include<iostream.h>
#include<conio.h>

struct list
{
char b;
int *k;
};

void main()
{
clrscr();
int *p1,*p2;
char *ptr;
int *mas[10];//massiv ukazatelei;
int *point;

struct list *n,*pr;

p1=new int;//ukazatel na nachalo dinam pamyati;

*p1=25;
cout<<p1;

p2=new int(15);//ukazatel na nachalo dinam pamyati; 1iu element=15;

mas[0]=new int;//0 ukazatel=ukazivaet na dinam pamyat;
mas[1]=p1;//1iy ukazatel=ukazivaet na dinam pamyat

ptr=new char ('*');//ukazatel na nachalo dinam pamyati; 1iy el='*';
point=new int[10];//
n=new list;//3 bytes
pr=n;//ukazatelu pr

n->b=*p1;//elem. b=25;
n->k=p2;//elem. k=15
cout<<"\n"<<*p2;
n->k++;//16
cout<<"\n"<<n->k;

delete p1;
delete p2;
delete mas[0];
delete ptr;
delete point;
delete n;
getch();
}
