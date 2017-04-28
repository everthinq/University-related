#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip.h>
#include <stdio.h>

const unsigned long n = 32;
 const int cd1 = 1;
 const int cd2 = 2;
 const int cd3 = 3;
 int k;
 int T = 1;
 unsigned long w;

class stack
{
 struct stacks
 {
  int value;
  stacks *next;
 };

 private:
 stacks *top;
 int count;

 public:
 int push (int value);
 int pop();
 int delete_st();
 void print();
 stack();
 ~stack();
};

stack *C = new stack();
stack *W = new stack();
stack *U = new stack();
stack *V = new stack();

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
 cout << temp -> value << " ";
}

stack::~stack()
{
 delete_st();
}

//void T10(int);
//int k;

class ToomCook
{
 public:
 unsigned long w;
 unsigned long ToomCookMultiplying(unsigned long u, unsigned long v);

 private:
 void T10();
};

unsigned long ToomCook::ToomCookMultiplying(unsigned long u, unsigned long v)
{
////////TOOMCOOK//////////////
  
/////////////////////T1/////////////////////
 unsigned long q[3];
 unsigned long r[3];
  q[0] = q[1] = 16;
  r[0] = r[1] = 4;
 unsigned long Q = 4;
 unsigned long R = 2;

  for (k = 2; ; k++)
 {
  Q = Q + R;
    if((R + 1)*(R + 1) <= Q)
     R = R + 1;
  q[k] = 1 << Q;
  r[k] = 1 << R;

  int sum;
  sum = q[k-1] + q[k];
    if((q[k-1] + q[k]) >= n)
     break;
 }
/////////////////////T2/////////////////
 C->push(cd1);
 C->push(u); C->push(v);
/////////////////////T3/////////////////
  for(int j = 0; j < 2; j++)
 {
 k--;
 int rr; int qq; int pp;
  if (k == 0)
 {
  w = u * v;
  cout << w;
 }
  if(k > 0) // k = 1
  {
   rr = r[k]; // 4
   qq = q[k]; // 16
   pp = q[k-1] + q[k]; // 16+16
   T=4;
  } //-->T4


/////////////////////T4//////////////////////
 unsigned long int u0 = u >> rr;             // 0x - left part
 unsigned long int u1 = u & ((1 << rr) - 1); // FF - right part

 unsigned long int v0 = v >> rr;             // 0x - left part
 unsigned long int v1 = v & ((1 << rr) - 1); // FF - right part
  unsigned long UU[2];
  UU[j] = u0 * j + u1;
  U->push(UU[j]);

  unsigned long VV[2];
  VV[j] =  v0 * j + v1;
  V->push(VV[j]);
/////////////////////////////////////////////

/////////////////////T5//////////////////////
C->push(cd2);
C->push(U->pop());
C->push(V->pop());
C->push(cd3);
//k T3
/////////////////////////////////////////////

/////////////////////T6//////////////////////
unsigned long WW[3];
   WW[j] = UU[j] * VV[j];
   W->push(WW[j]);
    //k T3
  }
}
/////////////////////////////////////////////

/////////////////////////////////////////////

/////////////////////T10/////////////////////
 void T10(int cd)
 {
  k = k + 1;
  C->pop();

  if (cd == cd3)  T;

  if (cd == cd2)
    {
	    W->push(w);
    }

  if (cd == cd1)
  {
    cout << w;
    return;
  }
 }
//////////////////////////////////
void main()
{
 clrscr();
 ToomCook T;
 unsigned long u, v;
 cout << "enter U = ";
 cin >> u;
 cout << "\n";

 cout << "enter V = ";
 cin >> v;

 cout << "\n    Res = "; T.ToomCookMultiplying(u,v);

 getch();
}
