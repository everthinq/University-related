#include "_queue.h"

void _queue::__print()
{
    try
    {
        int error404;

        if (myQueue.isEmpty())
            throw error404;

        for (int i = 0; i < myQueue.size(); i++)
            cout << myQueue[i] << " ";
        cout << "\n";
    }

    catch(int)
    {
        qDebug() << "Your queue is empty."; // ПУСТАЯ ОЧЕРЕДЬ
    }
}

int _queue::__push_back(int value)
{
    myQueue.push_back(value);
}

int _queue::__pop_back()
{
    try
    {
       int error;
       if (myQueue.isEmpty())
           throw error;
       else
           myQueue.pop_back();
    }

    catch(int)
    {
        qDebug() << "There is nothing to pop. //Your queue is empty."; // ПУСТАЯ ОЧЕРЕДЬ
    }
}

int _queue::__insert(int pos, int value)
{
    myQueue.insert(pos, value);
}

int _queue::operator[](int pos)
{
    try
    {
        int error;
        if (pos < 0)
            throw error;

        pos++; // ДЕЛАЕМ POS++, ИБО ИНДЕКС МАССИВА НАЧИНАЕТСЯ С НУЛЯ (0), а myQueue.size() С ЕДЕНИЦЫ (1)

        if(pos > myQueue.size())
            throw error;

        pos--; // ДЕЛАЕМ POS--, ИБО ВЕРНУТЬ НА МЕСТО НАДОБНО
        qDebug() << myQueue[pos];
    }

    catch(int)
    {
        qDebug() << "\nYour pos is out of border.\n"; // ВЫХОД ЗА ГРАНИЦУ-БОРДЮР
    }

    qDebug() << "\nYour queue size is: ";
    return myQueue.size();
}





