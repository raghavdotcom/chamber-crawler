#ifndef __POTION__
#define __POTION__
#include "../item.h"
#include "../../characters/playable/affectedAttack.h"
#include "../../characters/playable/affectedDefence.h"

class Potion : public Item
{
protected:
    int posX;
    int posY;
    int symbol; // is "p"
    int hFactor; // can be negative
    int aFactor; // can be negative
    int dFactor; // can be negative
    bool known;
public:
    Potion(int x, int y, int h, int a, int d) : Item{x, y, 'P'}, hFactor{h}, aFactor{a}, dFactor{d} {
        setKnown(false);
    }
    virtual ~Potion() = default;
    virtual void use(shared_ptr<Character> c) override;
    bool getKnown() {return known;}
    void setKnown(bool b) {known = b;}
};

void Potion::use(shared_ptr<Character> c) {
    if (hFactor != 0) {
        int newHP = c->getHP() + this->hFactor ;
        (newHP < c->getMHP()) ? c->setHP(newHP) : c->setHP(c->getMHP());
    }
    if (aFactor != 0) {
        int newAtk = c->getAtk()+ this->aFactor;
        c->setAtk(newAtk);
    }  //c = new AffectedAttack{c, aFactor};
    if (dFactor != 0) {
        int newDef = c->getDef()+ this->dFactor;
        c->setDef(newDef);
      }  //c = new AffectedDefence{c, dFactor};
}

#endif
