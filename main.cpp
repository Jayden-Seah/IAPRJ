#include <iostream>
#include <conio.h>

//Start program

int main() {
	//Code starts here
	bool boardState = false; // true = grid board. false = fighting/talking area
	// 1, 104, 1, 13, 1 (stats area after the 2nd 1) || 
// 104 SPACES (WIDTH), 11 SPACES (HEIGHT)
	// PRINTING THE BOARD OF THE GAME
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

	for (int o = 0; o < 17; o++) {
		for (int i = 0; i < 120; i++) {
			std::cout << playBoardWidth[i][o];
		}
		std::cout << std::endl;
	}






}