//---------------------------------------------------------------------------
#include <vcl.h>
#include <windows.h>
#include <iostream.h>
#include <conio.h>
#include "Unit2.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#define SECTOR_SIZE 512

HANDLE OpenDevice(int device)
{
        HANDLE handle;

        char _devicename[20];
        sprintf(_devicename, "\\\\.\\PhysicalDrive%d", device);

        // Creating a handle to disk drive using CreateFile () function ..
        handle = CreateFile(_devicename,
                            GENERIC_READ,
                            FILE_SHARE_READ,// | FILE_SHARE_WRITE,
                            NULL,
                            OPEN_EXISTING,
                            0,
                            NULL);

        if (handle == INVALID_HANDLE_VALUE)
        {
                cout << "Open Failed!\n";
                return INVALID_HANDLE_VALUE;
        }

        return handle;
}

bool CopySectorToFile(HANDLE Device, HANDLE File, DWORD Sector)
{
    const int NumberOfSectors = 1;
    bool Result = false;
    // Setting the pointer to point to the start of the sector we want to read ..
    SetFilePointer (Device, (Sector * SECTOR_SIZE), NULL, FILE_BEGIN);

    DWORD dwBytesRead;
    DWORD dwBytesWritten;

    unsigned char Buffer[SECTOR_SIZE];
    if (ReadFile (Device, Buffer, SECTOR_SIZE * NumberOfSectors, &dwBytesRead, NULL))
    {
       Result = WriteFile (File,
                           Buffer,
                           dwBytesRead,
                           &dwBytesWritten,
                           NULL);
    }

    return Result;
}

/*void ReadSector(DWORD Number_of_Sector)
{
        HANDLE handle;
        DWORD buffer = 0;
        BYTE sector[SECTOR_SIZE];
        int temp;
        LARGE_INTEGER li;

        handle = OpenDevice(0);
        cout << handle;

        ReadFile(handle, &sector, sizeof(&sector), &buffer, NULL);

        CloseHandle(handle);
}*/
