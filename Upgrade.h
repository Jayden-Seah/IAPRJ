#pragma once
#include <random>
#include <memory>
#include "CEntity.h"
#include "CPlayer.h"
class Upgrade :public CPlayer
{
    CPlayer& Player;

    static int killcount;

    bool upg1 = false;

    bool upg2 = false;

    bool upg3 = false;

    bool upg4 = false;

    bool upg5 = false;

    int pt = 5;
public:

    Upgrade(CPlayer& Player) : Player(Player) {
        
    }

    void upgrade();

    void unupgrade();


};

