#pragma once
#include "CEntity.h"
#include "CPlayer.h"
class Respawn:public CPlayer
{
private:

public:
	
	bool IsDead;

	void Respawning();

	void SecretRespawn();
};

