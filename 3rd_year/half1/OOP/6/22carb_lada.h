#ifndef CARB_LADA
#define CARB_LADA

#include "02BASElada.h"

class Carburator_Lada : public Lada
{
  public:
    void info()
    {
        cout << "I'm a CARB Lada!" << endl;
    }

    void move()
    {
        cout << "CARB Lada MOVED!" << endl;
    }

    void sell()
    {
        cout << "CARB Lada SOLD!" << endl;
    }
};

#endif // 22CARB_LADA

