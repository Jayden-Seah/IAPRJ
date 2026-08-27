#include "CPlayer.h"
int CPlayer::numberOfTilesCleared = 0;
void CPlayer::setTilesCleared(int g)
{
	numberOfTilesCleared = g;
}
int CPlayer::getTilesCleared()
{
	return numberOfTilesCleared;
}
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
	previousKarma = 50.0f;
	sethealth(100.0f);
	setAttack(20);
	setAttackRange(1);
	setDefence(5);
	setBcoordX(0);
	setBcoordY(0);
	PsetBoontext();
	for (int i = 0;i < 4; i++) {
		// max lvl 1
		boons[i].setBoons(1);
	}
	for (int i = 4;i < 7; i++) {
		// max lvl 1
		boons[i].setBoons(2);
	}
	for (int i = 7;i < 13; i++) {
		// max lvl 1
		boons[i].setBoons(3);
	}
	for (int i = 13;i < 15; i++) {
		// max lvl 1
		boons[i].setBoons(4);
	}
	for (int i = 15;i < 17; i++) {
		// max lvl 1
		boons[i].setBoons(5);
	}
	boons[17].setBoons(7);
	boons[18].setBoons(4, 10);
	boons[19].setBoons(3, 3);
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
	boons[7].setBoontext("\033[1mBlessing of Anti-Asphyxiation\033[0m\n\033[3m“Need not feel guilt for your actions, yes? Let your will sink further into this Nightmarish Reverie….”\033[0m\nTaking damage and then killing an enemy within the next 3 seconds slowly heals your hp back.");
	boons[8].setBoontext("\033[1mBoon of Radical Inaction\033[0m\n\033[3m“The world continues moving whether your existence fades away or not. That'must be what you were thinking, taking away innocent lives..”\033[0m\nEvery few seconds you are not attacked for, You move 1 step more. Up to a maximum of 3 steps at a time.");
	boons[9].setBoontext("\033[1mStroke of Bloodthirstry Fervor\033[0m\n\033[3m“To light the flames of Humanity’s end is but a sacred duty of ours that no other can perform.”\033[0m\nOne Hostile enemy’s HP will immediately be reduced by a certain percent of their max hp upon the start of the stage.");
	boons[18].setBoontext("\033[1mBlessing of The Frazzled Beginnings\033[0m\n\033[3m“You don’t even know where you are, or recall what truly horrid things you’ve done. Yet you remain steadfast in this nightmare. How admirable.”\033[0m\nEvery Human you talk to grants you a small amount of defensive stacks, up to 10. Removing 1 stack for each Human you kill.");
	boons[14].setBoontext("\033[1mBoon of Benignly Lies\033[0m\n\033[3m“You have them completely fooled, once again. Yet, your silent cries echo louder than the ripples of the yhorthern rain.”\033[0m\nAfter walking in the same direction a few times, move forward by a few tiles instead. This does not reset upon attacking or interacting.");
	boons[1].setBoontext("\033[1mProsopagnosia\033[0m\n\033[3m“Don’t You Remember Us?”\033[0m\nThe heads of all humans are visually removed.");
	boons[2].setBoontext("\033[1mPersecutery Delusion\033[0m\n\033[3m“They all hate me… I know they do..”\033[0m\nAll green humans now naturally run away from you.");
	boons[17].setBoontext("\033[1mPseudoBublbar Effect\033[0m\n\033[3m“You feel ready”\033[0m\nGain Inner Will for every attack you take.");
	boons[16].setBoontext("\033[1mPoise\033[0m\n\033[3m“You hear someone crying, before it twists into laughter. You can't help but do the same.”\033[0m\nAt the start of the board, all of your stats are either reduced or increased by an percentage.");
	boons[13].setBoontext("\033[1mThe Discovery of Alius\033[0m\n\033[3m“You feel something poking your throat, unfurling in a twisted beauty”\033[0m\nPlace a “FLOWER” object randomly across the board. Picking up this flower increases your perception of time. Additionally, increase HP and DEF by small amounts. If Disturbance of Lux Lv2+ is active, increases your current ATK once only.");
	boons[4].setBoontext("\033[1mThe Deliverance of Other\033[0m\n\033[3m“Come with me, into the light..”\033[0m\nEvery board now spawns with less people than normal. If Discovery of Alius Lv2+ is active, gain some DEF at the start of the round.");
	boons[10].setBoontext("\033[1mThe Disturbance of Lux\033[0m\n\033[3m“Your vision goes dark.. You try to move but your body refuses.”\033[0m\nEvery step you take has a chance for your body to shut down, losing a movement or attack. But in return, Bolstering your Attack upon your next move afterwards. If Deliverance of Others Lv2+ is active, you automatically spare the next orange Human you interact with.");
	boons[11].setBoontext("\033[1mBoon of Ceremonial Sacrifice\033[0m\n\033[3m“Your heart has been torn out”\033[0m\nEach ORANGE human you kill now grants additional attack, until you have cleared a particular number of rooms on this level. Reseting to 0 upon reaching a new level.");
	boons[5].setBoontext("\033[1mFavor of Unreleased Agony\033[0m\n\033[3m“Help… PLEASE.”\033[0m\nWhen your HP is extremely low, your bullet's gain greater range and hits a larger area.");
	boons[6].setBoontext("\033[1mClaim of The Forsaken\033[0m\n\033[3m“The light grew larger, flames slowly claiming all that it could reach”\033[0m\nExplosive Humans now explode with a larger radius.");
	boons[15].setBoontext("\033[1mBlossom of Malevorance\033[0m\n\033[3m“Do it.. You know you want to..”\033[0m\nConsumes your Inner Will every hit to deal more damage to the enemy.");
	boons[3].setBoontext("\033[1mFallen\033[0m\n\033[3m“Fallen down, down and downer”\033[0m\nAfter every completed tile, your Inner Will is changed. this change determining something that will happen next stage..");
	boons[12].setBoontext("\033[1mRecreation\033[0m\n\033[3m“You sit down, reminiscing.”\033[0m\nAt the start of the board, there will always be more Orange and Green Humans.");
	boons[19].setBoontext("\033[1mAptitude\033[0m\n\033[3m“Your quite good at this”\033[0m\nUpon being hit by an enemy, teleport away to a nearby location not that far away from where you once were. This can be repeated in the same board a few times. If Ode to Quietude, In Acceptance is active, regenerate some of your health additionally");
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