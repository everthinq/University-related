//---------------------------------------------------------------------------

#ifndef LONGSWORDH
#define LONGSWORDH
#include "BASECLASS.h"
//---------------------------------------------------------------------------
class LONGSWORD : public BASESTEEL
{
        public:
                LONGSWORD();
                ~LONGSWORD();
                short GetLevel();

                void Move(int To);
                void SLICEandDICE();
};
#endif


