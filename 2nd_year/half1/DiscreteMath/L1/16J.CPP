#include<iostream.h>
#include<conio.h>

// Opisanie tructuri mnojestva
struct set
{
  char setof[255];
  int size;
};

// sozdanie mnojestva
void create(set& curset)
{ curset.size=0; }
// dobavlenie elementov mnojestva
void insert(set &curset,char value)
{
 if(curset.size<255)
 {
  curset.setof[curset.size]=value;
  curset.size++;
 }
}

// udalenie vseh elementov mnojestva
void clear(set& curset)
{ curset.size=0; }
// proverka na vhojdenie elementa vo mnojestvo
int in(set curset,char value)
{
 for(int i=0;i<curset.size;i++)
 {
  if(curset.setof[i]==value)
  return 1;
 }
 return 0;
}

//raznost' dvuh mnojestv
void substraction(set& dest,set curset_f,set curset_s)
{
clear(dest);
for(int i=0;i<curset_f.size;i++)
 {
  if(!in(curset_s,curset_f.setof[i]))
  { insert(dest,curset_f.setof[i]); }
 }
}

// vvod mnojestva
void cin_set(set &dest)
{
 int count;
 cout<<"enter number of elements"<<endl;
 cin>>count;
 if(count>255)
  count=255;
  create(dest);
  char value;
  for(int i=0;i<count;i++)
   {
	cout<<"enter "<<i+1<<" element"<<endl;
	cin>>value;
	insert(dest,value);
   }
}

// vivod mnojestva
void cout_set(set dest)
{
 cout<<"{";
 for(int i=0;i<dest.size;i++)
  { cout<<dest.setof[i]<<" "; }
 cout<<"}"<<endl;
}

void main()
{
clrscr();
struct set X,Z,res;

cout<<"CURSET X"<<endl;
cin_set(X);
clrscr();
cout<<"X=";
cout_set(X);

cout<<"CURSET -Z"<<endl;
cin_set(Z);
clrscr();
cout<<"X=";
cout_set(X);
cout<<"-Z=";
cout_set(Z);

substraction(res,X,Z);
cout<<"X / -Z= "; cout_set(res);
getch();
}