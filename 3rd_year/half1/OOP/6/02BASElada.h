#ifndef Fiat2_H
#define Fiat2_H
#include <iostream>
using namespace std;



class Lada
{
public:
    virtual void info() = 0;
    virtual void move() = 0;
    virtual void sell() = 0;
    virtual ~Lada() {}
};

#endif // Fiat2_H

