#ifndef FIAT1_H
#define FIAT1_H
#include <iostream>
using namespace std;



class Fiat
{
public:
    virtual void info() = 0;
    virtual void move() = 0;
    virtual void sell() = 0;
    virtual ~Fiat() {}
};

#endif // FIAT1_H
