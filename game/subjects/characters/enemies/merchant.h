#ifndef __MERCHANT__
#define __MERCHANT__
#include "enemy.h"

class Merchant : public Enemy
{
private:
    /* data */
    bool hostile;
public:
    Merchant(int x, int y) : Enemy{30, 70, 5, x, y, 'M'} {
        changeHostile(false);
    }
    bool getHostile() {return hostile;}
    void changeHostile(bool b) {
        hostile = b;
    }
    int attack(shared_ptr<Character> c) override {
        if (Merchant::hostile) {
            return c->attackBy(atk);
        } return 0;
    }
};

#endif
