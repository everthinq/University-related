#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

class stack
{
 private:
 struct stacks
 {
  int value;
  stacks *next;
 };

 stacks *top;
 int count;
 public:
 int push (int value);
 int pop ();
 int delete_st ();
 void print ();
 stack();
 ~stack();
}

stack::stack()
{
 top = 0;
 count = 0;
}

int stack::pop()
{
 if (!top) return 0;
 stacks *temp = top;
 int value = top -> value;
 top = top -> next;
 delete temp;
 count--;
 return value;
}

int stack::push (int value)
{
 stacks *el = new stacks;
 if (!el) return 0;
 el -> value = value;
 el -> next = top;
 top = el;
 count++;
 return 1;
}

int stack::delete_st()
{
 if (!top) return 0;
 stacks *temp = top -> next;
 for (; top; temp = temp -> next)
 {
  delete top;
  top = temp;
 }
 count = 0;
 return 1;
}

void stack::print()
{
 stacks *temp = top;
 for (; temp; temp = temp -> next)
 cout << temp -> value << endl;
}

stack::~stack()
{
 delete_st();
}

int main ()
{
 clrscr();
 stack stacks;
 int counter = 0, q = 0;
 while (1)
 {
  cout << "Menu:" << endl;
  cout << "Print 1 - push el in stack" << endl;
  cout << "Print 2 - pop el from stack" << endl;
  cout << "Print 3 - print stack" << endl;
  cout << "Enter number: ";
  cin >> counter;
  switch(counter)
  {
   case 1: clrscr();
	   int value = 0;
	   cout << " Value = ";
	   cin >> value;
	   q = stacks.push(value);
	   if (!q) cout << "Error" << endl;
	   break;
   case 2: clrscr();
	   q = stacks.pop();
	   if (!q) cout << "Error" << endl;
	    else cout << "Value of element = " << q << endl;
	   break;
   case 3: clrscr();
	   cout << endl << "Your stack is: " << endl;
	   stacks.print();
	   break;
   default: exit(1);
  }
 }
 getch();
 return 0;
}