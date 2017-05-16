#include "list.h"

using namespace std;

void _list::print()
{
    cout << "\n\nWe have " << myvector.size() << " elements in container\n\n";

    for (unsigned int i = 0; i < myvector.size(); i++)
    {
        cout << "[" << i << "] element: " << myvector[i];
        cout << "\n";
    }
}

void _list::insert()
{
    int count;

    cout << "Enter count: "; cin >> count;

    string value;

    for (int i = 0; i < count; i++)
    {
        cout << "Enter [" << i << "] element: ";
        cin >> value;
        myvector.push_back(value);
    }
}

void _list::write_in_ex(const char *filepath)
{
    ofstream file_input (filepath);

    string str;
    string str2;

    for (unsigned int i = 0; i < myvector.size(); i++)
    {
        str = myvector[i];
        str2 = str.substr(0, 1);

        if ( (str2 != "B") && (str2 != "b") && (str2 != "Б") && (str2 != "б") )
            file_input << str << endl;
    }
}

void _list::read_from_ex(const char* filepath)
{
    string temp;                          //Это переменная для считывания символов.

    ifstream read_file (filepath);    //Открыли файл для чтения

    if(!read_file.is_open())
    {
        cerr << "File doesn't exist";
        exit(1);
    }

    cout << "Lines from file:\n";

    while (!read_file.eof())
    {
        read_file >> temp;
        cout << temp << endl;
    }

    read_file.close();               //Закрыли файл
}
