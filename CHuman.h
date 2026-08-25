#pragma once
#include "CEntity.h"
class CHuman :
    public CEntity
{
    int DetectionRange;
    int humanID; // can overlap, if human ID = 7 CAN EXPLODE!!!!!!
    static int maxhumanID; // used for max human spawns and give each human a unique id. Resets on room finish/loss
    int currenthumanID;
    bool isEntityFollowingPlayer;
    bool isEntityPatrolling;
    bool hasFoundPlayer;
    int* enemyPatrolType; // MAKE sure a patrolling entity has an enemypatrol type of kill yourself adelle
    bool* dirFlip;
    bool isEntityRunningFromPlayer;
    bool isEntityShooter;
    static int numberOfKilledHumans;

     
public:
    CHuman();
    ~CHuman();
    CHuman(int randvalue, int randid);

    bool getFollowStatus();
   bool getRoamStatus();
   bool getRunningAwayStatus();
   int getDetectionRange();
int getHumantagID();
int getHumanTypeID();
int* getEnemyPatrolType();

   void createType1RedHuman(int randd);
   void createType2RedHuman(int randd);
   void createTypeExplodingHuman(int randd);

   void setDetectionRange(int a);
   void setFollowStatus(bool a);
   void setRoamStatus(bool a);
   void setRunningAwayStatus(bool a);
   void setShooterStatus(bool a);
   void setHumanTypeID(int a);
 

   static void setkilledHumans(int a);
   static int getKilledHumans();
   void resetHumanID();
  void increaseHumanID();
  void humanWander();
  bool detectPlayer(CEntity* target);
  bool chaseEntity(CEntity* target);
};

