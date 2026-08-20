#pragma once
#include "CEntity.h"
class CPlayer :
	public CEntity
{
	int defense;
	float maxHP;
	float karma;

public:
	CPlayer(int randv);

	void attacking(CEntity* target);

	void setKarma(float k);

	void setmaxHP(float mhp);
	float getmaxHP();

	void setDefence(int d);
	int getDefence();

	float getKarma();
};
