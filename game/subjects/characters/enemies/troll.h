#ifndef __TROLL__
#define __TROLL__
#include "enemy.h"

class Troll : public Enemy
{
private:
    /* data */
public:
    Troll(int x, int y) : Enemy{120, 25, 15, x, y, 'T'} {}
};

#endif
