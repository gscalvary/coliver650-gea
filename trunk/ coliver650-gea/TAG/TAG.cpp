#include <windows.h>
#include <iostream>
#include <vector>
using namespace std;

// Canto defined classes.
#include <Test.h>

// The game engine will handle standard input via low-level windows console functions.  This allows the game to track the
// passage of time more realistically, without the interruptions that the use of cin would introduce.  Here the variables
// required for this feature are defined globally.
HANDLE hIn;
INPUT_RECORD inRec;
DWORD numRead, numEvents;
bool parseInput = false;
unsigned bufferSize = 128;
int inputBytes = 1;
vector<char> inputBuffer;

// main() helper functions.
void processAsciiChar() {
	
	if (inRec.Event.KeyEvent.uChar.AsciiChar == '\r' || inputBuffer.size() >= bufferSize) {
		parseInput = true;
		FlushConsoleInputBuffer(hIn);
		cout << endl;
	}
	else {
		if (inRec.Event.KeyEvent.uChar.AsciiChar == '\b') {
			if (inputBuffer.size() > 0) {
				inputBuffer.pop_back();
				cout << inRec.Event.KeyEvent.uChar.AsciiChar;
			}
		}
		else {
			inputBuffer.push_back(inRec.Event.KeyEvent.uChar.AsciiChar);
			cout << inRec.Event.KeyEvent.uChar.AsciiChar;
		}
	}
}

void getInput() {
	
	ReadConsoleInput(hIn, &inRec, inputBytes, &numRead);
	if (inRec.EventType == KEY_EVENT) {
		if (inRec.Event.KeyEvent.bKeyDown) {
			// Add code to unpause game.
			if (inRec.Event.KeyEvent.uChar.AsciiChar) {
				processAsciiChar();
			}
		}
	}
}

void run_tests() {
	
	cout << "Running Canto test suite..." << endl << endl;

	// Initialize a test instance.
	Test cantoTest;

	// Test the Clock class.
	cantoTest.test_Clock_class();
	cout << "Clock class tests complete." << endl;

	// Test the Game class.
	cantoTest.test_Game_class();
	cout << "Game class tests complete." << endl;

	// Test the Point class.
	cantoTest.test_Point_class();
	cout << "Point class tests complete." << endl;

	cout << endl << "Tests are conducted using assertions so failures are written to console." << endl;
	cout << "No news is good news, all tests have passed!" << endl << endl;
	cout << "Press any key to continue." << endl;
	cin.ignore();
}

// main() the function that drives the game.
int main(int argc, char* argv[]) {
	
	cout << "Welcome to Canto.\n\n" << endl;

	// A parameter of 't' passed to the game runs its test suite only then exits.
	if (argc > 0) {
		if (*argv[1] == 't') {
			run_tests();
			return 0;
		}
	}

	// Initialize game.
	Game cantoGame;

	// Take control of standard console input.
	hIn = GetStdHandle(STD_INPUT_HANDLE);
	cout << "> ";

	// Game loop.
	while (true)
	{
		// Check for console input.
		while (true)
		{
			GetNumberOfConsoleInputEvents(hIn, &numEvents);
			if (numEvents > 0) {
				getInput();
			}
			else {
				break;
			}
		}

		// Parse input.
		if (parseInput) {
			parseInput = false;
			for (unsigned i = 0; i < inputBuffer.size(); ++i) {
				cout << "   Parsing inputBuffer[" << i << "] = " << inputBuffer[i] << endl;
			}
			if (inputBuffer[0] == 'q') {
				break;
			}
			else {
				inputBuffer.clear();
				cout << "> ";
			}
		}

		// Update game world.
			// Add code to quit game.
			// Add code to pause game.
			// Add code to step game clock.
			// Add code to process parsed input.

		// Render.
	}
	return 0;
}