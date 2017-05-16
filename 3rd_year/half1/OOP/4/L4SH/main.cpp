#include "_vector.h"

int main()
{
    _vector Object0;

    Object0.read_from_file("BASE.txt");
    Object0._sort();
    Object0.print();
    Object0.write_vec_in_file("SORTED.txt");

    return 0;
}
