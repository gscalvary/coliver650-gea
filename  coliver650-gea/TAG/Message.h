#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Message {
private:
	vector<string> text;
	string owner;

public:
	Message(string owner);
	~Message();
	void addText(string x);
	void play();
	string getOwner();
};

