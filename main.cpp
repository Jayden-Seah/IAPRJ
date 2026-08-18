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

	// FIRST create all humans on board (FOR TEST CREATE BOARD ENTITIES INSTEAD LATER)
	for (int i = 0; i < numberOfBoardenemies; i++) {
		int thisID = rand() % 7 + 1;
		if (thisID > 4) {
			Human[i] = new CHuman(rand(), thisID);
			// regenerate if overlapping coords
			for (int o = 0;o < i; o++) {
				if ((i != o)) {
					if ((Human[i]->isEntityOverlapping(Human[o]))) {
						Human[i] = new CHuman(rand(), thisID);
					}
				}
			}
		}
		else {
			Human[i] = new CCanTalk(rand(), thisID, CEntity::getLevel());
		}
	}

	int rows = 120;
	int cols = 17;

	std::vector<std::vector<std::string>> board(rows, std::vector<std::string>(cols, { ' ' }));
	// PLAYING area for fighting board is only 104 x 11
	for (int o = 0; o < 17; o++) {
		for (int i = 0;i < 120; i++) {
			if (o == 0 or o== 16) {
				board[i][o] = "-";
			}
			else if (o == 11){
				if (i == 0 or i == 104 or i == 119) {
					board[i][o] = "|";
				}
				else if (i > 104){
					board[i][o] = " ";
				}
				else {
					board[i][o] = "-";
				}
			}
			else {
				if (i==0 or i==104 or i==119) {
					board[i][o] = "|";
				}
				else {
					board[i][o] = " ";
				}
			}
		}
	}
	// move objects and stuff here
	for (int i = 0; i < numberOfBoardenemies; i++) {
		int kl = static_cast<CHuman*>(Human[i])->getHumanTypeID();
		if (kl == 0) {
			kl = static_cast<CCanTalk*>(Human[i])->getHumanTypeID();
		}
		switch (kl) {
		case 1:
			board[Human[i]->getCoordX()][Human[i]->getCoordY()] = "\033[92mA\033[0m";
			board[Human[i]->getCoordX()][Human[i]->getCoordY() - 1] = "\033[92mO\033[0m";
			break;
		case 2:
			board[Human[i]->getCoordX()][Human[i]->getCoordY()] = "\033[92mA\033[0m";
			board[Human[i]->getCoordX()][Human[i]->getCoordY() - 1] = "\033[92mO\033[0m";
			break;
		case 3:
			board[Human[i]->getCoordX()][Human[i]->getCoordY()] = "\033[31mA\033[0m";
			board[Human[i]->getCoordX()][Human[i]->getCoordY() - 1] = "\033[31mO\033[0m";
			break;
		case 4:
			board[Human[i]->getCoordX()][Human[i]->getCoordY()] = "\033[31mA\033[0m";
			board[Human[i]->getCoordX()][Human[i]->getCoordY() - 1] = "\033[31mO\033[0m";
			break;
		case 5:
			board[Human[i]->getCoordX()][Human[i]->getCoordY()] = "\033[91mA\033[0m";
			board[Human[i]->getCoordX()][Human[i]->getCoordY() - 1] = "\033[91mO\033[0m";
			break;
		case 6:
			board[Human[i]->getCoordX()][Human[i]->getCoordY()] = "\033[91mA\033[0m";
			board[Human[i]->getCoordX()][Human[i]->getCoordY() - 1] = "\033[91mO\033[0m";
			break;
		case 7:
			board[Human[i]->getCoordX()][Human[i]->getCoordY()] = "\033[47m\033[30mA\033[0m";
			board[Human[i]->getCoordX()][Human[i]->getCoordY() - 1] = "\033[47m\033[30mO\033[0m";
			break;
		}
	}


	for (int o = 0; o < 17; o++) {
		for (int i = 0; i < 120; i++) {
			std::cout << board[i][o];
		}
		std::cout << std::endl;
	}






}