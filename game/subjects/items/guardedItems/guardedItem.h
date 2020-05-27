#ifndef __GUARDED_ITEM__
#define __GUARDED_ITEM__
#include "../../characters/enemies/dragon.h"
#include <memory>

class GuardedItem
{
private:
    std::shared_ptr<Dragon> dragon;
public:
    GuardedItem(int x, int y) : dragon{std::make_shared<Dragon>(x, y)} {}
    ~GuardedItem() {}
};

#endif
