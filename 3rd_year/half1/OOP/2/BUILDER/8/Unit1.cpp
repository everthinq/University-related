#include <fstream.h>
#include <string.h>
#include <iostream.h>

int main()
{
    cout << "filename: ";
    string file_name;

    cin >> file_name;

    // ������� ���� ��� �����
    ifstream inFile( file_name.c_str() );

    if ( !inFile ) {
         cerr <<"�� ���� ������� ������� ����: "
              <<file_name << " -- ��������� �������!\n";
         system("pause"); 
         return -1;
    }

    char ch;
    while ( inFile.get( ch ))
            cout.put( ch );

    system("pause");
}
 
