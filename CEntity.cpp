#include "CEntity.h"

int CEntity::onLevel = 0;

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

 void CEntity::moveInput(char dir)
 {
     switch (dir) {
     case 'W': // -1
         setCoordY(getCoordY() - 1);
         break;
     case 'A': // -1
         setCoordX(getCoordX() - 1);
         break;
     case 'S': // 1
         setCoordY(getCoordY() + 1);
         break;
     case 'D': // 1
         setCoordX(getCoordX() + 1);
         break;
     }
 }

