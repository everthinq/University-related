#ifndef _VECTOR_H
#define _VECTOR_H

#include <iostream>
#include <fstream>

#include <vector>
#include <algorithm>

using namespace std;

class _vector
{
public:
    _vector();
   ~_vector();

    void read_from_file(const char* filepath);
    void write_vec_in_file(const char* filepath);

    void print();
    void _sort();

private:
    vector <string> QStr_vec;
};

#endif // _VECTOR_H
