#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct mylist
{
 int value;
 mylist* next;
};

mylist *el = 0;
mylist *top = 0;

///////////add elem in list/////////////////////////
int add (mylist* &top, int n, int value)
{
 el = new mylist;
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

///////////print list//////////////////////////////////
int print_list (mylist* top)                         
{                                           
 if (!top) return -1;
 for(; top; top = top -> next)
 cout << top -> value << " ";
 return 0;
}
//////////////////////////////////////////////////////


////////////find n_elem////////////////////////
int find_n (mylist* top, int number)
{
 if (number <= 0) return -1;
 else
 {
  for (int i = 1; (i < number) && (top); i++)
   top = top -> next;
  if (!top) return -1;
  else return top -> value;
 }
}
//////////////////////////////////////////////////////////


///////////////find elem by value////////////////
int find_val (mylist* top, int value)
{
 int i = 1, p = 0;
 for (; top; top = top -> next, i++)
  if (top -> value == value)
  {
   p = 1;
   break;
  }
 if (p) return i;
 else return -1;
}
//////////////////////////////////////////////////////////

/////////////////////delete list///////////////////////
int delete_list (mylist* &top)
{
 mylist* temp;
 for (; top; temp = top -> next)
 {
  delete top;
  top = temp;
 }
 return 0;
}
//////////////////////////////////////////////////////////

///////////delete n_elem/////////////////////////////
int delete_n (mylist* &top, int n)
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
  for (int i=0;(i<(n-1))&&(temp->next)&&(temp->next->next);i++)//
   temp = temp -> next;
  mylist* temp2 = temp -> next;
  temp -> next = temp -> next -> next;
  delete temp2;
 }
 return 0;
}

/////////////int main///////////////////////////
int main()
{
 clrscr();
 mylist* top = 0;
 int n = 0;
 int value = 0;
 cout << "enter amount of elements: ";
 cin >> n;
 cout << endl;
 for (int i = 0; i < n; i++)
 {
  cout << "enter [" << i + 1 << "] element: ";
  cin >> value;
  add (top, n, value);
 }
 cout << endl;
 cout << endl << "mylist: ";
 print_list (top);

 cout << endl;
 cout << endl << "new mylist: ";

 int k = 0;

 for (i = 1; i <= n; i++)
 {
  k = find_n (top, i);
  if (k < 0)
  {
   delete_n (top, i);
   break;
  }
 }
 print_list (top);
 getch();
 return 0;
}
////////////////////////////////////////////////