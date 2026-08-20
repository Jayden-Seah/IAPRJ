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

	float getKarma();
};
