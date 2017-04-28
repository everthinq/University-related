#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<process.h>

int* number_ptr;
int no_of_integers;//kol-vo elementov

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
cout << setw(45) << "IVAN DURAK" << endl;
for (int i = 0; i < 10; i++)
{
 cout << setw(45) << "*" << endl;
 i++;
}

number_ptr=new int[10]; //sozdaet 10 yacheek 0-9
cout << "enter Z in list:"<<endl;//vvodit kol-vo chisel
cin >> no_of_integers;

number_ptr = new int[no_of_integers];//sozdaet stolko yacheek, skolko vvel Z
if ( number_ptr == NULL )
{
cout << "SRY BRO.\n";
exit(1);
}
cout << "enter "<<no_of_integers<<" Z with spacebars:\n";// vvodit chisla cherez probel
for ( int count = 0; count < no_of_integers; count++ )//cikl count
cin >> number_ptr[count];
cout << "average value: ";
cout << average (number_ptr, no_of_integers);
delete[] number_ptr;
getch();
}