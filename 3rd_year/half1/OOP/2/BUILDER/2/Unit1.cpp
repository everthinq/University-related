#include <iostream.h>
#include <fstream.h>
#include <string.h>
int main()
{
        system("chcp 1251");

   string ifile;
   cout <<"������� ��� ����� ��� ����������: ";
   cin >> ifile;

   string ofile = ifile + ".sort";

   try
    {
        ifstream infile( ifile.c_str() );  // ��������������� ������ ������ ifstream ��� ����� �� �����
        if ( ! infile ) throw(ifile);

        ofstream outfile( ofile.c_str() ); // ��������������� ������ ������ ofstream ��� ������ � ����
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
           cerr<<"������: �� ���� ������� ����: "<<filename<<"\n";
        }
   system("pause");     
   return 0;

}

