#ifndef CARB_FIAT
#define CARB_FIAT

#include "01BASEfiat.h"

class Carburator_Fiat : public Fiat
{
  public:
    void info()
    {
        cout << "I'm a CARB Fiat1!" << endl;
    }

    void move()
    {
        cout << "CARB Fiat MOVED!" << endl;
    }

    void sell()
    {
        cout << "CARB Fiat SOLD!" << endl;
    }
};

#endif // 21CARB_FIAT

