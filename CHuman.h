#pragma once
#include "CEntity.h"
class CHuman :
    public CEntity
{
    int DetectionRange;
    int humanID; // can overlap, if human ID = 7 CAN EXPLODE!!!!!!
    bool isEntityFollowingPlayer;
    bool isEntityFreeToRoam;
    bool isEntityRunningFromPlayer;
    bool isEntityShooter;

public:
    CHuman();
    CHuman(int randvalue);

    bool getFollowStatus();
   bool getRoamStatus();
   bool getRunningAwayStatus();


   void createType1GreenHuman(int randd);
   void createType2GreenHuman(int randd);
   void createType1OrangeHuman(int randd);
   void createType2OrangeHuman(int randd);
   void createType1RedHuman(int randd);
   void createType2RedHuman(int randd);
   void createTypeExplodingHuman(int randd);

   void setFollowStatus(bool a);
   void setRoamStatus(bool a);
   void setRunningAwayStatus(bool a);
   void setShooterStatus(bool a);
};

