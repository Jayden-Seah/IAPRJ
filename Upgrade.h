#pragma once
#include <random>
#include "CEntity.h"
#include "CPlayer.h"
class Upgrade :public CPlayer
{
    static int killcount;

    std::default_random_engine gene{std::random_device{}()};
    std::uniform_int_distribution<int> event_dist{5,10};
    bool upg1;

    bool upg2;
public:

    void upgrade();

    void unupgrade();


};

