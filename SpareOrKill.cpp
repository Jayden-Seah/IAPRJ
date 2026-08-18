#include "SpareOrKill.h"
#include "CPlayer.h"

int SpareOrKill::defaultKarmaGain = 5;          // not fixed, can be changed later
int SpareOrKill::defaultKarmaLoss = 10;         // not fixed, can be changed later

void SpareOrKill::applyKarmaChange(CPlayer* player, int karmaAmount)
{
    if (player == nullptr) return;

    int newKarma = player->getKarma() + karmaAmount;

    // Karma bounds between 0 (Evil) and 100 (Good)
    if (newKarma > 100) newKarma = 100;
    if (newKarma < 0) newKarma = 0;

    player->setKarma(newKarma);
    player->updateKarmaStats(); // Recalculates MaxHP = 70 + (Karma * 0.3)
}

void SpareOrKill::processInteraction(CPlayer* player, CCanTalk* npc, int choice)
{
    if (player == nullptr || npc == nullptr) return;

    // Option 1: Talk / Spare NPC
    if (choice == 1)
    {
        std::cout << "You chose to spare the entity." << std::endl;
        npc->dialogue(); // Play dialogue from CCanTalk
        applyKarmaChange(player, defaultKarmaGain);
        npc->setRoamStatus(true);
    }
    // Option 2: Attack / Kill NPC
    else if (choice == 2)
    {
        std::cout << "You attacked and eliminated the entity!" << std::endl;
        npc->sethealth(0.0f); // target dies
        applyKarmaChange(player, -defaultKarmaLoss);
    }
}
