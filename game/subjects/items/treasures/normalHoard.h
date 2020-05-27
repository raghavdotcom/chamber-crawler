#ifndef __NORMAL_HOARD__
#define __NORMAL_HOARD__
#include "treasure.h"

class NormalHoard : public Treasure
{
private:
    /* data */
public:
    NormalHoard(int x, int y) : Treasure{x, y, 1} {}
    ~NormalHoard() {}
};

#endif
