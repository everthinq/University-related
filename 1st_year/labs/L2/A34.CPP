#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

 int x,y;
  void data (int mas[], int n)
   {
    int m=rand();
    randomize();
    for ( int i=0; i<n; i++)
    mas[i]=random(m);
   }

  void print (int mas[], int n)
   {
    cout<<"array:\n";
    for (int i=0; i<n; i++)
    cout<<mas[i]<<" ";
    cout<<"\n";
    cout<<"\n";
   }

  void printt (int mas[], int n)
   {
    cout<<"elements:\n";
    cout<<mas[1]<<" "<<mas[2]<<" ";
    cout<<mas[n-1]<<" "<<mas[n-2]<<" ";
    cout<<mas[3]<<" "<<mas[4]<<" ";
    cout<<mas[n-3]<<" "<<mas[n-4];
   }

main()
 {
  clrscr();
  int a[9], n=10;
  data(a,n);
  print(a,n);
  printt(a,n);
  getch();
 }