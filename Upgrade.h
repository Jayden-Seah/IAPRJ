#pragma once
#include <random>
#include <memory> // WHAT IS MEMORY
#include "CEntity.h"
#include "CPlayer.h"
class Upgrade
{
    CPlayer& Player;

    static int killcount;

    bool upg1 = false;

    bool upg2 = false;

    bool upg3 = false;

    bool upg4 = false;

    bool upg5 = false;

    static int pt;

    // boon related stuff
    int boonLevel;
    int boonMaxLevel;
    bool hasBoonEffectTriggered; //checks if boon effect has been procced
    int boonEffectChancesLeft; // for boon types requiring chances like Aptitude

public:
    Upgrade();

    void setBoons(int boonMaxLvl, int boonEffectChances = 0);

    void upgrade();

    void unupgrade();


};