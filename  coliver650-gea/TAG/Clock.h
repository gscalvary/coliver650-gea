#pragma once
#include <time.h>

class Clock
{
private:
	time_t startTime;
	bool isPaused;
	double elapsedSeconds;

public:
	Clock();
	~Clock();
	time_t *getClockStartTime();
	// Returns seconds.
	double getClockElapsedTime();
	bool getClockIsPaused();
	void pauseClock();
	void unpauseClock();
};

