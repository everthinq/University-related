#include <  iostream>
#include <  string.h>
char inBuf[ 1024 ];
try
{
   while ( cin >> inBuf ) {
           char *str = new char[ strlen( inBuf ) + 1 ];
           strcpy( str, inBuf );
           // ... ������� ���-�� � �������� �������� str
           delete [] str;
   }
}
catch( ... ) { delete [] str; throw; }

//�������� � ����� string ����������� �����: 
#include <  iostream>
#include <  string.h>

string str;
while ( cin > str )
        // ... ������� ���-�� �� �������

