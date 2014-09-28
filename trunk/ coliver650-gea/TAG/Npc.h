#pragma once
#include "Message.h"

// An object representing a non-player character.  Many are created as children of each Circle.
class Npc {
private:
	string name;
	string type;
	Message *speech;

public:
	// Npc: string, string, Message *pointer ->
	// EFFECT: Creates an Npc object in memory with a name, a type and a pointer to a message which the Npc may speak.
	// INVARIANT: The Npc type is either 'shade' or 'demon' by program convention.
	// Example: see test class.
	Npc(string name, string type, Message *ptr);
	// ~Npc:
	// EFFECT: De-allocates the memory reserved for an Npc object.
	~Npc();
	// getName: -> string
	// Takes no input but returns a string representing the npcs name.
	// Example: see test class.
	string getName();
	// getType: -> string
	// Takes no input but returns a string representing the npcs type.
	// INVARIANT: The Npc type is either 'shade' or 'demon' by program convention.
	// Example: see test class.
	string getType();
	// speak:
	// Takes no input but plays the message associated with the npc, see the message class play() function.
	// Example: see test class.
	void speak();
};

