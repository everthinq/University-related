#include <iostream.h>
//----------------------------------------------------------------
class Base {
public:
   virtual void NameOf();   // Virtual function.
   void InvokingClass();   // Nonvirtual function.
};
//----------------------------------------------------------------
                                 // Implement the two functions
void Base::NameOf() {
   cout << "Base::NameOf\n";
}

void Base::InvokingClass() {
   cout << "Invoked by Base\n";
}
//----------------------------------------------------------------
class Derived : public Base {
public:
   void NameOf();          // Virtual function.
   void InvokingClass();   // Nonvirtual function.
};
//----------------------------------------------------------------
void Derived::NameOf() {
   cout << "Derived::NameOf\n";
}

void Derived::InvokingClass() {
   cout << "Invoked by Derived\n";
}
//----------------------------------------------------------------
int main()
{
   Derived aDerived; // Declare an object of type Derived.

   /* Declare two pointers, one of type Derived * and the other
     of type Base *, and initialize them to point to aDerived.*/
 //  Derived *pDerived = &aDerived;
 //  Base    *pBase    = &aDerived;

   Base *pBase = new Derived;
  // Derived *pDerived = new Base;

   pBase->NameOf();           // Call virtual function.
   pBase->InvokingClass();    // Call nonvirtual function.

 //  pDerived->NameOf();        // Call virtual function.
 //  pDerived->InvokingClass(); // Call nonvirtual function.

   system("paUsE");
}

