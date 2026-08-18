#pragma once
#include "CEntity.h"
class CHuman :
    public CEntity
{
    int DetectionRange;
    bool isEntityFollowingPlayer;
    bool isEntityFreeToRoam;
    bool isEntityRunningFromPlayer;
    bool isEntityShooter;

public:
    CHuman();

    bool getFollowStatus();
   bool getRoamStatus();
   bool getRunningAwayStatus();

   void setFollowStatus(bool a);
   void setRoamStatus(bool a);
   void setRunningAwayStatus(bool a);
   void setShooterStatus(bool a);
};

