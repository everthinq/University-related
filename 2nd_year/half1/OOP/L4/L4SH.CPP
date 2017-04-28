#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip.h>


class list
{
struct mylist
 {
  int value;
  mylist* next;
 };

mylist *top;

public:
 int print_list();
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
 top = 0;
}


///////////print list//////////////////////////////////
int list::print_list()
{
 mylist* temp = top;
 if (!temp) return -1;
 for(; temp; temp = temp -> next)
 cout << temp -> value << " ";
 return 0;
}
//////////////////////////////////////////////////////

///////////add elem in list/////////////////////////
int list::add (int n, int value)
{
 mylist* el = new mylist;
 if (!el) return -1;
 el -> value = value;
 if (!top) n = 0;
 if (n <= 0)
 {
  el -> next = top;
  top = el;
 }
 else
 {
  mylist *temp = top;
  for (int i = 0; (i < (n - 1)) && (temp -> next); i++)
   temp = temp -> next;
  el -> next = temp -> next;
  temp -> next = el;
 }
 return 0;
}
//////////////////////////////////////////////////////////

////////////find n_elem//////////////////////////////////
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
 n--;
 if (!top) return -1;
 if (n <= 0)
 {
  mylist* temp;
  temp = top -> next;
  delete top;
  top = temp;
  return 0;
 }

if (top -> next == 0)
 {
  mylist *temp;
  temp = top;
  delete top;
  top = 0;
  return 0;
 }

 else
 {
  mylist* temp = top;
  for (int i=0;(i<(n-1))&&(temp->next)&&(temp->next->next);i++)
   temp = temp -> next;
  mylist* temp2 = temp -> next;
  temp -> next = temp -> next -> next;
  delete temp2;
 }
 return 0;
}

list::~list()
{
 delete_list();
}
/////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////
void main()
{
clrscr();
list p;
 int n = 0;
 int value = 0;
 cout << "enter amount of elements: ";
 cin >> n;
 cout << endl;
 for (int i = 0; i < n; i++)
 {
  cout << "enter [" << i + 1 << "] element: ";
  cin >> value;
  p.add (n, value);
 }
 cout << endl;
 cout << endl << "list: ";
 p.print_list ();

 cout << endl;
 cout << endl << "new list: ";

 int k = 0;

 for (i = 1; i <= n; i++)
 {
  k = p.find_n (i);
  if (k < 0)
  {
   p.delete_n (i);
   break;
  }
 }
 p.print_list ();
 getch();
}
/////////////////////////////////////////////////////////////////