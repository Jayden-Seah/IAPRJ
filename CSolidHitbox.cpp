#include "CSolidHitbox.h"

bool CSolidHitbox::isEntityOverlapping(CSolidHitbox(*target)) // overlapping = true, not overlapping (good) = false
{
	for (int i = 0; i < getObjectHeight(); i++) { // 
		if ((getCoordX() == target->getCoordX()) and (getCoordY()+i == target->getCoordY())) {
			return false;
		}
	}
	return true;
}
