#include <fstream.h> 

const int fileCnt = 5;
string fileTabl[ fileCnt ] = {
    "Melville", "Joyce", "Musil", "Proust", "Kafka"
};

int main()
{
    ifstream inFile; // �� ������ �� � ����� ������

    for ( int ix = 0; ix < fileCnt; ++ix )
    {
        inFile.open( fileTabl[ix].c_str() );
        // ... ��������� ���������� ��������
        // ... ���������� ����
        inFile.close();
    }
}
 
