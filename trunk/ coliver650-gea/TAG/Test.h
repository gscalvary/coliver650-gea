#pragma once
#include <cassert>
#include <stdlib.h>
#include "Circle.h"
#include "Clock.h"
#include "Game.h"
#include "Message.h"
#include "Npc.h"
#include "Point.h"
#include "Player.h"

class Test {
private:

public:
	Test();
	~Test();

	void test_Clock_class();
	void test_Game_class();
	void test_Point_class();
	void test_Player_class();
	void test_Message_class();
	void test_Npc_class();
	void test_Circle_class();
};