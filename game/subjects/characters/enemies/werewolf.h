#ifndef __WEREWOLF__
#define __WEREWOLF__
#include "enemy.h"

class Werewolf : public Enemy
{
private:
    /* data */
public:
    Werewolf(int x, int y) : Enemy{120, 30, 5, x, y, 'W'} {}
};

#endif
