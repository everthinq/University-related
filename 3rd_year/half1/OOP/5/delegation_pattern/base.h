#ifndef BASE_H
#define BASE_H

#include <QByteArray>
#include <QFile>
#include <QDebug>
#include <QString>

#include <iostream>
#include <fstream>
using namespace std;

class BASE
{
public:
    virtual void fread(const char *filepath) = 0;
    virtual ~BASE() {}
};

#endif // BASE_H
