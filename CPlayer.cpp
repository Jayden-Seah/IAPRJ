#include "CPlayer.h"

CPlayer::CPlayer(int randv)
{
	setObjectHeight(1);
	setCoordY(6);
	switch (randv) {
	case 0:
		setCoordX(1);
		break;
	case 1:
		setCoordX(103);
		break;
	}
	maxHP = 100.0f;
	karma = 50.0f;
	sethealth(100.0f);
	setAttack(20);
	setAttackRange(1);
	setDefence(5);
}

void CPlayer::attacking(CEntity* target)
{

}



void CPlayer::setKarma(float k) {
	karma = k;
}

void CPlayer::setDefence(int d)
{
	defense = d;
}

int CPlayer::getDefence()
{
	return defense;
}

float CPlayer::getKarma() {
	return karma;
}
