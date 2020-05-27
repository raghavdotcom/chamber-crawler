#ifndef __PC__
#define __PC__

#include "../../items/item.h"
#include "../character.h"
#include <cstdlib>
#include <memory>

class PC : public Character {
protected:
    unsigned int totalGold;
public:
    PC(int hp, int atk, int def, int x, int y) : Character{hp, atk, def, x, y, '@'} {}
    //PC(PC* p);
    //void useItem(Item*);
   // virtual void move() = 0;
    virtual int attack(std::shared_ptr<Character> c) {return c->attackBy(atk);}
    virtual int attackBy(int oppAtk) {
    int miss = rand() % 2;
    int ceiling = (100*oppAtk) % (100+def) == 0 ? 0 : 1;
    int damage = miss * ( ( (100/(100+def))*oppAtk ) + ceiling ); // ceiling of this exp
    HP -= damage;
    return damage;
    }
    void addGold(int n) {if (n > 0) totalGold += n;}
    int getGold() {return totalGold;}
    virtual ~PC() = default;
};

#endif

//Damage(Def ender) = ceiling((100/(100+Def (Def ender)))∗Atk(Attacker)), where Attacker specifies the attacking character (enemy or PC) and defender specifies the character being attacked. Thus, in a single round a character can be both an attacker and a defender.
// If the player character has the Barrier Suit, then their damage calculation is changed such that Damage(PC) = ceiling(Damage(Defender)).