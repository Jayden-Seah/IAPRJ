#include "CEntity.h"
#include <iostream>
int CEntity::onLevel = 0;

CEntity::CEntity()
{
}

bool CEntity::isEntityInAttackRange(CEntity* target)
{
    int x = getCoordX();
    int y = getCoordY();
    int x2 = target->getCoordX();
    int y2 = target->getCoordY();
    int atkr = getAttackRange();
     
    for (int i = 0; i < atkr; i++) {
        if ((((x * (atkr-i)) == x2) and (y == y2)) or (((y * (atkr-1)) == y2) and (x == x2))) {
            return true;
        }
    }
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



 void CEntity::humanWander()
 {

 }

 int CEntity::getHumanTypeID()
 {
     return 0;
 }

