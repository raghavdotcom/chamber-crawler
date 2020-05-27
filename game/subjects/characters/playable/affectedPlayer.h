#ifndef __AFFECTED_PLAYER__
#define __AFFECTED_PLAYER__
#include "PC.h"

class AffectedPlayer : public PC
{
protected:
    PC* player;
    int effect;
public:
    // AffectedPlayer(PC* player, int effect) {
    // this->player = player;
    // this->effect = effect;
    // }
    AffectedPlayer(PC* player, int effect, int HP, int atk, int def, int x, int y) : player{player}, effect{effect} , PC{HP, atk, def, x, y} {}
    virtual ~AffectedPlayer() = default;
};

#endif
