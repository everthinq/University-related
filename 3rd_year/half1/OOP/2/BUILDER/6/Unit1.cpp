#include <fstream.h>
#include <iostream.h>
int main()
{
    // открыть файл copy.out для вывода
    ofstream outFile( "copy.out" );

    if ( ! outFile ) {
        cerr << "Не могу открыть 'copy.out' для вывода\n";
        return -1;
    }

    char ch;
    while ( cin.get( ch ) )
	    outFile.put( ch );
}

