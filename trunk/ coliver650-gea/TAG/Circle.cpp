#include "Circle.h"

// Circle: string, vector<Npc> *pointer, int, char, vector<Message> *Pointer
// EFFECT: Takes a name, a pointer to a vector of Npc objects, a rate of player spirit erosion, a character
// representing the correct answer to a question asked of the player in this circle and a pointer
// to a vector of message objects and creates a circle object in memory.
// Example: see test class.
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
// ~Circle:
// EFFECT: De-allocates the memory reserved for a Circle object.
Circle::~Circle() {

}
// getName: -> string
// Takes no input but returns the string representing the name of the Circle object.
// Example: see test class.
string Circle::getName() {
	return name;
}
// getCorrectAnswer: -> char
// Takes no input but returns the character representing the correct answer to a question asked of the player
// while "playing" in this Circle object.
// Example: see test class.
char Circle::getCorrectAnswer() {
	return correctAnswer;
}
// getStartTime: -> int
// Takes no input but returns the number of seconds since game start at which point the player entered this circle.
// Example: see test class.
int Circle::getStartTime() {
	return startTime;
}
// updateStartTime: int ->
// EFFECT: sets the start time of this Circle object to whatever value is passed in to the function.
// Example: see test class.
void Circle::updateStartTime(int x) {
	startTime = x;
}
// getSpiritErosionRate: -> int
// Takes no input but returns the a number representing how much spirit should be removed from the player per spirit update
// period (set dynamically).
// Example: see test class.
int Circle::getSpiritErosionRate() {
	return spiritErosionRate;
}
// isQuestionAsked: -> bool
// Takes no input but returns true or false representing if the player was asked a question in this circle yet.
// Example: see test class.
bool Circle::isQuestionAsked() {
	return questionAsked;
}
// setQuestionToAsked:
// EFFECT: sets the boolean representing if a question was asked of the player in this circle to true.
// Example: see test class.
void Circle::setQuestionToAsked() {
	questionAsked = true;
}
// playIntroduction:
// EFFECT: writes to output the text that introduces a player to this circle.
// Example: see test class.
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
// playNextDescription:
// EFFECT: writes to output text meant to further orientate a player to this circle.
// Example: see test class.
void Circle::playNextDescription() {
	if (descriptionsIndex >= descriptions->size() - 1) {
		descriptionsIndex = 0;
	}
	else {
		++descriptionsIndex;
	}

	descriptions->at(descriptionsIndex).play();
}
