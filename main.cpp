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
#include <random>//Random library
#include <thread>
//Start program
// DO WE HAVE ANY FUNCTIONS HERE!!! OR ARE THEY ALL IN CLASSES

std::default_random_engine generator(std::random_device{}());//default random engine creates the random value, generator is just the name for it , std random device gives it a random starting point without it itll be the same evry time


std::uniform_int_distribution<int> random(2, 1001);// uniform gives every num a equal chance, int is whole num, and distribution effectively says, give me a num from x to y

int main() {
	//Code starts here
	//srand(static_cast<int>(time(0)));
	CEntity* Player = new CPlayer(random(generator) % 2);
	bool boardState = false; // true = grid board. false = fighting/talking area
	bool isDialogueActive = false;


	// UPON board flip run thhis in a for loop 
	//RANDOMLY create entities, more entities per stage if karma is higher (karma 100 start)
	int numberOfBoardenemies;
	int numberOfBlocks; // enviromental hazards
	CEntity* Human[10];
	CSolidHitbox* EnvironmentalObjects[10];
	for (int i = 0; i < 10; i++) {
		Human[i] = nullptr;
		EnvironmentalObjects[i] = nullptr;
	}
	if (static_cast<CPlayer*>(Player)->getKarma() < 50) {
		numberOfBoardenemies = random(generator) % 5 + 3; //3 to 7
		numberOfBlocks = random(generator) % 5 + 4; // 4 to 8
	}
	else {
		numberOfBoardenemies = random(generator) % 4 + 7; // 7 to 10
		numberOfBlocks = random(generator) % 5 + 6; // 6 to 10
	}

	// object creation
	for (int i = 0; i < numberOfBlocks; i++) {
		EnvironmentalObjects[i] = new CSolidHitbox(random(generator));
		for (int o = 0;o < i; o++) {
			if ((i != o)) {
				if ((EnvironmentalObjects[i]->isEntityOverlapping(EnvironmentalObjects[o]))) {
					EnvironmentalObjects[i] = new CSolidHitbox(random(generator));
				}
			}
		}
	}


	for (int i = 0; i < numberOfBoardenemies; i++) {
		int thisID = random(generator) % 7 + 1;
		if (thisID > 4) {
			Human[i] = new CHuman(random(generator), thisID);
			// regenerate if overlapping coords, check for ALL objects 
			for (int o = 0;o < i; o++) {
				if ((i != o)) {
					if ((Human[i]->isEntityOverlapping(Human[o]))) {
						Human[i] = new CHuman(random(generator), thisID);
					}
				}
			}
			for (int t = 0; t < numberOfBlocks; t++) {
				if (Human[i]->isEntityOverlapping(EnvironmentalObjects[t])) {
					Human[i] = new CHuman(random(generator), thisID);
				}
			}
		}
		else {
			Human[i] = new CCanTalk(random(generator), thisID, CEntity::getLevel());
		}
	}
	


	int rows = 120;
	int cols = 17;

	do {
		std::vector<std::vector<std::string>> board(rows, std::vector<std::string>(cols, { ' ' }));
		// PLAYING area for fighting board is only 104 x 11
		for (int o = 0; o < 17; o++) {
			for (int i = 0;i < 120; i++) {
				if (o == 0 or o == 16) {
					board[i][o] = "-";
				}
				else if (o == 11) {
					if (i == 0 or i == 104 or i == 119) {
						board[i][o] = "|";
					}
					else if (i > 104) {
						board[i][o] = " ";
					}
					else {
						board[i][o] = "-";
					}
				}
				else {
					if (i == 0 or i == 104 or i == 119) {
						board[i][o] = "|";
					}
					else {
						board[i][o] = " ";
					}
				}
			}
		}
		// move objects and stuff here

		// MOVE ENEMIES AND CHECK FOR PLAYER KEY AND MOVE (define getch beforehand)
		while (isDialogueActive == false) {
			for (int i = 0; i < numberOfBoardenemies; i++) {
				int randdir = random(generator) % 4 + 1;
				Human[i]->humanWander(randdir);
				std::cout << Human[i]->getRoamStatus() << std::endl;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(250));
			system("cls");
			break;
		}
		// print ENEMIES
		for (int i = 0; i < numberOfBoardenemies; i++) {
			int kl = (Human[i])->getHumanTypeID();
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

		board[Player->getCoordX()][Player->getCoordY()] = "Y";

		for (int i = 0; i < numberOfBlocks; i++) {

			int randomObj = random(generator) % 4;
			switch (randomObj) {
			case 0:
				board[EnvironmentalObjects[i]->getCoordX()][EnvironmentalObjects[i]->getCoordY()] = "H";
			case 1:
				board[EnvironmentalObjects[i]->getCoordX()][EnvironmentalObjects[i]->getCoordY()] = "X";
			case 2:
				board[EnvironmentalObjects[i]->getCoordX()][EnvironmentalObjects[i]->getCoordY()] = "|";
			case 3:
				board[EnvironmentalObjects[i]->getCoordX()][EnvironmentalObjects[i]->getCoordY()] = "-";
			}
		}


		for (int o = 0; o < 17; o++) {
			for (int i = 0; i < 120; i++) {
				std::cout << board[i][o];
			}
			std::cout << std::endl;
		}

	} while (boardState == false);




}