#ifndef __TREASURE__
#define __TREASURE__
#include "../item.h"
#include "../../characters/character.h" // delete this
#include <memory>

#include "../../characters/playable/PC.h"

class Treasure : public Item
{
protected:
    int value;
public:
    Treasure(int x, int y, int value) : Item{x, y, 'G'}, value{value} {}
    void use(shared_ptr<Character> c) override {dynamic_pointer_cast<PC>(c)->addGold(value);}
    virtual ~Treasure() = default;
};

#endif
