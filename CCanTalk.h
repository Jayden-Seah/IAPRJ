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

public:
    CCanTalk(int randvalue, int ID, int lv);
    void dialogue();
};

