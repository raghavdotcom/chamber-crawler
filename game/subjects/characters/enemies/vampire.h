#ifndef __VAMPIRE__
#define __VAMPIRE__
#include "enemy.h"

class Vampire : public Enemy
{
private:
    /* data */
public:
    Vampire(int x, int y) : Enemy{50, 25, 25, x, y, 'V'} {}

};
#endif
