#ifndef __PLAYER_FACTORY__
#define __PLAYER_FACTORY__

#include "../characters/playable/PC.h"
#include "../characters/playable/dwarf.h"
#include "../characters/playable/elves.h"
#include "../characters/playable/human.h"
#include "../characters/playable/orc.h"
#include <string>
#include <memory>

using namespace std;
class PlayerFactory
{
private:
    /* data */
public:
    static shared_ptr<PC> generate(int x, int y, std::string type) {
        if (type == "d") return make_shared<Dwarf>(x, y);
        if (type == "o") return make_shared<Orc>(x, y);
        if (type == "h") return make_shared<Human>(x, y);
        if (type == "e") return make_shared<Elves>(x, y);
        else return make_shared<Human>(x, y);
    }
};

#endif
