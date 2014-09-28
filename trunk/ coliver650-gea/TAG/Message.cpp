#include "Message.h"

Message::Message(string x) {
	owner = x;
}

Message::~Message() {

}

void Message::addText(string x) {
	text.push_back(x);
}

void Message::play() {
	cout << endl;
	if (owner != "game") {
		cout << owner << " approaches and says:" << endl;
	}
	for (vector<string>::iterator it = text.begin(); it != text.end(); ++it) {
		cout << *it << endl;
	}
}

string Message::getOwner() {
	return owner;
}
