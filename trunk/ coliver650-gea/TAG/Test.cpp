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

	// Initialize an Npc message.
	Message testMessage1("Francesca");
	testMessage1.addText("Love, which in gentle hearts is quickly born,");
	testMessage1.addText("Seized him for my fair body--which, in a fierce");
	testMessage1.addText("Manner that still torments my soul, was torn");
	testMessage1.addText("Untimely away from me.  Love, which absolves");
	testMessage1.addText("None who are loved from loving, made my heart burn");
	testMessage1.addText("With joy so strong that as you see it cleaves");
	testMessage1.addText("Still to him, here.  Love gave us both one death.");

	// Initialize an Npc.
	Npc testNpc1("Francesca", "shade", &testMessage1);

	// Initialize another Npc message.
	Message testMessage2("Minos");
	testMessage2.addText("Tell me traveler, of what are these shades guilty of being?");
	testMessage2.addText(" a) Heretics");
	testMessage2.addText(" b) Lustful");
	testMessage2.addText(" c) Violent to Others");

	// Initialize another Npc.
	Npc testNpc2("Minos", "demon", &testMessage2);

	// Initialize a circle.
	vector<Npc> circleNpcs = { testNpc1, testNpc2 };
	Message testMessage3("game");
	testMessage3.addText("And now I can hear the notes of agony");
	testMessage3.addText("In sad crescendo beginning to reach my ear;");
	testMessage3.addText("Now I am where the noise of lamentation");
	testMessage3.addText("Comes at me in blasts of sorrow.  I am where");
	testMessage3.addText("All light is mute, with a bellowing like the ocean");
	testMessage3.addText("Turbulent in a storm of warring winds,");
	testMessage3.addText("The hurricane of Hell in perpetual motion");
	testMessage3.addText("Sweeping the ravaged spirits as it rends,");
	testMessage3.addText("Twists, and torments them.");
	Message testMessage4("game");
	testMessage4.addText("As winter starlings riding on their wings");
	testMessage4.addText("Form crowded flocks, so spirits dip and veer");
	testMessage4.addText("Foundering in the wind's rough buffetings,");
	testMessage4.addText("Upward or downward, driven here and there");
	testMessage4.addText("With never ease from pain nor hope of rest.");
	vector<Message> circleMessages = { testMessage3, testMessage4 };
	Circle testCircle("Canto II", &circleNpcs, 10, 'b', &circleMessages);

	// Initialize a game.
	vector<Circle> gameCantos = { testCircle };
	Game testGame(&gameCantos);

	// Constructor tests.
	// Test game clock creation.
	assert(false == testGame.gameClock.getClockIsPaused());
	// Test game player creation.
	assert(100 == testGame.gamePlayer.getSpirit());
	// Test initial game states.
	assert(0 == testGame.getPriorGameState());
	assert(0 == testGame.getCurrGameState());
	// Test incorrect answers maximum.
	assert(3 == testGame.getIncorrectAnswerMax());
	// Test throw speed.
	assert(100 == testGame.getThrowSpeed());
	// Test throw position.
	assert(2000 == testGame.getThrowPositionX());
	assert(0 == testGame.getThrowPositionY());
	assert("Canto II" == testGame.cantos->at(0).getName());
	
	// Update tests.
	// Test game state update.
	testGame.updateGameState(1);
	assert(1 == testGame.getCurrGameState());
	assert(0 == testGame.getPriorGameState());
	testGame.updateGameState(0);
	assert(1 == testGame.getCurrGameState());
	assert(0 == testGame.getPriorGameState());
	testGame.updateGameState(3);
	assert(1 == testGame.getCurrGameState());
	assert(0 == testGame.getPriorGameState());
	testGame.updateGameState(11);
	assert(1 == testGame.getCurrGameState());
	assert(0 == testGame.getPriorGameState());
	testGame.updateGameState(9);
	assert(9 == testGame.getCurrGameState());
	assert(1 == testGame.getPriorGameState());
	testGame.updateGameState(4);
	assert(9 == testGame.getCurrGameState());
	assert(1 == testGame.getPriorGameState());
	testGame.updateGameState(2);
	assert(2 == testGame.getCurrGameState());
	assert(1 == testGame.getPriorGameState());
	testGame.updateGameState(10);
	assert(10 == testGame.getCurrGameState());
	assert(1 == testGame.getPriorGameState());
	testGame.updateGameState(9);
	assert(10 == testGame.getCurrGameState());
	assert(1 == testGame.getPriorGameState());
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

