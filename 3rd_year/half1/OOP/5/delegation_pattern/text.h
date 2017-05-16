#ifndef TEXT_H
#define TEXT_H

#include "base.h"

class TEXT : public BASE
{
public:
    void fread(const char *filepath)
    {
        char temp;                          //Это переменная для считывания символов.

            ifstream read_file (filepath);    //Открыли файл для чтения

            if(!read_file.is_open())
            {
                qDebug() << "File doesn't exist";
                exit(404);
            }

            while (!read_file.eof())
            {
                temp = read_file.get();
                cout << char (temp);
            }
            read_file.close();               //Закрыли файл
    }
};

#endif // TEXT_H
