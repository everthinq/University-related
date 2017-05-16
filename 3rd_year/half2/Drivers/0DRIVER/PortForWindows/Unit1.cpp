//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include <string.h>
#include <iostream.h>
//---------------------------------------------------------------------------

#pragma argsused


int writing()
{
        char temp[1];

        FILE *file;
        if (!(file = _wfopen(L"\\\\.\\EmuDevice", L"w")))
        {
                wprintf(L"_wfopen failed!\n");
                return 404;
        }

        cout << "Enter value for port:\r\n";
        cin >> temp[0];

        fwrite(temp, sizeof(char), 1, file);
        fclose(file);

        return 0;
}

int reading()
{
        char buff[255];

        FILE *file;
        if (!(file = _wfopen(L"\\\\.\\EmuDevice", L"r")))
        {
                wprintf(L"_wfopen failed!\n");
                return 404;
        }

        fread(buff, sizeof(char), 255, file);
        printf("%x\n", *buff);
        fclose(file);

        return 0;
}

void menu()
{
        int switcher = 0;
    while (switcher != 3)
    {
        system ("cls");

        cout << "     Write in port = 1" << endl;
        cout << "    Read from port = 2" << endl;
        cout << "              exit = 3" << endl;

    cout << endl;
    cin >> switcher;

      switch (switcher)
      {
        case 1:
        {
          writing();
          break;
        }

        case 2:
        {
          reading();
          break;
        }

        default:
          exit(0);
      }
      system("pause");
    }
}

int check()
{

}

int main(int argc, char* argv[])
{
        menu();
        //check();
        return 0;
}

//---------------------------------------------------------------------------


