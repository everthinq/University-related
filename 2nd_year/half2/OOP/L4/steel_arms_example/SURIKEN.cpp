//---------------------------------------------------------------------------

#pragma hdrstop

#include "SURIKEN.h"
#include "BASECLASS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
SURIKEN::SURIKEN():BASESTEEL(20,1,0, "SURIKEN"){cout<<"Constructor for SURIKEN\n";}
//---------------------------------------------------------------------------
SURIKEN::~SURIKEN(){cout<<"Destructor for SURIKEN\n";}
//---------------------------------------------------------------------------
short SURIKEN::GetLevel()
{
        cout<<"GetLevel for SURIKEN\n";
        return _level;
}
//---------------------------------------------------------------------------
void SURIKEN::Move(int To)
{
        cout<<"Make move for SURIKEN\n";
        _x += To;
}
//---------------------------------------------------------------------------
void SURIKEN::SLICEandDICE()
{
        cout<<"TARGET SLICED by SURIKEN\n";
}
#pragma package(smart_init)


