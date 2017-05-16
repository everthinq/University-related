//---------------------------------------------------------------------------
#include <cstdio.h>
#include <cwchar.h>
#include<iostream.h>
#include<conio.h>
#include<vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused 
int main(int argc, char* argv[]) 
{
        FILE *In;
        FILE *Out;
        wchar_t *str=L"Helloea";
        wchar_t example[2000];
        Out=_wfopen(L"\\\\.\\EmuDevice",L"r");

        fread(example, 4000, 1, Out);
        wprintf(L"%s", example);
        fclose(Out);

        In=_wfopen(L"\\\\.\\EmuDevice",L"w");

        fwrite(str,wcslen(str)*2,1,In);
        fclose(In);
        Out=_wfopen(L"\\\\.\\EmuDevice", L"r");

        fread(example, 4000, 1, Out);
        wprintf(L"\n%s", example);
        fclose(Out);

        getch();
}
//---------------------------------------------------------------------------
 
