#include "Game.h"

// Game: vector<Circle> *pointer ->
// EFFECT: Creates a game object in memory with a current and prior state set to zero, a number of allowable incorrect
// answers set to three, a throw speed set to 100 meters/second and a throw destination point set to (2000,0).
// Example: see test class.
Game::Game(vector<Circle> *Cptr) {

	priorState = 0;
	currState = 0;
	incorrectAnswerMax = 3;
	// meters per second
	throwSpeed = 100;
	// meters from origin, (0,0) is lower left of map.
	throwPosition.updatePointx(2000);
	throwPosition.updatePointy(0);
	cantos = Cptr;
}
// ~Game:
// EFFECT: De-allocates the memory reserved for a Game object.
Game::~Game() {

}
// getCurrGameState: -> int
// Takes no input but returns a number representing current game state.
// INVARIANT: returned game state will be between 0 and 10 inclusively.
// Example: see test class.
int Game::getCurrGameState() {
	return currState;
}
// getPriorGameState: -> int
// Takes no input but returns a number representing the prior game state.
// INVARIANT: returned game state will be between 0 and 10 inclusively.
// Example: see test class.
int Game::getPriorGameState() {
	return priorState;
}
// updateGameState: int ->
// Takes a number representing a new game state and sets the game to that state depending on the encoded
// transition relation in this function.
// INVARIANT: game state will always be set to a number between 0 and 10 inclusively.
// Example: see test class.
void Game::updateGameState(int newstate) {
	// Encode allowable state transitions.
	if (newstate >= 0 && newstate <= 10) {
		switch (currState)
		{
		case 0:
			switch (newstate)
			{
			case 1:
			case 9:
				priorState = currState;
				currState = newstate;
			case 10:
				currState = newstate;
			default:
				break;
			}
			break;
		case 1:
			switch (newstate)
			{
			case 2:
			case 9:
				priorState = currState;
				currState = newstate;
			case 10:
				currState = newstate;
			default:
				break;
			}
			break;
		case 2:
			switch (newstate)
			{
			case 3:
			case 9:
				priorState = currState;
				currState = newstate;
			case 10:
				currState = newstate;
			default:
				break;
			}
			break;
		case 3:
			switch (newstate)
			{
			case 4:
			case 9:
				priorState = currState;
				currState = newstate;
			case 10:
				currState = newstate;
			default:
				break;
			}
			break;
		case 4:
			switch (newstate)
			{
			case 5:
			case 9:
				priorState = currState;
				currState = newstate;
			case 10:
				currState = newstate;
			default:
				break;
			}
			break;
		case 5:
			switch (newstate)
			{
			case 6:
			case 9:
				priorState = currState;
				currState = newstate;
			case 10:
				currState = newstate;
			default:
				break;
			}
			break;
		case 6:
			switch (newstate)
			{
			case 7:
			case 9:
				priorState = currState;
				currState = newstate;
			case 10:
				currState = newstate;
			default:
				break;
			}
			break;
		case 7:
			switch (newstate)
			{
			case 8:
			case 9:
				priorState = currState;
				currState = newstate;
			case 10:
				currState = newstate;
			default:
				break;
			}
			break;
		case 8:
			switch (newstate)
			{
			case 9:
				priorState = currState;
				currState = newstate;
			case 10:
				currState = newstate;
			default:
				break;
			}
			break;
		case 9:
			switch (newstate)
			{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
				if (newstate == priorState + 1) {
					currState = newstate;
				}
				break;
			case 10:
				currState = newstate;
			default:
				break;
			}
			break;
		case 10:
			break;
		default:
			break;
		}
	}
}
// getIncorrectAnswerMax: -> int
// Takes no input but returns a number representing the maximum number of incorrect answers the game allows.
// Example: see test class.
int Game::getIncorrectAnswerMax() {
	return incorrectAnswerMax;
}
// getThrowSpeed: -> int
// Takes no input but returns a number representing the speed in meters/second at which a player is thrown when siezed for
// speaking untruths.
// Example: see test class.
int Game::getThrowSpeed() {
	return throwSpeed;
}
// getThrowPositionX: -> int
// Takes no input but returns a number representing the x portion of a coordinate to which a player is thrown with (0,0)
// being the lower left handle corner of the map.
// Example: see test class.
int Game::getThrowPositionX() {
	return throwPosition.getPointx();
}
// getThrowPositionY: -> int
// Takes no input but returns a number representing the y portion of a coordinate to which a player is thrown with (0,0)
// being the lower left handle corner of the map.
// Example: see test class.
int Game::getThrowPositionY() {
	return throwPosition.getPointy();
}
