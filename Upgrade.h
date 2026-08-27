#pragma once
#include <random>
#include <iostream>
#include <memory> // WHAT IS MEMORY
#include "CEntity.h"
class Upgrade
{
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
    std::string boonFlavorText; // include name \n quote and \n effect
public:
    Upgrade();

    void setBoons(int boonMaxLvl, int boonEffectChances = 0);

    void setBoonlevel(int a);

    void setBoonChances(int a);

    void setBoonEffectStatus(bool a);

    void setBoontext(std::string a);

    int getBoonLevel();

    int getBoonChances();

    bool getBoonEffectStatus();

    std::string getBoonText();

    void upgrade(CEntity* target);

    void unupgrade();

    static void setkillcount(int ki);

    static int getkillcount();


};