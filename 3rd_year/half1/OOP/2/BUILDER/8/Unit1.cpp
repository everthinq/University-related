#include <fstream.h>
#include <string.h>
#include <iostream.h>

int main()
{
    cout << "filename: ";
    string file_name;

    cin >> file_name;

    // открыть файл для ввода
    ifstream inFile( file_name.c_str() );

    if ( !inFile ) {
         cerr <<"не могу открыть входной файл: "
              <<file_name << " -- аварийный останов!\n";
         system("pause"); 
         return -1;
    }

    char ch;
    while ( inFile.get( ch ))
            cout.put( ch );

    system("pause");
}
 
