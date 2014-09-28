#include "Message.h"

// Message: string ->
// EFFECT: Creates a message object in memory with an owner set to the passed in string.
// Example: see test class.
Message::Message(string x) {
	owner = x;
}
// ~Message:
// EFFECT: De-allocates the memory reserved for a Message object.
Message::~Message() {

}
// addText: string ->
// Adds the passed string to the vector of strings composing this message.
// Example: see test class.
void Message::addText(string x) {
	text.push_back(x);
}
// play:
// EFFECT: If the owner of the string is not 'game' writes to output a message stating the message owner says:
// followed by a new line and then each message string on its own new line.  'game' messages are treated the 
// same way but without the preceding owner line included.
// Example: see test class.
void Message::play() {
	cout << endl;
	if (owner != "game") {
		cout << owner << " approaches and says:" << endl;
	}
	for (vector<string>::iterator it = text.begin(); it != text.end(); ++it) {
		cout << *it << endl;
	}
}
// getOwner: -> string
// Takes no input but returns a string representing the message owners name.
// Example: see test class.
string Message::getOwner() {
	return owner;
}
