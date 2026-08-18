#include <iostream>
#include <conio.h>
#include <chrono>
#include "CEntity.h"
#include "CCanTalk.h"
#include "CSolidHitbox.h"
#include "CHuman.h"
#include "CObject.h"
#include "CItems.h"
#include "CPlayer.h"

//Start program
// DO WE HAVE ANY FUNCTIONS HERE!!! OR ARE THEY ALL IN CLASSES




int main() {
	//Code starts here
	srand(static_cast<int>(time(0)));
	CEntity* Player = new CPlayer;
	bool boardState = false; // true = grid board. false = fighting/talking area
	


	// UPON board flip run thhis in a for loop 
	//RANDOMLY create entities, more entities per stage if karma is higher (karma 100 start)
	int numberOfBoardenemies;
	CEntity* Human[10];
	for (int i = 0; i < 10; i++) {
		Human[i] = nullptr;
	}
	if (static_cast<CPlayer*>(Player)->getKarma() < 50) {
		numberOfBoardenemies = rand() % 5 + 3; //3 to 7
	}
	else {
		numberOfBoardenemies = rand() % 4 + 7; // 7 to 10
	}
	for (int i = 0; i < numberOfBoardenemies; i++) {
		int thisID = rand() % 7 + 1;
		if (thisID > 4) {
			Human[i] = new CHuman(rand(), thisID);
			// regenerate if overlapping coords

		}
		else {
			Human[i] = new CCanTalk(rand(), thisID, CEntity::getLevel());
		}
	}

	char playBoardWidth[120][17];
	// PLAYING area for fighting board is only 104 x 11
	for (int o = 0; o < 17; o++) {
		for (int i = 0;i < 120; i++) {
			if (o == 0 or o== 16) {
				playBoardWidth[i][o] = '-';
			}
			else if (o == 11){
				if (i == 0 or i == 104 or i == 119) {
					playBoardWidth[i][o] = '|';
				}
				else if (i > 104){
					playBoardWidth[i][o] = ' ';
				}
				else {
					playBoardWidth[i][o] = '-';
				}
			}
			else {
				if (i==0 or i==104 or i==119) {
					playBoardWidth[i][o] = '|';
				}
				else {
					playBoardWidth[i][o] = ' ';
				}
			}
		}
	}
	// move objects and stuff here


	for (int o = 0; o < 17; o++) {
		for (int i = 0; i < 120; i++) {
			std::cout << playBoardWidth[i][o];
		}
		std::cout << std::endl;
	}






}