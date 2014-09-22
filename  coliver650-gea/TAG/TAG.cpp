#include <windows.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	HANDLE hIn;
	INPUT_RECORD inRec;
	DWORD numRead, numEvents;
	bool Continue = true;
	bool parseInput = false;
	unsigned bufferSize = 128;
	vector<char> inputBuffer;

	hIn = GetStdHandle(STD_INPUT_HANDLE);

	cout << "Welcome to my first text based game!" << endl;
	cout << "> ";

	while (true)
	{
		while (true)
		{
			GetNumberOfConsoleInputEvents(hIn, &numEvents);
			if (numEvents > 0) {
				ReadConsoleInput(hIn, &inRec, 1, &numRead);
				if (inRec.EventType == KEY_EVENT) {
					if (inRec.Event.KeyEvent.bKeyDown) {
						if (inRec.Event.KeyEvent.uChar.AsciiChar) {
							if (inRec.Event.KeyEvent.uChar.AsciiChar == '\r') {
								parseInput = true;
								FlushConsoleInputBuffer(hIn);
								cout << endl;
							}
							else {
								inputBuffer.push_back(inRec.Event.KeyEvent.uChar.AsciiChar);
								cout << inRec.Event.KeyEvent.uChar.AsciiChar;
							}
						}
					}
				}
			}
			else {
				break;
			}
			if (inputBuffer.size() >= bufferSize) {
				break;
			}
		}

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
	}

	return 0;
}