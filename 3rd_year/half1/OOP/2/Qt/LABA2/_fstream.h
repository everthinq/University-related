#ifndef _FSTREAM_H
#define _FSTREAM_H

#include <QList>
#include <math.h>

#include <QDebug>
#include <iostream>
#include <fstream>
using namespace std;

class _FSTREAM
{
private:
    QList <int> myList;
    void check();

public:
    void insert(int count);
    void write_in_f(const char* filepath);
    void read_from_file(const char* filepath);
    void write_in_other(const char* filepath);
};

#endif // _FSTREAM_H
