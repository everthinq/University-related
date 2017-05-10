//---------------------------------------------------------------------------
#include <iostream.h>
#include <conio.h>
#include <map.h>
#include "baseclass.h"
#include "KATANA.h"
#include "SURIKEN.h"
#include "LONGSWORD.h"
//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
//---------------------------------------------------------------------------
enum Action {ADD=1,DELETE,DOSMTH,PRINT,GETLEVEL,MOVE,SLICEANDDICE};
//---------------------------------------------------------------------------
BASESTEEL* ADDSTEEL();
void DoSmth();
//---------------------------------------------------------------------------
map <std::string,BASESTEEL*> STEELs;

map <std::string,BASESTEEL*>::iterator it;
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
        BASESTEEL* pSTEEL=NULL;

        std::string name="";

        int action=0, temp=0;

 while (1)
  {

    clrscr();

        cout<<"What do you want to do?\n";
        cout<<"1 - To add STEEL\n2 - To delete STEEL\n3 - To do smth\n";
        cout<<"4 - To print STEEL list\n0 - exit\n";
        cout<<"Enter, please, number of operation...\n";

    cin>>action;

    switch(action)
    {
        case ADD:    pSTEEL=ADDSTEEL();

                     cout<<"Enter personal STEEL name\n";
                     cin>>name;

                     STEELs[name]=pSTEEL;

                     cout<<"The STEEL was added succesfully\n";

        	     break;

        case DELETE: clrscr();

                     cout<<"Enter name of the deleted STEEL\n";
                     cin>>name;

                     temp=0;

                     for (it=STEELs.begin(); it!=STEELs.end(); it++)
                     if (it->first==name)
                      {
                        delete (*it).second;
                        it->second=NULL;

                        STEELs.erase(it);
                        it=NULL;

                        cout<<"STEEL was deleted succesfully\n";
                        temp++; break;
                      }

                     if (!temp) cout<<"Program could not find match for "<<name<<endl;

                     break;

        case DOSMTH: clrscr();
        
                     DoSmth();
	             break;

        case PRINT:  for (it=STEELs.begin(); it!=STEELs.end(); it++)
                        cout << (*it).first << " : " << (*it).second->_type << endl;

                     break;

        case 0: exit(0);

        default: break;

    }

    system("pause");

  }
}
//---------------------------------------------------------------------------
BASESTEEL* ADDSTEEL()
{
   int model=0;
   BASESTEEL* pSTEEL=NULL;

   clrscr();
   
   cout<<"Choose STEEL model...\n";
   cout<<"1 - KATANA\n2 - SURIKEN\n3 - LONGSWORD\n";

  while(1)
   {

     cin>>model;

    switch(model)
        {

          case 1: pSTEEL=new KATANA(); break;

          case 2: pSTEEL=new SURIKEN(); break;

          case 3: pSTEEL=new LONGSWORD(); break;

          default: cout<<"Wrong number\n"; continue;

        }

    if (pSTEEL) return pSTEEL;
    else {cout<<"error"; system("pause"); continue;}

   }
}

//---------------------------------------------------------------------------
void DoSmth()
{
        int action=0;

        cout<<"1 - GetLevel\n2 - MakeMove\n3 - SLICEandDICE\n0 - exit\n";
        cin>>action;
        action+=4;

     it=STEELs.begin();

     while(it!=STEELs.end())
     {

        switch(action)
         {
           case GETLEVEL:  it->second->GetLevel();
                           break;

           case MOVE:     it->second->Move(1);
                          break;

           case SLICEANDDICE:    it->second->SLICEandDICE();
                          break;

           case 4: return;

           default: cout<<"Wrong number\n";

         }
       it++;
     }
}
//---------------------------------------------------------------------------


