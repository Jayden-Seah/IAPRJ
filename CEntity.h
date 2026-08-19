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


  bool isPlayerInAttackRange();

  int getAttack();
  float getHealth();
  int getAttackRange();
 static int getLevel();


  void setAttack(int atk);
  void sethealth(float hp);
  void setAttackRange(int atkr);
 static void setPsychosisLevel(int lvl);
 void moveInput(int dir); //1234 (WASD)
 virtual void humanWander(int randir);
 virtual int getHumanTypeID();
};

