//---------------------------------------------------------------------------
#pragma hdrstop
#include <vcl.h>
#include <stdio.h>
#include <string.h>
#include <iostream.h>
#include <conio.h>
#include <windows.h>
//---------------------------------------------------------------------------
#define SECTOR_SIZE 512

void PETYA()
{
        HANDLE FileHandle;
        DWORD buf = 0;
        LARGE_INTEGER li;
        unsigned char word[512];

        int SectorNumber;

        cout << "Enter Sector Number: ";
        cin >> SectorNumber;

        FileHandle = CreateFile("\\\\.\\PhysicalDrive0",
                                        GENERIC_READ,
                                        FILE_SHARE_READ,
                                        NULL,
                                        OPEN_EXISTING,
                                        0,
                                        NULL);

        li.QuadPart = (__int64)SectorNumber * (__int64)SECTOR_SIZE;
        li.LowPart = SetFilePointer (FileHandle, li.LowPart, &li.HighPart, FILE_BEGIN);

        if(FileHandle != INVALID_HANDLE_VALUE)
        {
          ReadFile(FileHandle, &word, sizeof(word), &buf, 0);

          int k = 1;
          printf("%d ", k);
          int counter = 1;

          for(int i = 0; i < SECTOR_SIZE; i++)
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
        else cout << "Error";

        CloseHandle(FileHandle);
}

HANDLE OpenDevice()
{
        HANDLE FileHandle;

        FileHandle = CreateFile("\\\\.\\PhysicalDrive0",
                            GENERIC_READ,
                            FILE_SHARE_READ,// | FILE_SHARE_WRITE,
                            NULL,
                            OPEN_EXISTING,
                            0,
                            NULL);

        if (FileHandle != INVALID_HANDLE_VALUE)
                return FileHandle;

        cout << "Open Failed!\n";
        return INVALID_HANDLE_VALUE;
}
