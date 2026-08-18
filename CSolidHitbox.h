#pragma once
#include "CObject.h"
class CSolidHitbox :
    public CObject
{
public:
    bool isEntityOverlapping(CSolidHitbox (*target));
    bool isEntityOutofBounds();
};

