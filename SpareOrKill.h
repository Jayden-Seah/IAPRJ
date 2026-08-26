#pragma once
#include <iostream>
#include <string>

class CPlayer;
class CCanTalk;

class SpareOrKill
{
private:
    static int defaultKarmaGain;
    static int defaultKarmaLoss;

public:
    // Process interaction between CPlayer and a talkable CCanTalk NPC on the board grid
    static void processInteraction(CPlayer* player, CCanTalk* npc, char choice);

    // Updates player Karma and recalculates stats
    static void applyKarmaChange(CPlayer* player, int karmaAmount);
};