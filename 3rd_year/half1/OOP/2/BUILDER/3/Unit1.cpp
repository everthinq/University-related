#include <sstream.h>
#include <string.h>
#include <iostream.h>
string program_name( "our_program" );
string version("0.01");

string mumble( int *array, int size )
{
   if ( ! array ) {
      ostringstream out_message;
      out_message << "ошибка: " << program_name << "--" << version
                  << ": " << __FILE__ << ": " << __LINE__ << " -- указатель равен 0; "
                  << " а должен адресовать массив.\n";
      // возвращаем строку, в которой находится сообщение
      return out_message.str();
   }
   return NULL;
}

void main ()
{
        system("chcp 1251");
        int *array=0;

        cout<<mumble(array,5);

        system("pause");

}



