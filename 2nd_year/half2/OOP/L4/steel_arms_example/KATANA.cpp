//---------------------------------------------------------------------------

#pragma hdrstop

#include "KATANA.h"
#include "BASECLASS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
KATANA::KATANA():BASESTEEL(25,1,0, "KATANA"){cout<<"Constructor for KATANA\n";}
//---------------------------------------------------------------------------
KATANA::~KATANA(){cout<<"Destructor for KATANA\n";}
//---------------------------------------------------------------------------
short KATANA::GetLevel()
{
        cout<<"GetLevel for KATANA\n";
        return _level;
}
//---------------------------------------------------------------------------
void KATANA::Move(int To)
{
        cout<<"Make move for KATANA\n";
        _x += To;
}
//---------------------------------------------------------------------------
void KATANA::SLICEandDICE()
{
        cout<<"TARGET SLICED by KATANA\n";
}

#pragma package(smart_init)


