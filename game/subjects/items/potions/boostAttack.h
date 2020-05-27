#ifndef __BOOST_ATTACK__
#define __BOOST_ATTACK__
#include "potion.h"

class BA : public Potion
{
private:
    /* data */
public:
    BA(int x, int y) : Potion{x, y, 0, 5, 0} {}
    ~BA(){}
};

#endif
