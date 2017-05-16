#include "fourth.h"

void Fourth::f_example()
{
    cout << "filename: ";
    string file_name;

    cin >> file_name;

    // открыть файл для ввода
    ifstream inFile (file_name.c_str() );

    if ( !inFile ) {
         cerr << "File doesn't exist: " << file_name << " -- EXIT!\n";
         exit(1);
    }

    char ch;
    while ( inFile.get(ch))
            cout.put(ch);

}

