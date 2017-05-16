
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
    HANDLE hOut;
    DWORD buff=0;

    wchar_t *a=L"aw";
    wchar_t *b;

    hOut = CreateFile("\\\\.\\EmuDevice", GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

    if (hOut != INVALID_HANDLE_VALUE)
    {
        WriteFile(hOut, &a, sizeof(&a), &buff, NULL);
        ReadFile(hOut, &b, sizeof(&a), &buff, NULL);
        wprintf(L"%s", b);
    }
    else cout<<"Error";

    CloseHandle(hOut);
    getch();
    return 0;
}
//---------------------------------------------------------------------------
