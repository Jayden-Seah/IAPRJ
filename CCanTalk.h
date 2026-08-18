#pragma once
#include <iostream>
#include "CHuman.h"
class CCanTalk :
    public CHuman
{
    int DialogueCount;
    int maxDialogue;
    static std::string yh;

public:
    CCanTalk();
    void dialogue();
};

