#include "Creating.h"
#include "Car.h"
#include "10Injector_carfactory.h"
#include "20carburator_carfactory.h"

#include <iostream>
using namespace std;

int main()
{
    Creating create;

    InjectorCarFactory Injector_Factory;
    CarburatorCarFactory Carburator_Factory;

    Car *Injector_Car;
    Car *Carburator_Car;


    int switcher;
    int exit = 0;

    while(switcher != exit)
    {
        system("cls");

        cout << "            11 CREATE INJECTOR FIAT = 1\n " << endl;
        cout << "          21 CREATE CARBURATOR FIAT = 2\n " << endl;

        cout << "            12 CREATE INJECTOR Lada = 3\n " << endl;
        cout << "          22 CREATE CARBURATOR Lada = 4\n " << endl;

        cout << "                  PRINT CARS info() = 5\n " << endl;

        cout << "                               EXIT = 0 " << endl;

        cout << endl;
        cin >> switcher;
        cout << endl;

        switch(switcher)
        {
            case 1:
            {
                Injector_Car = create.createFiat(Injector_Factory);
                break;
            }

            case 2:
            {
                Carburator_Car = create.createFiat(Carburator_Factory);
                break;
            }

            case 3:
            {
                Injector_Car = create.createLada(Injector_Factory);
                break;
            }

            case 4:
            {
                Carburator_Car = create.createLada(Carburator_Factory);
                break;
            }

            case 5:
            {
                Carburator_Car->CarInfo();
                break;
            }

            case 6:
            {
                Injector_Car->move();
                break;
            }
         }

               cout << endl;
             system("pause");
    }
}
