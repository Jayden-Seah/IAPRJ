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
	srand(static_cast<int>(time(0)));
	int randomevent = rand() % 3;

	karma = 50.0f;
	if (randomevent == 0) {
		sethealth(150.0f);
	}
	else {
		sethealth(100.0f);
	}

	if (randomevent == 1) {
		setAttack(24);
	}
	else {
		setAttack(20);
	}
	
	if (randomevent == 2) {
		setDefence(7);
	}
	else {
		setDefence(5);
	}

	setAttackRange(1);

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