#include <iostream.h>

// Вспомогательный класс
class Object  
{
  public:
    Object() { cout << "Object::ctor()" << endl; }
   ~Object() { cout << "Object::dtor()" << endl; }
};
 
// Базовый класс
class Base 
{
  public:
    Base() { cout << "Base::ctor()" << endl; }
    /*virtual*/ ~Base() { cout << "Base::dtor()" << endl; }
    virtual void print() = 0;
};
 
// Производный класс
class Derived: public Base 
{
  public:
    Derived() { cout << "Derived::ctor()" << endl; }
   ~Derived() { cout << "Derived::dtor()" << endl; }
    void print() {}   
    Object  obj;
};
 
int main ()
{
    Base * p = new Derived;
    delete p;

    cout<<endl;

    Derived *pd = new Derived;
    delete pd;

    system("pause");
    return 0;
}

