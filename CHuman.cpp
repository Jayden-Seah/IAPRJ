#include "CHuman.h"
#include "CCanTalk.h"
#include <iostream>

int CHuman::maxhumanID = 0;
int CHuman::numberOfKilledHumans = 0;


CHuman::CHuman()
{
    DetectionRange = 0;
    isEntityFollowingPlayer = false;
    isEntityRunningFromPlayer = false;
    isEntityShooter = false;
    isEntityPatrolling = false;
    humanID = 0;
    currenthumanID = 0;

}

CHuman::~CHuman()
{
    numberOfKilledHumans++;
    std::cout << "AA" << std::endl;
    delete enemyPatrolType;
}

CHuman::CHuman(int randvalue, int randid)
{
    currenthumanID = maxhumanID;
    maxhumanID++;
    int x = randvalue % 103 + 1;
    int y = randvalue % 8 + 2; // 2 to 9
    setObjectHeight(2);
    setCoordX(x);
    setCoordY(y);
    DetectionRange = 0;
    isEntityFollowingPlayer = true;
    isEntityRunningFromPlayer = false;
    isEntityShooter = false;
    isEntityPatrolling = true;
    humanID = randid;
    enemyPatrolType = new int;
    *enemyPatrolType = 1;
    hasFoundPlayer = false;
    dirFlip = new bool;
    *dirFlip = false;
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
    return isEntityPatrolling;
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
int* CHuman::getEnemyPatrolType()
{
    return enemyPatrolType;
}
void CHuman::createType1RedHuman(int randd) // default chaser
{
    int lvl = getLevel();
    switch (lvl) {
    case 0:
        setAttack(randd % 4 + 2);
        sethealth((randd % 4 + 2) + 0.0f);
        setAttackRange(1);
        DetectionRange = 3;
        *enemyPatrolType = (randd % 2 + 1);
        *dirFlip = false;
        break;
    case 1:
        setAttack(randd % 4 + 2);
        sethealth(randd % 4 + 2 + 0.0f);
        setAttackRange(1);
        DetectionRange = 3;
        break;
    case -1:
        setAttack(randd % 4 + 2);
        sethealth(randd % 4 + 2 + 0.0f);
        setAttackRange(1);
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
        setAttackRange(1);
        DetectionRange = 6;
        isEntityFollowingPlayer = false;
        isEntityShooter = true;
        isEntityPatrolling = false;
        break;
    case 1:
        setAttack(randd % 4 + 2);
        sethealth(randd % 4 + 2 + 0.0f);
        setAttackRange(1);
        DetectionRange = 6;
        isEntityPatrolling = false;
        break;
    case -1:
        setAttack(randd % 4 + 2);
        sethealth(randd % 4 + 2 + 0.0f);
        setAttackRange(1);
        DetectionRange = 6;
        isEntityFollowingPlayer = false;
        isEntityShooter = true;
        isEntityPatrolling = false;
        break;
    }
}

void CHuman::createTypeExplodingHuman(int randd)
{
    setAttack(9);
    sethealth(1);
    setAttackRange(3);
    DetectionRange = 15;
    isEntityPatrolling = false;
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
    isEntityPatrolling = a;
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

void CHuman::setkilledHumans(int a)
{
    numberOfKilledHumans = a;
}

int CHuman::getKilledHumans()
{
    return numberOfKilledHumans;
}

void CHuman::resetHumanID()
{
    currenthumanID = 0;
}

void CHuman::increaseHumanID()
{
    currenthumanID++;
}

void CHuman::humanWander() // add collision checks
{
    if ((isEntityPatrolling == true) and (hasFoundPlayer == false)) {
        int x = getCoordX();
        int y = getCoordY();
        switch (*getEnemyPatrolType()) {
        case 1: // move up and down
            if (*dirFlip == true) { // move up
                if (getCoordY() < 3) {
                    *dirFlip = false;
                }
                else {
                    setCoordY(getCoordY() - 1);
                }
            }
            else { // move down
                if (getCoordY() > 9) {
                    *dirFlip = true;
                }
                else {
                    setCoordY(getCoordY() + 1);
                }
            }
            break;
        case 2: // move left to right
            if (*dirFlip == true) { // move up
                if (getCoordX() < 25) {
                    *dirFlip = false;
                }
                else {
                    setCoordX(getCoordX() - 1);
                }
            }
            else { // move down
                if (getCoordX() > 50) {
                    *dirFlip = true;
                }
                else {
                    setCoordX(getCoordX() + 1);
                }
            }
            break;
        case 3: // move in an arc
            break;
        }
    }
}

bool CHuman::detectPlayer(CEntity* target)
{
    // detect player starts chase entity so i dont have to call both 
    if (getHumanTypeID() > 4) {
        int dx = abs(getCoordX() - target->getCoordX());
        int dy = abs(getCoordY() - target->getCoordY());
        int dr = DetectionRange;

        if ((dx + dy) <= dr) {
            DetectionRange += 10; //increase detection by 10 so its hard to outrun
            bool e = chaseEntity(target);
            return e;  // summon vfx if entity is in attack range
        }
    }

    return false;
}

bool CHuman::chaseEntity(CEntity* target)
{
    isEntityPatrolling = false;
    hasFoundPlayer = true;

    if (isEntityOutofBounds() == false) { //sets entity back in bounds
        int dx = (getCoordX() - target->getCoordX());
        int dy = (getCoordY() - target->getCoordY());
        int moveAmt = 0;
        if (abs(dx) >= abs(dy)) { // move x
            if (dx != 0) {
                moveAmt = dx / abs(dx); // 3 / -3 gives -1. 3/3 gives 1.
            }
            else {
                setCoordX(getCoordX() + 1);
            }
            setCoordX(getCoordX() - moveAmt);
        }
        else { // mpve y
            if (dx != 0) {
                moveAmt = dy / abs(dy);
            }
            else {
                setCoordY(getCoordY() + 1);
            }

            setCoordY(getCoordY() - moveAmt);
        }
    }


    if (isEntityInAttackRange(target)) {
        return true;
    }

    return false;
}

void CHuman::runFromEntity(CEntity* target)
{
    if (isEntityRunningFromPlayer) {
        if (isEntityOutofBounds() == false) { //sets entity back in bounds
            int dx = (getCoordX() - target->getCoordX());
            int dy = (getCoordY() - target->getCoordY());
            if (abs(dx) >= abs(dy)) { // move x
                if (dx > 0) { // if dx is positive, move negative
                    setCoordX(getCoordX() + 1);
                }
                else {
                    setCoordX(getCoordX() - 1);
                }
            }
            else { // mpve y
                if (dy > 0) {
                    setCoordY(getCoordY() + 1);
                }
                else {
                    setCoordY(getCoordY() - 1);
                }
            }
        }
    }
}

int CHuman::peekDirection()
{
    switch (*getEnemyPatrolType()) {
    case 1: // up/down patrol
        if (*dirFlip == true) {
            if (getCoordY() < 3) return 0; // about to flip, no real move this tick
            return 1; // up
        }
        else {
            if (getCoordY() > 9) return 0;
            return 3; // down
        }
    case 2: // left/right patrol
        if (*dirFlip == true) {
            if (getCoordX() < 25) return 0;
            return 2; // left
        }
        else {
            if (getCoordX() > 50) return 0;
            return 4; // right
        }
    default:
        return 0;
    }
}