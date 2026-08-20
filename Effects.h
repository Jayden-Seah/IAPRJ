#pragma once
#include "CEntity.h"

class Effects :
	public CEntity
{
private:
	bool upg1;

	bool upg2;
public:
	Effects();

	Effects(int xpos, int ypos,int ydiff, int xdiff, int atkr, int atk); // Summon player/enemy attack vfx, use isentityoverlapping to check if entity is getting hit

	void attacking(CEntity* target);

	void passive();

	void upgrade();

	void unupgrade();
};

