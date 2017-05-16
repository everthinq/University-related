#include "list.h"

using namespace std;

void _list::insert(int count)
{
    int value;

    for (int i = 0; i < count; i++)
    {
        cout << "Enter [" << i << "] element: ";
        cin >> value;
        mylist.push_back(value);
    }
    cout << "\n";
}

void _list::print()
{
    cout << "We have " << mylist.size() << " elements in list \n";

    for (int i = 0; i < mylist.size(); i++)
    {
        cout << "[" << i << "] element: " << mylist.at(i);
        cout << "\n";
    }
}

void _list::check()
{
    if (mylist.size() == 0)
    {
        cerr << "Try again later.";
        exit(1);
    }
}

void _list::write_in_basefile1(const char* filepath)
{
    ofstream file_input (filepath);

    char value[20];

    for (int i = 0; i < mylist.size(); i++)
    {
        itoa (mylist[i], value, 10);
        file_input << value << endl;
    }
}

void _list::read_from_file(const char* filepath)
{
    char temp;                          //Это переменная для считывания символов.

    ifstream read_file (filepath);    //Открыли файл для чтения

    if(!read_file.is_open())
    {
        cerr << "File doesn't exist";
        exit(1);
    }

    while (!read_file.eof())
    {
        temp = read_file.get();
        cout << char (temp);
    }

    read_file.close();               //Закрыли файл
}

void _list::write_geometric_even_average_in_file2(const char* filepath)
{
    check();
    int flag = 0;
    ofstream file_input (filepath);      //Геометрическое четных

    char value[20];

    double temp = 1;
    float counter = 0;
    float result = 0;
    for (int i = 0; i < mylist.size(); i++)
    {
        if (mylist[i] % 2 == 0)
        {
            flag++;
            temp = temp * mylist[i];
            itoa (temp, value, 10);
            counter += 1.0;
        }
    }

    result = pow (temp, 1/counter);
    file_input << "\n";
    if (flag != 0)
        file_input << "result of an even geometric average in file 2.txt: " << result << endl;
    else
        cerr << "\nPlease, add even elements.";
}

void _list::write_arithmetic_odd_average_in_file3(const char* filepath)
{
    check();
    int flag = 0;
    ofstream file_input (filepath);       //Арифметическое нечетных

    char value[20];

    int temp = 0;
    int counter = 0;
    for (int i = 0; i < mylist.size(); i++)
    {
        if (mylist[i] % 2 != 0)
        {
            flag++;
            temp = temp + mylist[i];
            itoa (temp, value, 10);
            counter++;
        }
    }

    float result = temp / counter;
    file_input << "\n";
    if (flag != 0)
        file_input << "result of an odd arithmetic average in file 3.txt: " << result;
    else
        cerr << "\nPlease, add odd elements.";
}
