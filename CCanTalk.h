#pragma once
#include <iostream>
#include "CHuman.h"
class CCanTalk :
    public CHuman
{

    static std::string yh;
    std::string actualDialogue[4];
    bool hasAlreadyTalked;
    static const int MAX_NAMES = 29; // change this number for max names
    static std::string NameList[MAX_NAMES];
    std::string entityName;

public:
    CCanTalk();
    CCanTalk(int randvalue, int ID, int lv);
    std::string getNames();
    std::string getDialogue(float karma, int dialogueNumber);
    bool getTalkStatus();
    void setTalkStatus(bool e);
    void becomeHostile(CEntity* target); // push back Player , then starts chasing Player
    void setDialogue(int dialogueNumber, std::string dialogue);
    static std::string getARandomName(int randv);
};

