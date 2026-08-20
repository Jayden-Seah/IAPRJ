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
    virtual ~CEntity();
    bool isEntityInAttackRange(CEntity* target);

  int getAttack();
  float getHealth();
  int getAttackRange();
 static int getLevel();

 virtual bool getRoamStatus();
  void setAttack(int atk);
  void sethealth(float hp);
  void setAttackRange(int atkr);
 static void setPsychosisLevel(int lvl);
 void moveInput(int dir); //1234 (WASD)
 void attacking(CEntity* target);


 virtual void humanWander();
 virtual int getHumanTypeID();


};

