#include "first.h"
#include "second.h"
#include "third.h"
#include "fourth.h"
#include "fifth.h"

int main()
{
    First first;
    Second second;
    Third third;
    Fourth fourth;
    Fifth fifth;

    int switcher = 0;
    while (switcher != 6)
    {
        system ("cls");

        cout << "     First example = 1" << endl;
        cout << "    Second example = 2" << endl;
        cout << "     Third example = 3" << endl;
        cout << "    Fourth example = 4" << endl;
        cout << "     Fifth example = 5" << endl;
        cout << "              EXIT = 6" << endl;

    cout << endl;
    cin >> switcher;

      switch (switcher)
      {
        case 1:
        {
          first.f_example();
          break;
        }

        case 2:
        {
          second.s_example();
          break;
        }

        case 3:
        {
          third.t_example();
          break;
        }

        case 4:
        {
          fourth.f_example();
          break;
        }

        case 5:
        {
          fifth.f_example();
          break;
        }
      }

     getch();
    }
}

