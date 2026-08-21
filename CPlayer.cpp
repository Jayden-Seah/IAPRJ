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
	karma = 50.0f;
	sethealth(100.0f);
	setAttack(20);
	setAttackRange(1);
	setDefence(5);
	setBcoordX(0);
	setBcoordY(0);
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

void CPlayer::setmaxHP(float mhp) {
	mhp = 75 + (karma * 0.5);
}

int CPlayer::getDefence()
{
	return defense;
}

float CPlayer::getKarma() {
	return karma;
}

void CPlayer::randomizePlayerStart(int randv)
{
	setCoordY(6);
	switch (randv) {
	case 0:
		setCoordX(1);
		break;
	case 1:
		setCoordX(103);
		break;
	}
}

int CPlayer::getBcoordX()
{
	return boardcoordX;
}

int CPlayer::getBcoordY()
{
	return boardcoordY;
}

void CPlayer::setBcoordX(int f)
{
	boardcoordX = f;
}

void CPlayer::setBcoordY(int f)
{
	boardcoordY = f;
}



float CPlayer::getmaxHP() {
	return maxHP;
}