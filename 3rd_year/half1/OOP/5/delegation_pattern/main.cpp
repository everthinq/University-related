#include "hex.h"
#include "text.h"
#include "switcher.h"

int main()
{
    SWITCHER switcher;

        int switcher2 = 0;
             int exit = 3;

        while(switcher2 != exit)
        {
            system("cls");

            cout << "             fread = 0 " << endl;
            cout << "             toHEX = 1 " << endl;
            cout << "            toTEXT = 2 " << endl;
            cout << "              EXIT = 3 " << endl;

            cout << endl;
            cin >> switcher2;
            cout << endl;

            switch(switcher2)
            {
                case 0: // print
                {
                    switcher.fread("1.txt");
                    break;
                }

                case 1:
                {
                    switcher.toHEX();
                    qDebug() << "SWITCHER CHANGED TO HEX.";
                    break;
                }

                case 2: //push_back
                {
                    switcher.toTEXT();
                    qDebug() << "SWITCHER CHANGED TO TEXT.";
                    break;
                }
            }
            cout << endl;
          system("pause");
        }
}
