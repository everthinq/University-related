#include "third.h"

string program_name( "our_program" );
string version("0.01");
int *array = 0;

void Third::t_example()
{
    cout << mumble(array, 5);
}

string Third::mumble(int *array, int size)
{
    if ( ! array )
     {
         ostringstream out_message;
         out_message << "Error: " << program_name << "--" << version
                     << ": " << __FILE__ << ": " << __LINE__ << " -- NULL pointer; "
                     << " instead of pointing array.\n";
         // возвращаем строку, в которой находится сообщение
         return out_message.str();
      }
      return NULL;
}

