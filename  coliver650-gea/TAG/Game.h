#pragma once
#include "Clock.h"
#include "Circle.h"
#include "Player.h"

// The primary object in the design, the game itself, one instance is created.
class Game
{
private:
	int priorState;
	int currState;
	int incorrectAnswerMax;
	int throwSpeed;
	Point throwPosition;

public:
	// Game: vector<Circle> *pointer ->
	// EFFECT: Creates a game object in memory with a current and prior state set to zero, a number of allowable incorrect
	// answers set to three, a throw speed set to 100 meters/second and a throw destination point set to (2000,0).
	// Example: see test class.
	Game(vector<Circle> *pointer);
	// ~Game:
	// EFFECT: De-allocates the memory reserved for a Game object.
	~Game();
	Clock gameClock;
	Player gamePlayer;
	vector<Circle> *cantos;
	// getCurrGameState: -> int
	// Takes no input but returns a number representing current game state.
	// INVARIANT: returned game state will be between 0 and 10 inclusively.
	// Example: see test class.
	int getCurrGameState();
	// getPriorGameState: -> int
	// Takes no input but returns a number representing the prior game state.
	// INVARIANT: returned game state will be between 0 and 10 inclusively.
	// Example: see test class.
	int getPriorGameState();
	// updateGameState: int ->
	// Takes a number representing a new game state and sets the game to that state depending on the encoded
	// transition relation in this function.
	// INVARIANT: game state will always be set to a number between 0 and 10 inclusively.
	// Example: see test class.
	void updateGameState(int newstate);
	// getIncorrectAnswerMax: -> int
	// Takes no input but returns a number representing the maximum number of incorrect answers the game allows.
	// Example: see test class.
	int getIncorrectAnswerMax();
	// getThrowSpeed: -> int
	// Takes no input but returns a number representing the speed in meters/second at which a player is thrown when siezed for
	// speaking untruths.
	// Example: see test class.
	int getThrowSpeed();
	// getThrowPositionX: -> int
	// Takes no input but returns a number representing the x portion of a coordinate to which a player is thrown with (0,0)
	// being the lower left handle corner of the map.
	// Example: see test class.
	int getThrowPositionX();
	// getThrowPositionY: -> int
	// Takes no input but returns a number representing the y portion of a coordinate to which a player is thrown with (0,0)
	// being the lower left handle corner of the map.
	// Example: see test class.
	int getThrowPositionY();
};

