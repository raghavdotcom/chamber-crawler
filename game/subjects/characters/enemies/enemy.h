#ifndef __ENEMY__
#define __ENEMY__
#include "../character.h"
#include "../../items/treasures/treasure.h"
#include "../../items/treasures/normalHoard.h"
#include "../../items/treasures/smallHoard.h"
#include <memory>

using namespace std;

class Enemy : public Character
{
private:
    /* data */
public:
    Enemy(int hp, int atk, int def, int x, int y, char c);
    virtual ~Enemy() = default;
    //void move() override;
    virtual int attack(shared_ptr<Character>);
    virtual int attackBy(int) override;
    virtual int giveGold() {
        if (getHP() <= 0) {
            if (rand()%2 + 1 == 1) return 1;
            else return 2;
        } else return 0;
    }
};

Enemy::Enemy(int hp, int atk, int def, int x, int y, char c) : Character{hp, atk, def, x, y, c} {}

int Enemy::attack(shared_ptr<Character> c) {
    return c->attackBy(atk);
}

int Enemy::attackBy(int oppAtk) {
    int ceiling = (100*oppAtk) % (100+def) == 0 ? 0 : 1;
    int damage = ( ( (100/(100+def))*oppAtk ) + ceiling ); // ceiling of this exp
    HP -= damage;
    return damage;
}
#endif

//Damage(Def ender) = ceiling((100/(100+Def (Def ender)))∗Atk(Attacker)), where Attacker specifies the attacking character (enemy or PC) and defender specifies the character being attacked. Thus, in a single round a character can be both an attacker and a defender.
// If the player character has the Barrier Suit, then their damage calculation is changed such that Damage(PC) = ceiling(Damage(Defender)).