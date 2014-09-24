#include "Game.h"

Game::Game() {

	Clock gameClock;
	state = 1;
}


Game::~Game() {

}

int Game::getGameState() {
	return state;
}

void Game::updateGameState(int newstate) {

	if (newstate < 0 || newstate > 9) {
		return;
	}

	switch (state)
	{
	case 1:
		switch (newstate)
		{
		case 0:
		case 2:
			state = newstate;
		default:
			break;
		}
		break;
	case 2:
		switch (newstate)
		{
		case 0:
		case 3:
			state = newstate;
		default:
			break;
		}
		break;
	case 3:
		switch (newstate)
		{
		case 0:
		case 4:
			state = newstate;
		default:
			break;
		}
		break;
	case 4:
		switch (newstate)
		{
		case 0:
		case 5:
			state = newstate;
		default:
			break;
		}
		break;
	case 5:
		switch (newstate)
		{
		case 0:
		case 6:
			state = newstate;
		default:
			break;
		}
		break;
	case 6:
		switch (newstate)
		{
		case 0:
		case 7:
			state = newstate;
		default:
			break;
		}
		break;
	case 7:
		switch (newstate)
		{
		case 0:
		case 8:
			state = newstate;
		default:
			break;
		}
		break;
	case 8:
		switch (newstate)
		{
		case 0:
		case 9:
			state = newstate;
		default:
			break;
		}
		break;
	case 9:
		switch (newstate)
		{
		case 0:
			state = newstate;
		default:
			break;
		}
		break;
	default:
		break;
	}
}