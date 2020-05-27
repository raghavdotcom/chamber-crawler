#ifndef __TREASURE_FACTORY__
#define __TREASURE_FACTORY__
#include <cstdlib>
#include "../../game.h"

#include "../items/treasures/dragonHoard.h"
#include "../items/treasures/merchantHoard.h"
#include "../items/treasures/normalHoard.h"
#include "../items/treasures/smallHoard.h"
#include <memory>
using namespace std;
class Treasure;

class TreasureFactory
{
private:
    /* data */
public:
    static shared_ptr<Treasure> generate(int x, int y) {
        int i = rand() % 8;
        if ((i==0) || (i==1) || (i==2) || (i==3) || (i==4)) {
            return make_shared<NormalHoard>(x,y);
        } else if ((i==5) || (i==6)) {
            return make_shared<SmallHoard>(x, y);
        } else {
            return make_shared<DragonHoard>(x,y);
        }
    }
    static shared_ptr<Treasure> generate(int x, int y, std::string type) {
        if (type == "merchantH") {return make_shared<MerchantHoard>(x, y);}
        if (type == "smallH") {return make_shared<SmallHoard>(x, y);}
        if (type == "normalH") {return make_shared<NormalHoard>(x, y);}
        if (type == "dragonH") {return make_shared<DragonHoard>(x, y);}
        else {return TreasureFactory::generate(x, y);} 
    }
};


#endif
