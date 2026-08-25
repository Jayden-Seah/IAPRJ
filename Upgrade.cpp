#include "Upgrade.h"
#include "CEntity.h"
#include "CPlayer.h"
#include "CObject.h"

int Upgrade::killcount = 0;
int Upgrade::pt = 5;


void Upgrade::setBoons(int boonMaxLvl, int boonEffectChances = 0)
{
    boonLevel = 0;
    boonMaxLevel = boonMaxLvl;
    hasBoonEffectTriggered = false;
    boonEffectChancesLeft = boonEffectChances;
}

void Upgrade::upgrade() {
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
