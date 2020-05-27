#ifndef __PHOENIX__
#define __PHOENIX__
#include "enemy.h"

class Phoenix : public Enemy
{
private:
    /* data */
public:
    Phoenix(int x, int y) : Enemy{50, 35, 20, x, y, 'X'} {}
};

#endif
