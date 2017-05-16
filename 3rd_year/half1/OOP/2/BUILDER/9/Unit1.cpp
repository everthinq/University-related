#include <fstream.h> 

const int fileCnt = 5;
string fileTabl[ fileCnt ] = {
    "Melville", "Joyce", "Musil", "Proust", "Kafka"
};

int main()
{
    ifstream inFile; // не связан ни с каким файлом

    for ( int ix = 0; ix < fileCnt; ++ix )
    {
        inFile.open( fileTabl[ix].c_str() );
        // ... проверить успешность открытия
        // ... обработать файл
        inFile.close();
    }
}
 
