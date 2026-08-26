#include "CEntity.h"
#include <iostream>
int CEntity::onLevel = 0;

CEntity::CEntity()
{
}

CEntity::~CEntity()
{
}

bool CEntity::isEntityInAttackRange(CEntity* target)
{
    int dx = abs(getCoordX() - target->getCoordX());
    int dy = abs(getCoordY() - target->getCoordY());
    int atkr = getAttackRange();

    return (dx + dy) <= atkr;
}

std::string CEntity::getNames()
{
    return std::string();
}

std::string CEntity::getDialogue(float karma, int dialogueNumber)
{
    return std::string();
}

int CEntity::getAttack()
{
    return attack;
}

float CEntity::getHealth()
{
    return health;
}

int CEntity::getAttackRange()
{
    return attackRange;
}

int CEntity::getLevel()
{
    return onLevel;
}

bool CEntity::getRoamStatus()
{
    return false;
}

void CEntity::setAttack(int atk)
{
    attack = atk;
}

void CEntity::sethealth(float hp)
{
    health = hp;
}

void CEntity::setAttackRange(int atkr)
{
    attackRange = atkr;
}

 void CEntity::setPsychosisLevel(int lvl)
{
     onLevel = lvl;
}

 void CEntity::moveInput(int dir)
 {
     switch (dir) {
     case 1: // -1
         setCoordY(getCoordY() - 1);
         break;
     case 2: // -1
         setCoordX(getCoordX() - 1);
         break;
     case 3: // 1
         setCoordY(getCoordY() + 1);
         break;
     case 4: // 1
         setCoordX(getCoordX() + 1);
         break;
     }
 }
 void CEntity::attacking(CEntity* target)
 {
     if (isEntityOverlapping(target)) {
         static_cast<CEntity*>(target)->sethealth(static_cast<CEntity*>(target)->getHealth() - getAttack());
     }
 }


 bool CEntity::detectPlayer(CEntity* target)
 {
     return false;
 }

 void CEntity::humanWander()
 {
     
 }

 int CEntity::getHumanTypeID()
 {
     return 0;
 }

 int CEntity::PgetBoonLevel(int boonNumber)
 {
     return 0;
 }

 void CEntity::setRoamStatus(bool a)
 {
 }

 void CEntity::runFromEntity(CEntity* target)
 {
 }

 void CEntity::setRunningAwayStatus(bool a)
 {
 }

