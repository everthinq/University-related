#ifndef EX1_H
#define EX1_H

#include <iostream>
using namespace std;

class A1
{
public:
    void foo() {  cout << "A: method foo executed. // foo()" << endl; }
    void bar() {  cout << "A: method bar executed. // bar()" << endl; }
};

class B1
{

private:
        A1* a; // Создаём объект, методам которого будет делегироваться поведение.

public:
        B1(){    a = new A1();}
       ~B1(){    delete a;}

  void foo() {  a->foo(); }
  void bar() {
      a->bar(); }
};

#endif // EX1_H
