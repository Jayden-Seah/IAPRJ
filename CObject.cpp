#include "CObject.h"

CObject::CObject()
{
}

CObject::CObject(int randv)
{
	coordX = randv % 100 + 1;
	coordY = randv % 8 + 1;
}

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