#pragma once
#include "CEntity.h"
#include "CPlayer.h"
class Respawn:public CPlayer
{
private:
	bool upg1;

	bool upg2;
public:
	
	void upgrade();

	void unupgrade();
};
};

