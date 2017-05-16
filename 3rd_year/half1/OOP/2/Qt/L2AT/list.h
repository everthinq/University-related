#ifndef _LIST_H
#define _LIST_H

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class _list
{

public:
    void read_from_ex(const char* filepath);
    void write_in_ex(const char* filepath);
    void insert();
    void print();

private:
    vector <string> myvector;
};

#endif // _LIST_H
