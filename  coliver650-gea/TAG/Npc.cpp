#include "Npc.h"

// Npc: string, string, Message *pointer ->
// EFFECT: Creates an Npc object in memory with a name, a type and a pointer to a message which the Npc may speak.
// INVARIANT: The Npc type is either 'shade' or 'demon' by program convention.
// Example: see test class.
Npc::Npc(string a, string b, Message *ptr) {
	name = a;
	type = b;
	speech = ptr;
}
// ~Npc:
// EFFECT: De-allocates the memory reserved for an Npc object.
Npc::~Npc() {

}
// getName: -> string
// Takes no input but returns a string representing the npcs name.
// Example: see test class.
string Npc::getName() {
	return name;
}
// getType: -> string
// Takes no input but returns a string representing the npcs type.
// INVARIANT: The Npc type is either 'shade' or 'demon' by program convention.
// Example: see test class.
string Npc::getType() {
	return type;
}
// speak:
// Takes no input but plays the message associated with the npc, see the message class play() function.
// Example: see test class.
void Npc::speak() {
	speech->play();
}