#pragma once
#include "Message.h"
#include "Npc.h"
#include <iostream>
#include <vector>

class Circle {
private:
	string name;
	int startTime;
	int spiritErosionRate;
	char correctAnswer;
	bool questionAsked;
	vector<Message> *descriptions;
	int descriptionsIndex;

public:
	Circle(string name, vector<Npc> *Nptr, int spiritErosionRate, char correctAnswer, vector<Message> *Mptr);
	~Circle();
	vector<Npc> *inhabitants;
	string getName();
	char getCorrectAnswer();
	int getStartTime();
	void updateStartTime(int x);
	int getSpiritErosionRate();
	bool isQuestionAsked();
	void setQuestionToAsked();
	void playIntroduction();
	void playNextDescription();
};

