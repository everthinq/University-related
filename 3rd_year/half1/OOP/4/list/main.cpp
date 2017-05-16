#include <list.h>
#include <vector>

using namespace std;

typedef int Type;

list <Type> a;

void drawMenu ()
{
    vector <string> menu {"Create list", "Add element", "push_back",
                          "pop_back", "Size", "Erase", "Print", "Erase All"};

    cout << "Choose operation that you want to do:\n";

    size_t i = 1;

    for ( auto &item : menu )
            cout << i++ << " - " << item << endl;

    cout << R"(Enter, please, number of operation and press "enter"-button...)" << endl;
}

void Create()
{
    cout << "Enter, please, count of our list elements\n";
    size_t count;
    cin >> count;

   // initializer_list <Type> initlist;

    Type temp_data;

    for ( size_t i = 0; i < count; i++ )
           {
                cin >> temp_data;
                a.push_back(temp_data);
           }
}

void Add ()
{
    cout << "Enter, please, data and number of the added element\n";
    Type data; int number;
    cin >> data >> number;

    a.Add(data, number);
}

void push()
{
    cout << "Enter, please, data of the pushed element\n";
    Type data;
    cin >> data;

    a.push_back(data);
}

void Erase()
{
    cout << "Enter, please, number of the deleted element\n";
    int number;
    cin >> number;

    a.erase(number);
}

void switch_move (int key)
{
    switch (key)
    {
        case 1: Create();
            break;

        case 2: Add ();
            break;

        case 3: push();
            break;

        case 4: cout << "Number of the pop_back-element is: " << a.pop_back() << endl;
            break;

        case 5: cout << "Size of your list is: " << a.Size() << endl;
            break;

        case 6: Erase();
            break;

        case 7: cout << "Your list is: \n"; a.Print();
            break;

        case 8: a.eraseAll();
            break;

        default: cout << "Wrong key\n"; break;
    }

}

int main()
{
    while(1)
    {
        drawMenu();

        int key;
        cin >> key;

        switch_move(key);

        system("pause");
        system("cls");
    }
    return 0;
}
