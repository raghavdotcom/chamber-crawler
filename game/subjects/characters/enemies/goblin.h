#ifndef __GOBLIN__
#define __GOBLIN__
#include "enemy.h"

class Goblin : public Enemy
{
private:
    /* data */
public:
    Goblin(int x, int y) : Enemy{70, 5, 10, x, y, 'N'} {}
};

#endif
