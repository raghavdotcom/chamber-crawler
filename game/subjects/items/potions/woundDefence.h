#ifndef __WOUND_DEFENCE__
#define __WOUND_DEFENCE__
#include "potion.h"

class WD : public Potion
{
private:
    /* data */
public:
    WD(int x, int y) : Potion{x,y,0,0,-5} {}
    ~WD(){}
};

#endif
