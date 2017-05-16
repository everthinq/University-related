#include "Creating.h"

Car *Creating::createFiat(EngineFactory &factory)
{
    CarPointer->vector_of_Fiats.push_back (factory.createFiat());
    return CarPointer;
}

Car *Creating::createLada(EngineFactory &factory)
{
    CarPointer->vector_of_Ladas.push_back (factory.createLada());
    return CarPointer;
}
