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
	// Circle: string, vector<Npc> *pointer, int, char, vector<Message> *Pointer
	// EFFECT: Takes a name, a pointer to a vector of Npc objects, a rate of player spirit erosion, a character
	// representing the correct answer to a question asked of the player in this circle and a pointer
	// to a vector of message objects and creates a circle object in memory.
	// Example: see test class.
	Circle(string name, vector<Npc> *Nptr, int spiritErosionRate, char correctAnswer, vector<Message> *Mptr);
	// ~Circle:
	// EFFECT: De-allocates the memory reserved for a Circle object.
	~Circle();
	vector<Npc> *inhabitants;
	// getName: -> string
	// Takes no input but returns the string representing the name of the Circle object.
	// Example: see test class.
	string getName();
	// getCorrectAnswer: -> char
	// Takes no input but returns the character representing the correct answer to a question asked of the player
	// while "playing" in this Circle object.
	// Example: see test class.
	char getCorrectAnswer();
	// getStartTime: -> int
	// Takes no input but returns the number of seconds since game start at which point the player entered this circle.
	// Example: see test class.
	int getStartTime();
	// updateStartTime: int ->
	// EFFECT: sets the start time of this Circle object to whatever value is passed in to the function.
	// Example: see test class.
	void updateStartTime(int x);
	// getSpiritErosionRate: -> int
	// Takes no input but returns the a number representing how much spirit should be removed from the player per spirit update
	// period (set dynamically).
	// Example: see test class.
	int getSpiritErosionRate();
	// isQuestionAsked: -> bool
	// Takes no input but returns true or false representing if the player was asked a question in this circle yet.
	// Example: see test class.
	bool isQuestionAsked();
	// setQuestionToAsked:
	// EFFECT: sets the boolean representing if a question was asked of the player in this circle to true.
	// Example: see test class.
	void setQuestionToAsked();
	// playIntroduction:
	// EFFECT: writes to output the text that introduces a player to this circle.
	// Example: see test class.
	void playIntroduction();
	// playNextDescription:
	// EFFECT: writes to output text meant to further orientate a player to this circle.
	// Example: see test class.
	void playNextDescription();
};

