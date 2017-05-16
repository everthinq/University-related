//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include <string.h>
#include <iostream.h>
#include <conio.h>
#include <windows.h>
//---------------------------------------------------------------------------
#pragma argsused

int BUFF = 512;

int main(int argc, char* argv[])
{
        HANDLE f;
        DWORD buf = 0;

        LARGE_INTEGER li;

        int counter = 1;
        int k = 1;

        unsigned char word[512];

        int n = 0;

        cout<<"Vvedite nomer sektora: ";
        cin>>n;

        f = CreateFile("\\\\.\\PhysicalDrive0", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);

        li.QuadPart = (__int64)n * (__int64)BUFF;
        li.LowPart = SetFilePointer (f, li.LowPart, &li.HighPart, FILE_BEGIN);

        printf("%d ", k);

        if(f != INVALID_HANDLE_VALUE)
        {
          ReadFile(f, &word, sizeof(word), &buf, 0);
          for(int i=0;i<BUFF;i++)
           {
             printf("%02x ",word[i]);

             if(counter == 16)
             {
               k++;
               printf("\n%d ", k);
               counter = 0;
             }
             counter++;
           }
        }
        else cout<<"Error";

        CloseHandle(f);

        getch();
        return 0;
}
//---------------------------------------------------------------------------
