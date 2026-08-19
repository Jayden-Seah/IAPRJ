#include "CSolidHitbox.h"

bool CSolidHitbox::isEntityOverlapping(CSolidHitbox(*target)) // overlapping = true, not overlapping (good) = false
{
	for (int i = 0; i < getObjectHeight(); i++) { // 
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
	for (int i = 0; i < getObjectHeight(); i++) {
		if (getCoordY()-i >= 10) {
			setCoordY(9);
			return true;
		}
		else if (getCoordY() - i <= 0) {
			setCoordY(2);
			return true;
		}
	}
	return false;
}
