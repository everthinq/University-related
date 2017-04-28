#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip.h>

class list
{
 struct mylist
 { 
  float value;
  mylist* next, *prev;
 };
 mylist *top;
 mylist *tail;

 public:
 int count;
 int print_list();
 int print_list2();
 int add (int n, int value);
 int find_n (int n);
 int find_val (int value);
 int delete_list ();
 int delete_n (int n);
 list();
 ~list();
}

list::list()
{
 count = 0;
 top = 0;
 tail = 0;
}

///////////print list//////////////////////////////////
int list::print_list ()
{
 mylist* temp = top;
 if (!temp) return -1;
 temp = top;
 for (; temp; temp = temp -> next)
  cout << temp -> value << " ";
 return 0;
}

int list::print_list2 ()
{ 
 mylist* temp = tail;
 if (!temp) return -1;
 temp = tail;
 for (; temp; temp = temp -> prev)
  cout << temp -> value << " ";
 return 0;
}


//////////////////////////////////////////////////////


///////////add elem in list/////////////////////////
int list::add (int n, int value)
{
 n--;
 mylist* el = new mylist;
 if (!el) return -1;
  else count++;
 el -> value = value;

 if (!top)
 {
  top = el;
  tail = el;
  el -> next = el -> prev = 0;
  return 1;
 }

 if (n <= 0)
 {
  el -> next = top;
  el -> prev = 0;
  top -> prev = el;
  top = el;
  return 1;
 }


 if (n >= (count - 1))
 {
  el -> next = 0;
  el -> prev = tail;
  tail -> next = el;
  tail = el;
  return count;
 }

 mylist *temp = top;
 for (int i = 0; i < (n - 1); i++)
  temp = temp -> next;
 el -> next = temp -> next;
 el -> prev = temp;
 temp -> next = el;
 el -> next -> prev = el;
 return 0;
}
///////////////////////////////////////////////////


////////////find n_elem////////////////////////
int list::find_n (int n)
{
 mylist* temp = top;
 if (n <= 0) return -1;
 else
 {
  for (int i = 1; (i < n) && (temp); i++)
   temp = temp -> next;
  if (!temp) return -1;
  else return temp -> value;
 }
}
//////////////////////////////////////////////////////////


///////////////find elem by value////////////////
int list::find_val (int value)
{
 mylist* temp = top;
 int i = 1;
 for (; temp; temp = temp -> next, i++)
  if (temp -> value == value) return i;
 return -1;
}
//////////////////////////////////////////////////////////

/////////////////////delete list///////////////////////
int list::delete_list ()
{
 if (!top) return 0;
 mylist* temp = top -> next;
 for (; top; temp = temp -> next)
 {
  delete top;
  top = temp;
 }
 return 1;
}
//////////////////////////////////////////////////////////

///////////delete n_elem/////////////////////////////
int list::delete_n (int n)
{
 mylist *temp=top;
  if (!top) return 1;
  count--;

  if (count==0)
   {
    delete top;
    top=0;
    tail=0;
    return 1;
   }

  if (n<=1)
   {
    top=top->next;
	top->prev=0;
    delete temp;
    return 1;
   }


 mylist* temp2;
  if (n>=count+1)
   {
    temp2=tail;
    tail=tail->prev;
    tail->next=0;
    delete temp2;
    return 1;
   }

// list* temp2;
for(int i=1;i<n-1;i++)
 {
  temp=temp->next; //n-1
 }

temp2=temp->next; //n
temp->next=temp2->next; //n+1
temp->next->prev=temp->next->prev->prev;
delete temp2;
return 1;}

list::~list()
{
 delete_list();
  count = 0;
 tail = 0;
}
/////////////////////////////////////////////////////////////////


/////////////int main///////////////////////////
int main()
{
 clrscr();
 int count; int q;
 list I;
 list II;
 int value2;
 int n; int value;

while(q!=6)
{
 clrscr();

 cout<<"     -->print_list = 0 "<<endl;
 cout<<"  add elem in list = 1 "<<endl;
 cout<<"       delete elem = 2 "<<endl;
 cout<<"         new_list2 = 3 "<<endl;
 cout<<"            find_n = 4 "<<endl;
 cout<<"              quit = 6 "<<endl;
 cout<<endl;
 cin>>q;

 switch(q)
 {

  case 0:
  {
   cout << endl;
   I.print_list(); break;
  }

   case 1:
   {
    cout<<"enter value of element"<<endl;
     cin>>value;
    cout<<"enter number of position in list"<<endl;
     cin>>n;
    cout<<endl;

    I.add(n, value); break;
   }

 case 2:
  {
   cout<<"enter position number in list"<<endl;
    cin>>n;
   cout<<endl; 

   I.delete_n(n); break;
  } 

  case 3:
  {
    for (int i = 1; i < I.count + 1; i++)
   {
    value2 = I.find_n(i);  
    II.add(i, value2); 
   }

   for (i = 1; i < I.count + 1; i++)
   {
    value2 = I.find_n(i);  
    II.add(i, value2); 
   }
      cout << endl;
      II.print_list(); II.delete_list(); break;
      
  }
 }
getch();
}

 I.delete_list();
 II.delete_list();
  
 return 0;
}
///////////////////////////////////////////////