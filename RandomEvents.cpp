#include "RandomEvents.h"

RandomEvents::RandomEvents()
    : rng(std::random_device{}())
{
}

float RandomEvents::rollFloat(float min, float max)
{
    std::uniform_real_distribution<float> dist(min, max); // Generates the stuff in a set range 
    return dist(rng);
}

int RandomEvents::rollInt(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

float RandomEvents::rollHealth()
{
    return rollFloat(75.0f, 115.0f);
}

int RandomEvents::rollAttack()
{
    return rollInt(15, 25);
}

int RandomEvents::rollDefence()
{
    return rollInt(3, 8);
}

void RandomEvents::applyStartingStats(CPlayer* player)
{

    player->sethealth(rollHealth());
    player->setAttack(rollAttack());
    player->setDefence(rollDefence());
}