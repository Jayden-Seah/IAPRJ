#include "CHuman.h"
#include "CCanTalk.h"
#include <iostream>

int CHuman::maxhumanID = 0; 

CHuman::CHuman()
{
    DetectionRange = 0;
    isEntityFollowingPlayer = false;
    isEntityRunningFromPlayer = false;
    isEntityShooter = false; 
    isEntityFreeToRoam = false;
    humanID = 0;
    currenthumanID = 0;
}

CHuman::CHuman(int randvalue, int randid)
{
    currenthumanID = maxhumanID;
    maxhumanID++;
    int x = randvalue % 103 + 1;
    int y = randvalue % 8 + 2;
    setObjectHeight(2);
    setCoordX(x);
    setCoordY(y);
    DetectionRange = 0;
    isEntityFollowingPlayer = true;
    isEntityRunningFromPlayer = false;
    isEntityShooter = false;
    isEntityFreeToRoam = true;
    humanID = randid;
    switch (humanID) {
    case 5:
        createType1RedHuman(randvalue);
        break;
    case 6:
        createType2RedHuman(randvalue);
        break;
    case 7:
        createTypeExplodingHuman(randvalue);
        break;
    }
}

bool CHuman::getFollowStatus()
{
    return isEntityFollowingPlayer;
}

bool CHuman::getRoamStatus()
{
    return isEntityFreeToRoam;
}

bool CHuman::getRunningAwayStatus()
{
    return isEntityRunningFromPlayer;
}

int CHuman::getDetectionRange()
{
    return DetectionRange;
}

int CHuman::getHumantagID()
{
    return currenthumanID;
}
int CHuman::getHumanTypeID()
{
    return humanID;
}
void CHuman::createType1RedHuman(int randd) // default chaser
{
    int lvl = getLevel();
    switch (lvl) {
    case 0:
        setAttack(randd % 4 + 2);
        sethealth((randd % 4 + 2) + 0.0f);
        setAttackRange(randd % 4 + 2);
        DetectionRange = 3;
        break;
    case 1:
        setAttack(randd % 4 + 2);
        sethealth(randd % 4 + 2 + 0.0f);
        setAttackRange(randd % 4 + 2);
        DetectionRange = 3;
        break;
    case -1:
        setAttack(randd % 4 + 2);
        sethealth(randd % 4 + 2 + 0.0f);
        setAttackRange(randd % 4 + 2);
        DetectionRange = 3;
        break;
    }
}

void CHuman::createType2RedHuman(int randd)
{
    int lvl = getLevel();
    switch (lvl) {
    case 0:
        setAttack(randd % 4 + 2);
        sethealth(randd % 4 + 2 + 0.0f);
        setAttackRange(randd % 4 + 2);
        DetectionRange = 3;
        isEntityFollowingPlayer = false;
        isEntityShooter = true;
        isEntityFreeToRoam = false;
        break;
    case 1:
        setAttack(randd % 4 + 2);
        sethealth(randd % 4 + 2 + 0.0f);
        setAttackRange(randd % 4 + 2);
        DetectionRange = 3;
        isEntityFreeToRoam = false;
        break;
    case -1:
        setAttack(randd % 4 + 2);
        sethealth(randd % 4 + 2 + 0.0f);
        setAttackRange(randd % 4 + 2);
        DetectionRange = 3;
        isEntityFollowingPlayer = false;
        isEntityShooter = true;
        isEntityFreeToRoam = false;
        break;
    }
}

void CHuman::createTypeExplodingHuman(int randd)
{
    setAttack(90);
    sethealth(1);
    setAttackRange(5);
    isEntityFreeToRoam = false;
}

void CHuman::setDetectionRange(int a)
{
    DetectionRange = a;
}

void CHuman::setFollowStatus(bool a)
{
    isEntityFollowingPlayer = a;
}

void CHuman::setRoamStatus(bool a)
{
    isEntityFreeToRoam = a;
}

void CHuman::setRunningAwayStatus(bool a)
{
    isEntityRunningFromPlayer = a;
}

void CHuman::setShooterStatus(bool a)
{
    isEntityShooter = a;
}

void CHuman::setHumanTypeID(int a)
{
    humanID = a;
}

void CHuman::resetHumanID()
{
    currenthumanID = 0;
}

void CHuman::increaseHumanID()
{
    currenthumanID++;
}


