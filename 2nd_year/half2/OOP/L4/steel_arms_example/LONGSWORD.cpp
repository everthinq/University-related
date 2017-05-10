//---------------------------------------------------------------------------

#pragma hdrstop

#include "LONGSWORD.h"
#include "BASECLASS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
LONGSWORD::LONGSWORD():BASESTEEL(15,1,0, "LONGSWORD"){cout<<"Constructor for LONGSWORD\n";}
//---------------------------------------------------------------------------
LONGSWORD::~LONGSWORD(){cout<<"Destructor for LONGSWORD\n";}
//---------------------------------------------------------------------------
short LONGSWORD::GetLevel()
{
        cout<<"GetLevel for LONGSWORD\n";
        return _level;
}
//---------------------------------------------------------------------------
void LONGSWORD::Move(int To)
{
        cout<<"Make move for LONGSWORD\n";
        _x += To;
}
//---------------------------------------------------------------------------
void LONGSWORD::SLICEandDICE()
{
        cout<<"TARGET SLICED by LONGSWORD\n";
}

#pragma package(smart_init)


