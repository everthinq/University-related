#include <fstream.h>
#include <iostream.h>
int main()
{
    // ������� ���� copy.out ��� ������
    ofstream outFile( "copy.out" );

    if ( ! outFile ) {
        cerr << "�� ���� ������� 'copy.out' ��� ������\n";
        return -1;
    }

    char ch;
    while ( cin.get( ch ) )
	    outFile.put( ch );
}

