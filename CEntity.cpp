#include "CEntity.h"
#include <iostream>
int CEntity::onLevel = 0;

CEntity::CEntity()
{
}

bool CEntity::isPlayerInAttackRange()
{
    return false;
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

 void CEntity::humanWander(int randir)
 {

 }

 int CEntity::getHumanTypeID()
 {
     return 0;
 }

