#include "CCanTalk.h"
#include <iostream>

std::string CCanTalk::yh = "yh";

CCanTalk::CCanTalk(int randvalue, int ID, int lv)
{
	int x = randvalue % 103 + 1;
	int y = randvalue % 8 + 2;
	setObjectHeight(2);
	setCoordX(x);
	setCoordY(y);
	setHumanTypeID(ID);
	switch (ID) {
	case 1:

		switch (lv) {
		case 1:

			break;
		case 0:

			break;
		case -1:

			break;
		}
		break;
	case 2:
		switch (lv) {
		case 1:

			break;
		case 0:
			
			break;

		case -1:

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

void CCanTalk::dialogue()
{
}
