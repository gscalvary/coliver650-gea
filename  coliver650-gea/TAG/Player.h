#pragma once
#include "Point.h"
#include <vector>
using namespace std;

// An object representing the player character.  Only one is created as a child of the Game.
class Player {
private:
	int spirit;
	bool isThrown;
	Point position;
	vector<int> correctAnswers;
	vector<int> incorrectAnswers;

public:
	// Player:
	// EFFECT: Creates a Player object in memory with a spirit initialized to 100, isThrown initialized to false, a position
	// initialized to (100,0) and empty vectors reserved for correct and incorrect answers (truths and falsehoods).
	// Example: see test class.
	Player();
	// ~Player:
	// EFFECT: De-allocates the memory reserved for a Player object.
	~Player();
	// getSpirit: -> int
	// Takes no input but returns a number representing the player's current spirit.
	// INVARIANT: Spirit is always between 0 and 100 inclusive.
	// Example: see test class.
	int getSpirit();
	// erodeSpirit: int ->
	// EFFECT: Reduces the player spirit by the amount passed.
	// INVARIANT: Will decrease spirit to a minimum value of 0.
	// Example: see test class.
	void erodeSpirit(int x);
	// refreshSpirit:
	// EFFECT: Sets the players spirit to 100.
	// Example: see test class.
	void refreshSpirit();
	// getIsThrown: -> bool
	// Takes no input but returns true or false depending on whether the player is in a thrown state.
	// Example: see test class.
	bool getIsThrown();
	// updateIsThrown: bool ->
	// EFFECT: take true or false as input and sets the players isThrown state to it.
	// Example: see test class.
	void updateIsThrown(bool x);
	// getPlayerPosX: -> int
	// Takes no input but returns a number representing the player's current position x coordinate.
	// Example: see test class.
	int getPlayerPosX();
	// getPlayerPosY: -> int
	// Takes no input but returns a number representing the player's current position y coordinate.
	// Example: see test class.
	int getPlayerPosY();
	// updatePlayerPos: int, int ->
	// EFFECT: Sets the players position x and y coordinates to those passed respectively.
	// Example: see test class.
	void updatePlayerPos(int x, int y);
	// addCorrectAnswers: int ->
	// EFFECT: Adds the passed value as a member to the correct answer vector.  The value corresponds to the game state in which
	// the question was asked and answered correctly.
	// INVARIANT: Only states 0 - 8 inclusive are valid pass values, other values will be ignored.
	// Example: see test class.
	void addCorrectAnswers(int x);
	// addIncorrectAnswers: int ->
	// EFFECT: Adds the passed value as a member to the incorrect answer vector.  The value corresponds to the game state in which
	// the question was asked and answered incorrectly.
	// INVARIANT: Only states 0 - 8 inclusive are valid pass values, other values will be ignored.
	// Example: see test class.
	void addIncorrectAnswers(int x);
	// removeIncorrectAnswers: int ->
	// EFFECT: Removes the passed value as a member from the incorrect answer vector.  The value corresponds to the game state in
	// which the question was first asked and answered incorrectly.  If the value is not present it will be ignored.
	// Example: see test class.
	void removeIncorrectAnswers(int x);
	// getNumCorrectAnswers: -> int
	// Takes no input but returns the number of questions correctly answered by the player.
	// Example: see test class.
	int getNumCorrectAnswers();
	// getNumIncorrectAnswers: -> int
	// Takes no input but returns the number of questions incorrectly answered by the player.
	// Example: see test class.
	int getNumIncorrectAnswers();
};

