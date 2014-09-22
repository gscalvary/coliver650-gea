#include <windows.h>
#include <iostream>
#include <vector>
using namespace std;

class Clock {
private:
public:
	// Add constructor.
};

class Item {
private:
public:
};

class Room {
private:
public:
};

class Player {
private:
public:
};

class Game {
private:
	// Add clock member.
	// Add room members.
	// Add player member.
public:
	// Add constructor.
};

int main()
{
	HANDLE hIn;
	INPUT_RECORD inRec;
	DWORD numRead, numEvents;
	bool parseInput = false;
	unsigned bufferSize = 128;
	int inputBytes = 1;
	vector<char> inputBuffer;

	hIn = GetStdHandle(STD_INPUT_HANDLE);

	cout << "Welcome to my first text based game!" << endl;
	cout << "> ";

	// Add code to create objects.

	// Game loop.
	while (true)
	{
		// Get input.
		while (true)
		{
			GetNumberOfConsoleInputEvents(hIn, &numEvents);
			if (numEvents > 0) {
				ReadConsoleInput(hIn, &inRec, inputBytes, &numRead);
				if (inRec.EventType == KEY_EVENT) {
					if (inRec.Event.KeyEvent.bKeyDown) {
						// Add code to unpause game.
						if (inRec.Event.KeyEvent.uChar.AsciiChar) {
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
					}
				}
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