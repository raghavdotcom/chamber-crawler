#ifndef __DWARF__
#define __DWARF__
#include "PC.h"

class Dwarf : public PC
{
private:
    /* data */
public:
    Dwarf(int x, int y) : PC{100, 20, 30, x, y} {}
};

#endif
