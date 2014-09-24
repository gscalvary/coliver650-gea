#pragma once
#include "Point.h"

class Player {
private:
	Point position;
	int falsehoods;

public:
	Player();
	~Player();
	int getPlayerPosX();
	int getPlayerPosY();
	void updatePlayerPos(int x, int y);
	int getPlayerFalsehoods();
	// addorsub = a to increment
	//            s to decrement
	void incrementPlayerFalsehoods(char addorsub);
};

