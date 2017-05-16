//---------------------------------------------------------------------------
#include <iostream.h>
#include <windows.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        __try
 {
          int a=0;
          a=1/a;
 }
        __except(GetExceptionCode() == EXCEPTION_INT_DIVIDE_BY_ZERO ?
             EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH)
 {
                cout<<"Error division by zero\n";
 } 

 system("pause");
        return 0;
}
//---------------------------------------------------------------------------
 