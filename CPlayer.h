#pragma once
#include "CEntity.h"
#include "Upgrade.h"
class CPlayer :
	public CEntity
{
	int defense;
	float maxHP;
	float karma; // current, updating karma
	float previousKarma; // last logged previous karma
	int boardcoordX;
	int boardcoordY;

	static const int MAX_BOONS = 20;
	Upgrade boons[MAX_BOONS];
	/*
	BOON LIST:
	[In order of Max level, put boons with chances last. Chances can ALSO mean stacks]
	eg. Name MaxLvl lvlFound +-Karma Chances
	0 - Ode to Quietude 1 0 +Karma 
	1 - Prosopagnosia 1 1 -Karma
	2 - Persecutory Delusion 1 1 -Karma
	3 - Fallen 1 -1 +Karma
	4 - Deliverance of Other 2 1 +Karma
	5 - Unreleased Agony 2 -1 -karma
	6 - Claim of the Forsaken 2 -1 -karma
	7 - Anti Asphyxiation 3 0 -karma
	9 - radical inaction 3 0 -karma
	10 - bloodthirsty fervor 3 0 -karma
	11 - Disturbance of Lux 3 1 +karma
	12 - cerominial sac 3 -1 -karma
	13 - recreation 3 -1 +karma
	14 - Alius 4 1 +karma
	15 - beningly lies 4 0 +karma
	16 - malevorance 5 -1 -karma
	17 - Poise 5 -1 +karma
	18 - pseudobulbar affect 7 1 -karma
	19 - Frazzled Beginnings 4 0 +karma 10 MAX
	20 - aptitude 3 -1 +karma 3 MAX
	*/
public:
	CPlayer();

	CPlayer(int randv);

	void attacking(CEntity* target);

	void setKarma(float k);

	void setPreviousKarma(float k);

	float getKarmaDifference();

	void setmaxHP(float mhp);
	float getmaxHP();

	void setDefence(int d);
	int getDefence();

	float getKarma();

	void randomizePlayerStart(int randv);
	int getBcoordX();
	int getBcoordY();
	void setBcoordX(int f);
	void setBcoordY(int f);

	//boon stuff
	void PsetBoonlevel(int a, int boonNumber);

	void PsetBoonChances(int a, int boonNumber);

	void PsetBoonEffectStatus(bool a, int boonNumber);

	void PsetBoontext();

	int PgetBoonLevel(int boonNumber);

	int PgetBoonChances(int boonNumber);

	bool PgetBoonEffectStatus(int boonNumber);

	std::string PgetBoonText(int boonNumber);
};