#include "SpareOrKill.h"
#include "CPlayer.h"

int SpareOrKill::defaultKarmaGain = 5;     // can be changed later
int SpareOrKill::defaultKarmaLoss = 10;     // can be changed later

void SpareOrKill::applyKarmaChange(CPlayer* player, int karmaAmount)
{
    if (player == nullptr) return;

    int newKarma = player->getKarma() + karmaAmount;

    // Checks Karma between 0 (Evil) and 100 (Good)
    if (newKarma > 100) newKarma = 100;
    if (newKarma < 0) newKarma = 0;

    player->setKarma(newKarma);
    //player->updateKarmaStats(); // Recalculates max health formula
}

void SpareOrKill::processInteraction(CPlayer* player, CCanTalk* npc, char board[10][104], int choice)
{
    if (player == nullptr || npc == nullptr) return;

    // Get exact grid coordinates from CSolidHitbox base class
    int targetX = npc->getCoordX();
    int targetY = npc->getCoordY();

    // Option 1: Talk / Spare NPC
    if (choice == 1)
    {
        std::cout << npc->getDialogue(static_cast<float>(player->getKarma())) << std::endl;
        
        applyKarmaChange(player, defaultKarmaGain);
        
        // NPC disappears off the board (runs away)
        npc->setRoamStatus(false);
        npc->sethealth(0.0f);
        
        // Remove Symbol From Board
        if (targetY >= 0 && targetY < 10 && targetX >= 0 && targetX < 104)
        {
            board[targetY][targetX] = ' ';
        }
    }
    // Option 2: Attack / Kill NPC
    else if (choice == 2)
    {
        std::cout << "You attacked and eliminated the human!" << std::endl;
        
        npc->sethealth(0.0f);
        applyKarmaChange(player, -defaultKarmaLoss);

        // Turn NPC tile into 'X' to show a body/corpse on the Board
        if (targetY >= 0 && targetY < 10 && targetX >= 0 && targetX < 104)
        {
            board[targetY][targetX] = 'X';
        }
    }
}
