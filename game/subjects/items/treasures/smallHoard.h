#ifndef __SMALL_HOARD__
#define __SMALL_HOARD__
#include "treasure.h"

class SmallHoard : public Treasure
{
private:
    /* data */
public:
    SmallHoard(int x, int y) : Treasure{x, y, 2} {}
    ~SmallHoard() {}
};

#endif
