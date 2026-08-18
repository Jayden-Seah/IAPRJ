#pragma once
#include "CEntity.h"
class CPlayer :
	public CEntity
{
	int defense;
	float maxHP;
	float karma;

public:
	void setKarma(float k);

	int getKarma();
};
