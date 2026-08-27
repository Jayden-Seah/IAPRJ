#include "Effects.h"

#include "CEntity.h"
#include <iostream>


Effects::Effects()
{
	upg1 = false;
	upg2 = false;
}

Effects::Effects(int xpos, int ypos, double ydiff, double xdiff, int atkr, int atk) // math library cos angle -sin angle
{
	upg1 = false;
	upg2 = false;
	double xDifference = xdiff * atkr; // ensure xdiff and ydiff is always -1 or 1 ty
	double yDifference = ydiff * atkr;
	setAttackRange(atkr);
	setCoordX(xpos + static_cast<int>(xDifference));
	setCoordY(ypos + static_cast<int>(yDifference));
	isEntityOutofBounds();
	setObjectHeight(1);
	setAttack(atk);
}



void Effects::passive() {

}

void Effects::upgrade() {
	if (upg1 = true) {

	}
	else if (upg2 = true) {

	}
}


void Effects::unupgrade() {
	upg1 = false;
	upg2 = false;
}


