#include "first.h"

void First::f_example()
{
    vector <int> the_vector;

    vector <int> :: iterator the_iterator;

    int count;
    cout << "Enter count\n"; cin >> count;

        for (int i = 0; i <= count; i++)
            the_vector.push_back(i);

        int total = 0;

        the_iterator = the_vector.begin();

        while (the_iterator != the_vector.end())
          total += *the_iterator++;

        cout << "Sum = " << total << endl;
}
