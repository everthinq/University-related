//---------------------------------------------------------------------------

#ifndef KATANAH
#define KATANAH
#include "BASECLASS.h"
//---------------------------------------------------------------------------
class KATANA : public BASESTEEL
{
        public:
                KATANA();
                ~KATANA();
                short GetLevel();

                void Move(int To);
                void SLICEandDICE();
};
#endif

