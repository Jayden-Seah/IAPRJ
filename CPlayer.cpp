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
	defense = 5;
	sethealth(100.0f);
	setAttack(20);
	setAttackRange(1);
}

void CPlayer::setKarma(float k) {
	karma = k;
}

int CPlayer::getKarma() {
	return karma;
}
