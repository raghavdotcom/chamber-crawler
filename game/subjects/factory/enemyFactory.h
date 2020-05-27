#ifndef __ENEMY_FACTORY__
#define __ENEMY_FACTORY__
#include "../../game.h"
#include <cstdlib>

#include "../characters/enemies/goblin.h"
#include "../characters/enemies/merchant.h"
#include "../characters/enemies/phoenix.h"
#include "../characters/enemies/troll.h"
#include "../characters/enemies/vampire.h"
#include "../characters/enemies/werewolf.h"

class Enemy;

using namespace std;
class EnemyFactory
{
protected:
    /* data */
public:
    static shared_ptr<Enemy> generate(int x, int y) {
        int i = rand() % 18;
        if ((i==0) || (i==1) || (i==2) || (i==3)) {
            return make_shared<Werewolf>(x, y);
        } else if ((i==4) || (i==5) || (i==6)) {
            return make_shared<Vampire>(x, y);
        } else if ((i==7) || (i==8) || (i==9) || (i==10) || (i==11)) {
            return make_shared<Goblin>(x, y);
        } else if  ((i==12) || (i==13)) {
            return make_shared<Troll>(x, y);
        } else if ((i==14) || (i==15)) {
            return make_shared<Phoenix>(x, y);
        } else {
            return make_shared<Merchant>(x, y);
        }
    }
    static shared_ptr<Enemy> generate(int x, int y, std::string which) {
        if (which == "werewolf") {
            return make_shared<Werewolf>(x, y);
        } else if (which == "vampire") {
            return make_shared<Vampire>(x, y);
        } else if (which == "goblin") {
            return make_shared<Goblin>(x, y);
        } else if  (which == "troll") {
            return make_shared<Troll>(x, y);
        } else if (which == "phoenix") {
            return make_shared<Phoenix>(x, y);
        } else {
            return make_shared<Merchant>(x, y);
        }
    }
};

#endif
