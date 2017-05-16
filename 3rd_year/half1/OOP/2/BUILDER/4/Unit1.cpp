#include <  iostream>
#include <  string.h>
char inBuf[ 1024 ];
try
{
   while ( cin >> inBuf ) {
           char *str = new char[ strlen( inBuf ) + 1 ];
           strcpy( str, inBuf );
           // ... сделать что-то с массивом символов str
           delete [] str;
   }
}
catch( ... ) { delete [] str; throw; }

//–аботать с типом string значительно проще: 
#include <  iostream>
#include <  string.h>

string str;
while ( cin > str )
        // ... сделать что-то со строкой

