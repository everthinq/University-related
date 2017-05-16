#ifndef _QUEUE_H
#define _QUEUE_H

#include <QDebug>
#include <QQueue>
#include <iostream>
using namespace std;

class _queue
{
private:
    QQueue <int> myQueue;
    QQueue <int> :: iterator it_begin = myQueue.begin();

public:
    void __print();
    int __push_back(int value);
    int __pop_back();

    int __insert(int pos, int value);

    int operator[](int pos);
};

#endif // _QUEUE_H
