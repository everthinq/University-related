#include "Car.h"

Car::~Car()
{
    unsigned int i;

    for(i = 0; i < vector_of_Fiats.size(); ++i)  delete vector_of_Fiats[i];

    for(i = 0; i < vector_of_Ladas.size(); ++i)  delete vector_of_Ladas[i];
}

void Car::CarInfo()
{
    unsigned int i;
    int switcher;
    int exit = 0;

    while(switcher != exit)
    {
        system("cls");

        cout << "            PRINT INFO ABOUT FIAT = 1\n " << endl;
        cout << "            PRINT INFO ABOUT LADA = 2\n " << endl;

        cout << "                             BACK = 0 " << endl;

        cout << endl;
        cin >> switcher;
        cout << endl;

        switch(switcher)
            {
                case 1:
                {
                        for(i = 0; i < vector_of_Fiats.size(); ++i)  vector_of_Fiats[i]->info();
                }

                case 2:
                {

                        for(i = 0; i < vector_of_Ladas.size(); ++i)  vector_of_Ladas[i]->info();
                }


                system("pause");
            }

        }
}

void Car::move()
{
    unsigned int i;

    for(i = 0; i < vector_of_Fiats.size(); ++i)  vector_of_Fiats[i]->move();

    for(i = 0; i < vector_of_Ladas.size(); ++i)  vector_of_Ladas[i]->move();
}

void Car::sell()
{
    unsigned int i;
}
