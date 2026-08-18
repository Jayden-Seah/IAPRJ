#include "CHuman.h"

CHuman::CHuman()
{
    DetectionRange = 0;
    isEntityFollowingPlayer = false;
    isEntityRunningFromPlayer = false;
    isEntityShooter = false; 
    isEntityFreeToRoam = false;
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


