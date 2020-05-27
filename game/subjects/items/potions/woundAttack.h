#ifndef __WOUND_ATTACK__
#define __WOUND_ATTACK__
#include "potion.h"

class WA : public Potion
{
private:
    /* data */
public:
    WA(int x, int y) : Potion{x,y,0,-5,0} {}
    ~WA(){}
};

#endif
