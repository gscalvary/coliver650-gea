#pragma once
#include "Point.h"
#include <vector>
using namespace std;

class Player {
private:
	int spirit;
	bool isThrown;
	Point position;
	vector<int> correctAnswers;
	vector<int> incorrectAnswers;

public:
	Player();
	~Player();
	int getSpirit();
	void erodeSpirit(int x);
	void refreshSpirit();
	bool getIsThrown();
	void updateIsThrown(bool x);
	int getPlayerPosX();
	int getPlayerPosY();
	void updatePlayerPos(int x, int y);
	void addCorrectAnswers(int x);
	void addIncorrectAnswers(int x);
	void removeIncorrectAnswers(int x);
	int getNumCorrectAnswers();
	int getNumIncorrectAnswers();
};

