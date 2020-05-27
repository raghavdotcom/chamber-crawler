#ifndef __ORC__
#define __ORC__
#include "PC.h"

class Orc : public PC
{
private:
    /* data */
public:
    Orc(int x, int y) : PC{180, 30, 25, x, y} {}

};

#endif
