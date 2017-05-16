#ifndef _LIST_H
#define _LIST_H

#include <QList>
#include <math.h>

#include <iostream>
#include <fstream>

using namespace std;

class _list
{
public:
    void insert(int count);
    void print();

    void write_in_basefile1(const char* filepath);
    void read_from_file(const char* filepath);

    void write_geometric_even_average_in_file2(const char* filepath);
    void write_arithmetic_odd_average_in_file3(const char* filepath);

private:
    QList <int> mylist;
    void check();
};

#endif // _LIST_H
