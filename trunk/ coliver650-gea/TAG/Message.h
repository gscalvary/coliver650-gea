#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// A message object that facilitates the communication of the game and npcs with the users.  Many
// are created as children of Circles, the Game and Npcs.
class Message {
private:
	vector<string> text;
	string owner;

public:
	// Message: string ->
	// EFFECT: Creates a message object in memory with an owner set to the passed in string.
	// Example: see test class.
	Message(string owner);
	// ~Message:
	// EFFECT: De-allocates the memory reserved for a Message object.
	~Message();
	// addText: string ->
	// Adds the passed string to the vector of strings composing this message.
	// Example: see test class.
	void addText(string x);
	// play:
	// EFFECT: If the owner of the string is not 'game' writes to output a message stating the message owner says:
	// followed by a new line and then each message string on its own new line.  'game' messages are treated the 
	// same way but without the preceding owner line included.
	// Example: see test class.
	void play();
	// getOwner: -> string
	// Takes no input but returns a string representing the message owners name.
	// Example: see test class.
	string getOwner();
};

