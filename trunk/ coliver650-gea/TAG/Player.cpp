#include "Player.h"


Player::Player() {
	spirit = 100;
	// meters from origin, (0,0) is lower left of map.
	position.updatePointx(100);
	position.updatePointy(500);
}

Player::~Player() {

}

int Player::getSpirit() {
	return spirit;
}

void Player::erodeSpirit(int x) {
	spirit -= x;

	if (spirit < 0) {
		spirit = 0;
	}
}

int Player::getPlayerPosX() {
	return position.getPointx();
}

int Player::getPlayerPosY() {
	return position.getPointy();
}

void Player::updatePlayerPos(int x, int y) {
	position.updatePointx(x);
	position.updatePointy(y);
}

void Player::addCorrectAnswers(int x) {
	if (x >= 0 && x <= 8) {
		correctAnswers.push_back(x);
	}
}

void Player::addIncorrectAnswers(int x) {
	if (x >= 0 && x <= 8) {
		incorrectAnswers.push_back(x);
	}
}

void Player::removeIncorrectAnswers(int x) {
	for (unsigned i = 0; i < incorrectAnswers.size(); i++) {
		if (incorrectAnswers[i] == x) {
			incorrectAnswers.erase(incorrectAnswers.begin() + i);
			i = incorrectAnswers.size();
		}
	}
}

int Player::getNumCorrectAnswers() {
	return correctAnswers.size();
}

int Player::getNumIncorrectAnswers() {
	return incorrectAnswers.size();
}
