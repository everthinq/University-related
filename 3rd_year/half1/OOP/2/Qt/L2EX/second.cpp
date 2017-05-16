#include "second.h"

void Second::s_example()
{
   string ifile;
   cout <<"Enter filename for sort: ";
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
                        outfile << buffer << "\n" ;
                }
        cout << "Success\n\n";
   }

   catch(const string& filename)
        {
           cerr << "File doesn't exist.\n\n";
        }
}


