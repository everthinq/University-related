//---------------------------------------------------------------------------

#pragma hdrstop
#include "arr.h"
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        try {
                A b(5,5);
                b.Print();

                b[3]=0;

                b++;

                b[-1]=4;

                b.Print();
            }


        catch (char *error)
         {
                cerr<<"ATTENTION! "<<error<<endl;
         }


        system("pause");
        return 0;
}
//---------------------------------------------------------------------------
 