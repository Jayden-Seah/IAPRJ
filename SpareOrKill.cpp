#include "SpareOrKill.h"
#include "CPlayer.h"
#include "CCanTalk.h"
#include <stdlib.h>

int SpareOrKill::defaultKarmaGain = 5;
int SpareOrKill::defaultKarmaLoss = 5;

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
        // Spare: NPC Stops
        npc->setRoamStatus(false);
        npc->sethealth(0.0f);
        applyKarmaChange(player, defaultKarmaGain);
    }
    else if (choice == '2')
    {
        // Kill: turn NPC hostile and starts a fight
        npc->setAttack(rand() % 4 + 2);              
        npc->sethealth((rand() % 4 + 2) + 0.0f);     
        npc->setAttackRange(1);                      
        npc->setDetectionRange(6);                    
        npc->setFollowStatus(true);                   
        npc->setRoamStatus(true);                     
        applyKarmaChange(player, -defaultKarmaLoss);
    }
}
