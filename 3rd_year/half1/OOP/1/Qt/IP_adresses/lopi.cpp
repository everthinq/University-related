#include "lopi.h"

void lopi::setRandomPositiveIntegers(int count)
{
    for (int i = 0; i < count; i++)
        list.push_back(i);
}

int lopi::putNumber(int value)
{
    list.push_back(value);
}

int lopi::getNumber(int i)
{
    qDebug() << "getNumber: " << list.at(i);
}

void lopi::add(int value)
{
    list.push_back(value);
}

void lopi::add(int pos, int value)
{
    list.insert(pos, value);
}

void lopi::clear()
{
    list.clear();
}

void lopi::print()
{
    if (list.size() == 0)
        return;

    for (int i = 0; i < list.size(); i++)
    {
        qDebug() << "list [" << i <<"]: " << list.at(i);
    }   qDebug() << "\n";
}
