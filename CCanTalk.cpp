#include "CCanTalk.h"
#include <iostream>

std::string CCanTalk::yh = "yh";
std::string CCanTalk::NameList[] = {
"Alexander Harm - ilton"
"Wolfgang Von Beef - hoven",
"The Man who Hanged, Wrionil",
"John Yhick",
"Yhohn Wick",
"Beaver Barker",
"Alloy Man",
"Baller",
"Johnathan Johnathan",
"Guy",
"Major Major",
"Gemerl",
"Maybe, Might Not Be, Always Will, Never Be",
"Clark Kent",
"If and May, Never Is, The Potential Yhorb",
"Mr Trauma",
"Homeless Man",
"A Man That Has Fallen Into The River In Lego City",
"Fighting General Daimos",
"Hades, God Of The Underworld",
"50 Shades of Grey",
"Kratos",
"Spider Hyphen Man",
"Spooder - Man",
"Black Panther",
"A - Math",
"Rowan Black",
"Ni - Hee Hee - Ism",
"Johnny Ridden",
"Mr.Procrastination",


};


CCanTalk::CCanTalk()
{
}

CCanTalk::CCanTalk(int randvalue, int ID, int lv)
{
	hasAlreadyTalked = false;
	int x = randvalue % 102 + 1;
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
			actualDialogue[0] = "The static is clearing... and now you have to look at what you've built.";
			actualDialogue[1] = "You don't need to fight us anymore, unless fighting is the only way you know how to exist.";
			actualDialogue[2] = "Put down the weapon and step through... or clear the last tile and stay here forever.";
			actualDialogue[3] = "Someone is waiting on the other side... but will they even recognize what's waking up?";
			break;
		case 0:
			actualDialogue[0] = "Ah, you. I remember that habit of yours... always cutting things short when they get uncomfortable.";
			actualDialogue[1] = "You could have walked away or played with someone who doesn't know what you did.";
			actualDialogue[2] = "Look at what you are carrying... is that really what you want to define you?";
			actualDialogue[3] = "Get that disgusting edge out of my sight before you stain what's left of this room.";
			break;
		case -1:
			actualDialogue[0] = "You once had everything sitting right beside you...";
			actualDialogue[1] = "But you just have to break every bond you touch.";
			actualDialogue[2] = "Do you not realize...";
			actualDialogue[3] = "What. Are. You. Doing.";
			break;
		}
		break;
	case 2:
		setAttack(0);
		setAttackRange(0);
		sethealth(1);
		switch (lv) {
		case 1:
			actualDialogue[0] = "Look around you. The prison is dissolving, leaving you entirely exposed.";
			actualDialogue[1] = "You survived the swarm inside your head... but did anyone survive you ?";
			actualDialogue[2] = "Take a deep breath and open your eyes to the room you created.";
			actualDialogue[3] = "Is this what you wanted after everything ?";
			break;
		case 0:
			actualDialogue[0] = "You keep staring at the floor, waiting for the static to stop.";
			actualDialogue[1] = "Removing us won't make the noise in your head any quieter.";
			actualDialogue[2] = "Go on.";
			actualDialogue[3] = "Make your choice so we can both stop pretending.";
			break;

		case -1:
			actualDialogue[0] = "Keep fighting the projections if it makes you feel alive.";
			actualDialogue[1] = "Do not stop until there's no one left to look at you.";
			actualDialogue[2] = "Soon, you won't have to worry about answering to anyone.";
			actualDialogue[3] = "Peace is just in reach.";
			break;
		}
		break;
	case 3:
		setAttack(10);
		setAttackRange(1);
		sethealth(76);
		switch (lv) {
		case 1:
			actualDialogue[0] = "You didn't erase a single memory... or maybe you just erased the people who cared.";
			actualDialogue[1] = "It takes strength to have the options like you were given and decide that this is what you wanted";
			actualDialogue[2] = "It is all falling apart.See the consequences of the actions you chose.";
			break;
		case 0:
			actualDialogue[0] = "You think moving forward means erasing everything behind you.";
			actualDialogue[1] = "Every time you hesitate, the pulse outside skips a beat.";
			actualDialogue[2] = "Put your weight into it... either drop the act or finish it.";
			break;
		case -1:
			actualDialogue[0] = "Break through everything holding you in this hellhole.";
			actualDialogue[1] = "or destroy the only reasons to leave.";
			actualDialogue[2] = "Nothing here is real, nothing matters here.";
			break;
		}
		actualDialogue[3] = "1. SPARE                                                  2. KILL";
		break;
	case 4:
		setAttack(43);
		setAttackRange(1);
		sethealth(54);
		switch (lv) {
		case 1:
			actualDialogue[0] = "The End Is Right Ahead… The Final reflection of your choices.";
			actualDialogue[1] = "Don't stop now. You have come too far to pretend you didn't mean to do this.";
			actualDialogue[2] = "Step forward and see if there is anyone left.";
			break;
		case 0:
			actualDialogue[0] = "We were fine sitting in the dark until your judgment came in here.";
			actualDialogue[1] = "You aren't defending yourself. You're just trying to shut it all down";
			actualDialogue[2] = "Look closely... Do you really want to do this?";
			break;
		case -1:
			actualDialogue[0] = "You keep striking at shadows because you're terrified of what happens when the room stays quiet.";
			actualDialogue[1] = "Is this how you protect yourself ? Making sure no one can reach you ?";
			actualDialogue[2] = "Is This Really what you are ? A Monster ?";
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

void CCanTalk::becomeHostile(CEntity* target)
{
	int x = getCoordX();
	int y = getCoordY();
	int x2 = target->getCoordX();
	int y2 = target->getCoordY();
	for (int i = 1; i < 3;i++) {
		if (x2 == (x-1 + i)) {
			target->setCoordX((x - (4 * (1 + i))));
			target->isEntityOutofBounds();

		}
	}
	for (int i = 1; i < 3;i++) {
		if (y2 == (y - 1 + i)) {
			target->setCoordY((y - (4 * (1 + i))));
			target->isEntityOutofBounds();
		}
	}
	setDetectionRange(20);
}

void CCanTalk::setDialogue(int dialogueNumber, std::string dialogue)
{

}

std::string CCanTalk::getARandomName(int randv)
{
	
	return (NameList[randv % MAX_NAMES]);
}
