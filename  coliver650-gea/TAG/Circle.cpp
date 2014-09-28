#include "Circle.h"

Circle::Circle(string a, vector<Npc> *Nptr, int x, char b, vector<Message> *Mptr) {
	name = a;
	inhabitants = Nptr;
	startTime = 0;
	spiritErosionRate = x;
	correctAnswer = b;
	questionAsked = false;
	descriptions = Mptr;
	descriptionsIndex = 0;
}

Circle::~Circle() {

}

string Circle::getName() {
	return name;
}

char Circle::getCorrectAnswer() {
	return correctAnswer;
}

int Circle::getStartTime() {
	return startTime;
}

void Circle::updateStartTime(int x) {
	startTime = x;
}

int Circle::getSpiritErosionRate() {
	return spiritErosionRate;
}

bool Circle::isQuestionAsked() {
	return questionAsked;
}

void Circle::setQuestionToAsked() {
	questionAsked = true;
}

void Circle::playIntroduction() {
	descriptions->at(0).play();

	if (inhabitants->size() > 0) {
		cout << endl << "Among those at this depth you may talk to: " << endl;
		for (unsigned x = 0; x < inhabitants->size(); ++x) {
			if (inhabitants->at(x).getType() == "shade") {
				cout << " " << inhabitants->at(x).getName() << endl;
			}
		}
	}
}

void Circle::playNextDescription() {
	if (descriptionsIndex >= descriptions->size() - 1) {
		descriptionsIndex = 0;
	}
	else {
		++descriptionsIndex;
	}

	descriptions->at(descriptionsIndex).play();
}
