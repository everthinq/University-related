#ifndef ARMY_H
#define ARMY_H

#include "01BASEfiat.h"
#include "02BASElada.h"

#include <vector>

class Car
{
public:
   ~Car();
    void CarInfo();
    void move();
    void sell();

    vector <Fiat*> vector_of_Fiats;
    vector <Lada*> vector_of_Ladas;
};

#endif // ARMY_H
