#ifndef __AFFECTED_ATTACK__
#define __AFFECTED_ATTACK__
#include "affectedPlayer.h"

class AffectedAttack : public AffectedPlayer
{
protected:

public:
    AffectedAttack(PC* player, int effect) : AffectedPlayer{player, effect, player->getHP(), player->getAtk(), player->getDef(), player->getInfo().x, player->getInfo().y} {}
    ~AffectedAttack();
    int attack(shared_ptr<Character> c) override {
        return c->attackBy(atk+effect);
    }
};

#endif
