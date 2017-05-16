#include "list.h"

int main()
{
    _list Object;

    int count; cout << "Enter count: "; cin >> count; cout << "\n";

    Object.insert(count);
    cout << "\n";

    Object.write_in_basefile1("1.txt");

    Object.write_geometric_even_average_in_file2("2.txt");
    Object.read_from_file("2.txt");

    Object.write_arithmetic_odd_average_in_file3("3.txt");
    Object.read_from_file("3.txt");
}
