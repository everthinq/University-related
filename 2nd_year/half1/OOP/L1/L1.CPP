#include<iostream.h>
#include<conio.h>


void main()
 {
  int n,m;
  clrscr();

////////VARIANT12////////////////////////////
/*/1/*/  float mas[5];                     // Odnomernyj massiv tipa float;
/*/2/*/  float *p;                         // Ukazatel' na tip float;
/*/3/*/  char mas2[5];                     // Staticheskij odnomernyj massiv simvolov;
/*/4/*/  int **pp;                         // Ukazatel' na massiv simvolov;
/*/5/*/  int masss[2][2][2];               // Trehmernyj massiv unsigned int;
/*/6/*/  int (*pp2)[2][2];                 // Ukazatel' na dvumernyj massiv  celyh chisel.
/////////////////////////////////////////////



////////ZADANIE//////////////////////////////
//////////*/1/*//////////////////////////////
cout<<"LAW in mas[5] = ";                  //
for(int i=0; i<5; i++)                     //
 {                                         //
  cout<<mas[i]<<" ";                       //
 }cout<<"\n";                              //
/////////////////////////////////////////////

//////////*/2/*//////////////////////////////
cout<<"\n";                                //
for(i=0; i<5; i++)                         //
 {                                         //
  cout<<"enter "<<i+1<<" element = ";      //
  cin>>mas[i];                             //
 }                                         //
/////////////////////////////////////////////

//////////*/3/*//////////////////////////////
cout<<"new mas[5] = ";                     //
for(i=0; i<5; i++)                         //
 {                                         //
  cout<<mas[i]<<" ";                       //
 }   cout<<"\n";                           //
/////////////////////////////////////////////

//////////*/4/*//////////////////////////////                                     //
p = mas;                                   //
cout<<"\nadress mas[5]="<<mas<<endl;       //
cout<<"adress *p="<<p<<endl;               //
cout<<"value *p="<<*p<<endl<<endl;         //
/////////////////////////////////////////////

//////////*/5/*//////////////////////////////
cout<<"Ukazatel soderj adres mas = ";      //
for(i=0; i<5; i++)                         //
 {                                         //
  cout<<p[i]<<" ";                         //
 }      cout<<endl;                        //
/////////////////////////////////////////////

//////////*/6/*//////////////////////////////
cout<<"\nDLYA STAT mas2[5] = LAW\n";       //
cout<<"\nmas2[5] = ";                      //
for(i=0; i<5; i++)                         //
 {                                         //
  cout<<(int)mas2[i]<<" ";                 //
 }                                         //
cout<<"\n";                                //
					   //
 for(i=0; i<5; i++)                        //
  {                                        //
   cout<<"enter "<<i+1<<" element = ";     //
   cin>>mas2[i];                           //
  }                                        //
					   //
cout<<"new mas2[5] = ";                    //
 for(i=0; i<5; i++)                        //
  {                                        //
   cout<<mas2[i]<<" ";                     //
  } cout<<"\n";                            //
/////////////////////////////////////////////

//////////*/7/*//////////////////////////////
p = new float[5];                          //
cout<<"\ndinamic mas p = ";                //
					   //
for(i=0; i<5; i++)                         //
 {                                         //
  cout<<p[i]<<" ";                         //
 }                                         //
					   //
cout<<endl;                                //
for(i=0; i<5; i++)                         //
 {                                         //
  cout<<"enter "<<i+1<<" element = ";      //
  cin>>p[i];                               //
 }                                         //
cout<<"dinamic mas p = ";                  //
for(i=0; i<5; i++)                         //
 {                                         //
  cout<<p[i]<<" ";                         //
 }   cout<<"\n";                           //
delete []p;                                //
/////////////////////////////////////////////

//////////*/8/*//////////////////////////////
					   //
pp = new int*[n];                          //
cout<<"\ndinamic mas pp = ";               //
cout<<endl;                                //
                                           //
cout<<"enter n = ";                        //
cin>>n;                                    //
cout<<"\nenter m = ";                      //
cin>>m;                                    //
					   //
 for(i=0; i<n; i++)                        //
 {                                         //
  pp[i]=new int[m];                        //
 }                                         //
					   //
for(i=0; i<n; i++)                         //
 {				           //
  for(int j=0; j<m; j++)                   //
  {                                        //
   cout<<pp[i][j]<<" ";                    //
					   //
  }  cout<<endl;                           //
 }cout<<endl;                              //
					   //
for(i=0; i<n; i++)                         //
 {                                         //
  for(int j=0; j<m; j++)                   //
  {                                        ///////
   cout<<"enter ["<<i<<"]"<<"["<<j<<"] elem = ";//
   cin>>pp[i][j];                          ///////
  }                                        //
 }                                         //
					   //
cout<<endl;	                           //
					   //
cout<<"dinamic mas pp = ";                 //
cout<<endl;                                //
for(i=0; i<n; i++)                         //
 {                                         //
  for(int j=0; j<m; j++)                   //
  {                                        //
   cout<<pp[i][j]<<" ";                    //
  }cout<<endl;                             //
 }                                         //
					   //
for(i=0; i<n; i++)                         //
 {                                         //
  delete []pp[i];                          //
 }                                         //
delete[]pp;                                //
/////////////////////////////////////////////

//////////*/9/*//////////////////////////////////////////
cout<<"\nelem[1][2][3] = "<<masss[1][2][3]<<endl;      //
/////////////////////////////////////////////////////////

//////////*/10/*/////////////////////////////////////////
cout<<"elem[1][2][3] = "<<masss[1][2][3]<<endl;        //
cout<<"elem[1][2][3] = "<<*(*(*(masss+1)+2)+3)<<endl;  //
/////////////////////////////////////////////////////////

//////////*/11/*/////////////////////////////////////////
pp2 = masss;                                           //
cout<<"\nmas [1][2][3] = 2"<<endl;                     //
masss[1][2][3]=2;                                      //
cout<<"elem[1][2][3] = "<<masss[1][2][3]<<endl;        //
cout<<"elem[1][2][3] = "<<*(*(*(masss+1)+2)+3)<<endl;  //
/////////////////////////////////////////////////////////
getch();
}