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

void CPlayer::setPreviousKarma(float k)
{
	previousKarma = k;
}

float CPlayer::getKarmaDifference()
{
	return karma - previousKarma;
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

void CPlayer::PsetBoonlevel(int a, int boonNumber)
{
	boons[boonNumber].setBoonlevel(a);
}

void CPlayer::PsetBoonChances(int a, int boonNumber)
{
	boons[boonNumber].setBoonChances(a);
}

void CPlayer::PsetBoonEffectStatus(bool a, int boonNumber)
{
	boons[boonNumber].setBoonEffectStatus(a);
}

void CPlayer::PsetBoontext()
{
		boons[0].setBoontext("\033[1mOde to Quietude, in Acceptance.\033[0m\n\033[3m“Peace, is that truly the color of your soul?”\033[0m\nThe first loss of HP you receive when entering the stage is nullified.");
		boons[1].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
		boons[2].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
		boons[3].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
		boons[4].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
		boons[5].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
		boons[6].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
		boons[7].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
		boons[8].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
		boons[9].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
		boons[10].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
		boons[11].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
		boons[12].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
		boons[13].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
		boons[14].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
		boons[15].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
		boons[16].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
		boons[17].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
		boons[18].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
		boons[19].setBoontext("\033[1mNAME\033[0m\n\033[3mQUOTE\033[0m\nTEXT");
}

int CPlayer::PgetBoonLevel(int boonNumber)
{
	return boons[boonNumber].getBoonLevel();
}

int CPlayer::PgetBoonChances(int boonNumber)
{
	return boons[boonNumber].getBoonChances();
}

bool CPlayer::PgetBoonEffectStatus(int boonNumber)
{
	return boons[boonNumber].getBoonEffectStatus();
}

std::string CPlayer::PgetBoonText(int boonNumber)
{
	return boons[boonNumber].getBoonText();
}





float CPlayer::getmaxHP() {
	return maxHP;
}