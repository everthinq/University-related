//---------------------------------------------------------------------------

#pragma hdrstop

#include "BASECLASS.h"
//---------------------------------------------------------------------------

BASESTEEL::BASESTEEL(short lvl, long status, int x, std::string t)
                   :_level(lvl),_status(status), _x(x), _type(t)
                   { cout << "Constructor for BASECLASS\n"; }
//---------------------------------------------------------------------------
BASESTEEL::~BASESTEEL() { cout<<"Destructor for BASECLASS\n"; }
//---------------------------------------------------------------------------

#pragma package(smart_init)

