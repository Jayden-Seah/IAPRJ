#include "Effects.h"

#include "CEntity.h"
#include <iostream>


Effects::Effects()
{
	upg1 = false;
	upg2 = false;
}

Effects::Effects(int xpos, int ypos, int ydiff, int xdiff, int atkr, int atk) // math library cos angle -sin angle
{
	upg1 = false;
	upg2 = false;
	int xDifference = xdiff * atkr; // ensure xdiff and ydiff is always -1 or 1 ty
	int yDifference = ydiff * atkr;
	setAttackRange(atkr);
	setCoordX(xpos + xDifference);
	setCoordY(ypos + yDifference);

	setAttack(atk);
}

void Effects::attacking(CEntity* target)
{
	if (isEntityInAttackRange(target)) {
		int s = target->getHealth() - getAttack();
		target->sethealth(s);
	}
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


