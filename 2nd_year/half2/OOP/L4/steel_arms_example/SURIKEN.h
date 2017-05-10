//---------------------------------------------------------------------------

#ifndef SURIKENH
#define SURIKENH
#include "BASECLASS.h"
//---------------------------------------------------------------------------
class SURIKEN : public BASESTEEL
{
        public:
                SURIKEN();
                ~SURIKEN();
                short GetLevel();

                void Move(int To);
                void SLICEandDICE();
};
#endif


