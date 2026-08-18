#pragma once
#include <iostream>

srand(static_cast<unsigned>(time(0)));

class RandomEvents
{
public:
	RandomEvents() {
		int eventnum = (rand() % 5);
		std::cout << eventnum;
	}
};

