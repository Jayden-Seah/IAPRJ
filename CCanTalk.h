#pragma once
#include <iostream>
#include "CHuman.h"
class CCanTalk :
    public CHuman
{
    int DialogueCount;
    int maxDialogue;
    static std::string yh;
    std::string actualDialogue;
    bool* IsEnemyHostile;
public:
    CCanTalk(int randvalue, int ID, int lv);
    void changeDialogue();
    std::string getDialogue(float karma);
};

