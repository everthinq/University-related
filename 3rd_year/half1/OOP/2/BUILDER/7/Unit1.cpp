#include <fstream>
#include "WordCount.h"

int main()
{
    // открыть файл word.out для вывода
    ofstream oFile( "word.out" );
    // здесь проверка успешности открытия ...

    // создать и вручную заполнить объект WordCount
    WordCount artist("Renoir" );
    artist.found( 7, 12 ); artist.found( 34, 18 );

    // вызывается оператор <<(ostream&, const WordCount&);
    oFile <<artist;
}

