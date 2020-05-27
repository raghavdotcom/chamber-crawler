#ifndef __AFFECTED_DEFENCE__
#define __AFFECTED_DEFENCE__
#include "affectedPlayer.h"

class AffectedDefence : public AffectedPlayer
{
private:
    /* data */
public:
    AffectedDefence(PC* player, int effect) : AffectedPlayer{player, effect, player->getHP(), player->getAtk(), player->getDef()+effect, player->getInfo().x, player->getInfo().y} {}
    ~AffectedDefence();
    int attackBy(int oppAtk) override {
    int miss = rand() % 2;
    int ceiling = (100*oppAtk) % (100+def) == 0 ? 0 : 1;
    int damage = miss * ( ( (100/(100+(def+effect)))*oppAtk ) + ceiling ); // ceiling of this exp
    HP -= damage;
    return damage;
    }
};

#endif
