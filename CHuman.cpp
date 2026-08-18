#include "CHuman.h"
#include "CCanTalk.h"
#include <iostream>



CHuman::CHuman()
{
    DetectionRange = 0;
    isEntityFollowingPlayer = false;
    isEntityRunningFromPlayer = false;
    isEntityShooter = false; 
    isEntityFreeToRoam = false;
    humanID = 0;

}

CHuman::CHuman(int randvalue)
{
    int x = randvalue % 104 + 1;
    int y = randvalue % 11 + 1;
    setObjectHeight(2);
    setCoordX(x);
    setCoordY(y);
    DetectionRange = 0;
    isEntityFollowingPlayer = false;
    isEntityRunningFromPlayer = false;
    isEntityShooter = false;
    isEntityFreeToRoam = false;
    humanID = randvalue % 7 + 1;
    switch (humanID) {
    case 1:
        createType1GreenHuman(randvalue);
        break;
    case 2:
        createType2GreenHuman(randvalue);
        break;
    case 3:
        createType1OrangeHuman(randvalue);
        break;
    case 4:
        createType2OrangeHuman(randvalue);
        break;
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

void CHuman::createType1GreenHuman(int randd)
{
    int lvl = getLevel();
    setAttack(0);
    setAttackRange(0);

    switch (lvl) {
    case 0:

    case 1:

    case -1:

    }
}

void CHuman::createType2GreenHuman(int randd)
{
    int lvl = getLevel();
    switch (lvl) {
    case 0:

    case 1:

    case -1:

    }
}

void CHuman::createType1OrangeHuman(int randd)
{
    int lvl = getLevel();
    switch (lvl) {
    case 0:

    case 1:

    case -1:

    }
}

void CHuman::createType2OrangeHuman(int randd)
{
    int lvl = getLevel();
    switch (lvl) {
    case 0:

    case 1:

    case -1:

    }
}

void CHuman::createType1RedHuman(int randd)
{
    int lvl = getLevel();
    switch (lvl) {
    case 0:

    case 1:

    case -1:

    }
}

void CHuman::createType2RedHuman(int randd)
{
    int lvl = getLevel();
    switch (lvl) {
    case 0:

    case 1:

    case -1:

    }
}

void CHuman::createTypeExplodingHuman(int randd)
{
    int lvl = getLevel();
    switch (lvl) {
    case 0:

    case 1:

    case -1:

    }
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


