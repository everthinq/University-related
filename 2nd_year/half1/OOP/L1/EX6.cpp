#include<iostream.h>
#include<conio.h>
#include<process.h>
int *number_ptr;
int no_of_integers;
double average (int* number_ptr, int no_of_integers)
{
int sum=0;
for (int i=0;i<no_of_integers;i++)
sum+=number_ptr[i];
sum/=no_of_integers;
return sum;
}
int main()
{
clrscr();
number_ptr=new int[10];
cout<<"Vvedite kol-vo cel-h chisel v spike:"<<endl;
cin>>no_of_integers;
number_ptr=new int[no_of_integers];
if(number_ptr==NULL)
{
cout<<"Izvinite, nedostatochno pamyati"<<endl;
exit(1);
}
cout<<"Nabirite "<<no_of_integers<<" cel-h chiel, razdelyaya ih probelami"<<endl;
for(int count=0;count<no_of_integers;count++)
cin>>number_ptr[count];
cout<<"Srednee znachenie: ";
cout<<average (number_ptr, no_of_integers);
delete[] number_ptr;
getch();
}