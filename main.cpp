#define _USE_MATH_DEFINES
#include <iostream>
#include <conio.h>
#include <chrono>
#include <cmath>
#include "CEntity.h"
#include "CCanTalk.h"
#include "CSolidHitbox.h"
#include "CHuman.h"
#include "CObject.h"
#include "CItems.h"
#include "CPlayer.h"
#include <random>//Random library
#include <thread>
#include <cctype>
#include "Effects.h"
#include <windows.h>//Windows library	
#include <atomic>

//Start program
// DO WE HAVE ANY FUNCTIONS HERE!!! OR ARE THEY ALL IN CLASSES

std::default_random_engine generator(std::random_device{}());//default random engine creates the random value, generator is just the name for it , std random device gives it a random starting point without it itll be the same evry time


std::uniform_int_distribution<int> random(2, 1001);// uniform gives every num a equal chance, int is whole num, and distribution effectively says, give me a num from x to y



//Group Data -> 
struct DialogueInt {
	std::string speaker;
	std::string text;
};


//Allows ANSI color and cursor codes to work
void enableVirtualTerminal() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hOut, &mode);
	SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}



void clearScreen() {
	std::cout << "\033[H\033[2J";
}
// func for aoe vfx, if you ahve time make it directional ig? its not that bad
void drawVFX(std::vector<std::vector<std::string>>& board, int coorx, int coory, int atk, int atkr, CEntity *target, std::string vfxindicator, CEntity *caller, int atkcd) {

	if (caller->canEntityAttack) {
		CEntity* VFX[8];
		for (int i = 0; i < 4; i++) {
			VFX[i] = new Effects(coorx, coory, cos((i * 90) * M_PI / 180), sin((i * 90) * M_PI / 180), atkr, atk); // 0, 90, 180, 270
		}
		for (int i = 0; i < 4; i++) {
			int yd = 0;
			int xd = 0;
			switch (i) {
			case 0:
				yd = -1;
				xd = 1;
				break;
			case 1:
				xd = -1;
				yd = -1;
				break;
			case 2:
				yd = 1;
				xd = 1;
				break;
			case 3:
				xd = -1;
				yd = 1;
				break;
			}
			VFX[i + 4] = new Effects(coorx, coory, xd, yd, atkr, atk);
		}

		for (int i = 0; i < 8; i++) {
			board[VFX[i]->getCoordX()][VFX[i]->getCoordY()] = vfxindicator; // make this customizable ltr
			if (VFX[i]->isEntityOverlapping(target)) {
				target->sethealth(target->getHealth() - atk);
			}
		}
		for (int i = 0; i < 8; i++) {
			delete VFX[i];
		}
	}
	caller->canEntityAttack = false;
	std::thread([caller, atkcd]() {
		std::this_thread::sleep_for(std::chrono::seconds(atkcd));
		caller->canEntityAttack = true;
		}).detach();
	return;
}

// Writes dialogue text into the bottom strip of the existing board grid
// Bottom strip region: i (row) = 1..103, o (col) = 12..15
void drawDialogueInBoard(std::vector<std::vector<std::string>>& board, const std::string& speaker, const std::string& text) {
	const int contentStartI = 1;
	const int contentEndI = 103;   // leaves i=104 as border
	const int contentStartO = 12;
	const int contentEndO = 15;    // o=16 is the bottom border


	// Clear the strip first (so old text doesn't linger between frames)
	for (int o = contentStartO; o <= contentEndO; o++) {
		for (int i = contentStartI; i < contentEndI; i++) {
			board[i][o] = " ";
		}
	}

	// Write speaker name on the first content row
	std::string speakerText = speaker + ":";
	for (int c = 0; c < (int)speakerText.size() && (contentStartI + 1 + c) < contentEndI; c++) {
		board[contentStartI + 1 + c][contentStartO] = std::string(1, speakerText[c]);
	}

	// Write the dialogue text, wrapping across the remaining rows
	int row = 1; // row 0 (contentStartO) is used by speaker name
	int col = 0;
	int maxCols = contentEndI - contentStartI - 2; // small left padding
	for (char c : text) {
		if (col >= maxCols) {
			row++;
			col = 0;
		}
		if (contentStartO + row > contentEndO) break; // ran out of vertical space
		board[contentStartI + 1 + col][contentStartO + row] = std::string(1, c);
		col++;
	}
}

