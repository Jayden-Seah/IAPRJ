#pragma once
#include "CEntity.h"
#include "CPlayer.h"
class Upgrade :public CPlayer
{
    static int killcount;

    bool upg1;

    bool upg2;
public:

    void upgrade();

    void unupgrade();
}

