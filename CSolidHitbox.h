#pragma once
#include "CObject.h"
class CSolidHitbox :
    public CObject
{
public:
    CSolidHitbox();
    CSolidHitbox(int randv);

    bool isEntityOverlapping(CSolidHitbox (*target));
    bool isEntityOutofBounds();
    bool isEntityGoingToOverlapInTheFuture(int dir, CSolidHitbox(*target)); // 1234 wasd
};

