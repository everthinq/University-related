//---------------------------------------------------------------------------
#pragma hdrstop
#include <windows.h>
#include <winioctl.h>
#include <stdio.h>
//---------------------------------------------------------------------------

BOOL GetDriveGeometry(DISK_GEOMETRY *pdg)
{
        HANDLE hDevice;
        BOOL bResult;
        DWORD junk;

        hDevice = CreateFile("\\\\.\\PhysicalDrive0",
                                        0,
                                        FILE_SHARE_READ, // | FILE_SHARE_WRITE,
                                        NULL,
                                        OPEN_EXISTING,
                                        0,
                                        NULL);

        if (hDevice == INVALID_HANDLE_VALUE)
                return (FALSE);


        bResult = DeviceIoControl(hDevice,
                                  IOCTL_DISK_GET_DRIVE_GEOMETRY,
                                  NULL, 0,
                                  pdg, sizeof(*pdg),
                                  &junk,
                                  (LPOVERLAPPED) NULL);
        CloseHandle(hDevice);

        return (bResult);
}

void PrintDriveGeometry()
{
        DISK_GEOMETRY pdg;
        BOOL bResult;
        ULONGLONG DiskSize;

        bResult = GetDriveGeometry (&pdg);

        if (bResult)
        {
                printf("Cylinders               = %I64d\n", pdg.Cylinders);
                printf("Tracks per cylinder     = %ld\n", (ULONG) pdg.TracksPerCylinder);
                printf("Sectors per track       = %ld\n", (ULONG) pdg.SectorsPerTrack);
                printf("Bytes per sector        = %ld\n\n", (ULONG) pdg.BytesPerSector);

                DiskSize = pdg.Cylinders.QuadPart * (ULONG)pdg.TracksPerCylinder *
                                (ULONG)pdg.SectorsPerTrack * (ULONG)pdg.BytesPerSector;

                printf("Disk size = %I64d(Bytes) = %I64d (Gb)\n", DiskSize,
                DiskSize / (1024 * 1024 * 1024));
        }

        else{
                printf ("GetDriveGeometry failed. Error %ld.\n", GetLastError ());
            }

}
#pragma package(smart_init)
 