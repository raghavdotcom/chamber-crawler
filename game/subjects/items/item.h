#ifndef __ITEM__
#define __ITEM__
#include "../subject.h"
#include "../characters/character.h"
#include <memory>

class Character;

class Item : public Subject
{
private:
    /* data */
public:
    Item(int x, int y, char c) : Subject{x, y, c} {}
    virtual void use(std::shared_ptr<Character>) = 0;
    virtual ~Item() {}
};

#endif
