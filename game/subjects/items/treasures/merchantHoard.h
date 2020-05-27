#ifndef __MERCHANT_HOARD__
#define __MERCHANT_HOARD__
#include "treasure.h"

class MerchantHoard : public Treasure
{
private:
    /* data */
public:
    MerchantHoard(int x, int y) : Treasure{x, y, 4} {}
    ~MerchantHoard() {}
};

#endif
