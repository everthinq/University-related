#ifndef Injector_Fiat1_H
#define Injector_Fiat1_H
#include "01BASEfiat.h"

class Injector_Fiat : public Fiat
{
  public:
    void info()
    {
        cout << "I'm an INJECTOR Fiat!" << endl;
    }

    void move()
    {
        cout << "INJECTOR Fiat MOVED!" << endl;
    }

    void sell()
    {
        cout << "INJECTOR Fiat SOLD!" << endl;
    }
};

#endif // Injector_Fiat1

