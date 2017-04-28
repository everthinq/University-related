#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

class turn
{
 private:
 struct turns
 {
  int value;
  turns *next,*tail;
 };

 turns *top, *tail;
 int count;

 public:
 int add (int value);
 int get ();
 delete_turn ();
 void print ();
 turn();
 ~turn();
}

turn::turn()
{
 top = 0;
 tail = 0;
 count = 0;
}

int turn::add (int value)
{
 turns *el = new turns;
 if (!el) return 0;
 el -> value = value;
 el -> next = 0;
 if (!tail) top = el;
 else tail -> next = el;
 tail = el;
 count++;
 return 1;
}

int turn::get ()
{
 if (!top) return 0;
 turns *temp = top;
 int value = top -> value;
 top = top -> next;
 if (!top) tail = 0;
 delete temp;
 count--;
 return value;
}

int turn::delete_turn()
{
 if (!top) return 0;
 turns *temp = top -> next;
 for (; top; temp = temp -> next)
 {
  delete top;
  top = temp;
 }
 count = 0;
 tail = 0;
 return 1;
}

void turn::print ()
{
 turns *temp = top;
 for (; temp; temp = temp -> next)
 cout << temp -> value << endl;
}

turn::~turn()
{
 delete_turn();
}

int main ()
{
 clrscr();
 turn turns;
 int counter = 0, q = 0;
 while (1)
 {
  cout << "Menu:" << endl;
  cout << "Print 1 - add el in turn" << endl;
  cout << "Print 2 - get el from och" << endl;
  cout << "Print 3 - print ochered" << endl;
  cout << "Enter number: ";
  cin >> counter;
  switch (counter)
  {
   case 1: clrscr();
	   cout << "Enter value: ";
	   int value = 0;
	   cin >> value;
	   q = turns.add (value);
	   if (!q) cout << "Error" << endl;
	   break;
   case 2: clrscr();
	   q = turns.get();
	   if (!q) cout << "Error" << endl;
	    else cout << endl << "Value of element = " << q << endl;
	   break;
   case 3: clrscr();
	   cout << endl << "Your turn is: " << endl;
	   turns.print();
	   break;
   default: exit(1);
  }
 }
 getch();
 return 0;
}