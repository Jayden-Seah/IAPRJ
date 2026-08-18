#pragma once
#include "CSolidHitbox.h"
class CEntity :
    public CSolidHitbox
{
    int attack;
    float health;
    int attackRange;
    static int onLevel; // -1, 0 or 1. Default 0
public:
    CEntity();

  bool isPlayerInAttackRange();

  int getAttack();
  int getHealth();
  int getAttackRange();
  int getLevel();


  void setAttack(int atk);
  void sethealth(float hp);
  void setAttackRange(int atkr);
 void setPsychosisLevel(int lvl);

};

