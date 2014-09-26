#include "Npc.h"

Npc::Npc(string a, string b, Message *ptr) {
	name = a;
	type = b;
	speech = ptr;
}

Npc::~Npc() {

}

string Npc::getName() {
	return name;
}

string Npc::getType() {
	return type;
}

void Npc::speak() {
	speech->play();
}