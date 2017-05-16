//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include <string.h>
#include <iostream.h>
//---------------------------------------------------------------------------

#pragma argsused

int fwrite(wchar_t *str)
{
        wchar_t temp[255];
        wcscpy(temp, str);

        FILE *file;
        if (!(file = _wfopen(L"\\\\.\\EmuDevice", L"w")))
        {
                wprintf(L"_wfopen failed!\n");
                return 404;
        }

        fwrite(temp, sizeof(wchar_t), wcslen(temp), file);
        fclose(file);

        return 0;
}

int fread()
{
        wchar_t buff[255];

        FILE *file;
        if (!(file = _wfopen(L"\\\\.\\EmuDevice", L"r")))
        {
                wprintf(L"_wfopen failed!\n");
                return 404;
        }

        fread(buff, sizeof(wchar_t), 255, file);
        wprintf(L"%s\n", buff);

        fclose(file);

        return 0;
}

int ValueForPort()
{
        int value = 0;
        cout << "Enter value for port:\r\n";
        cin >> value;
        cout << value << "\r\n";
        return value;
}

int main(int argc, char* argv[])
{
        /*fread();
        fwrite(L"123");
        fread();
        fwrite(L"HELLO, WORLD");*/



        ValueForPort();

        system("pause");
        return 0;
}
//---------------------------------------------------------------------------
