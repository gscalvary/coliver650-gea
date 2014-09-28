#pragma once
#include <time.h>

class Clock
{
private:
	time_t startTime;
	bool isPaused;
	double elapsedSeconds;

public:
	// Clock: 
	// EFFECT: Creates an unpaused clock object in memory with a start time set to current time and elapsed time set to 0.
	// Example: see test class.
	Clock();
	// ~Clock:
	// EFFECT: De-allocates the memory reserved for a Clock object.
	~Clock();
	// getClockStartTime: -> time_t
	// Takes no input but returns the time at which this clock was started.
	// Example: see test class.
	time_t *getClockStartTime();
	// getClockElapsedTime: -> double
	// Takes no input but returns a double representing the number of seconds that have passed since this clock was started.
	// Example: see test class.
	double getClockElapsedTime();
	// getClockIsPaused: -> bool
	// Takes no input but returns true or false depending on whether the clock is paused or not.
	// Example: see test class.
	bool getClockIsPaused();
	// pauseClock: 
	// EFFECT: Pauses this clock.
	// Example: see test class.
	void pauseClock();
	// unpauseClock: 
	// EFFECT: Unpauses this clock.
	// Example: see test class.
	void unpauseClock();
};