void statsInBoard(std::vector<std::vector<std::string>>& board, int hp, int attack, int def, int karma) {//same logic as for the dialogue except that the stats will only change if the player karma increases/decreases(e.g)
	const int statsStart = 105;
	const int statsEnd = 119;
	const int statsTop = 1;
	const int statsBottom = 15;

	//Clear
	for (int o = statsTop; o <= statsBottom; o++) {
		for (int i = statsStart; i < statsEnd; i++) {
			board[i][o] = " ";
		}
	}


	std::string playerStats = "Stats: "; // Title
	std::string hptext = "HP: " + std::to_string(hp);
	std::string attacktext = "ATK: " + std::to_string(attack);
	std::string deftext = "DEF: " + std::to_string(def);
	std::string karmatext = "KARMA: " + std::to_string(karma);

	for (int c = 0; c < static_cast<int>(playerStats.size()) && (statsStart + 1 + c) < statsEnd; c++) {//places each character accordingly into the array of spaces.
		board[statsStart + 1 + c][statsTop] = std::string(1, playerStats[c]);
	}
	for (int c = 0; c < static_cast<int>(hptext.size()) && (statsStart + 1 + c) < statsEnd; c++) {//places each character accordingly into the array of spaces.
		board[statsStart + 1 + c][statsTop + 1] = std::string(1, hptext[c]);
	}
	for (int c = 0; c < static_cast<int>(attacktext.size()) && (statsStart + 1 + c) < statsEnd; c++) {//places each character accordingly into the array of spaces.
		board[statsStart + 1 + c][statsTop + 2] = std::string(1, attacktext[c]);
	}
	for (int c = 0; c < static_cast<int>(deftext.size()) && (statsStart + 1 + c) < statsEnd; c++) {//places each character accordingly into the array of spaces.
		board[statsStart + 1 + c][statsTop + 3] = std::string(1, deftext[c]);
	}
	for (int c = 0; c < static_cast<int>(karmatext.size()) && (statsStart + 1 + c) < statsEnd; c++) {//places each character accordingly into the array of spaces.
		board[statsStart + 1 + c][statsTop + 4] = std::string(1, karmatext[c]);
	}

}

