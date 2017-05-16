#include "first.h"

void First::f_example()
{
    string str;

    cout << "Enter your name: ";

    cin >> str;
    if (str.empty())

       cerr << "Error: string is empty!\n";
    else cout << "Hello, " << str << "!" <<"\n\n";
}

