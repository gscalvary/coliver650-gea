#include "Clock.h"

// Clock: 
// EFFECT: Creates an unpaused clock object in memory with a start time set to current time and elapsed time set to 0.
// Example: see test class.
Clock::Clock() {
	time(&startTime);
	isPaused = false;
	elapsedSeconds = 0.0;
}
// ~Clock:
// EFFECT: De-allocates the memory reserved for a Clock object.
Clock::~Clock() {
}
// getClockStartTime: -> time_t
// Takes no input but returns the time at which this clock was started.
// Example: see test class.
time_t *Clock::getClockStartTime() {
	return &startTime;
}
// getClockElapsedTime: -> double
// Takes no input but returns a double representing the number of seconds that have passed since this clock was started.
// Example: see test class.
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
// getClockIsPaused: -> bool
// Takes no input but returns true or false depending on whether the clock is paused or not.
// Example: see test class.
bool Clock::getClockIsPaused() {
	return isPaused;
}
// pauseClock: 
// EFFECT: Pauses this clock.
// Example: see test class.
void Clock::pauseClock() {
	if (!isPaused) {
		elapsedSeconds = getClockElapsedTime();
		isPaused = true;
	}
}
// unpauseClock: 
// EFFECT: Unpauses this clock.
// Example: see test class.
void Clock::unpauseClock() {
	if (isPaused) {
		isPaused = false;
		time(&startTime);
	}
}
