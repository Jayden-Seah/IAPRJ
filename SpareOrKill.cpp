#include "SpareOrKill.h"
#include "CPlayer.h"
#include "CCanTalk.h"

int SpareOrKill::defaultKarmaGain = 5;      // can be changed later
int SpareOrKill::defaultKarmaLoss = 10;     // can be changed later

void SpareOrKill::applyKarmaChange(CPlayer* player, int karmaAmount)
{
    if (player == nullptr) return;

    float newKarma = player->getKarma() + karmaAmount;

    if (newKarma > 100.0f) newKarma = 100.0f;
    if (newKarma < 0.0f) newKarma = 0.0f;

    player->setKarma(newKarma);
}

void SpareOrKill::processInteraction(CPlayer* player, CCanTalk* npc, char choice)
{
    if (player == nullptr || npc == nullptr) return;

    if (choice == '1')
    {
        // Spare: NPC stops and dies
        npc->setRoamStatus(false);
        npc->sethealth(0.0f);
        applyKarmaChange(player, defaultKarmaGain);
    }
    else if (choice == '2')
    {
        // Kill
        npc->sethealth(0.0f);
        applyKarmaChange(player, -defaultKarmaLoss);
    }
}