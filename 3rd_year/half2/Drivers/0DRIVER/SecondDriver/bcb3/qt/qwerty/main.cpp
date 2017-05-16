#include <QtCore/QCoreApplication>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>


//---------------------------------------------------------------------------
using namespace std;

int main(int argc, char* argv[])
{
    HANDLE hOut;
    DWORD buff=0;

    wchar_t a[]=L"a";
    wchar_t b[1024];

    hOut = CreateFile(L"\\\\.\\EmuDevice", GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
 if (hOut != INVALID_HANDLE_VALUE){
       // ReadFile(hOut, &b, sizeof(b), &buff, NULL);
       // wprintf(L"%s", b);

       // cout<<endl;
        WriteFile(hOut, &a, 1, &buff, NULL);

        ReadFile(hOut, &b, 1, &buff, NULL);
        wprintf(L"%x", b[0]);

    CloseHandle(hOut);
    }
    else cout<<"Error";
    getch();
    return 0;
}
