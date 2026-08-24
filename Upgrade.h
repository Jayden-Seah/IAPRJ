#pragma once
#include <random>
#include <memory>
#include "CEntity.h"
#include "CPlayer.h"
class Upgrade :public CPlayer
{
    CPlayer& Player;

    static int killcount;

    bool upg1;

    bool upg2;

    bool upg3;

    bool upg4;

    bool upg5;

    int pt = 5;
public:

    Upgrade(CPlayer& Player) : Player(Player) {
        this->Player = Player;
    }

    void upgrade();

    void unupgrade();


};

