#ifndef SWITCHER_H
#define SWITCHER_H

#include "base.h"
#include "text.h"
#include "hex.h"

class SWITCHER : public BASE
{
private:
        BASE *switcher;
public:
    SWITCHER() : switcher (new TEXT()) { }     // Конструктор
    virtual ~SWITCHER() { delete switcher; }   // Деструктор

    void fread (const char *filepath) { switcher->fread(filepath); }

    void toTEXT()
    {
        delete switcher;
        switcher = new TEXT();
    }

    void toHEX()
    {
        delete switcher;
        switcher = new HEX();
    }
};
#endif // SWITCHER_H
