#include <iostream.h>
#include <fstream.h>
#include <string.h>
int main()
{
        system("chcp 1251");

   string ifile;
   cout <<"Введите имя файла для сортировки: ";
   cin >> ifile;

   string ofile = ifile + ".sort";

   try
    {
        ifstream infile( ifile.c_str() );  // сконструировать объект класса ifstream для ввода из файла
        if ( ! infile ) throw(ifile);

        ofstream outfile( ofile.c_str() ); // сконструировать объект класса ofstream для вывода в файл
        if ( ! outfile) throw(ofile);


        string buffer;
        while ( infile >> buffer )
                {
                        //text.push_back( buffer );
                        outfile<<buffer << "\n" ;
                }
        cout<<"Sucees\n";        
   }

   catch(const string& filename)
        {
           cerr<<"ошибка: не могу открыть файл: "<<filename<<"\n";
        }
   system("pause");     
   return 0;

}

