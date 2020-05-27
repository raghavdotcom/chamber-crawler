#ifndef __DRAGON__
#define __DRAGON__
#include "enemy.h"

class Dragon : public Enemy
{
private:
    /* data */
public:
    Dragon(int x, int y) : Enemy{150, 20, 20, x, y, 'D'} {}

};

#endif
