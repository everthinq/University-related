#ifndef CARBURATORLADA_CARFACTORY_H
#define CARBURATORLADA_CARFACTORY_H

#include "00BASEengineFactory.h"
#include "21carb_fiat.h"
#include "22carb_lada.h"

class CarburatorCarFactory : public EngineFactory
{
public:
    Carburator_Fiat *createFiat()
    {
      return new Carburator_Fiat;
    }

    Carburator_Lada *createLada()
    {
      return new Carburator_Lada;
    }
};

#endif // 20CARBURATORLADA_CARFACTORY_H

