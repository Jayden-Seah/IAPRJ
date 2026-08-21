#pragma once
#include "CEntity.h"
#include "CPlayer.h"
class Upgrade:public CPlayer
{
private:

public:
	
	bool IsDead;

	void Respawning();

	void SecretRespawn();
};

