#ifndef __BOOST_DEFENCE__
#define __BOOST_DEFENCE__
#include "potion.h"

class BD : public Potion
{
private:
    /* data */
public:
    BD(int x, int y) : Potion{x, y, 0,0,5} {}
    ~BD(){}
};


#endif
