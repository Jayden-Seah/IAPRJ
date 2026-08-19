#pragma once
#include <iostream>
#include <random>

//std::default_random_engine generator(std::random_device{}());//default random engine creates the random value, generator is just the name for it , std random device gives it a random starting point without it itll be the same evry time

//std::uniform_int_distribution<int> revents(0, 100);// uniform gives every num a equal chance, int is whole num, and distribution effectively says, give me a num from x to y


class RandomEvents
{
public:
	RandomEvents() {
		//int eventnum = (revents(generator) % 5);
		//std::cout << eventnum;
	}
};