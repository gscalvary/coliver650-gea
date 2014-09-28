#include "Player.h"

// Player:
// EFFECT: Creates a Player object in memory with a spirit initialized to 100, isThrown initialized to false, a position
// initialized to (100,0) and empty vectors reserved for correct and incorrect answers (truths and falsehoods).
// Example: see test class.
Player::Player() {
	spirit = 100;
	isThrown = false;
	// meters from origin, (0,0) is lower left of map.
	position.updatePointx(100);
	position.updatePointy(0);
}
// ~Player:
// EFFECT: De-allocates the memory reserved for a Player object.
Player::~Player() {

}
// getSpirit: -> int
// Takes no input but returns a number representing the player's current spirit.
// INVARIANT: Spirit is always between 0 and 100 inclusive.
// Example: see test class.
int Player::getSpirit() {
	return spirit;
}
// erodeSpirit: int ->
// EFFECT: Reduces the player spirit by the amount passed.
// INVARIANT: Will decrease spirit to a minimum value of 0.
// Example: see test class.
void Player::erodeSpirit(int x) {
	spirit -= x;

	if (spirit < 0) {
		spirit = 0;
	}
}
// refreshSpirit:
// EFFECT: Sets the players spirit to 100.
// Example: see test class.
void Player::refreshSpirit() {
	spirit = 100;
}
// getIsThrown: -> bool
// Takes no input but returns true or false depending on whether the player is in a thrown state.
// Example: see test class.
bool Player::getIsThrown() {
	return isThrown;
}
// updateIsThrown: bool ->
// EFFECT: take true or false as input and sets the players isThrown state to it.
// Example: see test class.
void Player::updateIsThrown(bool x) {
	isThrown = x;
}
// getPlayerPosX: -> int
// Takes no input but returns a number representing the player's current position x coordinate.
// Example: see test class.
int Player::getPlayerPosX() {
	return position.getPointx();
}
// getPlayerPosY: -> int
// Takes no input but returns a number representing the player's current position y coordinate.
// Example: see test class.
int Player::getPlayerPosY() {
	return position.getPointy();
}
// updatePlayerPos: int, int ->
// EFFECT: Sets the players position x and y coordinates to those passed respectively.
// Example: see test class.
void Player::updatePlayerPos(int x, int y) {
	position.updatePointx(x);
	position.updatePointy(y);
}
// addCorrectAnswers: int ->
// EFFECT: Adds the passed value as a member to the correct answer vector.  The value corresponds to the game state in which
// the question was asked and answered correctly.
// INVARIANT: Only states 0 - 8 inclusive are valid pass values, other values will be ignored.
// Example: see test class.
void Player::addCorrectAnswers(int x) {
	if (x >= 0 && x <= 8) {
		correctAnswers.push_back(x);
	}
}
// addIncorrectAnswers: int ->
// EFFECT: Adds the passed value as a member to the incorrect answer vector.  The value corresponds to the game state in which
// the question was asked and answered incorrectly.
// INVARIANT: Only states 0 - 8 inclusive are valid pass values, other values will be ignored.
// Example: see test class.
void Player::addIncorrectAnswers(int x) {
	if (x >= 0 && x <= 8) {
		incorrectAnswers.push_back(x);
	}
}
// removeIncorrectAnswers: int ->
// EFFECT: Removes the passed value as a member from the incorrect answer vector.  The value corresponds to the game state in
// which the question was first asked and answered incorrectly.  If the value is not present it will be ignored.
// Example: see test class.
void Player::removeIncorrectAnswers(int x) {
	for (unsigned i = 0; i < incorrectAnswers.size(); i++) {
		if (incorrectAnswers[i] == x) {
			incorrectAnswers.erase(incorrectAnswers.begin() + i);
			i = incorrectAnswers.size();
		}
	}
}
// getNumCorrectAnswers: -> int
// Takes no input but returns the number of questions correctly answered by the player.
// Example: see test class.
int Player::getNumCorrectAnswers() {
	return correctAnswers.size();
}
// getNumIncorrectAnswers: -> int
// Takes no input but returns the number of questions incorrectly answered by the player.
// Example: see test class.
int Player::getNumIncorrectAnswers() {
	return incorrectAnswers.size();
}
