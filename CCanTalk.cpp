#include "CCanTalk.h"
#include <iostream>

std::string CCanTalk::yh = "yh";
std::string CCanTalk::NameList[] = {
	"Alexander Harm-ilton",
	"The Man who Hanged, Wrionil",
	"John Yhick",
	"Beaver Barker",
	"Alloy Man",
	"John Human"
};

CCanTalk::CCanTalk(int randvalue, int ID, int lv)
{
	hasAlreadyTalked = false;
	int x = randvalue % 103 + 1;
	int y = randvalue % 8 + 2; // 2 3 4 5 6 7 8 9
	entityName = NameList[randvalue % MAX_NAMES];
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
			actualDialogue[0] = "";
			actualDialogue[1] = "";
			actualDialogue[2] = "";
			actualDialogue[3] = "";
			break;
		case 0:
			actualDialogue[0] = "Ah, you. I remember that habit of yours... always cutting things short when they get uncomfortable.";
			actualDialogue[1] = "You could have walked away or played with someone who doesn't know what you did.";
			actualDialogue[2] = "Look at what you are carrying... is that really what you want to define you?";
			actualDialogue[3] = "Get that disgusting edge out of my sight before you stain what's left of this room.";
			break;
		case -1:
			actualDialogue[0] = "";
			actualDialogue[1] = "";
			actualDialogue[2] = "";
			actualDialogue[3] = "";
			break;
		}
		break;
	case 2:
		setAttack(0);
		setAttackRange(0);
		sethealth(1);
		switch (lv) {
		case 1:
			actualDialogue[0] = "";
			actualDialogue[1] = "";
			actualDialogue[2] = "";
			actualDialogue[3] = "";
			break;
		case 0:
			actualDialogue[0] = "You keep staring at the floor, waiting for the static to stop.";
			actualDialogue[1] = "Removing us won't make the noise in your head any quieter.";
			actualDialogue[2] = "Go on.";
			actualDialogue[3] = "Make your choice so we can both stop pretending.";
			break;

		case -1:
			actualDialogue[0] = "";
			actualDialogue[1] = "";
			actualDialogue[2] = "";
			break;
		}
		break;
	case 3:
		switch (lv) {
		case 1:
			actualDialogue[0] = "";
			actualDialogue[1] = "";
			actualDialogue[2] = "";
			actualDialogue[3] = "";
			break;
		case 0:
			actualDialogue[0] = "You think moving forward means erasing everything behind you.";
			actualDialogue[1] = "Every time you hesitate, the pulse outside skips a beat.";
			actualDialogue[2] = "Put your weight into it... either drop the act or finish it.";
			break;
		case -1:
			actualDialogue[0] = "";
			actualDialogue[1] = "";
			actualDialogue[2] = "";
			break;
		}
		actualDialogue[3] = "1. SPARE                                                  2. KILL";
		break;
	case 4:
		switch (lv) {
		case 1:
			actualDialogue[0] = "";
			actualDialogue[1] = "";
			actualDialogue[2] = "";
			break;
		case 0:
			actualDialogue[0] = "We were fine sitting in the dark until your judgment came in here.";
			actualDialogue[1] = "You aren't defending yourself. You're just trying to shut it all down";
			actualDialogue[2] = "Look closely... Do you really want to do this?";
			break;
		case -1:
			actualDialogue[0] = "";
			actualDialogue[1] = "";
			actualDialogue[2] = "";
			break;
		}
		actualDialogue[3] = "1. SPARE                                                  2. KILL";
		break;
	}
}
std::string CCanTalk::getNames() {
	return entityName;
}

std::string CCanTalk::getDialogue(float karma, int dialogueNumber)
{
	std::string returnedDialogue;
	if ((karma > 50) or (dialogueNumber == 3 and (getHumanTypeID() == 4 or getHumanTypeID() == 3))) {
		returnedDialogue = actualDialogue[dialogueNumber];
	}
	else {
		returnedDialogue = yh + actualDialogue[dialogueNumber];
	}
	return returnedDialogue;
}

bool CCanTalk::getTalkStatus()
{
	return hasAlreadyTalked;
}

void CCanTalk::setTalkStatus(bool e)
{
	hasAlreadyTalked = e;
}
