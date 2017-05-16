#ifndef BASECARFACTORY
#define BASECARFACTORY
#include "01BASEfiat.h"
#include "02BASElada.h"


class EngineFactory
{
public:
    virtual Fiat *createFiat() = 0;
    virtual Lada *createLada() = 0;
    virtual ~EngineFactory() {}
};

#endif // BASECARFACTORY

