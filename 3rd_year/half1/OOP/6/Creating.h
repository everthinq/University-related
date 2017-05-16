#ifndef GAME
#define GAME

#include "00BASEengineFactory.h"
#include "Car.h"

class Creating
{
private:
    Car *CarPointer = new Car;

public:
    Car *createFiat(EngineFactory &factory);
    Car *createLada(EngineFactory &factory);
};

#endif // GAME

