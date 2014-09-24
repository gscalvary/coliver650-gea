#include "Clock.h"
#include "Test.h"

Test::Test() {

}

Test::~Test() {

}

void Test::test_Clock_class() {

	// Mark a test start time, used to test the clock start time later.
	time_t testStartTime = NULL;
	time(&testStartTime);
	
	// Sleep 2 seconds, used to test the clock start time later.
	unsigned sleepTime = 2000;
	_sleep(sleepTime);

	// Initialize a clock.
	Clock testClock;

	// Constructor tests.
	// Test the clock start time.
	assert(sleepTime/1000 <= difftime(*testClock.getClockStartTime(), testStartTime));
	// Test the clock pause state.
	assert(false == testClock.getClockIsPaused());
	// Test the clock elapsed time.
	assert(0.0 == testClock.getClockElapsedTime());

	// Function tests.
	// Sleep 2 seconds then test the clock elapsed time.
	_sleep(sleepTime);
	assert(testClock.getClockElapsedTime() >= sleepTime / 1000);
	// Pause the clock.
	testClock.pauseClock();
	assert(true == testClock.getClockIsPaused());
	// Sleep 2 seconds and make sure the clock elapsed time hasn't changed.
	_sleep(sleepTime);
	assert((3.0 > testClock.getClockElapsedTime()) && (testClock.getClockElapsedTime() >= sleepTime / 1000));
	// Unpause the clock and make sure the elapsed time is maintained.
	testClock.unpauseClock();
	assert(false == testClock.getClockIsPaused());
	assert((3.0 > testClock.getClockElapsedTime()) && (testClock.getClockElapsedTime() >= sleepTime / 1000));
	// Sleep 2 seconds and make sure the clock is again accruing elapsed time.
	_sleep(sleepTime);
	assert((5.0 > testClock.getClockElapsedTime()) && (testClock.getClockElapsedTime() >= 4.0));
}