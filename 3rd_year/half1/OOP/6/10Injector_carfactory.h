#ifndef FERST_CARFACTORY
#define FERST_CARFACTORY
#include "00BASEengineFactory.h"
#include "11Injector_fiat.h"
#include "12Injector_lada.h"

class InjectorCarFactory : public EngineFactory
{
public:
    Injector_Fiat *createFiat()
    {
      return new Injector_Fiat;
    }


    Injector_Lada *createLada()
    {
      return new Injector_Lada;
    }
};

#endif // ROMAN_ARMYFACTORY

