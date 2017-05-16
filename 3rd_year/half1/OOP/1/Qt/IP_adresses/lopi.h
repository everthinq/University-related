#ifndef LOPI_H
#define LOPI_H

#include <QList>
#include <QDebug>

class lopi
{
    public:

    void add(int value);
    void clear();
    void setRandomPositiveIntegers(int count);
    void add(int pos, int value);

    int putNumber(int value);
    int getNumber(int i);
    void print();


    QList <int> list;
};

#endif // LOPI_H
