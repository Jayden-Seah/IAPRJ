#pragma once
class CObject
{
	// dont mess up the axises again me 
	int coordX;
	int coordY;
	int objectHeight;
public:
	CObject();
	CObject(int randv);

	int getCoordX();
	int getCoordY();
	int getObjectHeight();

	void setCoordX(int x);
	void setCoordY(int y);
	void setObjectHeight(int h);
};

