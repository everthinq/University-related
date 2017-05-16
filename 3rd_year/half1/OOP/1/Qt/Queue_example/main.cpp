#include "_queue.h"

int main()
{
    _queue Object; // ОБЪЕКТ КЛАССА ОЧЕРЕДЬ

    int switcher = 0; // ПЕРЕКЛЮЧАТЕЛЬ
         int pos = 0; // ПОЗИЦИЯ
       int value = 0; // ЗНАЧЕНИЕ
        int exit = 5; // ВЫХОД ИЗ СВИТЧА

    while(switcher != exit) // ПОКА ПЕРЕКЛЮЧАТЕЛЬ НЕ РАВЕН ВЫХОДУ
    {
        system("cls");

        cout << "       print_queue = 0 " << endl;
        cout << "        operator[] = 1 " << endl;
        cout << "         push_back = 2 " << endl;
        cout << "          pop_back = 3 " << endl;
        cout << "            insert = 4 " << endl;
        cout << "              EXIT = 5 " << endl;

        cout << endl;
        cin >> switcher;

        switch(switcher) // ПЕРЕКЛЮЧАТЕЛЬ
        {
            case 0: // print
            {
                Object.__print();
                break;
            }

            case 1: //operator[]
            {
                qDebug() << "Enter position to execute overloaded operator[]: "; cin >> pos;
                qDebug() << Object[pos];
                break;
            }

            case 2: //push_back
            {
                qDebug() << "Enter value: "; cin >> value;
                Object.__push_back(value);
                break;
            }

            case 3: //pop_back
            {
                Object.__pop_back();
                break;
            }

            case 4: //insert
            {

                qDebug() <<   "Enter pos: "; cin >> pos;
                qDebug() << "Enter value: "; cin >> value;

                Object.__insert(pos, value);
                break;
            }
        }
      system("pause");
    }
}
