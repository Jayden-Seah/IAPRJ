#include "CCanTalk.h"
#include <iostream>

std::string CCanTalk::yh = "yh";

CCanTalk::CCanTalk(int randvalue, int ID, int lv)
{
	hasAlreadyTalked = false;
	int x = randvalue % 103 + 1;
	int y = randvalue % 8 + 2; // 2 3 4 5 6 7 8 9
	setObjectHeight(2);
	setCoordX(x);
	setCoordY(y);
	setHumanTypeID(ID);
	switch (ID) {
	case 1:
		setAttack(0);
		setAttackRange(0);
		sethealth(1);
		setDetectionRange(0);
		setFollowStatus(false);
		setRoamStatus(false);
		switch (lv) {
		case 1:
			maxDialogue = 2;
			DialogueCount = 0;
			actualDialogue = "hi this is test dialogue from GreenNPC1.";
			break;
			break;
		case 0:
			maxDialogue = 2;
			DialogueCount = 0;
			actualDialogue = "hi this is test dialogue from GreenNPC1.";
			break;
		case -1:
			maxDialogue = 2;
			DialogueCount = 0;
			actualDialogue = "hi this is test dialogue from GreenNPC1.";
			break;
			break;
		}
		break;
	case 2:
		setAttack(0);
		setAttackRange(0);
		sethealth(1);
		switch (lv) {
		case 1:
			maxDialogue = 2;
			DialogueCount = 0;
			actualDialogue = "hi this is test dialogue from GreenNPC2.";
			break;
			break;
		case 0:
			maxDialogue = 2;
			DialogueCount = 0;
			actualDialogue = "hi this is test dialogue from GreenNPC2.";
			break;
			break;

		case -1:
			maxDialogue = 2;
			DialogueCount = 0;
			actualDialogue = "hi this is test dialogue from GreenNPC2.";
			break;
			break;
		}
		break;
	case 3:
		switch (lv) {
		case 1:

			break;
		case 0:

			break;
		case -1:

			break;
		}
		break;
	case 4:
		switch (lv) {
		case 1:

			break;
		case 0:

			break;
		case -1:

			break;
		}
		break;
	}
}

void CCanTalk::changeDialogue()
{
	switch (getHumanTypeID()) {
	case 1:
		
		switch (getLevel()) {
		case 1:

			break;
		case 0:
			
			break;
		case -1:

			break;
		}
		break;
	case 2:
	
		switch (getLevel()) {
		case 1:

			break;
		case 0:

			break;

		case -1:

			break;
		}
		break;
	case 3:
		switch (getLevel()) {
		case 1:

			break;
		case 0:

			break;
		case -1:

			break;
		}
		break;
	case 4:
		switch (getLevel()) {
		case 1:

			break;
		case 0:

			break;
		case -1:

			break;
		}
		break;
	}
}

std::string CCanTalk::getDialogue(float karma)
{
	std::string returnedDialogue;
	if (karma > 50) {
		returnedDialogue = actualDialogue;
	}
	else {
		returnedDialogue = yh + actualDialogue;
	}
	return returnedDialogue;
	DialogueCount++;
}

bool CCanTalk::getTalkStatus()
{
	return hasAlreadyTalked;
}

void CCanTalk::setTalkStatus(bool e)
{
	hasAlreadyTalked = e;
}
