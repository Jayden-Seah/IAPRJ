#pragma once
#include <random>
#include "CPlayer.h"

class RandomEvents
{
private:
    std::mt19937 rng; // Wanted to use srand but it wont let me use uniform_real_distribution<float> 

    float rollFloat(float min, float max);
    int rollInt(int min, int max);

public:
    RandomEvents();

    // Individual
    float rollHealth();
    int rollAttack();
    int rollDefence();

    void applyStartingStats(CPlayer* player); // runs the whole thing
};