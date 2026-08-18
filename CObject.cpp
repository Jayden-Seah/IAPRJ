#include "CObject.h"

int CObject::getCoordX()
{
	return coordX;
}

int CObject::getCoordY()
{

	return coordY;
}

int CObject::getObjectHeight()
{
	return objectHeight;
}


void CObject::setCoordX(int x)
{
	coordX = x;
}

void CObject::setCoordY(int y)
{
	coordY = y;
}

void CObject::setObjectHeight(int h)
{
	objectHeight = h;
}