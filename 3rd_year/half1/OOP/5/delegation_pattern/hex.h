#ifndef HEX_H
#define HEX_H

#include "base.h"

class HEX : public BASE
{
public:
    void fread(const char *filepath)
    {
        QFile file(filepath);

        if(file.open(QIODevice::ReadOnly) | QIODevice::Text)
        {
            QByteArray line;

            while(!file.atEnd())
            { 
               line = file.readLine();
               qDebug() << line.toHex() << " ";
            }

            file.close();
        }
    }
};

#endif // HEX_H
