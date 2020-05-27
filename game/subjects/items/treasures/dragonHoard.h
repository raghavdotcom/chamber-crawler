#ifndef __DRAGON_HOARD__
#define __DRAGON_HOARD__
#include "treasure.h"
#include "../guardedItems/guardedItem.h"

class DragonHoard : public Treasure, public GuardedItem
{
private:
    /* data */
public:
    DragonHoard(int x, int y) : Treasure{x, y, 6}, GuardedItem{x, y} {}
    ~DragonHoard() {}
};

#endif
