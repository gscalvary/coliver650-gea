#pragma once
#include "Clock.h"
#include "Circle.h"
#include "Player.h"

class Game
{
private:
	int priorState;
	int currState;
	int incorrectAnswerMax;
	int throwSpeed;
	Point throwPosition;

public:
	Game(vector<Circle> *pointer);
	~Game();
	Clock gameClock;
	Player gamePlayer;
	vector<Circle> *cantos;
	int getCurrGameState();
	int getPriorGameState();
	void updateGameState(int newstate);
	int getIncorrectAnswerMax();
	int getThrowSpeed();
	int getThrowPositionX();
	int getThrowPositionY();
};

