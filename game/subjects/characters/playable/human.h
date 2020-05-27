#ifndef __HUMAN__
#define __HUMAN__
#include "PC.h"

class Human : public PC {
private:
    /* data */
public:
    Human(int x, int y) : PC{140, 20, 20, x, y} {}
};

#endif
