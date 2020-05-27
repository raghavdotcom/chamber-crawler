#ifndef __COMPASS__
#define __COMPASS__
#include "item.h"
#include "stair.h"

class Stair;

class Compass : public Item
{
private:
    Stair * stair;
public:
    Compass(int x, int y, Stair* s) : Item{x, y, 'C'}, stair{s} {}
    void use(std::shared_ptr<Character> c) {
        //s->makeVisible();
        }
};

#endif
