#pragma once
#include "Clock.h"

class Game
{
private:
	int state;

public:
	Game();
	~Game();
	Clock gameClock;
	int getGameState();
	void updateGameState(int newstate);
};

