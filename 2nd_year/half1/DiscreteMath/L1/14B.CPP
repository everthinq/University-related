#include <iostream.h>
#include <conio.h>

void main()
 {
   clrscr();
   int A[2];
   A[0]=1; A[1]=2;

   int B[3];
   B[0]=1; B[1]=2; B[2]=3;


 cout<<"A= "<<A[0]<<" "<<A[1]<<endl;
 cout<<"B= "<<B[0]<<" "<<B[1]<<" "<<B[2]<<endl;

 cout<<"AxB =";
   for (int i=0; i<2; i++)
    {
     for (int q=0; q<3; q++)
      {
       cout<<" ("<<A[i]<<";"<<B[q]<<")";
       }
    }

 cout<<"\nBxA =";
   for (i=0; i<3; i++)
    {
     for (int q=0; q<2; q++)
      {
       cout<<" ("<<B[i]<<";"<<A[q]<<")";
      }
    }

getch();
}