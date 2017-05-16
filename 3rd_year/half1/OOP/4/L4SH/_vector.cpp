#include "_vector.h"

using namespace std;

_vector::_vector()
{
}

_vector::~_vector()
{
}

void _vector::print()
{
    cout << "\n\nWe have " << QStr_vec.size() << " elements in vector\n\n";

    for (unsigned int i = 0; i < QStr_vec.size(); i++)
    {
        cout << "[" << i << "] element: " << QStr_vec[i];
        cout << "\n";
    }
}

void _vector::_sort()
{
    sort (QStr_vec.begin(), QStr_vec.end());
}

void _vector::read_from_file(const char* filepath)
{
    ifstream read_file(filepath);
        string str;

        if(!read_file.is_open())
        {
            cerr << "File doesn't exist";
            exit(1);
        }

        while (!read_file.eof())
        {
            read_file >> str;
            QStr_vec.push_back(str);
        }

    read_file.close();
}

void _vector::write_vec_in_file(const char* filepath)
{
    ofstream write_file(filepath);

        for (unsigned int i = 0; i < QStr_vec.size(); i++)
            write_file << QStr_vec[i] << endl;
}