void Test::test_Player_class() {

	// Initialize a player.
	Player testPlayer;

	// Constructor tests.
	// Test spirit.
	assert(100 == testPlayer.getSpirit());
	// Test isThrown.
	assert(false == testPlayer.getIsThrown());
	// Test position creation.
	assert(100 == testPlayer.getPlayerPosX());
	assert(0 == testPlayer.getPlayerPosY());
	// Test number of correct answers vector construction.
	assert(0 == testPlayer.getNumCorrectAnswers());
	// Test number of incorrect answers vector construction.
	assert(0 == testPlayer.getNumIncorrectAnswers());

	// Update tests.
	// Test spirit update.
	testPlayer.erodeSpirit(10);
	assert(90 == testPlayer.getSpirit());
	testPlayer.erodeSpirit(100);
	assert(0 == testPlayer.getSpirit());
	testPlayer.refreshSpirit();
	assert(100 == testPlayer.getSpirit());
	// Test isThrown update.
	testPlayer.updateIsThrown(true);
	assert(true == testPlayer.getIsThrown());
	// Test position update.
	testPlayer.updatePlayerPos(1, 2);
	assert(1 == testPlayer.getPlayerPosX());
	assert(2 == testPlayer.getPlayerPosY());
	// Test adding correct answers.
	testPlayer.addCorrectAnswers(0);
	assert(1 == testPlayer.getNumCorrectAnswers());
	testPlayer.addCorrectAnswers(10);
	assert(1 == testPlayer.getNumCorrectAnswers());
	// Test adding incorrect answers.
	testPlayer.addIncorrectAnswers(1);
	assert(1 == testPlayer.getNumIncorrectAnswers());
	testPlayer.addIncorrectAnswers(10);
	assert(1 == testPlayer.getNumIncorrectAnswers());
	// Test removing incorrect answers.
	testPlayer.addIncorrectAnswers(2);
	testPlayer.addIncorrectAnswers(3);
	testPlayer.removeIncorrectAnswers(1);
	assert(2 == testPlayer.getNumIncorrectAnswers());
}

void Test::test_Message_class() {

	// Initialize a message.
	Message testMessage1("game");

	// Constructor tests.
	// Test owner assignment.
	assert("game" == testMessage1.getOwner());

	// Update tests.
	// Test text update and play.
	testMessage1.addText("Through a round aperture I saw appear");
	testMessage1.addText("Some of the beautiful things that Heaven bears,");
	testMessage1.addText("Where we came forth, and once more saw the stars.");
	testMessage1.play();
	Message testMessage2("Virgil");
	testMessage2.addText("No living man, though once I was.");
	testMessage2.play();
}

void Test::test_Npc_class() {

	// Initialize a message.
	Message testMessage1("Francesca");
	testMessage1.addText("Love, which in gentle hearts is quickly born,");
	testMessage1.addText("Seized him for my fair body--which, in a fierce");
	testMessage1.addText("Manner that still torments my soul, was torn");
	testMessage1.addText("Untimely away from me.  Love, which absolves");
	testMessage1.addText("None who are loved from loving, made my heart burn");
	testMessage1.addText("With joy so strong that as you see it cleaves");
	testMessage1.addText("Still to him, here.  Love gave us both one death.");
	
	// Initialize an Npc.
	Npc testNpc1("Francesca", "shade", &testMessage1);

	// Constructor tests.
	assert("Francesca" == testNpc1.getName());
	testNpc1.speak();
}

void Test::test_Circle_class() {

	// Initialize an Npc message.
	Message testMessage1("Francesca");
	testMessage1.addText("Love, which in gentle hearts is quickly born,");
	testMessage1.addText("Seized him for my fair body--which, in a fierce");
	testMessage1.addText("Manner that still torments my soul, was torn");
	testMessage1.addText("Untimely away from me.  Love, which absolves");
	testMessage1.addText("None who are loved from loving, made my heart burn");
	testMessage1.addText("With joy so strong that as you see it cleaves");
	testMessage1.addText("Still to him, here.  Love gave us both one death.");

	// Initialize an Npc.
	Npc testNpc1("Francesca", "shade", &testMessage1);

	// Initialize another Npc message.
	Message testMessage2("Minos");
	testMessage2.addText("Tell me traveler, of what are these shades guilty of being?");
	testMessage2.addText(" a) Heretics");
	testMessage2.addText(" b) Lustful");
	testMessage2.addText(" c) Violent to Others");

	// Initialize another Npc.
	Npc testNpc2("Minos", "demon", &testMessage2);

	// Initialize a circle.
	vector<Npc> circleNpcs = {testNpc1, testNpc2};
	Message testMessage3("game");
	testMessage3.addText("And now I can hear the notes of agony");
	testMessage3.addText("In sad crescendo beginning to reach my ear;");
	testMessage3.addText("Now I am where the noise of lamentation");
	testMessage3.addText("Comes at me in blasts of sorrow.  I am where");
	testMessage3.addText("All light is mute, with a bellowing like the ocean");
	testMessage3.addText("Turbulent in a storm of warring winds,");
	testMessage3.addText("The hurricane of Hell in perpetual motion");
	testMessage3.addText("Sweeping the ravaged spirits as it rends,");
	testMessage3.addText("Twists, and torments them.");
	Message testMessage4("game");
	testMessage4.addText("As winter starlings riding on their wings");
	testMessage4.addText("Form crowded flocks, so spirits dip and veer");
	testMessage4.addText("Foundering in the wind's rough buffetings,");
	testMessage4.addText("Upward or downward, driven here and there");
	testMessage4.addText("With never ease from pain nor hope of rest.");
	vector<Message> circleMessages = { testMessage3, testMessage4 };
	Circle testCircle("Canto II", &circleNpcs, 10, 'b', &circleMessages);

	// Constructor tests.
	assert("Canto II" == testCircle.getName());
	assert('b' == testCircle.getCorrectAnswer());
	assert(0 == testCircle.getStartTime());
	assert(10 == testCircle.getSpiritErosionRate());
	assert(false == testCircle.isQuestionAsked());
	testCircle.playIntroduction();
	testCircle.playNextDescription();
	testCircle.playNextDescription();
	
	// Update tests.
	// Start time update.
	testCircle.updateStartTime(200);
	assert(200 == testCircle.getStartTime());
	// Question asked update.
	testCircle.setQuestionToAsked();
	assert(true == testCircle.isQuestionAsked());
}