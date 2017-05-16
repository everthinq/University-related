#include "list.h"

int main()
{
    _list Object;

    Object.insert();
    Object.print();

    cout << endl;

    Object.write_in_ex("ex.txt");
    Object.read_from_ex("ex.txt");

    return 0;
}
