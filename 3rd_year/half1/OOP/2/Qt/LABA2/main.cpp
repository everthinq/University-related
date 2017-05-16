#include "_fstream.h"

int main()
{

    _FSTREAM Object; // ОБЪЕКТ КЛАССА ОЧЕРЕДЬ

    int count;

    cout << "Enter count: ";
    cin >> count; cout << "\n";

    Object.insert(count);

    Object.write_in_f("f.txt");
    Object.write_in_other("g.txt");

    Object.read_from_file("g.txt"); cout << "\n";
    Object.read_from_file("h.txt");
}