int main() {
	enableVirtualTerminal();
	//Code starts here
	//srand(static_cast<int>(time(0)));
	bool boardState = true; // true = grid board. false = fighting/talking area
	bool isDialogueActive = false;
	bool playerHasEnded = true;
	bool playerHasDied = false;
	bool isInStartScreen = true;
	bool isPaused = false;
	bool isInOptions = true; // start screen v2 
	bool hasPlayerUnlockedTile[7][7];
	bool hasPlayerFinishedTile[7][7];
	bool isThisanInaccessibleTile[7][7];
	int getDialogueFromHumanNumber = 10;
	for (int i = 0; i < 7; i++) {
		for (int y = 0; y < 7; y++) {
			hasPlayerUnlockedTile[i][y] = false;
			hasPlayerFinishedTile[i][y] = false;
			isThisanInaccessibleTile[i][y] = false;
		}
	}
	// KEYBINDING HERE
	const int max_keybinds = 7;
	// 0: interact, 1: attack, 2: up, 3: down, 4: left, 5: right
	char keybindings[max_keybinds] = { // default keybinds
		'T',
		'R',
		'W',
		'S',
		'A',
		'D',
		'B'
	};
	char currentDirCast = ' ';

	// UPON board flip run thhis in a for loop 
	//RANDOMLY create entities, more entities per stage if karma is higher (karma 100 start)
	CEntity* Player = new CPlayer(random(generator) % 2);

	while (isInOptions) {
		do {
			// printing main menu
			std::cout << "                               _____    __   __   __    __    __   __    __   __    __   " << std::endl;
			std::cout << "                             /\\___/\\  /_/\\ /\\_\\ /\\_\\  /_/\\  /\\_\\ /\\_\\  /_/\\ /_/\\  /\\_\\    " << std::endl;
			std::cout << "                            / / _ \\ \\ ) ) \\ ( ( \\/_/  ) ) \\/ ( (( ( (  ) ) )) ) \\/ ( (" << std::endl;
			std::cout << "                            \\ \\(_)/ //_/   \\ \\_\\ /\\_\\/_/ \\  / \\_\\\\ \\ \\/ / //_/ \\  / \\_\\  " << std::endl;
			std::cout << "                            / / _ \\ \\\\ \\ \\   / // / /\\ \\ \\\\// / / \\ \\  / / \\ \\ \\\\// / /  " << std::endl;
			std::cout << "                           ( (_( )_) ))_) \\ (_(( (_(  )_) )( (_(  ( (__) )  )_) )( (_(" << std::endl;
			std::cout << "                            \\/_/ \\_\\/ \\_\\/ \\/_/ \\/_/  \\_\\/  \\/_/   \\/__\\/   \\_\\/  \\/_/  " << std::endl;
			std::cout << "                             _     _   __    __   __    _____    _____  __ __      _____" << std::endl;
			std::cout << "                            /_/\\ /\\_\\ /\\_\\  /_/\\ /\\_\\  /\\ __/\\ /\\_____\\/_/\\__/\\  /\\_____\\ " << std::endl;
			std::cout << "                            ) ) ) ( ( \\/_/  ) ) \\ ( (  ) )__\\/( (_____/) ) ) ) )( (_____/" << std::endl;
			std::cout << "                           /_/ / \\ \\_\\ /\\_\\/_/   \\ \\_\\/ / /    \\ \\__\\ /_/ /_/_/  \\ \\__\\ " << std::endl;
			std::cout << "                           \\ \\ \\_/ / // / /\\ \\ \\   / /\\ \\ \\_   / /__/_\\ \\ \\ \\ \\  / /__/_" << std::endl;
			std::cout << "                            \\ \\   / /( (_(  )_) \\ (_(  ) )__/\\( (_____\\)_) ) \\ \\( (_____\\ " << std::endl;
			std::cout << "                             \\_\\_/_/  \\/_/  \\_\\/ \\/_/  \\/___\\/ \\/_____/\\_\\/ \\_\\/ \\/_____/ " << std::endl;
			for (int i = 0; i < 4; i++) {
				std::cout << std::endl;
			}
			std::cout << "                                                'TTTTTTTTTTTTT'" << std::endl;
			std::cout << "                                           	/HHH        \\HHHHHn\\" << std::endl;
			std::cout << "                                           	|HHH             \\HHHHn\\" << std::endl;
			std::cout << "                                          	|HHH                >HHH>" << std::endl;
			std::cout << "                                           	|HHH             /HHHHn/" << std::endl;
			std::cout << "                                           	\\HHH       /HHHHHn/" << std::endl;
			std::cout << "                                           	  ---------------" << std::endl;


			std::cout << std::endl;

			std::cout << "                                                    -------------------" << std::endl;
			std::cout << "                                                    H - S E T T I N G S" << std::endl;
			std::cout << "                                                    -------------------" << std::endl;

			int yippeeKey = _getch();

			if (yippeeKey == 13) {
				isInStartScreen = false;
				boardState = true;
				playerHasEnded = false;
				isInOptions = false;
			}

			yippeeKey = (char)toupper(yippeeKey);
			if (yippeeKey == 72) {
				isInStartScreen = false;
				playerHasEnded = true;
			}
			clearScreen();
		} while (isInStartScreen);

		// options screen: NOT inStartScreen, playerHasEnded TRUE
		if (isInStartScreen == false and playerHasEnded == true) {
			bool pickingKey = false;
			char pointer[max_keybinds] =
			{
				'>',
				' ',
				' ',
				' ',
				' ',
				' ',
				' '
			};
			int selectedStringNumber = 0; //always selects first string on options enter
			std::string Options[max_keybinds] = {
				" Current Interact Key:        ",
				" Current Attack Key:          ",
				" Current Up Key:              ",
				" Current Down Key:            ",
				" Current Left Key:            ",
				" Current Right Key:           ",
				" Current Pause Key:           "
			};

			do {
				// to add more keybinds add extra char pointer
				std::cout << "Press Enter on selected Keybind then Press a key(only alphabet PLEASE) to change the keybinds." << std::endl;
				std::cout << "Press Up and Down key to change the Targeted key." << std::endl;

				for (int m = 0; m < max_keybinds; m++) {
					if (pickingKey == true and (m == selectedStringNumber)) {
						std::cout << "\033[33m" << pointer[m] << Options[m] << keybindings[m] << "\033[0m" << std::endl;
					}
					else {
						std::cout << pointer[m] << Options[m] << keybindings[m] << std::endl;
					}
				}
				int pickedKey = _getch();

				if (pickingKey == false) {
					if (pickedKey == 0 || pickedKey == 224) { // updown
						pickedKey = _getch(); // up and down arrows are part of an extended library of getch so a bit of funny things needed
						if (pickedKey == 72) {
							if (selectedStringNumber != 0) {
								selectedStringNumber -= 1;
							}
						}
						else if (pickedKey == 80) {
							if (selectedStringNumber != (max_keybinds - 1)) {
								selectedStringNumber += 1;
							}
						}
					}
					else if (pickedKey == 13) { // enter
						pickingKey = true;
					}
					else if (pickedKey == 27) { //exit
						isInStartScreen = true;
					}
				}
				else { // key is being PICKED NOW so change keybind
					keybindings[selectedStringNumber] = pickedKey;
					keybindings[selectedStringNumber] = (char)toupper(keybindings[selectedStringNumber]);
					pickingKey = false;
				}
				for (int i = 0; i < max_keybinds; i++) {
					pointer[i] = ' ';
				}
				pointer[selectedStringNumber] = '>';

				clearScreen();
			} while (isInStartScreen == false and playerHasEnded == true);
		}
	}
	while (playerHasEnded == false) { // create a new player manually when player dies
		bool didPlayerGetaBoon = false;
		const int MAX_RANDOMEVENTS = 7;
		bool isThisRandomEventActive[MAX_RANDOMEVENTS];
		for (int i = 0; i < MAX_RANDOMEVENTS; i++) {
			isThisRandomEventActive[i] = false;
		}
		isThisRandomEventActive[0/*random(generator) % MAX_RANDOMEVENTS*/] = true;
		/*random Event:
		0 - Fast 
		1 - Tanky
		2 - Aggressive
		3 - Chaotic
		4 - Vampiric
		5 - Crowded
		6 - Healing Winds
		7 - Critical
		8 -
		*/
		if (playerHasDied) {
			Player = new CPlayer(random(generator) % 2);
			playerHasDied = false;
		}
		if (boardState == false) {
			int numberOfBoardenemies;
			int numberOfBlocks; // enviromental hazards
			CEntity* Human[10];
			CSolidHitbox* EnvironmentalObjects[10];
			for (int i = 0; i < 10; i++) {
				Human[i] = nullptr;
				EnvironmentalObjects[i] = nullptr;
			}
			if (static_cast<CPlayer*>(Player)->getKarma() < 50) {
				numberOfBoardenemies = random(generator) % 1 + 3; //1 to 3
				numberOfBlocks = random(generator) % 5 + 4; // 4 to 8
			}
			else {
				numberOfBoardenemies = random(generator) % 3 + 4; // 3 to 7
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

			int boon9changer = 0;
			switch (Player->PgetBoonLevel(9)) {//boon9 bloodthirsty, will trigger on one random enemy regardless and only at the start so effect chance bool doesnt need to be change
			case 1:
				boon9changer = 0.20;
				break;
			case 2:
				boon9changer = 0.25;
				break;
			case 3:
				boon9changer = 0.35;
				break;
			}
			// pick a random human and subtract hp from boon9changer
			int unluckyHuman = random(generator) % numberOfBoardenemies;
			Human[unluckyHuman]->sethealth(Human[unluckyHuman]->getHealth() * (1 - boon9changer));

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
				if (_kbhit()) {   // only getch if a keys pressed so doesnt doom gameflow
					currentDirCast = _getch();
					currentDirCast = (char)toupper(currentDirCast);
				}

				if (currentDirCast == keybindings[0]) {
					for (int f = 0; f < numberOfBoardenemies; f++) {
						if (Human[f] != nullptr) {
							if ((Human[f]->getHumanTypeID() > 0) and (Human[f]->getHumanTypeID() < 5)) { // 1-4
								if ((static_cast<CCanTalk*>(Human[f])->getTalkStatus() == false)) {
									for (int g = 0; g < 4; g++) {
										if (Player->isEntityGoingToOverlapInTheFuture(g + 1, Human[f])) {
											isDialogueActive = true;
											static_cast<CCanTalk*>(Human[f])->setTalkStatus(true);
										}
									}
								}
							}
						}
					}
				}
				if (currentDirCast == 'O') {
					Player->sethealth(0);
				}
				if (currentDirCast == 'P') { //instanly end current board
					CHuman::setkilledHumans(100);
					currentDirCast = ' ';
				}
				if (currentDirCast == keybindings[6]) {
					isDialogueActive = true;
					isPaused = true;
					currentDirCast = ' ';
				}

				// MOVE ENEMIES AND CHECK FOR PLAYER KEY AND MOVE (define getch beforehand)
				// So, what happens is a loop occurs when dialogue is NOT active that allows for all entities to move every 0.25s (including player
				// when we add that check later). Collision check also happens here but randomly, after a few seconds the program hangs and stops working.
				// we suspect maybe theres an overload of something but we are unsure whats wrong
				if (isDialogueActive == false) {

					if (currentDirCast == keybindings[1]) {
						currentDirCast = ' ';
						if (Player->canEntityAttack) {
							for (int i = 0; i < numberOfBoardenemies; i++) {
								if (Human[i] != nullptr) {
									drawVFX(board, Player->getCoordX(), Player->getCoordY(), Player->getAttack(), Player->getAttackRange(), Human[i], "\033[34m#\033[0m", Player, 1);
									if (Human[i]->getHealth() <= 0) {
										delete Human[i];
										Human[i] = nullptr;
									}
								}
							}
							std::this_thread::sleep_for(std::chrono::milliseconds(100));
						}
					}

					for (int i = 0; i < numberOfBoardenemies; i++) {
						if (Human[i] != nullptr) {
							int repeatTimes = 1;
							if (isThisRandomEventActive[0] == true) {
								repeatTimes = 2;
							}
							for (int j = 0; j < repeatTimes; j++) {
								if (Human[i]->detectPlayer(Player)) {
									if (Human[i]->canEntityAttack) {
										drawVFX(board, Human[i]->getCoordX(), Human[i]->getCoordY(), Human[i]->getAttack(), Human[i]->getAttackRange(), Player, "\033[31mO\033[0m", Human[i], 1);
									}
								}
							}
							Human[i]->humanWander();
						}
					}
					bool allowPlayerMovement = true;
					int currentDirInt = 0;
					if (currentDirCast == keybindings[2]) {
						currentDirInt = 1;
					}
					else if (currentDirCast == keybindings[3]) {
						currentDirInt = 3;
					}
					else if (currentDirCast == keybindings[5]) {
						currentDirInt = 4;
					}
					else if (currentDirCast == keybindings[4]) {
						currentDirInt = 2;
					}
					for (int o = 0; o < numberOfBoardenemies; o++) {
						if (Human[o] != nullptr) {
							if (Player->isEntityGoingToOverlapInTheFuture(currentDirInt, Human[o])) {
								allowPlayerMovement = false;
							}
						}
					}
					for (int o = 0; o < numberOfBoardenemies; o++) {
						if (Player->isEntityGoingToOverlapInTheFuture(currentDirInt, EnvironmentalObjects[o])) {
							allowPlayerMovement = false;
						}
					}
					if (allowPlayerMovement) {
						Player->moveInput(currentDirInt);
						Player->isEntityOutofBounds();
					}
					currentDirCast = ' ';
					std::this_thread::sleep_for(std::chrono::milliseconds(250));
					clearScreen();
				}

				// print ENEMIES
				for (int i = 0; i < numberOfBoardenemies; i++) {
					if (Human[i] != nullptr) {
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
							board[Human[i]->getCoordX()][Human[i]->getCoordY() - 1] = "\033[31mA\033[0m";
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
				}


				board[Player->getCoordX()][Player->getCoordY()] = "Y";

				for (int i = 0; i < numberOfBlocks; i++) {
					board[EnvironmentalObjects[i]->getCoordX()][EnvironmentalObjects[i]->getCoordY()] = "#";
				}

				//Stats board:

				statsInBoard(board, Player->getHealth(), Player->getAttack(), static_cast<CPlayer*>(Player)->getDefence(), static_cast<CPlayer*>(Player)->getKarma());

				if (isDialogueActive) {
					//TextBox
					if (isPaused == false) {
						int noOfDiag = 0;
						if (getDialogueFromHumanNumber == 10) {
							for (int d = 0; d < numberOfBoardenemies; d++) {
								bool foundMatch = false;
								for (int b = 0; b < 4; b++) {
									if (Human[d] != nullptr) {
										if (Player->isEntityGoingToOverlapInTheFuture(b + 1, Human[d])) {
											getDialogueFromHumanNumber = d;
											foundMatch = true;
											break;
										}
									}
								}
								if (foundMatch == true) {
									break;
								}
							}
						}


						std::vector<DialogueInt> script = {
							{Human[getDialogueFromHumanNumber]->getNames(),Human[getDialogueFromHumanNumber]->getDialogue(static_cast<CPlayer*>(Player)->getKarma(), 0)},
							{Human[getDialogueFromHumanNumber]->getNames(),Human[getDialogueFromHumanNumber]->getDialogue(static_cast<CPlayer*>(Player)->getKarma(), 1)},
							{Human[getDialogueFromHumanNumber]->getNames(),Human[getDialogueFromHumanNumber]->getDialogue(static_cast<CPlayer*>(Player)->getKarma(), 2)},
							{Human[getDialogueFromHumanNumber]->getNames(),Human[getDialogueFromHumanNumber]->getDialogue(static_cast<CPlayer*>(Player)->getKarma(), 3)}
						};



						for (const auto& line : script) {
							std::string revealedText = "";

							clearScreen();
							for (int o = 0; o < 17; o++) {
								for (int i = 0; i < 120; i++) {
									std::cout << board[i][o];
								}
								std::cout << std::endl;
								if (o == 11) {
									std::cout << "\0337"; // DEC save cursor position -- right after row 11 (o=11), before dialogue strip starts
								}
							}

							for (char c : line.text) {
								revealedText += c;
								drawDialogueInBoard(board, line.speaker, revealedText);

								std::cout << "\0338"; // DEC restore cursor position -- back to right after row 11
								for (int o = 12; o <= 15; o++) {
									for (int i = 0; i < 120; i++) {
										std::cout << board[i][o];
									}
									std::cout << "\033[K" << std::endl;
								}
								std::this_thread::sleep_for(std::chrono::milliseconds(30));
							}
							std::cin.get();
							noOfDiag++;
							if (noOfDiag == 4) {
								isDialogueActive = false;
							}
						}
					}
					else { //PAUSE = TRUE
						//std::vector<DialogueInt> script = {
						//	{"PAUSED", "PRESS ESC TO RETURN TO GAME"}
						//};
						int unpausekey = _getch();
						if (unpausekey == 27) {
							isDialogueActive = false;
							isPaused = false;
						}
					}
				}
				else {
					for (int o = 0; o < 17; o++) {
						for (int i = 0; i < 120; i++) {
							std::cout << board[i][o];
						}
						std::cout << std::endl;
					}
				}
				// change this to smth else where it resets the board ya
				if (CHuman::getKilledHumans() >= numberOfBoardenemies) {
					for (int i = 0; i < numberOfBoardenemies; i++) {
						if (Human[i] != nullptr) {
							delete Human[i];
							Human[i] = nullptr;
						}
					}
					CHuman::setkilledHumans(0);
					boardState = true;
					// lets go boon gambling!
					int randomizer = 0;
					if (CPlayer::getLevel() == 0) {
						randomizer = random(generator) % 3; // 1/3 chance
					}
					else {
						randomizer = random(generator) % 5; // 1/5 chance
					}
					if (randomizer == 0) {
						didPlayerGetaBoon = true;// later will check if player should get a boon
				}
					// FOR NOW since all enemies have to die you dont need to check to delete all enemies for prototype change ltr
					for (int i = 0; i < numberOfBlocks; i++) {
						delete EnvironmentalObjects[i];
						EnvironmentalObjects[i] = nullptr;
					}
				}
				if (Player->getHealth() <= 0) {
					while (Player->getCoordY() < 15) {
						Player->setCoordY(Player->getCoordY() + 1);

						board[Player->getCoordX()][Player->getCoordY()] = "Y";

						board[Player->getCoordX()][Player->getCoordY() - 1] = " ";
						for (int o = 0; o < 17; o++) {
							for (int i = 0; i < 120; i++) {
								std::cout << board[i][o];
							}
							std::cout << std::endl;
						}
						clearScreen();
						std::this_thread::sleep_for(std::chrono::milliseconds(50));
						// YOU DIED screen
						// reset everything here ty
					}
					bool inDeathScreen = true;
					while (inDeathScreen){
						std::cout << "__   _______ _   _  ______ _____ ___________ " << std::endl;
						std::cout << "\\ \\ / /  _  | | | | |  _  \\_   _|  ___|  _  \\" << std::endl;
						std::cout << " \\ V /| | | | | | | | | | | | | | |__ | | | |" << std::endl;
						std::cout << "  \\ / | | | | | | | | | | | | | |  __|| | | |" << std::endl;
						std::cout << "  | | \\ \\_/ / |_| | | |/ / _| |_| |___| |/ / " << std::endl;
						std::cout << "  \\_/  \\___/ \\___/  |___/  \\___/\\____/|___/" << std::endl;

						std::cout << std::endl;
						std::cout << std::endl;
						std::cout << std::endl;

						std::cout << "You have fell to the nihilistic temptations offered by " << CCanTalk::getARandomName(random(generator)) << std::endl;

						std::cout << std::endl;
						std::cout << " -- Press Any Key to replay --" << std::endl;

						int respawnKey = _getch();
						if (respawnKey >= 0) {
							inDeathScreen = false;
							clearScreen();
						}
					}
					delete Player;
					Player = nullptr;
					playerHasDied = true;
					boardState = true;
					for (int i = 0; i < 7; i++) {
						for (int y = 0; y < 7; y++) {
							hasPlayerUnlockedTile[i][y] = false;
							hasPlayerFinishedTile[i][y] = false;
						}
					}
				}                                    

			} while (boardState == false);
		}
		if ((boardState == true) and (playerHasDied == false)) { // traversel board, when you finish a stage on boards false, flip boolean to end up here
			clearScreen(); // clear current board
			int rows = 0;
			int cols = 0;
			switch (CEntity::getLevel()) {
			case 0:
				rows = 5;
				cols = 5;
				break;
			case 1:
				rows = 7;
				cols = 7;
				break;
			case -1:
				rows = 7;
				cols = 7;
				break;
			}
			int boonID = 20;
			// player receives boon here before moving/ascent/descent
			if (didPlayerGetaBoon) {
				bool typoboo = false;
				if (static_cast<CPlayer*>(Player)->getKarmaDifference() > 0) { // positive
					typoboo = true;
				}
				else {
					typoboo = false;
				}
				switch (CPlayer::getLevel()) { // if lvl is not 0, means boon is active.
				case 0:
					switch (random(generator) % 3) {
					case 0:
						if (typoboo) { // positive
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(0) + 1, 0);
							boonID = 0;
						}
						else {
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(7) + 1, 7);
							boonID = 7;
						}
						break;
					case 1:
						if (typoboo) { // positive
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(18) + 1, 18);
							boonID = 10;
						}
						else {
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(8) + 1, 8);
							boonID = 8;
						}
						break;
					case 2:
						if (typoboo) { // positive
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(14) + 1, 14);
							boonID = 14;
						}
						else {
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(9) + 1, 9);
							boonID = 9;
							break;
						}
					}
					break;
				case 1:
					switch (random(generator) % 3) {
					case 0:
						if (typoboo) { // positive
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(13) + 1, 13);
							boonID = 13;
						}
						else {
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(1) + 1, 1);
							boonID = 1;
						}
						break;
					case 1:
						if (typoboo) { // positive
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(4) + 1, 4);
							boonID = 4;
						}
						else {
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(2) + 1, 2);
							boonID = 2;
						}
						break;
					case 2:
						if (typoboo) { // positive
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(10) + 1, 10);
							boonID = 10;
						}
						else {
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(17) + 1, 17);
							boonID = 17;
						}
						break;
					}
					break;
				case -1:
					switch (random(generator) % 4) {
					case 0:
						if (typoboo) { // positive
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(3) + 1, 3);
							boonID = 3;
						}
						else {
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(11) + 1, 11);
							boonID = 11;
						}
						break;
					case 1:
						if (typoboo) { // positive
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(12) + 1, 12);
							boonID = 12;
						}
						else {
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(5) + 1, 5);
							boonID = 5;
						}
						break;
					case 2:
						if (typoboo) { // positive
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(19) + 1, 19);
							boonID = 19;
						}
						else {
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(6) + 1, 6);
							boonID = 6;
						}
						break;
					case 3:
						if (typoboo) { // positive
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(16) + 1, 16);
							boonID = 16;
						}
						else {
							static_cast<CPlayer*>(Player)->PsetBoonlevel(static_cast<CPlayer*>(Player)->PgetBoonLevel(15) + 1, 15);
							boonID = 15;
						}
						break;
					}
					break;
				}
			}
			do {
				// print board, level 0 5x5 grid, level 1 and -1 is a 7x7 grid

				for (int i = 0; i < 4; i++) {
					int bx = static_cast<CPlayer*>(Player)->getBcoordX();
					int by = static_cast<CPlayer*>(Player)->getBcoordY();
					switch (i) {
					case 0:
						bx -= 1;
						break;
					case 1:
						by -= 1;
						break;
					case 2:
						bx += 1;
						break;
					case 3:
						by += 1;
						break;
					}
					if ((bx < rows and bx > -1) and (by < cols and by > -1)) { // if within boundaries
						hasPlayerUnlockedTile[bx][by] = true;
					}
				}

				std::vector<std::vector<std::string>> board(rows, std::vector<std::string>(cols, { ' ' }));
				for (int o = 0; o < cols; o++) {
					for (int i = 0; i < rows; i++) {
						board[i][o] = " #";
						if (hasPlayerUnlockedTile[i][o]) {
							board[i][o] = " .";
						}
						if (hasPlayerFinishedTile[i][o]) {
							board[i][o] = " o";
						}
					}
				}

				board[static_cast<CPlayer*>(Player)->getBcoordX()][static_cast<CPlayer*>(Player)->getBcoordY()] = " Y";


				// print board
				for (int o = 0; o < cols; o++) {
					std::cout << "                                                             ";
					for (int i = 0; i < rows; i++) {
						std::cout << board[i][o];
					}
					std::cout << std::endl;
				}
				if (didPlayerGetaBoon) {
					didPlayerGetaBoon = false;
					std::cout << "--------------------------------" << std::endl;
					std::cout << "    -- YOU HAVE RECEIVED --" << std::endl;
					std::cout << "--------------------------------" << std::endl;
					std::cout << static_cast<CPlayer*>(Player)->PgetBoonText(boonID) << std::endl;
					boonID = 0;
				}

				char keydir = _getch();
				keydir = (char)toupper(keydir);

				if (keydir == keybindings[2]) {

					if (static_cast<CPlayer*>(Player)->getBcoordY() != 0) {
						static_cast<CPlayer*>(Player)->setBcoordY(static_cast<CPlayer*>(Player)->getBcoordY() - 1);
					}
				}
				else if (keydir == keybindings[3]) {
					if (static_cast<CPlayer*>(Player)->getBcoordY() != (cols - 1)) {
						static_cast<CPlayer*>(Player)->setBcoordY(static_cast<CPlayer*>(Player)->getBcoordY() + 1);
					}
				}
				else if (keydir == keybindings[4]) {
					if (static_cast<CPlayer*>(Player)->getBcoordX() != 0) {
						static_cast<CPlayer*>(Player)->setBcoordX(static_cast<CPlayer*>(Player)->getBcoordX() - 1);
					}
				}
				else if (keydir == keybindings[5]) {
					if (static_cast<CPlayer*>(Player)->getBcoordX() != (rows - 1)) {
						static_cast<CPlayer*>(Player)->setBcoordX(static_cast<CPlayer*>(Player)->getBcoordX() + 1);
					}
				}
				if ((hasPlayerUnlockedTile[static_cast<CPlayer*>(Player)->getBcoordX()][static_cast<CPlayer*>(Player)->getBcoordY()] == true) and (hasPlayerFinishedTile[static_cast<CPlayer*>(Player)->getBcoordX()][static_cast<CPlayer*>(Player)->getBcoordY()] == false)) {
					boardState = false;
					hasPlayerFinishedTile[static_cast<CPlayer*>(Player)->getBcoordX()][static_cast<CPlayer*>(Player)->getBcoordY()] = true; //assume player finishes bc if player dies resets anyways
				}
				clearScreen();
				// randomized events dont happen consistently so you cant see it so i can despawn the board
				// before player gets sent, play randomized event anims here or smth 

			} while (boardState == true);
		}
	}
}