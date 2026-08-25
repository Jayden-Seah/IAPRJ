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
	
	for (int i = 0;i < 4; i++) {
		// max lvl 1
		boons[i].setBoons(1);
	}
	for (int i = 4;i < 7; i++) {
		// max lvl 1
		boons[i].setBoons(2);
	}
	for (int i = 7;i < 14; i++) {
		// max lvl 1
		boons[i].setBoons(3);
	}
	for (int i = 14;i < 16; i++) {
		// max lvl 1
		boons[i].setBoons(4);
	}
	for (int i = 16;i < 18; i++) {
		// max lvl 1
		boons[i].setBoons(5);
	}
	boons[18].setBoons(7);
	boons[19].setBoons(4, 10);
	boons[20].setBoons(3, 3);
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