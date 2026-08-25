#include "Upgrade.h"
#include "CEntity.h"
#include "CPlayer.h"
#include "CObject.h"

int Upgrade::killcount = 0;
int Upgrade::pt = 5;


Upgrade::Upgrade()
{
    upg1 = false;
    upg2 = false;
    upg3 = false;
    upg4 = false;
    upg5 = false;
    boonLevel = 0;
    boonMaxLevel = 0;
    hasBoonEffectTriggered = false;
    boonEffectChancesLeft = 0;
}

void Upgrade::setBoons(int boonMaxLvl, int boonEffectChances)
{
    boonLevel = 0;
    boonMaxLevel = boonMaxLvl;
    hasBoonEffectTriggered = false;
    boonEffectChancesLeft = boonEffectChances;
}

void Upgrade::setBoonlevel(int a)
{
    if (a <= boonMaxLevel) {
        boonLevel = a;
    }
}

void Upgrade::setBoonChances(int a)
{
    boonEffectChancesLeft = a;
}

void Upgrade::setBoonEffectStatus(bool a)
{
    hasBoonEffectTriggered = a;
}

void Upgrade::setBoontext(std::string a)
{
    boonFlavorText = a;
}

int Upgrade::getBoonLevel()
{
    return boonLevel;
}

int Upgrade::getBoonChances()
{
    return boonEffectChancesLeft;
}

bool Upgrade::getBoonEffectStatus()
{
    return hasBoonEffectTriggered;
}

std::string Upgrade::getBoonText()
{
    return boonFlavorText;
}

void Upgrade::upgrade(CEntity* target) {
    if (upg1 == false && killcount == 5) {
        //each upg will increase atk by 5, unless we want it to be a random thing then sure ig
        target->setAttack(25);
    }
    else if (upg1 && !upg2 && killcount == 10) {
        target->setAttack(30);
    }
    else if (upg1 && upg2 && !upg3 && killcount == 20) {
        target->setAttack(35);
    }
    else if (upg1 && upg2 && upg3 && !upg4 && killcount == 30) {
        target->setAttack(40);
    }
    else if (upg1 && upg2 && upg3 && upg4 && !upg5 && killcount == 44) {
        target->setAttack(45);
    }
}



void Upgrade::unupgrade() {
    killcount = 0;
    upg1 = false;
    upg2 = false;
    upg3 = false;
    upg4 = false;
    upg5 = false;
}
