#include <fstream>
#include "WordCount.h"

int main()
{
    // ������� ���� word.out ��� ������
    ofstream oFile( "word.out" );
    // ����� �������� ���������� �������� ...

    // ������� � ������� ��������� ������ WordCount
    WordCount artist("Renoir" );
    artist.found( 7, 12 ); artist.found( 34, 18 );

    // ���������� �������� <<(ostream&, const WordCount&);
    oFile <<artist;
}

