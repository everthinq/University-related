#ifndef Injector_Fiat2_H
#define Injector_Fiat2_H
#include "02BASElada.h"

class Injector_Lada : public Lada
{
  public:
    void info()
    {
        cout << "I'm an INJECTOR Lada!" << endl;
    }

    void move()
    {
        cout << "INJECTOR Lada MOVED!" << endl;
    }

    void sell()
    {
        cout << "INJECTOR Lada SOLD!" << endl;
    }
};

#endif // Injector_Fiat2

