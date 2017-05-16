#include "_fstream.h"

void _FSTREAM::insert(int count)
{
    int value;

       for (int i = 0; i < count; i++)
       {
           cout << "Enter [" << i << "] element: ";
           cin >> value;
           myList.push_back(value);
       }
       cout << "\n";
}

void _FSTREAM::check()
{
    if (myList.isEmpty())
    {
        qDebug() << "Your list is empty.";
        exit(404);
    }
}

void _FSTREAM::read_from_file(const char *filepath)
{
    char temp;                          //Это переменная для считывания символов.

        ifstream read_file (filepath);  //Открыли файл для чтения

        if(!read_file.is_open())
        {
            qDebug() << "File doesn't exist";
            exit(404);
        }

        while (!read_file.eof())
        {
            temp = read_file.get();
            cout << char (temp);
        }

        read_file.close();               //Закрыли файл
}

void _FSTREAM::write_in_f(const char *filepath)
{
    ofstream file_input (filepath);
        for (int i = 0; i < myList.size(); i++)
            file_input << myList[i] << endl;
}

void _FSTREAM::write_in_other(const char *filepath)
{
    check();

        ofstream file_g (filepath);      //2 и 4
        ofstream file_h ("h.txt");

        for (int i = 0; i < myList.size(); i++)
        {
            if ( (myList[i] % 2 == 0) && (myList[i] % 4 == 0) && (myList[i] % 6 != 0) )
                file_g << "file g: " << myList[i] << "\n";
            else
                file_h << "file h: " << myList[i] << "\n";
        }
}
