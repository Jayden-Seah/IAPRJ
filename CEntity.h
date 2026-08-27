#pragma once
#include "CSolidHitbox.h"
#include <iostream>
class CEntity :
    public CSolidHitbox
{
    int attack = 0;
    float health = 0.0f;
    int attackRange = 0;
    static int onLevel; // -1, 0 or 1. Default 0
public:

    std::atomic<bool> canEntityAttack{ true };

    CEntity();
    virtual ~CEntity();
    bool isEntityInAttackRange(CEntity* target);

    virtual std::string getNames();
   virtual std::string getDialogue(float karma, int dialogueNumber);
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


 // possibly reusable behaviour for non human entities in the future
 virtual bool detectPlayer(CEntity* target);
 virtual void humanWander();
 virtual int getHumanTypeID();
 virtual int PgetBoonLevel(int boonNumber);
 virtual void setRoamStatus(bool a);
virtual void runFromEntity(CEntity* target);
virtual void setRunningAwayStatus(bool a);
};

