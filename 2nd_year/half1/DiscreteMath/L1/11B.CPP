#include<iostream.h>
#include<conio.h>


struct set
{
  double setof[255];
  int size;
};

//sozdanie mnojestva
void create(set& curset)
{ curset.size=0; }

//dobavlenie elementov mnojestva
void insert(set &curset,double value)
{
 if(curset.size<255)
 {
  curset.setof[curset.size]=value;
  curset.size++;
 }
}

//udalenie vseh elementov mnojestva
void clear(set& curset)
{ curset.size=0; }

// proverka na vhojdenie elementa
int in(set curset,double value)
{
 for(int i=0;i<curset.size;i++)
 {
  if(curset.setof[i]==value)
  return 1;
 }
 return 0;
}

//ob'edinenie 
void composition(set& dest,set curset_f,set curset_s)
{
 int i;
 clear(dest);
 for(i=0;i<curset_f.size;i++)
  insert(dest,curset_f.setof[i]);
 for(i=0;i<curset_s.size;i++)
  {
   if(!in(dest,curset_s.setof[i]))
   insert(dest,curset_s.setof[i]);
  }
}

//peresechenie 
void intersection(set& dest,set curset_f,set curset_s)
{
 clear(dest);
 for(int i=0;i<curset_f.size;i++)
  {
   if(in(curset_s,curset_f.setof[i]))
    { insert(dest,curset_f.setof[i]); }
  }
}

//raznost' 
void substraction(set& dest,set curset_f,set curset_s)
{
clear(dest);
for(int i=0;i<curset_f.size;i++)
 {
  if(!in(curset_s,curset_f.setof[i]))
  { insert(dest,curset_f.setof[i]); }
 }
}

//vvod mnojestva
void cin_set(set &dest)
{
 int count;
 cout<<"enter numbers of elements"<<endl;
 cin>>count;
 if(count>255)
  count=255;
  create(dest);
  double value;
  for(int i=0;i<count;i++)
   {
    cout<<"enter "<<i+1<<" element"<<endl;
    cin>>value;
    insert(dest,value);
   }
}

//vivod mnojestva
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
struct set A,B,res1,res2,res3,res4;
cout<<"CURSET A"<<endl;
cin_set(A);
clrscr();
cout<<"A=";
cout_set(A);
cout<<"CURSET B"<<endl;
cin_set(B);
clrscr();
cout<<"A=";
cout_set(A);
cout<<"B=";
cout_set(B);
intersection(res1,A,B);
composition(res2,A,B);
substraction(res3,A,B);
substraction(res4,B,A);
cout<<"A ^ B= "; cout_set(res1);
cout<<"A U B= "; cout_set(res2);
cout<<"A / B= "; cout_set(res3);
cout<<"B / A= "; cout_set(res4);
getch();
}