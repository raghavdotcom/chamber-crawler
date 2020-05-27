#ifndef __ELVES__
#define __ELVES__
#include "PC.h"

class Elves : public PC
{
private:
    /* data */
public:
    Elves(int x, int y) : PC{140, 30, 10, x, y} {}

};

#endif

