
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

    wchar_t a[]=L"0";
    wchar_t b[1024];

    hOut = CreateFile("\\\\.\\EmuDevice", GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

        ReadFile(hOut, &b, sizeof(b), &buff, NULL);
        wprintf(L"%s", b);

        cout<<endl;
        WriteFile(hOut, &a, sizeof(a), &buff, NULL);

        ReadFile(hOut, &b, sizeof(b), &buff, NULL);
        wprintf(L"%s", b);

    CloseHandle(hOut);
    getch();
    return 0;
}
//---------------------------------------------------------------------------

