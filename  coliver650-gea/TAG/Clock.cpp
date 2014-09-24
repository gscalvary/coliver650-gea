#include "Clock.h"

Clock::Clock() {
	time(&startTime);
	isPaused = false;
	elapsedSeconds = 0.0;
}

Clock::~Clock() {
}

time_t *Clock::getClockStartTime() {
	return &startTime;
}

double Clock::getClockElapsedTime() {
	if (isPaused) {
		return elapsedSeconds;
	}
	else {
		time_t timeNow = NULL;
		time(&timeNow);
		double newElapsedSeconds = 0.0;
		newElapsedSeconds = difftime(timeNow, *getClockStartTime());
		return newElapsedSeconds + elapsedSeconds;
	}
}

bool Clock::getClockIsPaused() {
	return isPaused;
}

void Clock::pauseClock() {
	if (!isPaused) {
		elapsedSeconds = getClockElapsedTime();
		isPaused = true;
	}
}

void Clock::unpauseClock() {
	if (isPaused) {
		isPaused = false;
		time(&startTime);
	}
}
