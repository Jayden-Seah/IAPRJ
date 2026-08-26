#include "CSolidHitbox.h"
#include <iostream>


CSolidHitbox::CSolidHitbox()
{
}

CSolidHitbox::CSolidHitbox(int randv)
{
	setCoordX(randv % 103 + 1);
	setCoordY(randv % 8 + 2);
	setObjectHeight(1);
}
bool CSolidHitbox::isEntityOverlapping(CSolidHitbox* target) // overlapping = true, not overlapping (good) = false
{
	for (int i = 0; i < getObjectHeight(); i++) { // 1
		if ((getCoordX() == target->getCoordX()) and (getCoordY()-i == target->getCoordY())) {
			return true;
		}
	}
	return false;
}

bool CSolidHitbox::isEntityOutofBounds() // if entity is out of bounds on either axis, set to the spot not out of bounds and returns true
{
	if (getCoordX() >= 104) {
		setCoordX(103);
		return true;
	}
	else if (getCoordX() <= 0) {
		setCoordX(1);
		return true;
	}
	for (int i = 0; i < 1; i++) {
		if (getCoordY() >= 11) {
			setCoordY(10);
			return true;
		}
		else if (getCoordY() <= 0) {
			setCoordY(2);
			return true;
		}
	}
	return false;
}
// reuse this for ALL moving collisions for moving entities
bool CSolidHitbox::isEntityGoingToOverlapInTheFuture(int dir, CSolidHitbox(*target)) // 1234 wasd -1, -1, 1, 1 if overlapping TRUE if NOT overlapping (good) FALSE
{
	int x = getCoordX();
	int y = getCoordY();
	int x2 = target->getCoordX();
	int y2 = target->getCoordY();
	int differenceX = 0;
	int differenceY = 0;
	switch (dir) {
	case 1:
		differenceY = -1;
		break;
	case 2:
		differenceX = -1;
		break;
	case 3:
		differenceY = 1;
		break;
	case 4:
		differenceX = 1;
		break;
	}
	if ((((x + differenceX) == x2) and (y == y2)) or (((y + differenceY) == y2) and (x == x2))) {
		return true;
	}

	return false;
}

