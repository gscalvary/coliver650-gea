#pragma once
#include "Message.h"

class Npc {
private:
	string name;
	string type;
	Message *speech;

public:
	Npc(string name, string type, Message *ptr);
	~Npc();
	string getName();
	string getType();
	void speak();
};

