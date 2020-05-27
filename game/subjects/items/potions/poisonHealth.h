#ifndef __POISON_HEALTH__
#define __POISON_HEALTH__
#include "potion.h"

class PH : public Potion
{
private:
    /* data */
public:
    PH(int x, int y) : Potion{x, y, -10, 0, 0} {}
    ~PH(){}
};

#endif
