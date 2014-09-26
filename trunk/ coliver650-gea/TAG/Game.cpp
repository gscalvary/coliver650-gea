#include "Game.h"

Game::Game(vector<Circle> *Cptr) {

	priorState = 0;
	currState = 0;
	incorrectAnswerMax = 3;
	// meters per second
	throwSpeed = 10;
	// meters from origin, (0,0) is lower left of map.
	throwPosition.updatePointx(2000);
	throwPosition.updatePointy(3000);
	cantos = Cptr;
}


Game::~Game() {

}

int Game::getCurrGameState() {
	return currState;
}

int Game::getPriorGameState() {
	return priorState;
}

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

int Game::getIncorrectAnswerMax() {
	return incorrectAnswerMax;
}

int Game::getThrowSpeed() {
	return throwSpeed;
}

int Game::getThrowPositionX() {
	return throwPosition.getPointx();
}

int Game::getThrowPositionY() {
	return throwPosition.getPointy();
}
