#include <iostream.h>
#include <conio.h>


int maximum(int *mas, int n, int k)
{
 int a;
 if(k==n-1) return k;

 a = maximum(mas,n,k+1);
 if(mas[a]>mas[k]) return a;
 else return k;

}

int main()
{clrscr();
int mas[100];
int i,n,max;

cout<<"Vvedite razmer massiva: ";
cin>>n;
for(i=0;i<n;i++)
 {
  cout<<"Vvedite mas["<<i<<"]:";
  cin>>mas[i];
 }
cout<<endl;

max = maximum(mas,n,0);
cout<<"Max:"<<mas[max]<<endl;

getch();
return 0;
}