#pragma once
#include <iostream>
#include <string>
#include "CCanTalk.h"

class CPlayer;

class SpareOrKill
{
private:
    static int defaultKarmaGain;
    static int defaultKarmaLoss;

public:
    // Process interaction between Player and a Talkable Human NPC
    static void processInteraction(CPlayer* player, CCanTalk* npc, int choice);

    // Modify player karma and automatically recalculate stats
    static void applyKarmaChange(CPlayer* player, int karmaAmount);
};
