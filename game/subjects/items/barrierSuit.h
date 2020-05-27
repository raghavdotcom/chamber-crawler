#ifndef __BARRIER_SUIT__
#define __BARRIER_SUIT__
#include "item.h"
#include "../characters/character.h"
#include "guardedItems/guardedItem.h"

class BarrierSuit : public Item, public GuardedItem {
private:
    /* data */
public:
    BarrierSuit(int x, int y) : Item{x, y, 'B'}, GuardedItem{x, y} {} //
    void use(Character * c) {
        int newAtk = 2*c->getAtk();
        c->setAtk(newAtk);
        c->setDAtk(newAtk);
    }
};

#endif
