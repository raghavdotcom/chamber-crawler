#ifndef __STAIR__
#define __STAIR__
#include "item.h"

class Stair : public Item
{
private:
    //bool visible = false;
public:
    Stair(int x, int y) : Item{x, y, '.'} {} //
    void makeVisible() {info.symbol = '/';} //
    void use(std::shared_ptr<Character> c) override {
        //c->moveToNextFloor();
    }
};
#endif
