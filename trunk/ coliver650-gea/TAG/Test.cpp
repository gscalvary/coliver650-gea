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

	// Update tests.
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

void Test::test_Game_class() {

	// Initialize a game.
	Game testGame;

	// Constructor tests.
	// Test game clock creation.
	assert(false == testGame.gameClock.getClockIsPaused());
	// Test initial game state.
	assert(1 == testGame.getGameState());
	
	// Update tests.
	// Test game state update.
	testGame.updateGameState(1);
	assert(1 == testGame.getGameState());
	testGame.updateGameState(10);
	assert(1 == testGame.getGameState());
	testGame.updateGameState(2);
	assert(2 == testGame.getGameState());
	testGame.updateGameState(1);
	assert(2 == testGame.getGameState());
	testGame.updateGameState(4);
	assert(2 == testGame.getGameState());
	testGame.updateGameState(0);
	assert(0 == testGame.getGameState());
	testGame.updateGameState(1);
	assert(0 == testGame.getGameState());
}

void Test::test_Point_class() {

	// Initialize a point.
	Point testPoint;

	// Constructor tests.
	assert(0 == testPoint.getPointx());
	assert(0 == testPoint.getPointy());

	// Update tests.
	// Test x update.
	int i = 1;
	testPoint.updatePointx(i);
	assert(1 == testPoint.getPointx());
	// Test y update.
	testPoint.updatePointy(i);
	assert(1 == testPoint.getPointy());
}