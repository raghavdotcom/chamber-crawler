#ifndef __POTION_FACTORY__
#define __POTION_FACTORY__
#include "../../game.h"
#include <cstdlib>

#include "../items/potions/boostAttack.h"
#include "../items/potions/boostDefence.h"
#include "../items/potions/poisonHealth.h"
#include "../items/potions/restoreHealth.h"
#include "../items/potions/woundAttack.h"
#include "../items/potions/woundDefence.h"

#include <memory>
using namespace std;

class PotionFactory
{
protected:
    /* 1/6 chance to spawn a particular potion */
public:
    static shared_ptr<Potion> generate(int x, int y) {
        int i = rand() % 6;
        switch (i) {
            case 0 : {
                return make_shared<BA>(x, y);
            } case 1 : {
                return make_shared<BD>(x, y);
            } case 2 : {
                return make_shared<RH>(x, y);
            } case 3 : {
                return make_shared<WA>(x, y);
            } case 4 : {
                return make_shared<WD>(x, y);
            } case 5 : {
                return make_shared<PH>(x, y);
            } default : return make_shared<RH>(x, y);
        }
    }


    static shared_ptr<Potion> generate(int x, int y, std::string type) {

        if (type == "BA") {return make_shared<BA>(x, y);}
        else if (type == "BD") {return make_shared<BD>(x, y);}
        else if (type == "RH") {return make_shared<RH>(x, y);}
        else if (type == "WA") {return make_shared<WA>(x, y);}
        else if (type == "WD") {return make_shared<WD>(x, y);}
        else if (type == "PH") {return make_shared<PH>(x, y);}
        else {return PotionFactory::generate(x, y);}
    }
};

#endif
