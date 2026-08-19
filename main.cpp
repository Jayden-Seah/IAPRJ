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
#include <cctype>
//Start program
// DO WE HAVE ANY FUNCTIONS HERE!!! OR ARE THEY ALL IN CLASSES

std::default_random_engine generator(std::random_device{}());//default random engine creates the random value, generator is just the name for it , std random device gives it a random starting point without it itll be the same evry time


std::uniform_int_distribution<int> random(2, 1001);// uniform gives every num a equal chance, int is whole num, and distribution effectively says, give me a num from x to y

//Group Data -> 
struct DialogueInt {
	std::string speaker;
	std::string text;
};

//Clear the screen
void clearScreen() {
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}

// Writes dialogue text into the bottom strip of the existing board grid
// Bottom strip region: i (row) = 1..103, o (col) = 12..15
void drawDialogueInBoard(std::vector<std::vector<std::string>>& board,
	const std::string& speaker,
	const std::string& text) {
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

int main() {
	//Code starts here
	//srand(static_cast<int>(time(0)));
	CEntity* Player = new CPlayer(random(generator) % 2);
	bool boardState = true; // true = grid board. false = fighting/talking area
	bool isDialogueActive = false;

	// KEYBINDING HERE
	char upKey = 'W';
	char downKey = 'S';
	char leftKey = 'A';
	char rightKey = 'D';
	char interactKey = 'T';
	char currentDirCast = ' ';

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

		if (currentDirCast == 'T') {

		}

		// MOVE ENEMIES AND CHECK FOR PLAYER KEY AND MOVE (define getch beforehand)
		// So, what happens is a loop occurs when dialogue is NOT active that allows for all entities to move every 0.25s (including player
		// when we add that check later). Collision check also happens here but randomly, after a few seconds the program hangs and stops working.
		// we suspect maybe theres an overload of something but we are unsure whats wrong
		while (isDialogueActive == false) {
			for (int i = 0; i < numberOfBoardenemies; i++) {
				int randdir = random(generator) % 4 + 1;
				for (int o = 0; o < numberOfBoardenemies; o++) {
					if (Human[i]->isEntityGoingToOverlapInTheFuture(randdir, Human[o])) {
						randdir = random(generator) % 4 + 1;
					}
				}
				for (int o = 0; o < numberOfBlocks; o++) {
					if (Human[i]->isEntityGoingToOverlapInTheFuture(randdir, EnvironmentalObjects[o])) {
						randdir = random(generator) % 4 + 1;
					}
				}
				Human[i]->humanWander();
			}
			if (currentDirCast == upKey) {
				Player->moveInput(1);
			}
			else if (currentDirCast == downKey) {
				Player->moveInput(3);
			}
			else if (currentDirCast == rightKey) {
				Player->moveInput(4);
			}
			else if (currentDirCast == leftKey) {
				Player->moveInput(2);
			}
			currentDirCast = ' ';
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

		board[Player->getCoordX()][Player->getCoordY()] = "Y";

		for (int i = 0; i < numberOfBlocks; i++) {
			board[EnvironmentalObjects[i]->getCoordX()][EnvironmentalObjects[i]->getCoordY()] = "#";
		}


		for (int o = 0; o < 17; o++) {
			for (int i = 0; i < 120; i++) {
				std::cout << board[i][o];
			}
			std::cout << std::endl;
		}

	} while (boardState == false);

	//TextBox
	std::vector<std::vector<std::string>> textBoxBoard(rows, std::vector<std::string>(cols, { ' ' }));
	for (int o = 0; o < 17; o++) {
		for (int i = 0; i < 120; i++) {
			if (o == 0 or o == 16) {
				textBoxBoard[i][o] = "-";
			}
			else if (o == 11) {
				if (i == 0 or i == 104 or i == 119) {
					textBoxBoard[i][o] = "|";
				}
				else if (i > 104) {
					textBoxBoard[i][o] = " ";
				}
				else {
					textBoxBoard[i][o] = "-";
				}
			}
			else {
				if (i == 0 or i == 104 or i == 119) {
					textBoxBoard[i][o] = "|";
				}
				else {
					textBoxBoard[i][o] = " ";
				}
			}
		}
	}

	std::vector<DialogueInt> script = {
		{"March 7th", "Hey, are you listening to me?! Trailblazer!"},
		{"Dan Heng",  "Calm down, March. They just woke up."},
		{"March 7th", "Oh, right! Welcome back to the Express!"}
	};

	for (const auto& line : script) {
		std::string revealedText = "";
		for (char c : line.text) {
			revealedText += c;
			drawDialogueInBoard(textBoxBoard, line.speaker, revealedText);

			clearScreen();
			for (int o = 0; o < 17; o++) {
				for (int i = 0; i < 120; i++) {
					std::cout << textBoxBoard[i][o];
				}
				std::cout << std::endl;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(30));
		}
		std::cin.get();
	}

}