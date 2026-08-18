#include "CEntity.h"

CEntity::CEntity()
{
    onLevel = 0;
}

bool CEntity::isPlayerInAttackRange()
{
    return false;
}

int CEntity::getAttack()
{
    return attack;
}

int CEntity::getHealth()
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

