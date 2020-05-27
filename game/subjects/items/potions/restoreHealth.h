#ifndef __RESTORE_HEALTH__
#define __RESTORE_HEALTH__
#include "potion.h"

class RH : public Potion
{
private:
    /* data */
public:
    RH(int x, int y) : Potion{x,y,10,0,0} {}
    ~RH(){}
};

#endif
